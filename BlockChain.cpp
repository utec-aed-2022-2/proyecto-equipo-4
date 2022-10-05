//
// Created by User on 30/9/2022.
//

#include "BlockChain.h"


template <typename T>
T BlockChain<T>::insertRegister(T data)
{
    auto last_block = blockchain.get(last_id);
    if (last_block.get_size() == block_size)
    {
        T *n_register = new T(block_size);
        n_register[0] = data;
        Block<T> n_block = Block<T>(last_block.get_id(), block_size, n_register, last_block.get_hash());
        blockchain.insert(last_block.get_id() + 1, n_register);
    }
    else
    {
        blockchain.get(last_id)[blockchain.get(last_id).get_size()] = data;
    }
}

template <typename T>
int BlockChain<T>::get_last_id()
{
    return last_id;
}
