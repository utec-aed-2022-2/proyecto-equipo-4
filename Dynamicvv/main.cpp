#include "copypaste.h"
#include "BlockChain.h"
#include <iostream>
#include <QApplication>
#include <inicio.h>
//#include "../../../UTEC/UTEC 2022 -2/ESTRUCTURAS/proyectoblockchain/proyecto-equipo-4/BlockChain.h"

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
    bc.insertRegister("Hola1");
    bc.insertRegister("Mundo1");
    bc.insertRegister("Nose1");
    bc.insertRegister("NosE1");
    int id_b=0,id_r=0;
    auto reg = bc.searchRegister(std::function<bool(std::string)>(&f1), id_b, id_r);
    bc.print();
    bc.updateRegister(id_b,id_r,"hola");
    bc.print();
    std::cout<<bc.searchRegister(std::function<bool(std::string)>(&f2), id_b, id_r);

}
int main(int argc, char *argv[])
{

//    test_blockchain();

    QApplication a(argc, argv);
//    CopyPaste w;
    Inicio xd;
    xd.show();
    xd.exec();
//    w.test();
    std::cout<<"fdsafdsa"<<std::endl;
    return a.exec();


}
