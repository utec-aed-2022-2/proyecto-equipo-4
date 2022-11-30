#include "../Vector/CircularArray.h"

#include <iostream>

template<typename T, typename CMP = std::greater<T>>
class Heap
{
public:
    CircularArray<T> elements{5};
    CMP cmp;
public:
    Heap(){
    }
    Heap(int _cap){
        elements = CircularArray<T>(_cap);
    }
    void push(const T& data){//O(log n)
        elements.push_back(data);
        heapify_up(elements.size()-1);
    }

    void pop(){//O(log n)
        //verificar que el heap tenga elementos
        if (elements.size() == 0) return ;
        elements[0] = elements[elements.size() - 1];
        elements.pop_back();
        if (elements.size() != 0)
        heapify_down(0);
    }

    void display(){
        for(auto& a : elements){
            std::cout<<a<<",";//16,14,10,8,7,9,3,2,4,1,
        }
        std::cout<<std::endl;
    }

protected:
        void heapify_down(int index){
            int max_i;
            if (left(index) >= (int)elements.size()) return;
            else if (right(index) >= (int)elements.size()) max_i = left(index);
            else max_i = cmp(elements.at(left(index)),elements.at(right(index)))?left(index):right(index);
            if (cmp(elements.at(max_i),elements.at(index))){
                T value_temp = elements.at(index);
                elements.at(index) = elements.at(max_i);
                elements.at(max_i) = value_temp;
                heapify_down( max_i);
            }
        }

        void heapify_up(int index){
            if (index == 0) return;
            if (cmp(elements[index],elements[parent(index)])){
                T value_temp = elements[index];
                elements[index] = elements[parent(index)];
                elements[parent(index)] = value_temp;
                heapify_up(parent(index));
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
};
template<typename T, typename TV>
struct Entry {
    T key;
    ForwardList<TV>* values;
    Entry(){
        values = new ForwardList<TV>();
    }
    Entry(T key){
        this->key = key;
        values = new ForwardList<TV>();
    }

    void insert(TV value){
        values->push_front(value);
    }
    bool operator>(const Entry& another) const{
        return key > another.key;
    }
    bool operator<(const Entry& another) const{
        return key < another.key;
    }
    bool operator==(const Entry& another) const {
        return key == another.key;
    }
    bool operator!=(const Entry& another) const {
        return key != another.key;
    }
    //TODO: arreglar error cuando se añade el destructor
};

template<typename T, typename TV, typename CMP = std::greater<Entry<T, TV>>>
class multiHeap : public Heap<Entry<T, TV>, CMP>{
public:
    multiHeap() = default;
    void push(T key, TV value) {
        for(int i=0; i<this->elements.size(); i++){
            if (this->elements[i].key == key) {
                this->elements[i].values->push_front(value);
                return;
            }
        }
        Entry<T, TV> n_entry(key);
        n_entry.insert(value);
        Heap<Entry<T, TV>, CMP>::push(n_entry);
        //std::cout<<this->elements[0].key<<std::endl;
    }


};