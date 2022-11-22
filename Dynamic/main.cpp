#include "copypaste.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CopyPaste w;
    w.test();

    w.show();

//    w.test();
    std::cout<<"fdsafdsa"<<std::endl;
    return a.exec();


}
