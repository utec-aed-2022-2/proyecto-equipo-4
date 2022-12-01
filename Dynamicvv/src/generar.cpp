#include "generar.h"
#include "inicio.h"
#include "copypaste.h"
#include "ui_generar.h"
#include "iostream"

Generar::Generar(BlockChain<Register, decltype(&Register::emisor), &Register::emisor,string, decltype(&Register::receptor),&Register::receptor, string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string> *&bc, QWidget *parent) :
    QDialog(parent),bc(bc),
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
        if (ui->checkBox->isChecked()){
            int id_block = ui->lineEdit_4->text().toInt();
            int pos = ui->lineEdit_5->text().toInt();
            this->bc->updateRegister(id_block, pos, Register(emisor+","+receptor+","+monto+","+fecha));
        }
        else {
            this->bc->insertRegister(Register(emisor+","+receptor+","+monto+","+fecha));
        }
        this->bc->print();
    }
}


void Generar::on_pushButton_2_clicked()
{
    this->bc->print();
}

