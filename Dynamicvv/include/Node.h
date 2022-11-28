//
// Created by User on 30/9/2022.
//

#ifndef PROYECTO_EQUIPO_4_NODE_H
#define PROYECTO_EQUIPO_4_NODE_H


template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(){
        next = nullptr;
        prev = nullptr;
    }

    Node(T value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }

    void killSelf(){
        // TODO
    }
};

#endif //PROYECTO_EQUIPO_4_NODE_H
