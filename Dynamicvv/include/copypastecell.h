#ifndef COPYPASTECELL_H
#define COPYPASTECELL_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
namespace Ui {
class CopyPasteCell;
}

class CopyPasteCell : public QWidget
{
    Q_OBJECT

public:
    explicit CopyPasteCell(QWidget *parent = nullptr);
    ~CopyPasteCell();
    int cellNumber;

    QString getTextData();
    QString getCellName();

    void setTextData(QString cellText);
    void setCellName(QString cellName);

private:
    Ui::CopyPasteCell *ui;
signals:
    void closeThiscell(int);

private slots:
    void on_pushButton_clicked();
    void on_deleteButton_clicked();
    void on_clearButton_clicked();
    void on_copyButton_clicked();
    void on_pasteButton_clicked();
};

#endif // COPYPASTECELL_H
