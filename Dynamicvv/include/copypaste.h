#ifndef COPYPASTE_H
#define COPYPASTE_H


//#include "jetbrains://clion/navigate/reference?project=proyecto_equipo_4&path=BlockChain.h"


//#include "../../../UTEC/UTEC 2022 -2/ESTRUCTURAS/proyectoblockchain/proyecto-equipo-4/BlockChain.h"

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QDebug>
#include <tabnew.h>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <tabnew.h>
QT_BEGIN_NAMESPACE
namespace Ui { class CopyPaste; }
QT_END_NAMESPACE

class CopyPaste : public QMainWindow
{
    Q_OBJECT

public:
    CopyPaste(QWidget *parent = nullptr);
    ~CopyPaste();
    QVector<TabNew*> allTabPtr;
    std::vector<std::vector<std::string>> allRegisters;
    void test();
    std::vector<std::string> process_line(QByteArray lines);
    void test_blockchain();
private slots:

    void on_newTabButton_clicked();

    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::CopyPaste *ui;
    void addTab(QString tabname);

};
#endif // COPYPASTE_H
