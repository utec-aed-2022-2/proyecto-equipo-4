//
// Created by juaquin on 01/10/22.
//

#ifndef PROYECTO_EQUIPO_4_CHAINHASH_H
#define PROYECTO_EQUIPO_4_CHAINHASH_H

#include "ForwardList.h"
#include <functional>

using namespace std;

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
    hash<TK> getHash;

public:
    ChainHash(int _capacity = 5);

    float fillFactor();

    bool insert(TK key, TV value);

    TV get(TK key);

    void rehashing();

    void remove(TK key);

    int bucket_count();

    int bucket_size(int i_bucket);

    /*ForwardList<Entry>::iterator begin(int i_bucket){
        return array[i_bucket].begin();
    }

    ForwardList<Entry>::iterator end(int i_bucket){
        return array[i_bucket].end();
    }*/

    ~ChainHash();
};

#endif //PROYECTO_EQUIPO_4_CHAINHASH_H
