//
// Created by User on 30/9/2022.
//

#ifndef PROYECTO_EQUIPO_4_LIST_H
#define PROYECTO_EQUIPO_4_LIST_H

#include "Node.h"
#include <string>

template <typename T>
class List {
public:
    virtual T front() = 0;
    virtual T back() = 0;
    virtual void push_front(T) = 0;
    virtual void push_back(T) = 0;
    virtual T pop_front() = 0;
    virtual T pop_back() = 0;
    virtual T insert(T, int) = 0;
    virtual bool remove(int) = 0;
    virtual T& operator[](int) = 0;//debe ser declarado en cada clase hija
    virtual bool is_empty() = 0;
    virtual int size() = 0;
    virtual void clear() = 0;
};


#endif //PROYECTO_EQUIPO_4_LIST_H
