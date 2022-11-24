#include <iostream>
#include "Block.h"
#include "BlockChain.h"
#include "sha256.h"
#include "Register.h"
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


void test_register(){
    BlockChain<Register> bc(4,"../MOCK_DATA_DEMO.csv");
    bc.print();
    bc.createIndex(&Register::emisor);
    bc.createIndexHeap(&Register::monto);
    bc.createIndexMinHeap(&Register::monto);
    bc.createIndexAVL(&Register::monto);
    bc.createIndexB(&Register::monto);
}

int main()
{
    test_block();
    //test_blockchain();
    test_register();
    return 0;
}