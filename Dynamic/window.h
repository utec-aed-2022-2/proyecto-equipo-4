#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "../BlockChain.h"
#include "../Register.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

signals:
private slots:
    void on_pushButton_clicked();

    void on_pushButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    BlockChain<Register>* bc;
    Dialog* d;
};

#endif // WINDOW_H
