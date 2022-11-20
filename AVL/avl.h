//
// Created by juaquin on 18/11/22.
//

#ifndef PROYECTO_EQUIPO_4_AVL_H
#define PROYECTO_EQUIPO_4_AVL_H

#include <string>
#include <iostream>
#include "node.h"

template <typename T>
class AVLTree
{
private:
    NodeBT<T> *root;

public:
    AVLTree() : root(nullptr) {}
    void insert(T value)
    {
        insert(this->root, value);
    }
    T* find(T value)
    {
        return find(this->root, value);
    }

    std::string getPreOrder(){
        return getPreOrder(this->root);
    }

    int height()
    {
        return height(this->root);
    }
    NodeBT<T>* minValue()
    {
        return minValue(this->root);
    }
    T maxValue()
    {
        return maxValue(this->root);
    }
    bool isBalanced()
    {
        return isBalanced(this->root);
    }
    int size()
    {
        return size(this->root);
    }
    void remove(T value)
    {
        remove(this->root, value);
    }
    void displayPretty()
    {
        displayPretty(this->root, 1);
    }

    ~AVLTree(){
        if(this->root != nullptr){
            this->root->killSelf();
        }
    }

private:

    std::string getPreOrder(NodeBT<T> *node){
        if (node == nullptr)
            return "";
        std::string res = "";
        res += std::to_string(node->data) + " ";
        res += getPreOrder(node->left);
        res += getPreOrder(node->right);
        return res;
    }
    void insert(NodeBT<T> *&node, T value){
        if(node == nullptr){
            node = new NodeBT<T>(value);
        }else if(value < node->data){
            insert(node->left, value);
        }else if(value > node->data){
            insert(node->right, value);
        }else {
            node->data.insert(value);
        };
        updateHeight(node);
        balance(node);
    }


    T* find(NodeBT<T> *node, T value){
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->data == value)
        {
            return &node->data;
        }
        if (value > node->data){
            return find(node->right, value);
        }
        return find(node->left, value);
    }
    int height(NodeBT<T> *node){
        if(node == nullptr) return -1;
        return node->height;
    }
    bool isBalanced(NodeBT<T> *node) {
        if(node == nullptr){
            return true;
        }
        int balance = balancingFactor(node);
        if(balance > 1 || balance < -1){
            return false;
        }
        return isBalanced(node->left) && isBalanced(node->right);
    }
    T minValue(NodeBT<T> *node){
        if (node == nullptr)
            throw("Tree is empty");
        else if (node->left == nullptr)
            return node->data;
        else
            return minValue(node->left);
    }
    T maxValue(NodeBT<T> *node){
        if (node == nullptr)
            throw("Arbol vacio");
        else if (node->right == nullptr)
            return node->data;
        else
            return maxValue(node->right);
    };
    int size(NodeBT<T> *node){
        if (node == nullptr)
            throw("Arbol vacio");
        else if (node->right == nullptr)
            return node->data;
        else
            return maxValue(node->right);
    }
    void remove(NodeBT<T> *&node, T value){
        if (node == nullptr)
            return;
        else if (value < node->data)
            remove(node->left, value);
        else if (value > node->data)
            remove(node->right, value);
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            }else if(node->left == nullptr) {
                NodeBT<T> *temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                NodeBT<T> *temp = node;
                node = node->left;
                delete temp;
            }else{
                T temp = maxValue(node->left);
                node->data = temp;
                remove(node->left, temp);
            }
        }
        updateHeight(node);
        balance(node);
    }
    void displayPretty(NodeBT<T> *node, int level){
        if (!node) return;
        displayPretty(node->left, level+1);
        if (node->left) {
            for (int i=0; i<level-1; i++){
                std::cout << "    ";
            }
            std::cout << "  /"<<std::endl;
        }
        for (int i=0; i<level-1; i++){
            std::cout << "    ";
        }
        std::cout << node->data << std::endl;
        if (node->right) {
            for (int i=0; i<level-1; i++){
                std::cout << "    ";
            }
            std::cout << "  \\"<<std::endl;
        }
        displayPretty(node->right, level+1);
    }

    /*add for avl*/
    int balancingFactor(NodeBT<T> *node){
        if(node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }
    void updateHeight(NodeBT<T> *node){
        if(node == nullptr) return;
        node->height = std::max(height(node->left), height(node->right)) + 1;
    }
    void balance(NodeBT<T> *&node){
        int balance_factor = balancingFactor(node);
        if (balance_factor >= 2) {
            if (balancingFactor(node->left) <= -1) {
                left_rota(node->left);
            }
            right_rota(node);
        }
        if (balance_factor <= -2) {
            if (balancingFactor(node->right) >= 1) {
                right_rota(node->right);
            }
            left_rota(node);
        }
    }
    void left_rota(NodeBT<T> *&node){
        NodeBT<T> *z = node->right;
        node->right = z->left;
        z->left = node;
        updateHeight(node);
        updateHeight(z);
        node = z;
    }
    void right_rota(NodeBT<T> *&node){
        NodeBT<T> *z = node->left;
        node->left = z->right;
        z->right = node;
        updateHeight(node);
        updateHeight(z);
        node = z;
    }
};


#endif //PROYECTO_EQUIPO_4_AVL_H
