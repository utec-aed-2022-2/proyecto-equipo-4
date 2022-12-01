#include "copypaste.h"
#include "BlockChain.h"
#include <iostream>
#include <QApplication>
#include <inicio.h>
#include "loadfile.h"
#include "../BlockChain.h"
#include "../Register.h"
//#include "../../../UTEC/UTEC 2022 -2/ESTRUCTURAS/proyectoblockchain/proyecto-equipo-4/BlockChain.h"

bool f1(std::string r){
    if(r=="Nose") return true;
    else return false;
}

bool f2(std::string r){
    if(r=="hola") return true;
    else return false;
}


int main(int argc, char *argv[])
{

//    test_blockchain();

    QApplication a(argc, argv);
    BlockChain<Register, decltype(&Register::emisor), &Register::emisor,string, decltype(&Register::receptor),&Register::receptor, string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string> *bc;
    LoadFile *val  = new LoadFile;
//    Generar* main = new Generar;
    val->show();

    std::cout<<"fdsafdsa"<<std::endl;
    return a.exec();


}
