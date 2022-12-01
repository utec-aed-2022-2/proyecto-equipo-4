#include "tdialog.h"
#include "ui_tdialog.h"

TDialog::TDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TDialog)
{
    ui->setupUi(this);
}

TDialog::~TDialog()
{
    delete ui;
}
