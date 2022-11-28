#ifndef GENERAR_H
#define GENERAR_H

#include <QDialog>

namespace Ui {
class Generar;
}

class Generar : public QDialog
{
    Q_OBJECT

public:
    explicit Generar(QWidget *parent = nullptr);
    ~Generar();

private:
    Ui::Generar *ui;
};

#endif // GENERAR_H
