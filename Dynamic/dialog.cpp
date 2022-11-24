#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(BlockChain<Register>*& bc,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog), bc(bc)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    std::cout << ui->lineEdit->text().toStdString() << std::endl;
    this->bc = new BlockChain<Register>(4, ui->lineEdit->text().toStdString());
    this->close();
}

