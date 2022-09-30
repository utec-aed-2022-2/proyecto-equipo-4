//
// Created by juaquin on 30/09/22.
//

#include "Block.h"
#include "sha256.h"
#include <chrono>
#include <ctime>

template<typename T>
Block<T>::Block(int id, int size, std::string& parent_hash) {
    this->size = size;
    this->id = id;
    this->registers = new T[size];
    this->parent_hash = parent_hash;
    this->created_time = _get_time();
}

template<typename T>
std::string Block<T>::_get_time() {
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);
    std::string now_date = std::ctime(&end_time);
    return now_date;
}

template<typename T>
void Block<T>::_hash_block() {
    SHA256 hasher;
    hasher.add(id, sizeof(int));
    hasher.add((char*)parent_hash, sizeof(std::string));
    hasher.add((char*)created_time, sizeof(std::string));
    hasher.add(registers, sizeof(T)*size);
    this->hash = hasher.getHash();
}
