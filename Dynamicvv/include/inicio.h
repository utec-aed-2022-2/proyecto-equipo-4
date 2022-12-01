#ifndef INICIO_H
#define INICIO_H
#include "copypaste.h"
#include "generar.h"
#include <QDialog>
#include "BlockChain.h"
#include "Register.h"



namespace Ui {
class Inicio;
}

class Inicio : public QDialog
{
    Q_OBJECT


public:
    explicit Inicio(QWidget *parent = nullptr);
    explicit Inicio(QWidget *parent = nullptr, CopyPaste* pantalla = nullptr, Generar* pantalla2 = nullptr);
    ~Inicio();
    CopyPaste *Transacciones = nullptr;
    Generar *Registrar = nullptr;
    BlockChain<Register, decltype(&Register::emisor), &Register::emisor,std::string, decltype(&Register::receptor),&Register::receptor, std::string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,std::string> *bc;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::Inicio *ui;
};

#endif // INICIO_H
