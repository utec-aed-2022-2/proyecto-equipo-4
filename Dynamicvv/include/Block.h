//
// Created by juaquin on 30/09/22.
//

#ifndef PROYECTO_EQUIPO_4_BLOCK_H
#define PROYECTO_EQUIPO_4_BLOCK_H

#include "sha256.h"
#include <iostream>
#include <fstream>
#include <ios>
//#include "json/json.h"
//#include <nlohmann/json.hpp>

//#include "rapidjson/document.h"

template<typename T>
class Block {
private:
    int id;
    int nonce;
    int size;
    T *registers;
    std::string hash;
    const std::string &parent_hash;
public:
    Block() = default;

    Block(const int &id, const int &size, T *registers, std::string &parent_hash);

    int get_size();

    int get_id();

    std::string& get_hash();

    void recalculate_hash();

    T &at(const int &index);

    void print();
    void toCSV();


private:

    std::string _hash_block();

    std::string _calculate_hash();

    bool _verify_hash(const std::string &hash_v);

    std::string _hash_registers();
};

template<typename T>
Block<T>::Block(const int &id, const int &size, T *registers, std::string &parent_hash): parent_hash(parent_hash) {
    this->size = size;
    this->id = id;
    this->registers = registers;
    this->hash = _calculate_hash();
}

template<typename T>
std::string Block<T>::_hash_block() {
    SHA256 sha256;
    return sha256(std::to_string(id) + parent_hash + _hash_registers());
}

template<typename T>
std::string Block<T>::_calculate_hash() {
    SHA256 sha256;
    std::string t_hash = _hash_block();
    this->nonce = 0;
    do {
        this->nonce++;
        sha256(t_hash + std::to_string(this->nonce));
    } while (!_verify_hash(sha256.getHash()));
    return sha256.getHash();
}

template<typename T>
bool Block<T>::_verify_hash(const std::string &hash_v) {
    return (hash_v.at(0) == '0' && hash_v.at(1) == '0' && hash_v.at(2) == '0');
}

template<typename T>
int Block<T>::get_size() {
    return size;
}

template<typename T>
int Block<T>::get_id() {
    return id;
}

template<typename T>
std::string& Block<T>::get_hash() {
    return this->hash;
}

template<typename T>
std::string Block<T>::_hash_registers() {
    SHA256 sha256;
    std::string text = "";
    for (int i = 0; i < size; i++) {
        text += std::string(registers[i]);
    }
    sha256(text);
    return sha256.getHash();
}

template<typename T>
void Block<T>::recalculate_hash() {
    this->hash = this->_calculate_hash();
}

template<typename T>
T &Block<T>::at(const int &index) {
    if (index < 0 || index >= size) throw ("Indice fuera de rango");
    return registers[index];
}

template<typename T>
void Block<T>::print() {

    std::cout << "id: " << this->id << std::endl;
    std::cout << "nonce: " << this->nonce << std::endl;
    std::cout << "hash: " << this->hash << std::endl;
    std::cout << "parent hash: " << this->parent_hash << std::endl;
    std::cout << "Registers:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << '\t' << std::string(this->registers[i]) << std::endl;
    }
}

template<typename T>
void Block<T>::toCSV() {
    std::ofstream myfile;
    myfile.open ("example.csv", std::fstream::app);
    myfile << this->id <<","<<this->nonce<<","<<this->hash<<","<<this->parent_hash<<",";
    for (int i = 0; i < size; i++){
        if (i != 0){
            myfile << ',' << std::string(this->registers[i]);
        }else{
            myfile<< std::string(this->registers[i]);
        }
    }
    myfile<<std::endl;
    myfile.close();

}

#endif //PROYECTO_EQUIPO_4_BLOCK_H
