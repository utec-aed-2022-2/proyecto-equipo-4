//
// Created by juaquin on 26/10/22.
//

#ifndef PROYECTO_EQUIPO_4_INDEX_H
#define PROYECTO_EQUIPO_4_INDEX_H

#include "ChainHash.h"
#include "Heap/heap.h"
#include "AVL/avl.h"
#include "Btree/btree.h"
#include "trie/triePatricia.h"

template <typename TK, typename TV>
struct Index{
    virtual string type() = 0;
    virtual void insert(const TK&, const TV&) = 0;
    virtual ForwardList<Entry<TK, TV>>* start_with(const string& key){}
    virtual Entry<TK, TV>& get(){}
    virtual Entry<TK, TV>& get(TK){}
    virtual ForwardList<Entry<TK, TV>>* get(TK, TK){}
};

template <typename TK, typename TV>
struct HashIndex : public Index<TK, TV>{
    ChainHash<TK, ForwardList<TV>*> blocks;
    string type() override {return "hash";}
    void insert(const TK& key, const TV& value) override {
        auto r = blocks.find(key);
        if (r) {
            (*r)->push_front(value);
        }
        else{
            auto* f = new ForwardList<TV>();
            f->push_front(value);
            blocks.insert(key, f);
        }
    }
    Entry<TK, TV>& get(TK k){
        auto* res = new Entry<TK, TV>(k);
        auto& e = blocks.get(k);
        for(auto e_: *e){
            res->insert(e_);
        }
        return *res;
    }
    HashIndex() = default;
};

template <typename TK, typename TV>
struct MaxHeapIndex : public Index<TK, TV>{
    string type() override {return "max";}
    MaxHeapIndex() = default;
    multiHeap<TK, TV> blocks;
    void insert(const TK& key, const TV& value) override {
        blocks.push(key, value);
    }
    Entry<TK, TV>& get() override{
        return blocks.elements[0];
    }
};

template <typename TK, typename TV>
struct MinHeapIndex : public Index<TK, TV>{
    string type() override {return "min";}
    MinHeapIndex() = default;
    multiHeap<TK, TV, std::less<>> blocks;
    void insert(const TK& key, const TV& value) override {
        blocks.push(key, value);
    }
    Entry<TK, TV>& get() override{
        return blocks.elements[0];
    }
};

template <typename TK, typename TV>
struct AVLIndex : public Index<TK, TV> {
    struct S {
        TK key;
        ForwardList<TV> f;
        S() = default;
        S(TK k, TV value) {
            key = k;
            this->insert(value);
        }
        void insert(TV value) {
            f.push_front(value);
        }
        void insert(S value) {
            f.push_front(value.f.front());
        }
        bool operator==(const S& k){
            this->key = k.key;
        }
        bool operator>(const S& k){
            this->key > k.key;
        }
        bool operator<(const S& k){
            this->key < k.key;
        }
    };

    string type() override {return "avl";}
    AVLIndex() = default;
    AVLTree<S> avl;
    void insert(const TK& key, const TV& value) override {
        avl.insert(S(key, value));
    }
};

template <typename TK ,typename TV>
struct BTreeIndex : public Index<TK, TV> {
    string type() override {return "btree";}
    BTreeIndex() = default;
    BTree<Entry<TK,TV>> btree{10};
    void insert(const TK& key, const TV& value) override {
        Entry<TK, TV> e(key);
        e.insert(value);
        btree.insert(e);
    }
    ForwardList<Entry<TK, TV>>* get(TK start, TK end){
        return btree.search_range(start, end);
    }
};

template <typename TK ,typename TV>
struct TrieIndex : public Index<TK, TV> {
    string type() override {return "trie";}
    TrieIndex() = default;
    TriePatricia<Entry<TK, TV>> trie;
    void insert(const TK& key, const TV& value) override {
        auto* e = new Entry<TK, TV>(key);
        e->insert(value);
        trie.insert(key, e);
    }
    ForwardList<Entry<TK, TV>>* start_with(const string& key) override{
        return trie.start_with(key);
    }
};


#endif //PROYECTO_EQUIPO_4_INDEX_H
