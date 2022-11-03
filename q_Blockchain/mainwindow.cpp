#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    _secDialog = new class secDialog(this);
    _secDialog->show();
}


void MainWindow::on_pushButton_2_clicked()
{

    _TDialog = new class TDialog(this);
    _TDialog->show();
}

