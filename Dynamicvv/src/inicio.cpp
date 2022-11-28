#include "inicio.h"
#include "ui_inicio.h"
#include "copypaste.h"
#include "generar.h"
//#include "
Inicio::Inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
}

Inicio::~Inicio()
{
    delete ui;
}

void Inicio::on_pushButton_clicked()
{
    std::cout<<"DERI"<<std::endl;
    hide();
    CopyPaste* w = new CopyPaste;
    w->test();
    w->show();

}


void Inicio::on_pushButton_2_clicked()
{
    hide();
    Generar* g = new Generar;
    g->show();
}

