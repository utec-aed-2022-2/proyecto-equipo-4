#include "CircularArray.h"

#include <iostream>

template<typename T>
class Heap
{   
    private:
    CircularArray<T> elements;
public:
    Heap(){}
    Heap(int _cap){
        elements = CircularArray<T>(_cap);
    }
    void push(T data){//O(log n)
        elements.push_back(data);
        heapify_up(elements, elements.size()-1);
    }

    void pop(){//O(log n)
        //verificar que el heap tenga elementos
        if (elements.size() == 0) return ;
        elements[0] = elements[elements.size() - 1];
        elements.pop_back();
        if (elements.size() != 0)
        heapify_down(elements, 0);
    }

    void display(){
        for(auto& a : elements){
            std::cout<<a<<",";//16,14,10,8,7,9,3,2,4,1,
        }
        std::cout<<std::endl;
    }

    private:
        static void heapify_down(CircularArray<T> &elements, int index){
            int max_i;
            if (left(index) >= (int)elements.size()) return;
            else if (right(index) >= (int)elements.size()) max_i = left(index);
            else max_i = elements.at(left(index))>elements.at(right(index))?left(index):right(index);
            if (elements.at(index) < elements.at(max_i)){
                T value_temp = elements.at(index);
                elements.at(index) = elements.at(max_i);
                elements.at(max_i) = value_temp;
                heapify_down(elements, max_i);
            }
        }

        static void heapify_up(CircularArray<T> &elements, int index){
            if (index == 0) return;
            if (elements.at(parent(index)) < elements.at(index)){
                T value_temp = elements.at(index);
                elements.at(index) = elements.at(parent(index));
                elements.at(parent(index)) = value_temp;
                heapify_up(elements, parent(index));
            }
        }

        static int left(int index){
            return index*2+1;
        }

        static int right(int index){
            return index*2+2;
        }

        static int parent(int index){
            return (index-1)/2;
        }

    public:
        static void build_from(CircularArray<T>& elements){
            for(int i=elements.size()/2; i>=0; i--){//O(n/2)
                heapify_down(elements, i);//O(log n)
            }
        }
};