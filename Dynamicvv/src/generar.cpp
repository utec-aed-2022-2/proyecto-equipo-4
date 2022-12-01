#include "generar.h"
#include "inicio.h"
#include "copypaste.h"
#include "ui_generar.h"
#include "iostream"

Generar::Generar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Generar)
{

    ui->setupUi(this);
//    l->show();
}



Generar::~Generar()
{
    delete ui;
}


void Generar::on_pushButton_clicked()
{
    std::string emisor = ui->lineEdit->text().toStdString();
    std::string receptor = ui->lineEdit_2->text().toStdString();
    if (emisor!="" and receptor!=""){
        std::string monto = ui->lineEdit_3->text().toStdString();
        auto p = std::chrono::system_clock::now();
        std::string fecha = std::to_string(std::chrono::duration_cast<std::chrono::seconds>(p.time_since_epoch()).count());
        this->bc->insertRegister(Register(emisor+","+receptor+","+monto+","+fecha));
        this->bc->print();
    }
}


void Generar::on_pushButton_2_clicked()
{
//    this->hide();

//    Inicio w = new Inicio

}

