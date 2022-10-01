//
// Created by User on 30/9/2022.
//

#include "BlockChain.h"

template <typename T>
T BlockChain<T>::searchRegister(std::function<bool(T)> &f)
{
    auto it = blockchain->head;
    while (it->next != nullptr)
    {
        for (auto it2 = 0; it2 < block_size; it2++)
        {
            if (f(it->registers[it2]))
            {
                return it->registers[it2];
            }
        }
    }
}
template <typename T>
T BlockChain<T>::insertRegister(T data)
{
    auto it = blockchain->head;

    // Anadir exepciones
    while ((it->next)->next != nullptr)
    {
        it = it->next;
    }
    auto parent = it;
    auto child = it->next;
    if (child._get_size() == block_size)
    {
        T*n_register = new T(block_size);
        Block<T> n_block = Block<T>(parent._get_id(), block_size, n_register, parent._get_hash());
        blockchain.push_back(n_block);
    }
    else
    {
        

    }
}
