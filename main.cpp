#include <iostream>
#include "Block.h"
#include "BlockChain.h"
#include "sha256.h"
#include "Register.h"

void test_register(){
    BlockChain<Register, decltype(&Register::emisor), &Register::emisor,string, decltype(&Register::receptor),&Register::receptor, string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string> bc(4,"../MOCK_DATA_DEMO.csv");
    bc.print();
    bc.createIndex(&Register::emisor, 1);
    bc.createIndexHeap(&Register::emisor, 1);
    bc.createIndexMinHeap(&Register::emisor, 1);
    bc.createIndexMinHeap(&Register::receptor, 2);
    bc.createIndexHeap(&Register::monto, 3);
    bc.createIndexAVL(&Register::monto, 3);
    bc.createIndexB(&Register::monto, 3);
    bc.createIndexTrie(&Register::receptor, 2);
    auto r = bc.getMax(&Register::monto, 3);
    auto r2 = bc.getMax(&Register::emisor, 1);
    auto r3 = bc.getMin(&Register::receptor, 2);
    auto r4 = bc.getValue(&Register::emisor, "Aerified",1);
    auto r5 = bc.getInRange(&Register::fecha, "0000000000", "13",4);
    auto r6 = bc.start_with(&Register::receptor, "Puc", 2);
    for (auto it: *r3) {
        cout << it.regis->receptor << endl;
    }
    for(auto it: *r){
        cout << it.regis->monto << endl;
    }
    for(auto it: *r2){
        cout << it.regis->emisor << endl;
    }
    for(auto it: *r4){
        cout << it.regis->emisor << endl;
    }
    for(auto it: *r5){
        cout << it.regis->fecha << endl;
    }
    for(auto it: *r6){
        cout << it.regis->emisor << endl;
    }
}

int main()
{
    //test_block();
    //test_blockchain();
    test_register();
    return 0;
}