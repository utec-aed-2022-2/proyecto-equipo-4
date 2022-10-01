//
// Created by User on 30/9/2022.
//

#include "BlockChain.h"

template<typename T>
T BlockChain<T>::searchRegister(std::function<bool(T)> &f) {
    auto it = blockchain->head;
    while(it->next != nullptr){
        for(auto it2 = 0; it2 < block_size; it2++){
            if(f(it->registers[it2])){
                return it->registers[it2];
            }
        }
    }
}
