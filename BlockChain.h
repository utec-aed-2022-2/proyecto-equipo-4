//
// Created by User on 30/9/2022.
//

#ifndef PROYECTO_EQUIPO_4_BLOCKCHAIN_H
#define PROYECTO_EQUIPO_4_BLOCKCHAIN_H

#include <functional>
#include "ForwardList.h"
#include "Block.h"

template<typename T>
class BlockChain {
private:
    ForwardList<Block<T>> blockchain;
    int block_size;
public:
    T searchRegister(std::function<bool(T)> &f);

};


#endif //PROYECTO_EQUIPO_4_BLOCKCHAIN_H
