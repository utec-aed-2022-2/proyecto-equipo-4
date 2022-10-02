//
// Created by juaquin on 30/09/22.
//

#ifndef PROYECTO_EQUIPO_4_BLOCK_H
#define PROYECTO_EQUIPO_4_BLOCK_H

#include <string>
#include <iostream>
#include "sha256.h"
#include <chrono>
#include <ctime>

template <typename T>
class Block {
private:
    int id;
    int nonce;
    int size;
    T* registers;
    std::string created_time;
    std::string hash;
    const std::string& parent_hash;
public:
    Block(const int &id, const int &size, T* registers, std::string& parent_hash);
    int get_size();
    int get_id();
    std::string get_hash();
private:
    std::string _get_time();
    std::string _hash_block();
    std::string _calculate_hash();
    bool _verify_hash(std::string hash_v);
    std::string _hash_registers();
};

template<typename T>
Block<T>::Block(const int &id, const int &size, T* registers, std::string& parent_hash): parent_hash(parent_hash) {
    this->size = size;
    this->id = id;
    this->registers = registers;
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
    return hasher(std::to_string(id) + parent_hash + created_time + _hash_registers());
}

template<typename T>
std::string Block<T>::_calculate_hash() {
    SHA256 hasher;
    std::string t_hash = _hash_block();
    this->nonce = 0;
    do {
        this->nonce++;
        hasher(t_hash + std::to_string(this->nonce));
    }while (!_verify_hash(hasher.getHash()));
    return hasher.getHash();
}

template<typename T>
bool Block<T>::_verify_hash(std::string hash_v) {
    return (hash_v.at(0) == '0' && hash_v.at(1) == '0' && hash_v.at(2) == '0');
}

template<typename T>
int Block<T>::get_size(){
    return size;
}

template<typename T>
int Block<T>::get_id(){
    return id;
}

template<typename T>
std::string Block<T>::get_hash(){
    return this->hash;
}

template<typename T>
std::string Block<T>::_hash_registers() {
    SHA256 sha256;
    auto it = this->registers;
    for (int i = 0; i<size; i++){
        sha256.add(it, sizeof(T));
        it++;
    }
    return sha256.getHash();
}

#endif //PROYECTO_EQUIPO_4_BLOCK_H
