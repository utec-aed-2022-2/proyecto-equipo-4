#ifndef SEARCHER_H
#define SEARCHER_H

#include <QDialog>
#include "../Register.h"
#include "../BlockChain.h"
namespace Ui {
class Searcher;
}

class Searcher : public QDialog
{
    Q_OBJECT

public:
    explicit Searcher(QWidget *parent = nullptr);
    ~Searcher();
    BlockChain<Register, decltype(&Register::emisor), &Register::emisor,string, decltype(&Register::receptor),&Register::receptor, string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string> *bc;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Searcher *ui;
};

#endif // SEARCHER_H
