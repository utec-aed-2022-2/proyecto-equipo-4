#include "inicio.h"
#include "ui_inicio.h"
#include "copypaste.h"
#include "generar.h"
#include "loadfile.h"
//#include "
Inicio::Inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
}

Inicio::Inicio(QWidget *parent, CopyPaste* pantalla, Generar* pantalla2) :
    QDialog(parent),
    ui(new Ui::Inicio)
{
    this->Transacciones = pantalla;
    this->Registrar = pantalla2;
    ui->setupUi(this);
}

Inicio::~Inicio()
{
    delete Transacciones;
    delete Registrar;
    delete ui;
}

void Inicio::on_pushButton_clicked()
{

//    hide();
    Transacciones->test();
    Transacciones->show();

}


void Inicio::on_pushButton_2_clicked()
{
//    hide();
    Registrar->show();
}

