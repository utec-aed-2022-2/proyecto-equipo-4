/********************************************************************************
** Form generated from reading UI file 'tabnew.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABNEW_H
#define UI_TABNEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabNew
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QGridLayout *cellLayout;
    QPushButton *addButton;

    void setupUi(QWidget *TabNew)
    {
        if (TabNew->objectName().isEmpty())
            TabNew->setObjectName("TabNew");
        TabNew->resize(856, 324);
        verticalLayout_2 = new QVBoxLayout(TabNew);
        verticalLayout_2->setObjectName("verticalLayout_2");
        scrollArea = new QScrollArea(TabNew);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 832, 300));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        cellLayout = new QGridLayout();
        cellLayout->setObjectName("cellLayout");

        verticalLayout->addLayout(cellLayout);

        addButton = new QPushButton(scrollAreaWidgetContents);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        retranslateUi(TabNew);

        QMetaObject::connectSlotsByName(TabNew);
    } // setupUi

    void retranslateUi(QWidget *TabNew)
    {
        TabNew->setWindowTitle(QCoreApplication::translate("TabNew", "Form", nullptr));
        addButton->setText(QCoreApplication::translate("TabNew", "Add New Cell", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TabNew: public Ui_TabNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABNEW_H
