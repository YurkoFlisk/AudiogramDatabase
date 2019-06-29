/********************************************************************************
** Form generated from reading UI file 'NewPatientDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPATIENTDIALOG_H
#define UI_NEWPATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewPatientDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameLE;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *professionLE;
    QLabel *label_4;
    QLineEdit *addressLE;
    QDateEdit *birthdayDE;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okPB;
    QPushButton *cancelPB;

    void setupUi(QDialog *NewPatientDialog)
    {
        if (NewPatientDialog->objectName().isEmpty())
            NewPatientDialog->setObjectName(QString::fromUtf8("NewPatientDialog"));
        NewPatientDialog->resize(322, 188);
        verticalLayout = new QVBoxLayout(NewPatientDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setHorizontalSpacing(15);
        label = new QLabel(NewPatientDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nameLE = new QLineEdit(NewPatientDialog);
        nameLE->setObjectName(QString::fromUtf8("nameLE"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLE);

        label_2 = new QLabel(NewPatientDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setTextFormat(Qt::AutoText);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(NewPatientDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        professionLE = new QLineEdit(NewPatientDialog);
        professionLE->setObjectName(QString::fromUtf8("professionLE"));

        formLayout->setWidget(2, QFormLayout::FieldRole, professionLE);

        label_4 = new QLabel(NewPatientDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        addressLE = new QLineEdit(NewPatientDialog);
        addressLE->setObjectName(QString::fromUtf8("addressLE"));

        formLayout->setWidget(3, QFormLayout::FieldRole, addressLE);

        birthdayDE = new QDateEdit(NewPatientDialog);
        birthdayDE->setObjectName(QString::fromUtf8("birthdayDE"));
        birthdayDE->setCalendarPopup(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, birthdayDE);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okPB = new QPushButton(NewPatientDialog);
        okPB->setObjectName(QString::fromUtf8("okPB"));

        hboxLayout->addWidget(okPB);

        cancelPB = new QPushButton(NewPatientDialog);
        cancelPB->setObjectName(QString::fromUtf8("cancelPB"));

        hboxLayout->addWidget(cancelPB);


        verticalLayout->addLayout(hboxLayout);


        retranslateUi(NewPatientDialog);
        QObject::connect(okPB, SIGNAL(clicked()), NewPatientDialog, SLOT(accept()));
        QObject::connect(cancelPB, SIGNAL(clicked()), NewPatientDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewPatientDialog);
    } // setupUi

    void retranslateUi(QDialog *NewPatientDialog)
    {
        NewPatientDialog->setWindowTitle(QApplication::translate("NewPatientDialog", "New Patient Dialog", nullptr));
        label->setText(QApplication::translate("NewPatientDialog", "Full name:", nullptr));
        label_2->setText(QApplication::translate("NewPatientDialog", "Birthday:", nullptr));
        label_3->setText(QApplication::translate("NewPatientDialog", "Profession:", nullptr));
        label_4->setText(QApplication::translate("NewPatientDialog", "Address:", nullptr));
        okPB->setText(QApplication::translate("NewPatientDialog", "OK", nullptr));
        cancelPB->setText(QApplication::translate("NewPatientDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewPatientDialog: public Ui_NewPatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPATIENTDIALOG_H
