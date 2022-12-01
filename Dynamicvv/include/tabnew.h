#ifndef TABNEW_H
#define TABNEW_H

#include <QWidget>
#include <copypastecell.h>
#include <QVector>
namespace Ui {
class TabNew;
}

class TabNew : public QWidget
{
    Q_OBJECT

public:
    explicit TabNew(QWidget *parent = nullptr);
    ~TabNew();
    int cellNumberTotal;
    QVector<CopyPasteCell*> allCellPtr;
    void addNewCell(QString cellText="", QString cellName="Cell Name");

private slots:
    void on_addButton_clicked();

public slots:
    void closeCell(int);

private:
    Ui::TabNew *ui;
};

#endif // TABNEW_H
