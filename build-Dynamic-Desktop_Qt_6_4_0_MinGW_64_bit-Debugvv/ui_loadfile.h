/********************************************************************************
** Form generated from reading UI file 'loadfile.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADFILE_H
#define UI_LOADFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoadFile
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *LoadFile)
    {
        if (LoadFile->objectName().isEmpty())
            LoadFile->setObjectName("LoadFile");
        LoadFile->resize(400, 300);
        pushButton = new QPushButton(LoadFile);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 120, 161, 41));
        pushButton_2 = new QPushButton(LoadFile);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(140, 220, 89, 25));

        retranslateUi(LoadFile);

        QMetaObject::connectSlotsByName(LoadFile);
    } // setupUi

    void retranslateUi(QDialog *LoadFile)
    {
        LoadFile->setWindowTitle(QCoreApplication::translate("LoadFile", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("LoadFile", "CARGAR ARCHIVO", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoadFile", "CLOSE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadFile: public Ui_LoadFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADFILE_H
