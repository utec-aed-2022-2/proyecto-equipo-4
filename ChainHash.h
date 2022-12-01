//
// Created by juaquin on 01/10/22.
//

#ifndef PROYECTO_EQUIPO_4_CHAINHASH_H
#define PROYECTO_EQUIPO_4_CHAINHASH_H

#include "ForwardList/ForwardList.h"


const float maxFillFactor = 0.5;
const int maxCollision = 3;

template<typename TK, typename TV>
class ChainHash {
private:
    struct Entry {
        TK key;
        TV value;
        size_t hashcode;

        Entry() {}

        Entry(TK _k, TV _v, size_t h) {
            key = _k;
            value = _v;
            hashcode = h;
        }
    };

    ForwardList<Entry> *array;
    int capacity;
    int size;
    std::hash <TK> getHash;

public:
    ChainHash(int _capacity = 5);

    float fillFactor();

    bool insert(TK key, TV& value);

    TV &get(TK key);

    void rehashing();

    void remove(TK key);

    int bucket_count();

    int bucket_size(int i_bucket);

    TV* find(TK key);

    /*ForwardList<Entry>::iterator begin(int i_bucket){
        return array[i_bucket].begin();
    }

    ForwardList<Entry>::iterator end(int i_bucket){
        return array[i_bucket].end();
    }*/

    ~ChainHash();
};

template<typename TK, typename TV>
ChainHash<TK, TV>::ChainHash(int _capacity) {
    this->capacity = _capacity;
    this->array = new ForwardList<Entry>[this->capacity];
    this->size = 0;
}

template<typename TK, typename TV>
float ChainHash<TK, TV>::fillFactor() {
    return size / (capacity * maxCollision);
}

template<typename TK, typename TV>
bool ChainHash<TK, TV>::insert(TK key, TV& value) {
    if (fillFactor() >= maxFillFactor) rehashing();
    size_t hashcode = getHash(key);
    int index = hashcode % capacity;
    //TODO: evaluar si la llave existe

    int ts = array[index].size();

    if (ts == maxCollision) {
        rehashing();
        hashcode = getHash(key);
        index = hashcode % capacity;
    }

    for (auto it = array[index].begin(); it != array[index].end(); it++) {
        if (it->key == key) {
            it->value = value;
            return true;
        }
    }
    array[index].push_front(Entry(key, value, hashcode));
    size++;
    return true;
}

template<typename TK, typename TV>
TV &ChainHash<TK, TV>::get(TK key) {
    size_t hashcode = getHash(key);
    int index = hashcode % capacity;
    //TODO: iterar en la lista array[index]
    for (auto it = array[index].begin(); it != array[index].end(); it++) {
        if (it->key == key) {
            return it->value;
        }
    }
    throw ("No existe la clave");
}

template<typename TK, typename TV>
void ChainHash<TK, TV>::rehashing() {
    ForwardList<Entry> *t = new ForwardList<Entry>[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        for (auto it = array[i].begin(); it != array[i].end(); it++) {
            size_t hashcode = getHash(it->key);
            int index = hashcode % (capacity * 2);
            t[index].push_front(Entry(it->key, it->value, hashcode));
        }
    }
    //falta liberar el array anterior
    capacity *= 2;
    delete[] this->array;
    this->array = t;
}

template<typename TK, typename TV>
void ChainHash<TK, TV>::remove(TK key) {
    size_t hashcode = getHash(key);
    int index = hashcode % capacity;
    for (auto it = array[index].begin(); it != array[index].end(); it++) {
        if (it->key == key) {
            array[index].remove(it);
            break;
        }
    }
    size--;
}

template<typename TK, typename TV>
int ChainHash<TK, TV>::bucket_count() {
    return capacity;
}

template<typename TK, typename TV>
int ChainHash<TK, TV>::bucket_size(int i_bucket) {
    return std::distance(array[i_bucket].begin(), array[i_bucket].end());
}

template<typename TK, typename TV>
ChainHash<TK, TV>::~ChainHash() {
    delete[] this->array;
}

template<typename TK, typename TV>
TV* ChainHash<TK, TV>::find(TK key) {
    size_t hashcode = getHash(key);
    int index = hashcode % capacity;
    //TODO: iterar en la lista array[index]
    for (auto it = array[index].begin(); it != array[index].end(); it++) {
        if (it->key == key) {
            return &it->value;
        }
    }
    return nullptr;
}


#endif //PROYECTO_EQUIPO_4_CHAINHASH_H
