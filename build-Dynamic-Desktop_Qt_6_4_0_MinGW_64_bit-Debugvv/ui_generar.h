/********************************************************************************
** Form generated from reading UI file 'generar.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERAR_H
#define UI_GENERAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Generar
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *Generar)
    {
        if (Generar->objectName().isEmpty())
            Generar->setObjectName("Generar");
        Generar->resize(819, 549);
        pushButton = new QPushButton(Generar);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 370, 341, 81));
        lineEdit_2 = new QLineEdit(Generar);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(320, 190, 201, 51));
        label_2 = new QLabel(Generar);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, 120, 53, 20));
        label_3 = new QLabel(Generar);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 200, 69, 20));
        label_4 = new QLabel(Generar);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 290, 74, 20));
        label = new QLabel(Generar);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 20, 170, 20));
        lineEdit_3 = new QLineEdit(Generar);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(320, 280, 201, 51));
        lineEdit = new QLineEdit(Generar);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(320, 110, 201, 51));
        pushButton_2 = new QPushButton(Generar);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 10, 131, 51));
        checkBox = new QCheckBox(Generar);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(620, 110, 92, 23));
        lineEdit_4 = new QLineEdit(Generar);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(620, 160, 113, 25));
        lineEdit_5 = new QLineEdit(Generar);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(620, 210, 113, 25));
        label_5 = new QLabel(Generar);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(620, 140, 67, 17));
        label_6 = new QLabel(Generar);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(620, 190, 67, 17));

        retranslateUi(Generar);

        QMetaObject::connectSlotsByName(Generar);
    } // setupUi

    void retranslateUi(QDialog *Generar)
    {
        Generar->setWindowTitle(QCoreApplication::translate("Generar", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Generar", "ENVIAR", nullptr));
        label_2->setText(QCoreApplication::translate("Generar", "EMISOR", nullptr));
        label_3->setText(QCoreApplication::translate("Generar", "RECEPTOR", nullptr));
        label_4->setText(QCoreApplication::translate("Generar", "CANTIDAD", nullptr));
        label->setText(QCoreApplication::translate("Generar", "REALIZAR TRANSACCION", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Generar", "Print", nullptr));
        checkBox->setText(QCoreApplication::translate("Generar", "update", nullptr));
        label_5->setText(QCoreApplication::translate("Generar", "Id block", nullptr));
        label_6->setText(QCoreApplication::translate("Generar", "Posici\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Generar: public Ui_Generar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERAR_H
