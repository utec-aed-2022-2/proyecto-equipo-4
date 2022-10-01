//
// Created by juaquin on 30/09/22.
//

#include "Block.h"
#include "sha256.h"
#include <chrono>
#include <ctime>

template<typename T>
Block<T>::Block(int id, int size, T* registers, std::string& parent_hash) {
    this->size = size;
    this->id = id;
    this->registers = registers;
    this->parent_hash = parent_hash;
    this->created_time = _get_time();
    this->hash = _calculate_hash();
}
template<typename T>
Block<T>::Block(int id, int size, std::string& parent_hash) {
    this->size = size;
    this->id = id;
    this->parent_hash = parent_hash;
    this->created_time = _get_time();
    this->hash = _calculate_hash();
}

template<typename T>
std::string Block<T>::_get_time() {
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now);
    std::string now_date = std::ctime(&end_time);
    return now_date;
}

template<typename T>
std::string Block<T>::_hash_block() {
    SHA256 hasher;
    return hasher(std::to_string(id))+hasher( parent_hash)+hasher( created_time)+hasher(registers, sizeof(T)*size);
}

template<typename T>
std::string Block<T>::_calculate_hash() {
    SHA256 hasher;
    char *t_hash = _hash_block();
    this->nonce = 0;
    do {
        this->nonce++;
        hasher.reset();
        hasher(t_hash, sizeof(std::string))+hasher(std::to_string(this->nonce));
    }while (!_verify_hash(hasher.getHash()));
    return hasher.getHash();
}

template<typename T>
bool Block<T>::_verify_hash(std::string hash_v) {
    return (hash_v.at(0) == '0' && hash_v.at(1) == '0' && hash_v.at(2) == '0');
}

template<typename T>
int Block<T>::_get_size(){
    return size;
}

template<typename T>
int Block<T>::_get_id(){
    return id;
}

template<typename T>
int Block<T>::_get_hash(){
    return id;
}