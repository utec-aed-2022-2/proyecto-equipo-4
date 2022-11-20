#ifndef NODEB_H
#define NODEB_H

using namespace std;

template <typename TK>
struct NodeB {
    //array de keys
    TK* keys;
    //array de punteros a hijos
    NodeB** children;
    //cantidad de keys
    int count;
    //indicador de nodo hoja
    bool leaf;

    NodeB(): keys(nullptr), children(nullptr), count(0), leaf(true) {}

    NodeB(int M, bool _leaf = true){
        count = 0;
        leaf = _leaf;
        keys = new TK[M-1];
        children = new NodeB<TK>*[M];
        for(int i=0;i<M;i++) children[i] = nullptr;
    }

    void display(){
        for (int i = 0; i < count; ++i)
            cout<<keys[i]<<", ";
        cout<<endl;
    }

    void killSelf(){
        delete[] keys;
        delete[] children;
    }
    ~NodeB(){
        delete[] keys;
        delete[] children;
    }
};

#endif