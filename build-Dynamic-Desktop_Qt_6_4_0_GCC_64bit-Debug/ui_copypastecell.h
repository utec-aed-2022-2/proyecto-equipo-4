/********************************************************************************
** Form generated from reading UI file 'copypastecell.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COPYPASTECELL_H
#define UI_COPYPASTECELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CopyPasteCell
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *CopyPasteCell)
    {
        if (CopyPasteCell->objectName().isEmpty())
            CopyPasteCell->setObjectName("CopyPasteCell");
        CopyPasteCell->resize(680, 160);
        verticalLayout = new QVBoxLayout(CopyPasteCell);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        textEdit = new QTextEdit(CopyPasteCell);
        textEdit->setObjectName("textEdit");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_2->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CopyPasteCell);

        QMetaObject::connectSlotsByName(CopyPasteCell);
    } // setupUi

    void retranslateUi(QWidget *CopyPasteCell)
    {
        CopyPasteCell->setWindowTitle(QCoreApplication::translate("CopyPasteCell", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CopyPasteCell: public Ui_CopyPasteCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COPYPASTECELL_H
