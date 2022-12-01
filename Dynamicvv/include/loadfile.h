#ifndef LOADFILE_H
#define LOADFILE_H

#include <QDialog>
#include "copypaste.h"
#include "../BlockChain.h"
#include "../Register.h"
namespace Ui {
class LoadFile;
}

class LoadFile : public QDialog
{
    Q_OBJECT

public:
//    explicit LoadFile(QWidget *parent = nullptr);
    explicit LoadFile(BlockChain<Register, decltype(&Register::emisor), &Register::emisor,string, decltype(&Register::receptor),&Register::receptor, string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string> *bc, QWidget *parent = nullptr);
    explicit LoadFile(QWidget *parent = nullptr);
    ~LoadFile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoadFile *ui;
    BlockChain<Register, decltype(&Register::emisor), &Register::emisor,string, decltype(&Register::receptor),&Register::receptor, string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string> *bc;
};

#endif // LOADFILE_H
