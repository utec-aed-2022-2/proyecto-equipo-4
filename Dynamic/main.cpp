#include "copypaste.h"
#include "window.h"
#include "dialog.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window main;
    //CopyPaste w;
    //w.test();
    main.show();
    //w.show();

//    w.test();
    std::cout<<"fdsafdsa"<<std::endl;
    return a.exec();


}
