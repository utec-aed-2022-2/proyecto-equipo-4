#include "generar.h"
#include "ui_generar.h"

Generar::Generar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Generar)
{
    ui->setupUi(this);
}

Generar::~Generar()
{
    delete ui;
}
