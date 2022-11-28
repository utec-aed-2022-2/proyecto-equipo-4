//
// Created by juaquin on 31/10/22.
//

#ifndef PROYECTO_EQUIPO_4_CIRCULARARRAY_H
#define PROYECTO_EQUIPO_4_CIRCULARARRAY_H

#include <string>

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
public:
    CircularArray();
    explicit CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    std::string to_string(const std::string& sep=" ");
    void resize();

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
std::string CircularArray<T>::to_string(const std::string& sep)
{
    std::string result;
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;
}
/////////////////////////////////////////////////////////////

template <class T>
void CircularArray<T>::resize(){
    int* array1 = new int[capacity*2];
    for(int i = 0; i < capacity; i++) {
        array1[i] = array[(i+front)%capacity];
    }
    this->array = array1;
    front = 0;
    back = capacity - 1;
    capacity *= 2;
}

template <class T>
void CircularArray<T>::push_front(T data)
{
    int s = prev(front);
    if (front == -1 || back == -1){
        front = back = 0;
        s = front;
    }else if (prev(front) == back) {
        resize();
        s = prev(front);
    }
    array[s] = data;
    front = s;
}

template <class T>
void CircularArray<T>::push_back(T data)
{
    int s = next(back);
    if (front == -1 || back == -1){
        front = back = 0;
        s = back;
    }
    else if (next(back) == front) {
        resize();
        s = next(back);
    }
    array[s] = data;
    back = s;
}

template <class T>
void CircularArray<T>::insert(T data, int pos){
    if (next(back) == front){
        resize();
    }
    push_front(data);
    for(int i=0; i<pos; i++){
        swap(array[(front+i)%capacity], array[next(front+i)]);
    }
}

template <class T>
T CircularArray<T>::pop_front(){
    if (is_empty()){
        throw "El arreglo no contiene elementos";
    }

    T t = array[front];

    if (size() == 1) front = back = -1;
    else front = next(front);

    return t;
}

template <class T>
T CircularArray<T>::pop_back(){
    if (is_empty()){
        throw "El arreglo no contiene elementos";
    }

    T t = array[back];

    if (size() == 1) front = back = -1;
    else  back = prev(back);

    return t;
}

template <class T>
int CircularArray<T>::size()
{
    if (is_empty()) return 0;
    else if (front <= back) return back - front + 1;
    else return capacity-front+back+1;
}

template <class T>
bool CircularArray<T>::is_full()
{
    return prev(front) == back;
}

template <class T>
bool CircularArray<T>::is_empty()
{
    return front == -1 || back == -1;
}

template<class T>
bool CircularArray<T>::is_sorted() {
    if (front == back){
        return true;
    }
    bool descending = true;
    bool ascending = true;

    int it = front;
    int j = 0;
    for (auto i = 0; i < size()-1; i++){
        //cout<<array[next(it)]<<" "<<array[it]<<endl;

        if(array[next(it)] < array[it]){
            ascending = false;
        }
        if (array[next(it)] > array[it]){
            descending = false;
        }
        it = next(it);
    }
    return (ascending || descending);

}

template <class T>
T &CircularArray<T>::operator[](int index)
{

    if (index >= size() || index < 0) {
        throw "Fuera de los limites";
    }
    return array[(front+index)%capacity];
}

template<class T>
void CircularArray<T>::reverse() {
    for (int i=0; i<capacity/2; i++){
        swap((*this)[i], (*this)[size()-1-i]);
    }
}

template<class T>
void CircularArray<T>::sort(){
    int i, digitPlace = 1;
    int n = size();
    int result[n];
    auto getmax = [&](){
        int i;
        int max = (*this)[front];
        for (i = 0; i < size() ; i++){
            if ((*this)[i] > max)
                max = (*this)[i];
        }
        return max;
    };
    int largestNum = getmax();

    while(largestNum/digitPlace >0){
        int count[10] = {0};

        for (i = 0; i < n; i++)
            count[ ((*this)[i]/digitPlace)%10 ]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--)
        {
            result[count[ ((*this)[i]/digitPlace)%10 ] - 1] = (*this)[i];
            count[ ((*this)[i]/digitPlace)%10 ]--;
        }

        for (i = 0; i < n; i++)
            (*this)[i] = result[i];

        digitPlace *= 10;
    }
}

template<typename T>
void CircularArray<T>::clear() {
    back = front = -1;
}
#endif //PROYECTO_EQUIPO_4_CIRCULARARRAY_H
