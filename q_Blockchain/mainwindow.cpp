#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QMessageBox>
#include <QGridLayout>
#include <QFileDialog>
#include <QProgressDialog>
#include <QMimeDatabase>
#include <QHeaderView>
#include <QDesktopServices>

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

void MainWindow::on_pushButton_3_clicked()
{
    std::string path = ui->csvPath->text().toStdString();
    std::cout << path << std::endl;
}

