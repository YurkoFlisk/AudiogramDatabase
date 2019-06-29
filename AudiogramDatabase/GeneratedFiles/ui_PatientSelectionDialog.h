/********************************************************************************
** Form generated from reading UI file 'PatientSelectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTSELECTIONDIALOG_H
#define UI_PATIENTSELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PatientSelectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *patientsTV;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addPB;
    QPushButton *editPB;
    QPushButton *deletePB;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okPB;
    QPushButton *cancelPB;

    void setupUi(QDialog *PatientSelectionDialog)
    {
        if (PatientSelectionDialog->objectName().isEmpty())
            PatientSelectionDialog->setObjectName(QString::fromUtf8("PatientSelectionDialog"));
        PatientSelectionDialog->resize(462, 450);
        verticalLayout = new QVBoxLayout(PatientSelectionDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        patientsTV = new QTableView(PatientSelectionDialog);
        patientsTV->setObjectName(QString::fromUtf8("patientsTV"));
        patientsTV->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(patientsTV);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addPB = new QPushButton(PatientSelectionDialog);
        addPB->setObjectName(QString::fromUtf8("addPB"));

        horizontalLayout_2->addWidget(addPB);

        editPB = new QPushButton(PatientSelectionDialog);
        editPB->setObjectName(QString::fromUtf8("editPB"));

        horizontalLayout_2->addWidget(editPB);

        deletePB = new QPushButton(PatientSelectionDialog);
        deletePB->setObjectName(QString::fromUtf8("deletePB"));

        horizontalLayout_2->addWidget(deletePB);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okPB = new QPushButton(PatientSelectionDialog);
        okPB->setObjectName(QString::fromUtf8("okPB"));

        horizontalLayout->addWidget(okPB);

        cancelPB = new QPushButton(PatientSelectionDialog);
        cancelPB->setObjectName(QString::fromUtf8("cancelPB"));

        horizontalLayout->addWidget(cancelPB);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PatientSelectionDialog);

        QMetaObject::connectSlotsByName(PatientSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientSelectionDialog)
    {
        PatientSelectionDialog->setWindowTitle(QApplication::translate("PatientSelectionDialog", "Patients", nullptr));
        addPB->setText(QApplication::translate("PatientSelectionDialog", "Add", nullptr));
        editPB->setText(QApplication::translate("PatientSelectionDialog", "Edit", nullptr));
        deletePB->setText(QApplication::translate("PatientSelectionDialog", "Delete", nullptr));
        okPB->setText(QApplication::translate("PatientSelectionDialog", "OK", nullptr));
        cancelPB->setText(QApplication::translate("PatientSelectionDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientSelectionDialog: public Ui_PatientSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTSELECTIONDIALOG_H
