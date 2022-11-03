//
// Created by juaquin on 26/10/22.
//

#ifndef PROYECTO_EQUIPO_4_INDEX_H
#define PROYECTO_EQUIPO_4_INDEX_H

#include "ChainHash.h"
#include "heap.h"

template <typename TK, typename TV>
struct Index{
    virtual void insert(TK, TV) = 0;
    virtual void top(){}
    virtual void get(){}
    virtual void get(TK){}
};

template <typename TK, typename TV>
struct HashIndex : public Index<TK, TV>{
    ChainHash<TK, ForwardList<TV>*> blocks;
    void insert(TK key, TV value) override {
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
    HashIndex() = default;
};

template <typename TK, typename TV>
struct MaxHeapIndex : public Index<TK, TV>{
    MaxHeapIndex() = default;
    multiHeap<TK, TV> blocks;
    void insert(TK key, TV value) override {
        blocks.push(key, value);
    }
};

template <typename TK, typename TV>
struct MinHeapIndex : public Index<TK, TV>{
    MinHeapIndex() = default;
    multiHeap<TK, TV, std::less<>> blocks;
    void insert(TK key, TV value) override {
        blocks.push(key, value);
    }
};

#endif //PROYECTO_EQUIPO_4_INDEX_H
