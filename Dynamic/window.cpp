#include "window.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <chrono>

Window::Window(QWidget *parent)
    : QMainWindow{parent}, ui(new Ui::MainWindow), d(new Dialog(bc))
{
    ui->setupUi(this);
    d->show();
}

void Window::on_pushButton_clicked()
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


void Window::on_pushButton_clicked(bool checked)
{
    std::cout << checked << std::endl;
}

Window::~Window(){
    delete bc;
}
