/********************************************************************************
** Form generated from reading UI file 'NewAudiogramDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWAUDIOGRAMDIALOG_H
#define UI_NEWAUDIOGRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_NewAudiogramDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QChartView *leftEarChart;
    QChartView *rightEarChart;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *patientIDLE;
    QPushButton *patientSelectPB;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *firstSampleRB;
    QRadioButton *secondSampleRB;
    QVBoxLayout *verticalLayout;
    QPushButton *leftEarPB;
    QPushButton *rightEarPB;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okPB;
    QPushButton *cancelPB;

    void setupUi(QDialog *NewAudiogramDialog)
    {
        if (NewAudiogramDialog->objectName().isEmpty())
            NewAudiogramDialog->setObjectName(QString::fromUtf8("NewAudiogramDialog"));
        NewAudiogramDialog->resize(771, 410);
        verticalLayout_2 = new QVBoxLayout(NewAudiogramDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leftEarChart = new QChartView(NewAudiogramDialog);
        leftEarChart->setObjectName(QString::fromUtf8("leftEarChart"));

        horizontalLayout->addWidget(leftEarChart);

        rightEarChart = new QChartView(NewAudiogramDialog);
        rightEarChart->setObjectName(QString::fromUtf8("rightEarChart"));

        horizontalLayout->addWidget(rightEarChart);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox = new QGroupBox(NewAudiogramDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        patientIDLE = new QLineEdit(groupBox);
        patientIDLE->setObjectName(QString::fromUtf8("patientIDLE"));

        horizontalLayout_2->addWidget(patientIDLE);

        patientSelectPB = new QPushButton(groupBox);
        patientSelectPB->setObjectName(QString::fromUtf8("patientSelectPB"));

        horizontalLayout_2->addWidget(patientSelectPB);


        horizontalLayout_4->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        groupBox_5 = new QGroupBox(NewAudiogramDialog);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        firstSampleRB = new QRadioButton(groupBox_5);
        firstSampleRB->setObjectName(QString::fromUtf8("firstSampleRB"));

        horizontalLayout_5->addWidget(firstSampleRB);

        secondSampleRB = new QRadioButton(groupBox_5);
        secondSampleRB->setObjectName(QString::fromUtf8("secondSampleRB"));

        horizontalLayout_5->addWidget(secondSampleRB);


        horizontalLayout_4->addWidget(groupBox_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        leftEarPB = new QPushButton(NewAudiogramDialog);
        leftEarPB->setObjectName(QString::fromUtf8("leftEarPB"));

        verticalLayout->addWidget(leftEarPB);

        rightEarPB = new QPushButton(NewAudiogramDialog);
        rightEarPB->setObjectName(QString::fromUtf8("rightEarPB"));

        verticalLayout->addWidget(rightEarPB);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        okPB = new QPushButton(NewAudiogramDialog);
        okPB->setObjectName(QString::fromUtf8("okPB"));

        horizontalLayout_3->addWidget(okPB);

        cancelPB = new QPushButton(NewAudiogramDialog);
        cancelPB->setObjectName(QString::fromUtf8("cancelPB"));

        horizontalLayout_3->addWidget(cancelPB);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(NewAudiogramDialog);
        QObject::connect(okPB, SIGNAL(clicked()), NewAudiogramDialog, SLOT(accept()));
        QObject::connect(cancelPB, SIGNAL(clicked()), NewAudiogramDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewAudiogramDialog);
    } // setupUi

    void retranslateUi(QDialog *NewAudiogramDialog)
    {
        NewAudiogramDialog->setWindowTitle(QApplication::translate("NewAudiogramDialog", "NewAudiogramDialog", nullptr));
        groupBox->setTitle(QApplication::translate("NewAudiogramDialog", "Patient selection", nullptr));
        label->setText(QApplication::translate("NewAudiogramDialog", "Patient ID:", nullptr));
        patientSelectPB->setText(QApplication::translate("NewAudiogramDialog", "Select", nullptr));
        groupBox_5->setTitle(QApplication::translate("NewAudiogramDialog", "Selected sample", nullptr));
        firstSampleRB->setText(QApplication::translate("NewAudiogramDialog", "First", nullptr));
        secondSampleRB->setText(QApplication::translate("NewAudiogramDialog", "Second", nullptr));
        leftEarPB->setText(QApplication::translate("NewAudiogramDialog", "Edit LEFT ear", nullptr));
        rightEarPB->setText(QApplication::translate("NewAudiogramDialog", "Edit RIGHT ear", nullptr));
        okPB->setText(QApplication::translate("NewAudiogramDialog", "OK", nullptr));
        cancelPB->setText(QApplication::translate("NewAudiogramDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewAudiogramDialog: public Ui_NewAudiogramDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWAUDIOGRAMDIALOG_H
