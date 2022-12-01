#include "copypaste.h"
#include "BlockChain.h"
#include <iostream>
#include <QApplication>
#include <inicio.h>
#include "loadfile.h"
#include "../BlockChain.h"
#include "../Register.h"
//#include "../../../UTEC/UTEC 2022 -2/ESTRUCTURAS/proyectoblockchain/proyecto-equipo-4/BlockChain.h"

int main(int argc, char *argv[])
{

//    test_blockchain();

    QApplication a(argc, argv);
    //BlockChain<Register, decltype(&Register::emisor), &Register::emisor,string, decltype(&Register::receptor),&Register::receptor, string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string> *bc;
    LoadFile *val  = new LoadFile();
//    Generar* main = new Generar;
    val->show();
    return a.exec();


}
