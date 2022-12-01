//
// Created by juaquin on 18/11/22.
//

#ifndef PROYECTO_EQUIPO_4_NODEAVL_H
#define PROYECTO_EQUIPO_4_NODEAVL_H

template <typename T>
struct NodeBT {
    T data;
    int height;
    NodeBT* left;
    NodeBT* right;
    NodeBT() : left(nullptr), right(nullptr), height(0) {}
    NodeBT(T value) : data(value), left(nullptr), right(nullptr), height(0) {}

    void killSelf(){
        if(left != nullptr) left->killSelf();
        if(right != nullptr) right->killSelf();
        delete this;
    }
};

#endif //PROYECTO_EQUIPO_4_NODE_H
