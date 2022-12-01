//
// Created by juaquin on 30/11/22.
//

#ifndef PROYECTO_EQUIPO_4_TRIEPATRICIA_H
#define PROYECTO_EQUIPO_4_TRIEPATRICIA_H
#include "../ForwardList/ForwardList.h"
#include <iostream>
using namespace std;

#ifndef CONST_ALPHA
#define CONST_ALPHA
const unsigned ALPHA_SIZE = 26;//tamanio del alfabeto: letras minusculas
#endif
template <typename T>
class TriePatricia {
private:
    struct TrieNode{
        // opcion 1:   TrieNode **children;
        // opcion 2:   list<pair<char, TrieNode*>> children;
        // opcion 3:   map<pair<char, TrieNode*>> children;
        TrieNode **children;
        string preffix;
        bool endWord; //indica si es final de una palabra
        T* data = nullptr;
        TrieNode(){}

        TrieNode(string p){
            children = new TrieNode*[ALPHA_SIZE];
            for (int i=0; i<ALPHA_SIZE; i++) children[i] = nullptr;
            endWord = false;
            preffix = p;
        }

        void insert(const string& key, T* n_data){
            int i = 0;
            while (i<key.size() and i < preffix.size() and preffix[i] == key[i]) {
                i++;
            }
            if (i == key.size()) {
                if (i != preffix.size()){
                    string rest = preffix.substr(i, preffix.size()-i);
                    this->preffix = preffix.substr(0, i);

                    TrieNode* t = new TrieNode(rest);
                    swap(this->endWord, t->endWord);
                    this->endWord = true;
                    swap(this->data, t->data);
                    this->data = n_data;
                    swap(t->children, this->children);
                    this->children[rest[0]-'a'] = t;
                }
                this->endWord = true;
                for(auto _e: *n_data->values){
                    this->data->insert(_e);
                }
                return;
            }
            else if (i == preffix.size()) {
                TrieNode *& child = children[(int)key[i]-'a'];
                if (!child){
                    child = new TrieNode(key.substr(i, key.size()-i));
                    child->endWord = true;
                    child->data = n_data;
                    return;
                }
                else {
                    child->insert(key.substr(i, key.size()-i), n_data);
                }
            }
            else {
                string p_rest = preffix.substr(i, preffix.size()-i);
                string k_rest = key.substr(i, key.size()-i);
                this->preffix = preffix.substr(0, i);
                TrieNode* t_p = new TrieNode(p_rest);
                swap(t_p->children, this->children);
                swap(t_p->endWord, this->endWord);
                swap(t_p->data, this->data);
                TrieNode* t_k = new TrieNode(k_rest);
                t_k->endWord = true;
                t_k->data = n_data;
                this->children[p_rest[0]-'a'] = t_p;
                this->children[k_rest[0]-'a'] = t_k;
            }
        }

        bool search(const string& key) {
            int i = 0;
            while (i<key.size() and i < preffix.size() and preffix[i] == key[i]) {
                i++;
            }
            if (i == key.size()) {
                if (i != preffix.size()){
                    return false;
                }
                return this->endWord;
            }
            else if (i == preffix.size()) {
                TrieNode * child = children[(int)key[i]-'a'];
                return child && child->search(key.substr(i, key.size() - i));
            }
            else {
                return false;
            }
        }

        TrieNode* _search(string key){
            int i = 0;
            while (i<key.size() and i < preffix.size() and preffix[i] == key[i]) {
                i++;
            }
            if (i == key.size()) {
                if (i != preffix.size()){
                    return this;
                }
                return this;
            }
            else if (i == preffix.size()) {
                TrieNode * child = children[(int)key[i]-'a'];
                return (child!= nullptr)? child->_search(key.substr(i, key.size() - i)):nullptr;
            }
            else {
                return nullptr;
            }
        }

        ~TrieNode(){
            for (int i=0; i<ALPHA_SIZE; i++) {
                if (children[i]) delete children[i];
            }
            delete[] children;
        }
    };
    TrieNode* root;

    int count(TrieNode*& node){
        int c = 0;
        for(int i=0; i<ALPHA_SIZE; i++){
            if (node->children[i]) c++;
        }
        return c++;
    }

    bool remove(TrieNode*& node, const string& key) {
        int i = 0;
        while (i<key.size() and i < node->preffix.size() and node->preffix[i] == key[i]) {
            i++;
        }
        if (i == key.size()) {
            if (i == node->preffix.size()){
                int sz = count(node);
                if (sz>1) {
                    node->endWord = false;
                    return false;
                }
                else if (sz == 1) {
                    TrieNode* temp = node;
                    int i = 0;
                    for(i=0; i<ALPHA_SIZE; i++) {
                        if (node->children[i]) break;
                    }
                    node = node->children[i];
                    node->preffix = temp->preffix+node->preffix;
                    delete temp;
                    return true;
                }
                else {
                    delete node;
                    node = nullptr;
                    return true;
                }
            }
        }
        else if (i == node->preffix.size()) {
            TrieNode *& child = node->children[(int)key[i]-'a'];
            if (child) {
                bool r = remove(child, key.substr(i, key.size()-i));
                if (r){
                    int sz = count(node);
                    if (sz == 1) {
                        TrieNode* temp = node;
                        int i = 0;
                        for(i=0; i<ALPHA_SIZE; i++) {
                            if (node->children[i]) break;
                        }
                        if (!(node->children[i]->endWord and node->endWord)){
                            node = node->children[i];
                            node->preffix = temp->preffix+node->preffix;
                            delete temp;
                            return true;
                        }
                        return false;
                    }
                    else {
                        return false;
                    }
                }
                else return false;
            }
        }
        return false;
    }


    string toString(TrieNode*& node, string sep, string prefix){
        if (node == nullptr) return "";
        string result = "";
        if (node->endWord) {
            result += prefix+ node->preffix + sep;
        }
        for (int i=0; i<ALPHA_SIZE; i++){
            if(node->children[i]) {
                result += toString(node->children[i], sep, prefix+node->preffix);
            }
        }
        return result;
    }

    void _start_with(TrieNode* node, ForwardList<T>*& res){
        if (node == nullptr) return;

        if (node->endWord) {
            res->push_front(*node->data);
        }
        for (int i=0; i<ALPHA_SIZE; i++){
            if(node->children[i]) {
                _start_with(node->children[i], res);
            }
        }
    }
public:
    TriePatricia(): root(nullptr) {}

    void insert(const string& key, T* n_data){
        if (!root) root = new TrieNode("");
        root->insert(key, n_data);
    }
    bool search(const string& key){
        return root->search(key);
    }
    void remove(const string& key){
        remove(root, key);
    }

    ForwardList<T>* start_with(string key){
        TrieNode* n = root->_search(key);
        auto* res = new ForwardList<T>();
        _start_with(n, res);
        return res;
    }
    //imprime ordenado
    string toString(const string& sep){
        return toString(root, sep, "");
    }
};
#endif //PROYECTO_EQUIPO_4_TRIEPATRICIA_H
