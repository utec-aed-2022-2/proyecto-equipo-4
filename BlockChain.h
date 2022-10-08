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
    T* b_block;
    int c;
    ChainHash<int, Block<T>*> blockchain;
    int block_size;
    int last_id;
    std::string genesis="";
public:
    BlockChain(int block_size){
        this->block_size=block_size;
        b_block = new T[block_size];
        c = 0;
        last_id = 0;
    }

    T searchRegister(function<bool(string)> f, int &id_block, int &pos_register);

    void updateRegister(int id_block, int pos_register, T new_register);

    void insertRegister(T data);

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
T BlockChain<T>::searchRegister(function<bool(string)> f, int &id_block, int &pos_register)
{
    for (int i = 0; i < last_id; ++i)
    {
        Block<T>* block = blockchain.get(i);
        for(int j = 0; j < block_size; ++j)
        {
            const T tmp_register = block->at(j);
            if(f(tmp_register))
            {
                id_block = i;
                pos_register = j;
                return tmp_register;
            }
        }
    }
    throw ("No se encontró el registro");
}

template <typename T>
void BlockChain<T>::updateRegister(int id_block, int pos_register, T new_register) {
    Block<T>* block= blockchain.get(id_block);
    block->at(pos_register) = new_register;
    block->recalculate_hash();
    while( ++id_block < last_id)
    {
        blockchain.get(id_block)->recalculate_hash();
    }
}

template <typename T>
void BlockChain<T>::insertRegister(T data)
{
    b_block[c] = data;
    c++;
    if (c == block_size){
        Block<T>* n_block = new Block<T>(last_id, block_size, b_block, genesis);
        blockchain.insert(last_id, n_block);
        last_id++;
        c = 0;
    }
}

template <typename T>
int BlockChain<T>::get_last_id()
{
    return last_id;
}



#endif //PROYECTO_EQUIPO_4_BLOCKCHAIN_H
