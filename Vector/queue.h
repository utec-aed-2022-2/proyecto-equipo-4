//
// Created by juaquin on 19/11/22.
//

#ifndef PROYECTO_EQUIPO_4_QUEUE_H
#define PROYECTO_EQUIPO_4_QUEUE_H

#include "CircularArray.h"

template <typename T>
class QueueArray : public CircularArray<T> {
public:
    QueueArray() : CircularArray<T>() {}
    QueueArray(int _capacity) : CircularArray<T>(_capacity) {}
    void enqueue(T value) {
        CircularArray<T>::push_back(value);
    }
    T dequeue() {
        return CircularArray<T>::pop_front();
    }
};

#endif //PROYECTO_EQUIPO_4_QUEUE_H
