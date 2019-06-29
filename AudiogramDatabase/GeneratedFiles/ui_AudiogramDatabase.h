/********************************************************************************
** Form generated from reading UI file 'AudiogramDatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOGRAMDATABASE_H
#define UI_AUDIOGRAMDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudiogramDatabaseClass
{
public:
    QAction *actionAbout;
    QAction *actionNew;
    QAction *actionExit;
    QAction *actionPatients;
    QAction *actionOptions;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *newPB;
    QPushButton *editPB;
    QSpacerItem *horizontalSpacer;
    QPushButton *deletePB;
    QTableView *audiogramTV;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AudiogramDatabaseClass)
    {
        if (AudiogramDatabaseClass->objectName().isEmpty())
            AudiogramDatabaseClass->setObjectName(QString::fromUtf8("AudiogramDatabaseClass"));
        AudiogramDatabaseClass->resize(631, 405);
        actionAbout = new QAction(AudiogramDatabaseClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionNew = new QAction(AudiogramDatabaseClass);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionNew->setCheckable(false);
        actionNew->setChecked(false);
        actionNew->setEnabled(true);
        actionExit = new QAction(AudiogramDatabaseClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPatients = new QAction(AudiogramDatabaseClass);
        actionPatients->setObjectName(QString::fromUtf8("actionPatients"));
        actionOptions = new QAction(AudiogramDatabaseClass);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        centralWidget = new QWidget(AudiogramDatabaseClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newPB = new QPushButton(centralWidget);
        newPB->setObjectName(QString::fromUtf8("newPB"));

        horizontalLayout->addWidget(newPB);

        editPB = new QPushButton(centralWidget);
        editPB->setObjectName(QString::fromUtf8("editPB"));

        horizontalLayout->addWidget(editPB);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        deletePB = new QPushButton(centralWidget);
        deletePB->setObjectName(QString::fromUtf8("deletePB"));

        horizontalLayout->addWidget(deletePB);


        verticalLayout->addLayout(horizontalLayout);

        audiogramTV = new QTableView(centralWidget);
        audiogramTV->setObjectName(QString::fromUtf8("audiogramTV"));
        audiogramTV->setAlternatingRowColors(true);
        audiogramTV->setSelectionMode(QAbstractItemView::SingleSelection);
        audiogramTV->setSelectionBehavior(QAbstractItemView::SelectRows);
        audiogramTV->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        audiogramTV->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(audiogramTV);

        AudiogramDatabaseClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AudiogramDatabaseClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 631, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        AudiogramDatabaseClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(AudiogramDatabaseClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AudiogramDatabaseClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionPatients);
        menuFile->addSeparator();
        menuFile->addAction(actionOptions);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuAbout->addAction(actionAbout);

        retranslateUi(AudiogramDatabaseClass);

        QMetaObject::connectSlotsByName(AudiogramDatabaseClass);
    } // setupUi

    void retranslateUi(QMainWindow *AudiogramDatabaseClass)
    {
        AudiogramDatabaseClass->setWindowTitle(QApplication::translate("AudiogramDatabaseClass", "AudiogramDatabase", nullptr));
        actionAbout->setText(QApplication::translate("AudiogramDatabaseClass", "About", nullptr));
        actionNew->setText(QApplication::translate("AudiogramDatabaseClass", "New audiogram", nullptr));
        actionExit->setText(QApplication::translate("AudiogramDatabaseClass", "Exit", nullptr));
        actionPatients->setText(QApplication::translate("AudiogramDatabaseClass", "Edit patients", nullptr));
        actionOptions->setText(QApplication::translate("AudiogramDatabaseClass", "Options", nullptr));
        newPB->setText(QApplication::translate("AudiogramDatabaseClass", "New", nullptr));
        editPB->setText(QApplication::translate("AudiogramDatabaseClass", "Edit", nullptr));
        deletePB->setText(QApplication::translate("AudiogramDatabaseClass", "Delete", nullptr));
        menuFile->setTitle(QApplication::translate("AudiogramDatabaseClass", "File", nullptr));
        menuAbout->setTitle(QApplication::translate("AudiogramDatabaseClass", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudiogramDatabaseClass: public Ui_AudiogramDatabaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOGRAMDATABASE_H
