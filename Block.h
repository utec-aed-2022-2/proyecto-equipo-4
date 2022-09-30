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
    Block(int id, int size, std::string& parent_hash);
private:
    std::string _get_time();
    void _hash_block();
    void _calculate_hash();
};

#endif //PROYECTO_EQUIPO_4_BLOCK_H
