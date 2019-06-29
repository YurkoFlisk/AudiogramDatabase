/********************************************************************************
** Form generated from reading UI file 'PointsEditorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTSEDITORDIALOG_H
#define UI_POINTSEDITORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PointsEditorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *pointsTW;
    QHBoxLayout *horizontalLayout;
    QPushButton *addPB;
    QPushButton *deletePB;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *savePB;
    QPushButton *cancelPB;

    void setupUi(QDialog *PointsEditorDialog)
    {
        if (PointsEditorDialog->objectName().isEmpty())
            PointsEditorDialog->setObjectName(QString::fromUtf8("PointsEditorDialog"));
        PointsEditorDialog->resize(224, 299);
        verticalLayout = new QVBoxLayout(PointsEditorDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pointsTW = new QTableWidget(PointsEditorDialog);
        pointsTW->setObjectName(QString::fromUtf8("pointsTW"));
        pointsTW->setSortingEnabled(false);

        verticalLayout->addWidget(pointsTW);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addPB = new QPushButton(PointsEditorDialog);
        addPB->setObjectName(QString::fromUtf8("addPB"));

        horizontalLayout->addWidget(addPB);

        deletePB = new QPushButton(PointsEditorDialog);
        deletePB->setObjectName(QString::fromUtf8("deletePB"));

        horizontalLayout->addWidget(deletePB);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        savePB = new QPushButton(PointsEditorDialog);
        savePB->setObjectName(QString::fromUtf8("savePB"));

        horizontalLayout_2->addWidget(savePB);

        cancelPB = new QPushButton(PointsEditorDialog);
        cancelPB->setObjectName(QString::fromUtf8("cancelPB"));

        horizontalLayout_2->addWidget(cancelPB);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PointsEditorDialog);
        QObject::connect(savePB, SIGNAL(clicked()), PointsEditorDialog, SLOT(accept()));
        QObject::connect(cancelPB, SIGNAL(clicked()), PointsEditorDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PointsEditorDialog);
    } // setupUi

    void retranslateUi(QDialog *PointsEditorDialog)
    {
        PointsEditorDialog->setWindowTitle(QApplication::translate("PointsEditorDialog", "Edit points", nullptr));
        addPB->setText(QApplication::translate("PointsEditorDialog", "Add", nullptr));
        deletePB->setText(QApplication::translate("PointsEditorDialog", "Delete", nullptr));
        savePB->setText(QApplication::translate("PointsEditorDialog", "Save", nullptr));
        cancelPB->setText(QApplication::translate("PointsEditorDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PointsEditorDialog: public Ui_PointsEditorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTSEDITORDIALOG_H
