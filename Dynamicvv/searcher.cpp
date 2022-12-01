#include "searcher.h"
#include "ui_searcher.h"

Searcher::Searcher(BlockChain<Register, decltype(&Register::emisor), &Register::emisor,string, decltype(&Register::receptor),&Register::receptor, string, decltype(&Register::monto),&Register::monto, float, decltype(&Register::fecha), &Register::fecha,string> *&bc,QWidget *parent) :
    QDialog(parent),
    bc(bc),
    ui(new Ui::Searcher)
{
    ui->setupUi(this);
}

Searcher::~Searcher()
{
    delete ui;
}

void Searcher::on_pushButton_clicked()
{
    string atr = ui->comboBox->currentText().toStdString();
    string type = ui->comboBox_2->currentText().toStdString();
    if (atr == "emisor"){
        if (type == "Hash"){
            bc->createIndex(&Register::emisor, 1);
        }
        else if (type == "MinHeap"){
            bc->createIndexMinHeap(&Register::emisor, 1);
        }
        else if (type == "MaxHeap"){
            bc->createIndexHeap(&Register::emisor, 1);
        }
        else if (type == "BTree"){

            bc->createIndexB(&Register::emisor, 1);
        }
        else if (type == "Trie"){
            bc->createIndexTrie(&Register::emisor, 1);
        }
    }
    else if(atr == "receptor"){
        if (type == "Hash"){
            bc->createIndex(&Register::receptor, 2);
        }
        else if (type == "MinHeap"){
            bc->createIndexMinHeap(&Register::receptor, 2);
        }
        else if (type == "MaxHeap"){
            bc->createIndexHeap(&Register::receptor, 2);
        }
        else if (type == "BTree"){

            bc->createIndexB(&Register::receptor, 2);
        }
        else if (type == "Trie"){
            bc->createIndexTrie(&Register::receptor, 2);
        }
    }
    else if (atr == "monto"){
        if (type == "Hash"){
            bc->createIndex(&Register::monto, 3);
        }
        else if (type == "MinHeap"){
            bc->createIndexMinHeap(&Register::monto, 3);
        }
        else if (type == "MaxHeap"){
            bc->createIndexHeap(&Register::monto, 3);
        }
        else if (type == "BTree"){
            bc->createIndexB(&Register::monto, 3);
        }
    }
    else {
        if (type == "Hash"){
            bc->createIndex(&Register::fecha, 4);
        }
        else if (type == "MinHeap"){
            bc->createIndexMinHeap(&Register::fecha, 4);
        }
        else if (type == "MaxHeap"){
            bc->createIndexHeap(&Register::fecha, 4);
        }
        else if (type == "BTree"){

            bc->createIndexB(&Register::fecha, 4);
        }
        else if (type == "Trie"){
            bc->createIndexTrie(&Register::fecha, 4);
        }
    }
}


void Searcher::on_pushButton_2_clicked()
{
    string atr = ui->comboBox_3->currentText().toStdString();
    string type = ui->comboBox_4->currentText().toStdString();
    ForwardList<ResultIndex<Register>>* res;
    if (atr == "emisor"){
        if (type == "value"){
            res = bc->getValue(&Register::emisor, ui->lineEdit->text().toStdString(),1);
        }
        else if (type == "min"){
            res = bc->getMin(&Register::emisor,1);
        }
        else if (type == "max"){
            res = bc->getMax(&Register::emisor,1);
        }
        else if (type == "range"){
            res = bc->getInRange(&Register::emisor,ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString(),1);
        }
        else if (type == "start_with"){
            res = bc->start_with(&Register::emisor, ui->lineEdit->text().toStdString(),1);
        }
    }
    else if(atr == "receptor"){
        if (type == "value"){
            res = bc->getValue(&Register::receptor, ui->lineEdit->text().toStdString(),2);
        }
        else if (type == "min"){
            res = bc->getMin(&Register::receptor,2);
        }
        else if (type == "max"){
            res = bc->getMax(&Register::receptor,2);
        }
        else if (type == "range"){
            res = bc->getInRange(&Register::receptor,ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString(),2);
        }
        else if (type == "start_with"){
            res = bc->start_with(&Register::receptor, ui->lineEdit->text().toStdString(),2);
        }
    }
    else if (atr == "monto"){
        if (type == "value"){
            res = bc->getValue(&Register::monto, ui->lineEdit->text().toDouble(),3);
        }
        else if (type == "min"){
            res = bc->getMin(&Register::monto,3);
        }
        else if (type == "max"){
            res = bc->getMax(&Register::monto,3);
        }
        else if (type == "range"){
            res = bc->getInRange(&Register::monto,ui->lineEdit->text().toDouble(),ui->lineEdit_2->text().toDouble(),3);
        }
    }
    else {
        if (type == "value"){
            res = bc->getValue(&Register::fecha, ui->lineEdit->text().toStdString(),4);
        }
        else if (type == "min"){
            res = bc->getMin(&Register::fecha,4);
        }
        else if (type == "max"){
            res = bc->getMax(&Register::fecha,4);
        }
        else if (type == "range"){
            res = bc->getInRange(&Register::fecha,ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString(),4);
        }
        else if (type == "start_with"){
            res = bc->start_with(&Register::fecha, ui->lineEdit->text().toStdString(),4);
        }
    }
    string q;
    for(auto e: *res){
        q += e.regis->emisor + " "+e.regis->receptor + " "+to_string(e.regis->monto) + " "+e.regis->fecha + "\n";
    }
    QString text = QString::fromStdString(q);
    ui->plainTextEdit->setPlainText(text);
}

