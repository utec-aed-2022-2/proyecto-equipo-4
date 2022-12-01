/********************************************************************************
** Form generated from reading UI file 'copypaste.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COPYPASTE_H
#define UI_COPYPASTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CopyPaste
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QPushButton *newTabButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CopyPaste)
    {
        if (CopyPaste->objectName().isEmpty())
            CopyPaste->setObjectName("CopyPaste");
        CopyPaste->resize(712, 499);
        actionLoad = new QAction(CopyPaste);
        actionLoad->setObjectName("actionLoad");
        actionSave = new QAction(CopyPaste);
        actionSave->setObjectName("actionSave");
        centralwidget = new QWidget(CopyPaste);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabsClosable(false);

        verticalLayout->addWidget(tabWidget);

        newTabButton = new QPushButton(centralwidget);
        newTabButton->setObjectName("newTabButton");

        verticalLayout->addWidget(newTabButton);


        horizontalLayout->addLayout(verticalLayout);

        CopyPaste->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CopyPaste);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 712, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        CopyPaste->setMenuBar(menubar);
        statusbar = new QStatusBar(CopyPaste);
        statusbar->setObjectName("statusbar");
        CopyPaste->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);

        retranslateUi(CopyPaste);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(CopyPaste);
    } // setupUi

    void retranslateUi(QMainWindow *CopyPaste)
    {
        CopyPaste->setWindowTitle(QCoreApplication::translate("CopyPaste", "CopyPaste", nullptr));
        actionLoad->setText(QCoreApplication::translate("CopyPaste", "Load", nullptr));
        actionSave->setText(QCoreApplication::translate("CopyPaste", "Save", nullptr));
        newTabButton->setText(QCoreApplication::translate("CopyPaste", "Add New Tab", nullptr));
        menuFile->setTitle(QCoreApplication::translate("CopyPaste", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CopyPaste: public Ui_CopyPaste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COPYPASTE_H
