#include <iostream>
#include "Block.h"
#include "BlockChain.h"
#include "sha256.h"

void test_block(){
    SHA256 sha256;
    sha256("0");
    std::string parent0 = sha256.getHash();
    std::string regis[] = {"juaquin", "remon", "flores"};
    Block<std::string> b(1, 3, regis, parent0);
    b.print();
}

bool f1(std::string r){
    if(r=="Nose") return true;
    else return false;
}

bool f2(std::string r){
    if(r=="hola") return true;
    else return false;
}

void test_blockchain(){
    BlockChain<std::string> bc(4);
    bc.insertRegister("Hola");
    bc.insertRegister("Mundo");
    bc.insertRegister("Nose");
    bc.insertRegister("NosE");
    int id_b=0,id_r=0;
    auto reg = bc.searchRegister(std::function<bool(std::string)>(&f1), id_b, id_r);
    std::cout<<id_b<<" "<<id_r<<" "<<reg<<std::endl;
    bc.updateRegister(id_b,id_r,"hola");
    cout<<bc.searchRegister(std::function<bool(std::string)>(&f2), id_b, id_r);
}

int main()
{
    test_block();
    test_blockchain();
    return 0;
}