//
// Created by User on 30/9/2022.
//

#ifndef PROYECTO_EQUIPO_4_BLOCKCHAIN_H
#define PROYECTO_EQUIPO_4_BLOCKCHAIN_H

#include <functional>
#include <fstream>
#include "ChainHash.h"
#include "Block.h"
#include "Index.h"

template<typename T>
class BlockChain {
private:
    T *b_block;
    int c;
    ChainHash<int, Block<T> *> blockchain;
    int block_size;
    int next_id;
    std::string genesis;
    std::string bc_path;
public:
    BlockChain(int block_size, const std::string &n_path = "../data.csv") {
        bc_path = n_path;
        this->block_size = block_size;
        b_block = new T[block_size];
        c = 0;
        next_id = 0;
        loadFromCSV(bc_path);
    }

    template <typename TA>
    void createIndex(TA attribute);

    template <typename TA>
    void createIndexHeap(TA attribute);

    T searchRegister(std::function<bool(std::string)> f, int &id_block, int &pos_register);

    void updateRegister(int id_block, int pos_register, T new_register);

    void insertRegister(T data);

    int getLastId();

    void loadFromCSV(const std::string &path);

    void print();

    ~BlockChain();

private:
    void _rehash_block(const int &id);
};

template<typename T>
void BlockChain<T>::_rehash_block(const int &id) {
    auto block = blockchain.get(id);
    if (block.get_id() != id) return;
    block.recalculate_hash();
    _rehash_block(id + 1);
}

template<typename T>
T BlockChain<T>::searchRegister(std::function<bool(std::string)> f, int &id_block, int &pos_register) {
    for (int i = 0; i < next_id; ++i) {
        Block<T> *block = blockchain.get(i);
        for (int j = 0; j < block_size; ++j) {
            const T tmp_register = block->at(j);
            if (f(tmp_register)) {
                id_block = i;
                pos_register = j;
                return tmp_register;
            }
        }
    }
    throw ("No se encontró el registro");
}

template<typename T>
void BlockChain<T>::updateRegister(int id_block, int pos_register, T new_register) {
    Block<T> *block = blockchain.get(id_block);
    block->at(pos_register) = new_register;
    block->recalculate_hash();
    while (++id_block < next_id) {
        blockchain.get(id_block)->recalculate_hash();
    }
}

template<typename T>
void BlockChain<T>::insertRegister(T data) {
    b_block[c] = data;
    c++;
    if (c == block_size) {
        T *temp = new T[block_size];
        std::copy_n(b_block, block_size, temp);
        if (next_id != 0) {
            auto &x = (blockchain.get(next_id - 1))->get_hash();
            auto *n_block = new Block<T>(next_id, block_size, temp, x);
            blockchain.insert(next_id, n_block);
        } else {
            auto *n_block = new Block<T>(next_id, block_size, temp, this->genesis);
            blockchain.insert(next_id, n_block);
        }
        next_id++;
        c = 0;
    }
}

template<typename T>
int BlockChain<T>::getLastId() {
    return next_id;
}

template<typename T>
void BlockChain<T>::loadFromCSV(const std::string &path) {
    std::fstream f(path, std::ios::in);
    std::string line;
    if (f.is_open()) {
        getline(f, line);
        while (getline(f, line)) {
            T regist(line);
            this->insertRegister(regist);
        }
        f.close();
    } else throw "Could not open the file";
}

template<typename T>
BlockChain<T>::~BlockChain() {
    std::fstream f(this->bc_path, std::ios::out);
    if (f.is_open()) {
        f << std::endl;
        for (int i = 0; i < next_id; i++) {
            auto t = blockchain.get(i);
            for (int j = 0; j < block_size; j++) {
                f << std::string(t->at(j)) << std::endl;
            }
        }
    } else throw "Could not open the file";
}

template<typename T>
void BlockChain<T>::print() {
    int n = 0;
    while (n < next_id) {
        this->blockchain.get(n)->print();
        std::cout << std::endl;
        n++;
    }
}

template<typename T>
template<typename TA>
void BlockChain<T>::createIndex(TA attribute) {
    if (next_id == 0){
        return;
    }
    auto temp = blockchain.get(0)->at(0).*attribute;
    HashIndex<decltype(temp), int> index{};
    for (int i = 0; i < next_id; i++) {
        auto t = blockchain.get(i);
        for (int j = 0; j < block_size; j++) {
            index.insert(t->at(j).*attribute, i);
        }
    }
}

template<typename T>
template<typename TA>
void BlockChain<T>::createIndexHeap(TA attribute) {
    if (next_id == 0){
        return;
    }
    auto temp = blockchain.get(0)->at(0).*attribute;
    MaxHeapIndex<decltype(temp), int> index;
    for (int i = 0; i < next_id; i++) {
        auto t = blockchain.get(i);
        for (int j = 0; j < block_size; j++) {
            index.insert(t->at(j).*attribute, i);
        }
    }
}

#endif //PROYECTO_EQUIPO_4_BLOCKCHAIN_H
