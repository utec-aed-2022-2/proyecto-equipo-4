#include "window.h"
#include "ui_mainwindow.h"
#include <iostream>

Window::Window(QWidget *parent)
    : QMainWindow{parent}, ui(new Ui::MainWindow), d(new Dialog(bc))
{
    ui->setupUi(this);
    d->show();
}

void Window::on_pushButton_clicked()
{
    bc->print();
}


void Window::on_pushButton_clicked(bool checked)
{
    std::cout << checked << std::endl;
}
