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

    void setupUi(QDialog *LoadFile)
    {
        if (LoadFile->objectName().isEmpty())
            LoadFile->setObjectName("LoadFile");
        LoadFile->resize(400, 300);
        pushButton = new QPushButton(LoadFile);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 180, 161, 41));

        retranslateUi(LoadFile);

        QMetaObject::connectSlotsByName(LoadFile);
    } // setupUi

    void retranslateUi(QDialog *LoadFile)
    {
        LoadFile->setWindowTitle(QCoreApplication::translate("LoadFile", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("LoadFile", "CARGAR ARCHIVO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadFile: public Ui_LoadFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADFILE_H
