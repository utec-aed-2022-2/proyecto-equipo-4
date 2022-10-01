//
// Created by User on 30/9/2022.
//

#ifndef PROYECTO_EQUIPO_4_BLOCKCHAIN_H
#define PROYECTO_EQUIPO_4_BLOCKCHAIN_H

#include <functional>
#include "ChainHash.h"
#include "Block.h"

template<typename T>
class BlockChain {
private:
    ChainHash<std::string, Block<T>> blockchain;
    int block_size;
public:
    T searchRegister(std::function<bool(T)> &f);
    T insertRegister(T data);
    
};


#endif //PROYECTO_EQUIPO_4_BLOCKCHAIN_H
