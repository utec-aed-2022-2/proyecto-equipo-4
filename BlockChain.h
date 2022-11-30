//
// Created by User on 30/9/2022.
//

#ifndef PROYECTO_EQUIPO_4_BLOCKCHAIN_H
#define PROYECTO_EQUIPO_4_BLOCKCHAIN_H

#include <functional>
#include <fstream>
#include <any>
#include "ChainHash.h"
#include "Block.h"
#include "Index.h"

template<typename T>
struct ResultIndex {
    T* regis;
    int block_pos;
    int block;
    ResultIndex() = default;
    ResultIndex(T* r, const int& block_pos, const int& block): regis(r), block_pos(block_pos), block(block) {}
};

template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
class BlockChain {
private:
    CircularArray<Index<string, int>*> indice1{1};
    CircularArray<Index<string, int>*> indice2{1};
    CircularArray<Index<float , int>*> indice3{1};
    CircularArray<Index<string, int>*> indice4{1};
    T *b_block;
    int c;
    ChainHash<int, Block<T> *> blockchain;
    int block_size;
    int next_id;
    std::string genesis;
    std::string bc_path;

public:

    BlockChain(int block_size, const std::string &n_path = "../data.csv") {
        bc_path = n_path;
        this->block_size = block_size;
        b_block = new T[block_size];
        c = 0;
        next_id = 0;
        loadFromCSV(bc_path);
    }

    template <typename TA>
    void createIndex(TA attribute, int i_atr);

    template <typename TA>
    void createIndexHeap(TA attribute, int i_atr);

    template <typename TA>
    void createIndexMinHeap(TA attribute, int i_atr);

    template <typename TA>
    void createIndexAVL(TA attribute, int i_atr);

    template <typename TA>
    void createIndexB(TA attribute, int i_atr);

    template< typename TF>
    ForwardList<ResultIndex<T>>* searchRegister(TF& f);

    void updateRegister(int id_block, int pos_register, T new_register);

    void insertRegister(T data);

    int getLastId();

    void loadFromCSV(const std::string &path);

    void print();

    template<typename TA>
    ForwardList<ResultIndex<T>>* getMax(TA atribute, int i_atr);

    template<typename TA>
    ForwardList<ResultIndex<T>>* getMin(TA atribute, int i_atr);

    template<typename TA, typename TV>
    ForwardList<ResultIndex<T>>* getValue(TA atribute, TV value, int i_atr);

    template<typename TA, typename TV>
    ForwardList<ResultIndex<T>>* getInRange(TA atribute, TV start, TV end, int i_atr);

    ~BlockChain();

private:
    template<class I, class TA>
    void _create_index(TA data, int i_atr);

    void _rehash_block(const int &id);
};

template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
void BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::_rehash_block(const int &id) {
    auto block = blockchain.get(id);
    if (block.get_id() != id) return;
    block.recalculate_hash();
    _rehash_block(id + 1);
}


template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
template<typename TF>
ForwardList<ResultIndex<T>>* BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::searchRegister(TF& f) {
    auto* res = new ForwardList<ResultIndex<T>>();
    for (int i = 0; i < next_id; ++i) {
        Block<T> *block = blockchain.get(i);
        for (int j = 0; j < block_size; ++j) {
            T& tmp_register = block->at(j);
            if (f(tmp_register)) {
                res->push_front(ResultIndex(&tmp_register, j, i));
            }
        }
    }
    return res;
}

template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
void BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::updateRegister(int id_block, int pos_register, T new_register) {
    Block<T> *block = blockchain.get(id_block);
    block->at(pos_register) = new_register;
    block->recalculate_hash();
    while (++id_block < next_id) {
        blockchain.get(id_block)->recalculate_hash();
    }
}

template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
void BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::insertRegister(T data) {
    b_block[c] = data;
    c++;
    if (c == block_size) {
        T *temp = new T[block_size];
        std::copy_n(b_block, block_size, temp);
        for(int i=0; i<block_size; i++){
            for(int j=0; j<indice1.size(); i++){
                indice1[i]->insert(temp[i].*a1, next_id);
            }
            for(int j=0; j<indice1.size(); i++){
                indice2[i]->insert(temp[i].*a2, next_id);
            }
            for(int j=0; j<indice1.size(); i++){
                indice3[i]->insert(temp[i].*a3, next_id);
            }
            for(int j=0; j<indice1.size(); i++){
                indice4[i]->insert(temp[i].*a4, next_id);
            }
        }
        if (next_id != 0) {
            auto &x = (blockchain.get(next_id - 1))->get_hash();
            auto *n_block = new Block<T>(next_id, block_size, temp, x);
            blockchain.insert(next_id, n_block);
        } else {
            auto *n_block = new Block<T>(next_id, block_size, temp, this->genesis);
            blockchain.insert(next_id, n_block);
        }
        next_id++;
        c = 0;
    }
}


template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
int BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::getLastId() {
    return next_id;
}


template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
void BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::loadFromCSV(const std::string &path) {
    std::fstream f(path, std::ios::in);
    std::string line;
    if (f.is_open()) {
        getline(f, line);
        while (getline(f, line)) {
            T regist(line);
            this->insertRegister(regist);
        }
        f.close();
    } else throw "Could not open the file";
}


template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::~BlockChain() {
    std::fstream f(this->bc_path, std::ios::out);
    if (f.is_open()) {
        f << std::endl;
        for (int i = 0; i < next_id; i++) {
            auto t = blockchain.get(i);
            for (int j = 0; j < block_size; j++) {
                f << std::string(t->at(j)) << std::endl;
            }
        }
    } else throw "Could not open the file";
}


template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
void BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::print() {
    int n = 0;
    while (n < next_id) {
        this->blockchain.get(n)->print();
        std::cout << std::endl;
        n++;
    }
}

template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
template<typename TA>
void BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::createIndex(TA attribute, int atr) {
    if (next_id == 0) {
        return;
    }
    auto temp = blockchain.get(0)->at(0).*attribute;
    _create_index<HashIndex<decltype(temp), int>>(attribute, atr);
}


template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
template<typename TA>
void BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::createIndexHeap(TA attribute, int i_atr) {
    if (next_id == 0) {
        return;
    }
    auto temp = blockchain.get(0)->at(0).*attribute;
    _create_index<MaxHeapIndex<decltype(temp), int>>(attribute, i_atr);
}

template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
template<typename TA>
void BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::createIndexMinHeap(TA attribute, int i_atr) {
    if (next_id == 0) {
        return;
    }
    auto temp = blockchain.get(0)->at(0).*attribute;
    _create_index<MinHeapIndex<decltype(temp), int>>(attribute, i_atr);
}


template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
template<typename TA>
void BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::createIndexAVL(TA attribute, int i_atr) {
    if (next_id == 0) {
        return;
    }
    auto temp = blockchain.get(0)->at(0).*attribute;
    _create_index<AVLIndex<decltype(temp), int>>(attribute, i_atr);
}


template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
template<typename TA>
void BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::createIndexB(TA attribute, int i_atr) {
    if (next_id == 0) {
        return;
    }
    auto temp = blockchain.get(0)->at(0).*attribute;
    _create_index<BTreeIndex<decltype(temp), int>>(attribute, i_atr);
}

template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
template<class I, class TA>
void BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::_create_index(TA data, int i_atr) {
    auto* index = new I();
    if constexpr (std::is_same<TA,A1>::value) {
        switch (i_atr) {
            case 1:
                indice1.push_back(index);
                break;
            case 2:
                indice2.push_back(index);
                break;
            case 4:
                indice4.push_back(index);
                break;
        }
    }
    else {
        indice3.push_back(index);
    }
    for (int i = 0; i < next_id; i++) {
        auto t = blockchain.get(i);
        for (int j = 0; j < block_size; j++) {
            index->insert(t->at(j).*data, i);
        }
    }
}

template<typename T, typename A1, A1 a1,  typename V1, typename A2, A2 a2, typename V2,  typename A3, A3 a3, typename V3,  typename A4, A4 a4, typename V4>
template<typename TA>
ForwardList<ResultIndex<T>>* BlockChain<T, A1, a1 ,V1, A2, a2,V2, A3, a3,V3, A4, a4,V4>::getMax(TA atribute, int i_atr) {
    auto temp = blockchain.get(0)->at(0).*atribute;
    auto fun = [atribute, this, &temp](auto &indi){
        for(int i=0; i<indi.size(); i++){
            auto* index = indi[i];
            if (index->type() == "max") {
                auto* res = new ForwardList<ResultIndex<T>>();
                auto indices = index->get();
                cout << "Usando indice MaxHeap" << endl;
                for(auto ind: *indices.values){
                    Block<T>*& bl = this->blockchain.get(ind);
                    for(int pos_block = 0; pos_block < this->block_size; pos_block++) {
                        T& reg = bl->at(pos_block);
                        if (reg.*atribute == indices.key) {
                            res->push_front(ResultIndex(&reg, pos_block, ind));
                        }
                    }
                }
                return res;
            }
        }
        for (int i = 0; i < next_id; i++) {
            auto t = blockchain.get(i);
            for (int j = 0; j < block_size; j++) {
                if(t->at(j).*atribute>temp) temp = t->at(j).*atribute;
            }
        }
        auto filt = [&atribute, temp](const T& regist){return regist.*atribute == temp;};
        return searchRegister(filt);
    };
    if constexpr (std::is_same<TA,A1>::value) {
        if (i_atr == 1) {
            return fun(indice1);
        } else if (i_atr == 2) {
            return fun(indice2);
        } else if (i_atr == 4) {
            return fun(indice4);
        }
    }
    else {
        return fun(indice3);
    }
}

template<typename T, typename A1, A1 a1, typename V1, typename A2, A2 a2, typename V2, typename A3, A3 a3, typename V3, typename A4, A4 a4, typename V4>
template<typename TA>
ForwardList<ResultIndex<T>>* BlockChain<T, A1, a1, V1, A2, a2, V2, A3, a3, V3, A4, a4, V4>::getMin(TA atribute, int i_atr) {
    auto temp = blockchain.get(0)->at(0).*atribute;
    auto fun = [atribute, this, &temp](auto &indi){
        for(int i=0; i<indi.size(); i++){
            auto* index = indi[i];
            if (index->type() == "min") {
                auto* res = new ForwardList<ResultIndex<T>>();
                auto indices = index->get();
                cout << "Usando indice MinHeap" << endl;
                for(auto ind: *indices.values){
                    Block<T>*& bl = this->blockchain.get(ind);
                    for(int pos_block = 0; pos_block < this->block_size; pos_block++) {
                        T& reg = bl->at(pos_block);
                        if (reg.*atribute == indices.key) {
                            res->push_front(ResultIndex(&reg, pos_block, ind));
                        }
                    }
                }
                return res;
            }
        }
        for (int i = 0; i < next_id; i++) {
            auto t = blockchain.get(i);
            for (int j = 0; j < block_size; j++) {
                if(t->at(j).*atribute<temp) temp = t->at(j).*atribute;
            }
        }
        auto filt = [&atribute, temp](const T& regist){return regist.*atribute == temp;};
        return searchRegister(filt);
    };
    if constexpr (std::is_same<TA,A1>::value) {
        if (i_atr == 1) {
            return fun(indice1);
        } else if (i_atr == 2) {
            return fun(indice2);
        } else if (i_atr == 4) {
            return fun(indice4);
        }
    }
    else {
        return fun(indice3);
    }
}

template<typename T, typename A1, A1 a1, typename V1, typename A2, A2 a2, typename V2, typename A3, A3 a3, typename V3, typename A4, A4 a4, typename V4>
template<typename TA, typename TV>
ForwardList<ResultIndex<T>> *
BlockChain<T, A1, a1, V1, A2, a2, V2, A3, a3, V3, A4, a4, V4>::getValue(TA atribute, TV value, int i_atr) {
    auto temp = blockchain.get(0)->at(0).*atribute;
    auto fun = [atribute, this, &temp, value](auto &indi){
        for(int i=0; i<indi.size(); i++){
            auto* index = indi[i];
            if (index->type() == "hash") {
                auto* res = new ForwardList<ResultIndex<T>>();
                auto indices = index->get(value);
                cout << "Usando indice hash" << endl;
                for(auto ind: *indices.values){
                    Block<T>*& bl = this->blockchain.get(ind);
                    for(int pos_block = 0; pos_block < this->block_size; pos_block++) {
                        T& reg = bl->at(pos_block);
                        if (reg.*atribute == indices.key) {
                            res->push_front(ResultIndex(&reg, pos_block, ind));
                        }
                    }
                }
                return res;
            }
        }
        auto filt = [&atribute, value](const T& regist){return regist.*atribute == value;};
        return searchRegister(filt);
    };
    if constexpr (std::is_same<TA,A1>::value) {
        if (i_atr == 1) {
            return fun(indice1);
        } else if (i_atr == 2) {
            return fun(indice2);
        } else if (i_atr == 4) {
            return fun(indice4);
        }
    }
    else {
        return fun(indice3);
    }
}

template<typename T, typename A1, A1 a1, typename V1, typename A2, A2 a2, typename V2, typename A3, A3 a3, typename V3, typename A4, A4 a4, typename V4>
template<typename TA, typename TV>
ForwardList<ResultIndex<T>> *
BlockChain<T, A1, a1, V1, A2, a2, V2, A3, a3, V3, A4, a4, V4>::getInRange(TA atribute, TV start, TV end, int i_atr) {
    auto temp = blockchain.get(0)->at(0).*atribute;
    auto fun = [atribute, this, &temp, start, end](auto &indi){
        for(int i=0; i<indi.size(); i++){
            auto* index = indi[i];
            if (index->type() == "btree") {
                auto* res = new ForwardList<ResultIndex<T>>();
                auto indices = index->get(start, end);
                cout << indices->size() << endl;
                cout << "Usando indice Btree" << endl;
                for(auto ind: *indices){
                    for(auto in: *ind.values) {
                        Block<T> *&bl = this->blockchain.get(in);
                        cout << "ok" << endl;
                        for (int pos_block = 0; pos_block < this->block_size; pos_block++) {
                            T &reg = bl->at(pos_block);
                            if (reg.*atribute == ind.key) {
                                res->push_front(ResultIndex(&reg, pos_block, in));
                            }
                        }
                    }
                }
                return res;
            }
        }
        auto filt = [&atribute, start, end](const T& regist){return start <= (regist.*atribute) and (regist.*atribute) <= end;};
        return searchRegister(filt);
    };
    if constexpr (std::is_same<TA,A1>::value) {
        if (i_atr == 1) {
            return fun(indice1);
        } else if (i_atr == 2) {
            return fun(indice2);
        } else if (i_atr == 4) {
            return fun(indice4);
        }
    }
    else {
        return fun(indice3);
    }
}

#endif //PROYECTO_EQUIPO_4_BLOCKCHAIN_H
