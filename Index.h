//
// Created by juaquin on 26/10/22.
//

#ifndef PROYECTO_EQUIPO_4_INDEX_H
#define PROYECTO_EQUIPO_4_INDEX_H

#include "ChainHash.h"

template <typename TK, typename TV>
struct Index{
    ChainHash<TK, ForwardList<TV>*> blocks;
    void insert(TK key, TV value);
    Index() = default;
};

template<typename TK, typename TV>
void Index<TK, TV>::insert(TK key, TV value) {
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

#endif //PROYECTO_EQUIPO_4_INDEX_H
