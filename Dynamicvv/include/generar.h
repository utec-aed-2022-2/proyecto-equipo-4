#ifndef GENERAR_H
#define GENERAR_H
#include "copypaste.h"
#include <QDialog>
#include "loadfile.h"
#include "../BlockChain.h"
#include "../Register.h"

namespace Ui {
class Generar;
}

class Generar : public QDialog
{
    Q_OBJECT

public:
    explicit Generar(QWidget *parent = nullptr);
    explicit Generar(BlockChain<Register, decltype(&Register::emisor), &Register::emisor,string, decltype(&Register::receptor),&Register::receptor, string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string> *bc, QWidget *parent);
    BlockChain<Register, decltype(&Register::emisor), &Register::emisor,string, decltype(&Register::receptor),&Register::receptor, string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string> *bc;
    ~Generar();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::Generar *ui;
    LoadFile *l;
};

#endif // GENERAR_H
