/********************************************************************************
** Form generated from reading UI file 'EarParamsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EARPARAMSDIALOG_H
#define UI_EARPARAMSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EarParamsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *bonePointsPB;
    QPushButton *airPointsPB;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *normalSpeechDSB;
    QLabel *label_2;
    QDoubleSpinBox *whisperSpeechDSB;
    QLabel *label_3;
    QComboBox *autophonyCB;
    QLabel *label_4;
    QComboBox *bingTestCB;
    QLabel *label_5;
    QComboBox *federiciTestCB;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *savePB;
    QPushButton *cancelPB;

    void setupUi(QDialog *EarParamsDialog)
    {
        if (EarParamsDialog->objectName().isEmpty())
            EarParamsDialog->setObjectName(QString::fromUtf8("EarParamsDialog"));
        EarParamsDialog->resize(302, 285);
        verticalLayout = new QVBoxLayout(EarParamsDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(EarParamsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(280, 0));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bonePointsPB = new QPushButton(groupBox);
        bonePointsPB->setObjectName(QString::fromUtf8("bonePointsPB"));

        horizontalLayout->addWidget(bonePointsPB);

        airPointsPB = new QPushButton(groupBox);
        airPointsPB->setObjectName(QString::fromUtf8("airPointsPB"));

        horizontalLayout->addWidget(airPointsPB);


        verticalLayout->addWidget(groupBox);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(EarParamsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        normalSpeechDSB = new QDoubleSpinBox(EarParamsDialog);
        normalSpeechDSB->setObjectName(QString::fromUtf8("normalSpeechDSB"));
        normalSpeechDSB->setDecimals(1);
        normalSpeechDSB->setSingleStep(0.100000000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, normalSpeechDSB);

        label_2 = new QLabel(EarParamsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        whisperSpeechDSB = new QDoubleSpinBox(EarParamsDialog);
        whisperSpeechDSB->setObjectName(QString::fromUtf8("whisperSpeechDSB"));
        whisperSpeechDSB->setDecimals(1);
        whisperSpeechDSB->setSingleStep(0.100000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, whisperSpeechDSB);

        label_3 = new QLabel(EarParamsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        autophonyCB = new QComboBox(EarParamsDialog);
        autophonyCB->setObjectName(QString::fromUtf8("autophonyCB"));

        formLayout->setWidget(2, QFormLayout::FieldRole, autophonyCB);

        label_4 = new QLabel(EarParamsDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        bingTestCB = new QComboBox(EarParamsDialog);
        bingTestCB->setObjectName(QString::fromUtf8("bingTestCB"));

        formLayout->setWidget(3, QFormLayout::FieldRole, bingTestCB);

        label_5 = new QLabel(EarParamsDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        federiciTestCB = new QComboBox(EarParamsDialog);
        federiciTestCB->setObjectName(QString::fromUtf8("federiciTestCB"));

        formLayout->setWidget(4, QFormLayout::FieldRole, federiciTestCB);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        savePB = new QPushButton(EarParamsDialog);
        savePB->setObjectName(QString::fromUtf8("savePB"));

        horizontalLayout_2->addWidget(savePB);

        cancelPB = new QPushButton(EarParamsDialog);
        cancelPB->setObjectName(QString::fromUtf8("cancelPB"));

        horizontalLayout_2->addWidget(cancelPB);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(EarParamsDialog);
        QObject::connect(savePB, SIGNAL(clicked()), EarParamsDialog, SLOT(accept()));
        QObject::connect(cancelPB, SIGNAL(clicked()), EarParamsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EarParamsDialog);
    } // setupUi

    void retranslateUi(QDialog *EarParamsDialog)
    {
        EarParamsDialog->setWindowTitle(QApplication::translate("EarParamsDialog", "Ear info", nullptr));
        groupBox->setTitle(QApplication::translate("EarParamsDialog", "Audiometry by conductivity", nullptr));
        bonePointsPB->setText(QApplication::translate("EarParamsDialog", "Edit bone points", nullptr));
        airPointsPB->setText(QApplication::translate("EarParamsDialog", "Edit air points", nullptr));
        label->setText(QApplication::translate("EarParamsDialog", "Normal speech (m):", nullptr));
        label_2->setText(QApplication::translate("EarParamsDialog", "Whisper speech (m):", nullptr));
        label_3->setText(QApplication::translate("EarParamsDialog", "Occlusion autophony:", nullptr));
        label_4->setText(QApplication::translate("EarParamsDialog", "Bing test:", nullptr));
        label_5->setText(QApplication::translate("EarParamsDialog", "Federici test:", nullptr));
        savePB->setText(QApplication::translate("EarParamsDialog", "Save", nullptr));
        cancelPB->setText(QApplication::translate("EarParamsDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EarParamsDialog: public Ui_EarParamsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EARPARAMSDIALOG_H
