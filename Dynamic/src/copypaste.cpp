#include "copypaste.h"
#include "ui_copypaste.h"
#include <bits/stdc++.h>
#include <chrono>
#include <thread>

CopyPaste::CopyPaste(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CopyPaste)
{
    ui->setupUi(this);
//    addTab("Default");
}

CopyPaste::~CopyPaste()
{
    delete ui;
}

void CopyPaste::test()
{

//    QString filename = "Data.txt";
//    QFile filexd(filename);
//    if (filexd.open(QIODevice::ReadWrite)) {
//        QTextStream stream(&filexd);
//        stream << "something";
//    }



    std::cout<<"TEST PASSED"<<std::endl;

    QFile file("example.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    while (!file.atEnd()) {
        std::cout<<"ENTRA PROCESS"<<std::endl;

        QByteArray line = file.readLine();
        auto s_line = process_line(line);
        allRegisters.push_back(s_line);
    }


    std::cout<<"TAMANO"<<allRegisters.size()<<std::endl;

    for (int i = 0; i < (int)allRegisters.size();i++){

        addTab(QString("BLOCK ID %0").arg(ui->tabWidget->count()+1));
        for (int j = 0; j < (int)allRegisters[i].size()-4;j++){
            allTabPtr[i]->addNewCell();
        }
        std::cout<<"REAL TAMANO = "<<allRegisters[0].size();
        for (int j = 0; j < (int)allRegisters[i].size()-4;j++){
            QString str = QString::fromUtf8(allRegisters[i][j+4].c_str());

            allTabPtr[i]->allCellPtr[j]->setTextData(str);
        }

    }

//    for (auto it = allTabPtr.begin(); it != allTabPtr.end();it++){

//    }s
}
std::vector<std::string> CopyPaste::process_line(QByteArray line){

    std::cout<<"PROCESS LINE"<<std::endl;
    std::vector<std::string> v;

    QString str(line);
    std::string sline = line.toStdString();
    std::stringstream ss(sline);

       while (ss.good()) {
           std::string substr;
           getline(ss, substr, ',');
           v.push_back(substr);
       }

       for (size_t i = 0; i < v.size(); i++)
           std::cout << v[i] << std::endl;
    return v;
}

void CopyPaste::addTab(QString tabName){

    TabNew *newTabptr = new TabNew(this);
    ui->tabWidget->addTab(newTabptr, tabName);
    newTabptr->setAttribute(Qt::WA_DeleteOnClose, true);
    allTabPtr.append(newTabptr);
}

void CopyPaste::on_newTabButton_clicked()
{
    addTab(QString("BLOCK ID  %0").arg(ui->tabWidget->count()+1));
}


void CopyPaste::on_tabWidget_tabCloseRequested(int index)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Confirmation", "Delete this tab?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes){
        qDebug() << "Removing tab of index" <<index;
        allTabPtr[index]->close();
        ui->tabWidget->removeTab(index);
        allTabPtr.remove(index);
    }
    if (allTabPtr.length() == 0){
        addTab("Default");
        ui->statusbar->showMessage("Added Default Tab", 3000);
    }
}

