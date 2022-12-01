#include "loadfile.h"
#include "ui_loadfile.h"

LoadFile::LoadFile(QWidget *parent)
    : QWidget{parent}, ui(new Ui::QWidget)
{
    ui->setupUi(this);
}
