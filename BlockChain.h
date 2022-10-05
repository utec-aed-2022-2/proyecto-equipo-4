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
    ChainHash<int, Block<T>> blockchain;
    int block_size;
    int last_id;
public:
    T searchRegister(std::function<bool(T)> &f, int &idBlock, int &posRegister);

    void updateRegister(int idBlock, int posRegister, T newRegister);

    T insertRegister(T data);

    int get_last_id();
private:
    void _rehash_block(const int &id);
};

template<typename T>
void BlockChain<T>::_rehash_block(const int &id) {
    auto block = blockchain.get(id);
    if (block.get_id() != id) return;
    block.recalculate_hash();
    _rehash_block(id+1);
}

template <typename T>
T BlockChain<T>::searchRegister(std::function<bool(T)> &f, int &idBlock, int &posRegister)
{
    for (int i = 0; i < blockchain.bucket_count(); ++i)
    {
        Block<T> block = blockchain->array[i].front()->value;
        for(int j = 0; j < block_size; ++j)
        {
            if(f(block->registers[j]))
            {
                idBlock = i;
                posRegister = j;
                return block->registers[j];
            }
        }
    }
    return T();
}

template <typename T>
void BlockChain<T>::updateRegister(int idBlock, int posRegister, T newRegister)
{
    blockchain->array[idBlock].front()->value->registers[posRegister] = newRegister;
}



#endif //PROYECTO_EQUIPO_4_BLOCKCHAIN_H
