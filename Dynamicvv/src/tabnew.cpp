#include "tabnew.h"
#include "ui_tabnew.h"

TabNew::TabNew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabNew)
{
    ui->setupUi(this);
}

TabNew::~TabNew()
{
    delete ui;
}

void TabNew::on_addButton_clicked()
{
    addNewCell();
}

void TabNew::addNewCell(QString cellText, QString cellName)
{
    CopyPasteCell* newCell = new CopyPasteCell(this);// Crear el objeto
    ui->cellLayout->addWidget(newCell, cellNumberTotal, 0);
    connect(newCell, SIGNAL(closeThisCell(int)), this, SLOT(closeCell(int)));
    newCell->setAttribute(Qt::WA_DeleteOnClose, true);
    newCell->cellNumber = cellNumberTotal;
    newCell->setTextData(cellText);
    newCell->setCellName(cellName);
    allCellPtr.append(newCell);
    cellNumberTotal++;

}

void TabNew::closeCell(int cellNumber){
    allCellPtr[cellNumber]->close();
    for (int i = cellNumber+1;i<allCellPtr.length();i++){
        allCellPtr[i]->cellNumber--;
    }
    cellNumberTotal--;
    allCellPtr.remove(cellNumber);
}

//CopyPasteCell* newCell = new CopyPasteCell(this);
//ui->cell
