#include "loadfile.h"
#include "ui_loadfile.h"
#include "QFileDialog"
#include "QMessageBox"
#include "inicio.h"
#include "generar.h"
#include <iostream>


//LoadFile::LoadFile(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::LoadFile)
//{
//    ui->setupUi(this);
//}


LoadFile::LoadFile(BlockChain<Register, decltype(&Register::emisor), &Register::emisor,string, decltype(&Register::receptor),&Register::receptor, string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string> *bc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadFile)
{
    ui->setupUi(this);
    this->bc = bc;
}

LoadFile::LoadFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadFile)
{
    ui->setupUi(this);
}


LoadFile::~LoadFile()
{
    delete ui;
}




void LoadFile::on_pushButton_clicked()
{
    QString csv_filter = "CSV (*.csv)";
    QString nombre_archivo = QFileDialog::getOpenFileName(this, tr("Abrir archivo")
                            , "/", csv_filter, &csv_filter,
                                                          QFileDialog::DontUseNativeDialog);

    qDebug("%s", qUtf8Printable(nombre_archivo));
    std::string new_name = nombre_archivo.toLocal8Bit().constData();

    std::cout<<"holaa"<<std::endl;

    std::cout<<new_name<<std::endl;

    if(nombre_archivo.isEmpty()){

    }else{


        auto *bc = new BlockChain<Register, decltype(&Register::emisor), &Register::emisor,std::string, decltype(&Register::receptor),&Register::receptor, std::string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string>(4, new_name);
        Generar* pRegistro = new Generar;
        CopyPaste *aplicacion = new CopyPaste;
        aplicacion->bc = bc;
        pRegistro->bc = bc;
        Inicio *inicio = new Inicio(nullptr, aplicacion, pRegistro);
        aplicacion->test();
        inicio->show();

    }

}

