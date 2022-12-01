/********************************************************************************
** Form generated from reading UI file 'searcher.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHER_H
#define UI_SEARCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Searcher
{
public:
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *Searcher)
    {
        if (Searcher->objectName().isEmpty())
            Searcher->setObjectName("Searcher");
        Searcher->resize(902, 547);
        comboBox = new QComboBox(Searcher);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(40, 70, 86, 25));
        comboBox_2 = new QComboBox(Searcher);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(170, 70, 86, 25));
        pushButton = new QPushButton(Searcher);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 70, 89, 25));
        pushButton_2 = new QPushButton(Searcher);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(470, 450, 89, 25));
        comboBox_3 = new QComboBox(Searcher);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(400, 300, 86, 25));
        comboBox_4 = new QComboBox(Searcher);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(540, 300, 86, 25));
        lineEdit = new QLineEdit(Searcher);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(390, 370, 113, 25));
        lineEdit_2 = new QLineEdit(Searcher);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(540, 370, 113, 25));
        plainTextEdit = new QPlainTextEdit(Searcher);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(20, 170, 331, 361));

        retranslateUi(Searcher);

        QMetaObject::connectSlotsByName(Searcher);
    } // setupUi

    void retranslateUi(QDialog *Searcher)
    {
        Searcher->setWindowTitle(QCoreApplication::translate("Searcher", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Searcher", "emisor", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Searcher", "receptor", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Searcher", "monto", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Searcher", "fecha", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("Searcher", "Hash", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Searcher", "MinHeap", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Searcher", "MaxHeap", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("Searcher", "Btree", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("Searcher", "Trie", nullptr));

        pushButton->setText(QCoreApplication::translate("Searcher", "Crear Indice", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Searcher", "Search", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Searcher", "emisor", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Searcher", "receptor", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("Searcher", "monto", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("Searcher", "fecha", nullptr));

        comboBox_4->setItemText(0, QCoreApplication::translate("Searcher", "value", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("Searcher", "min", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("Searcher", "max", nullptr));
        comboBox_4->setItemText(3, QCoreApplication::translate("Searcher", "range", nullptr));
        comboBox_4->setItemText(4, QCoreApplication::translate("Searcher", "start_with", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Searcher: public Ui_Searcher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHER_H
