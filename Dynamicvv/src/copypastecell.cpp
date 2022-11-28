    #include "copypastecell.h"
#include "ui_copypastecell.h"

CopyPasteCell::CopyPasteCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CopyPasteCell)
{
    ui->setupUi(this);
}

CopyPasteCell::~CopyPasteCell()
{
    delete ui;
}

void CopyPasteCell::setTextData(QString celltext){
    ui->textEdit->clear();
    ui->textEdit->insertPlainText(celltext);

}
void CopyPasteCell::setCellName(QString cellName){
//    ui->cellLabel->setText(cellName);

}

void CopyPasteCell::on_pushButton_clicked()
{

}


void CopyPasteCell::on_deleteButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Confirmation", "Delete this Cell?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes){
        emit closeThiscell(cellNumber);
        this->close();
    }
}


void CopyPasteCell::on_clearButton_clicked()
{
    ui->textEdit->clear();
}


void CopyPasteCell::on_copyButton_clicked()
{

}


void CopyPasteCell::on_pasteButton_clicked()
{

}

