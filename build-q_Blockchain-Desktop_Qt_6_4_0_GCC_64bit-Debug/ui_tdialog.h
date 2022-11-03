/********************************************************************************
** Form generated from reading UI file 'tdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TDIALOG_H
#define UI_TDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TDialog
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *TDialog)
    {
        if (TDialog->objectName().isEmpty())
            TDialog->setObjectName("TDialog");
        TDialog->resize(631, 407);
        pushButton = new QPushButton(TDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 220, 481, 81));
        lineEdit = new QLineEdit(TDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 40, 361, 41));
        lineEdit_2 = new QLineEdit(TDialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(200, 100, 361, 41));
        lineEdit_3 = new QLineEdit(TDialog);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(200, 160, 361, 41));
        label = new QLabel(TDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 50, 111, 31));
        label_2 = new QLabel(TDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 120, 63, 20));
        label_3 = new QLabel(TDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 110, 111, 21));
        label_4 = new QLabel(TDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 170, 111, 21));

        retranslateUi(TDialog);

        QMetaObject::connectSlotsByName(TDialog);
    } // setupUi

    void retranslateUi(QDialog *TDialog)
    {
        TDialog->setWindowTitle(QCoreApplication::translate("TDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("TDialog", "Enviar", nullptr));
        label->setText(QCoreApplication::translate("TDialog", "EMISOR", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("TDialog", "DESTINATARIO", nullptr));
        label_4->setText(QCoreApplication::translate("TDialog", "CANTIDAD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TDialog: public Ui_TDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TDIALOG_H
