/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Inicio
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Inicio)
    {
        if (Inicio->objectName().isEmpty())
            Inicio->setObjectName("Inicio");
        Inicio->resize(573, 408);
        pushButton = new QPushButton(Inicio);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(390, 210, 93, 29));
        label = new QLabel(Inicio);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 50, 241, 41));
        pushButton_2 = new QPushButton(Inicio);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(50, 210, 93, 29));
        pushButton_3 = new QPushButton(Inicio);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(220, 310, 89, 25));

        retranslateUi(Inicio);

        QMetaObject::connectSlotsByName(Inicio);
    } // setupUi

    void retranslateUi(QDialog *Inicio)
    {
        Inicio->setWindowTitle(QCoreApplication::translate("Inicio", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Inicio", "Ver", nullptr));
        label->setText(QCoreApplication::translate("Inicio", "                    BIENVENIDO", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Inicio", "Registros", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Inicio", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inicio: public Ui_Inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
