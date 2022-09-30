//
// Created by juaquin on 30/09/22.
//

#ifndef PROYECTO_EQUIPO_4_BLOCK_H
#define PROYECTO_EQUIPO_4_BLOCK_H

#include <string>

template <typename T>
class Block {
private:
    int id;
    int nonce;
    int size;
    T* registers;
    std::string created_time;
    std::string parent_hash;
    std::string hash;
public:
    Block(int id, int size, T* registers, std::string& parent_hash);
private:
    std::string _get_time();
    std::string _hash_block();
    std::string _calculate_hash();
    bool _verify_hash(std::string hash_v);
};

#endif //PROYECTO_EQUIPO_4_BLOCK_H
