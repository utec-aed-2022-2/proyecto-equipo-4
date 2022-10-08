//
// Created by User on 30/9/2022.
//

#ifndef PROYECTO_EQUIPO_4_FORWARDLIST_H
#define PROYECTO_EQUIPO_4_FORWARDLIST_H

#include <iostream>
#include "Node.h"
#include "List.h"

template <typename T>
class ForwardList : public List<T> {
private:
    Node<T>* head = nullptr;
    int nodes;
    struct iterator{
        Node<T> *current;
        iterator(Node<T>*current):current(current){};
        iterator& operator++(){
            if(current!= nullptr)
                current = current -> next;
            return *this;
        }

        iterator& operator++(int){
            if(current!= nullptr)
                current = current -> next;
            return *this;
        }

        bool operator!=(const iterator& other){
            return this->current!=other.current;
        }

        T* operator->(){
            return &current->data;
        }
    };
public:
    ForwardList() : head(nullptr), nodes(0){}

    ~ForwardList(){
        clear();
    }

    iterator begin(){
        return iterator(head);
    }

    iterator end(){
        return iterator(nullptr);
    }
    T front(){
        if (head != nullptr){
            return head->data;
        }else{
            throw ("No hay elementos en la lista");
        }
    }

    T back(){
        if (head != nullptr){
            auto temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            return temp->data;
        }else{
            throw ("No hay elementos en la lista");

        }
    }

    void push_front(T data){
        Node<T>* nodo = new Node<T>(data);
        nodo->next = head;
        head = nodo;
        nodes++;
    }

    void push_back(T data){
        Node<T>* nodo = new Node<T>;
        nodo->data = data;
        if (is_empty()){
            head = nodo;
        }else{
            Node<T>* temp = head;
            while (temp->next !=nullptr){
                temp = temp->next;
            }
            temp->next = nodo;
            nodo->next = nullptr;
        }
        nodes++;
    }

    T pop_front(){
        if (is_empty()){
            throw ("No hay elementos en la lista");
        }
        T value = front();
        if (nodes == 1){
            delete head;
            head = nullptr;
        }else{
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        nodes--;
        return value;
    }

    T pop_back(){
        if(nodes == 0){
            throw ("No hay elementos");
        }
        T value = back();
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            nodes--;
            return value;
        }else{
            Node<T>* temp = head;
            while((temp->next)->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            return value;
        }

    }

    T insert(T data, int pos){
        if (pos < 0 or pos > nodes) throw ("Posicion fuera de rango");
        if (pos == 0) {
            push_front(data);
            return data;
        }
        else if (pos == nodes){
            push_back(data);
            return data;
        }
        Node<T>* nodo = new Node<T>;
        nodo->data = data;
        Node<T>* temp = head;
        int i = 0;
        while(i++ < pos - 1) temp = temp->next;
        nodo->next = temp->next;
        temp->next = nodo;
        nodes++;
        return data;
    }

    bool remove(int pos){
        if (pos < 0 || pos >= nodes) throw ("Posicion fuera de rango");
        if (pos == 0) {
            pop_front();
            return true;
        }
        else if (pos == nodes-1) {
            pop_back();
            return true;
        }
        Node<T>* temp = head;
        for (int i=0; i<pos-1; i++) temp = temp->next;
        temp->next = (temp->next)->next;
        delete temp;
        nodes--;
        return true;
    }

    T& operator[](int pos){
        if (0 <= pos >= nodes) {
            throw ("Posicion fuera de rango");
        }
        Node<T>* t = head;
        for(int i=0; i<pos; i++) t = t->next;
        return t->data;

    }

    bool is_empty(){
        return nodes == 0;
    }

    int size(){
        return nodes;
    }

    void clear(){
        while(head != nullptr){
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        nodes = 0;
    }
};


#endif //PROYECTO_EQUIPO_4_FORWARDLIST_H
