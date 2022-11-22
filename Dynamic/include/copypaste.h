#ifndef COPYPASTE_H
#define COPYPASTE_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QDebug>
#include <tabnew.h>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <tabnew.h>
QT_BEGIN_NAMESPACE
namespace Ui { class CopyPaste; }
QT_END_NAMESPACE

class CopyPaste : public QMainWindow
{
    Q_OBJECT

public:
    CopyPaste(QWidget *parent = nullptr);
    ~CopyPaste();
    QVector<TabNew*> allTabPtr;
    std::vector<std::vector<std::string>> allRegisters;
    void test();
    std::vector<std::string> process_line(QByteArray lines);
private slots:

    void on_newTabButton_clicked();

    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::CopyPaste *ui;
    void addTab(QString tabname);

};
#endif // COPYPASTE_H
