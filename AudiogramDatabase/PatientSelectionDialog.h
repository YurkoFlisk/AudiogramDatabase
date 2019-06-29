#pragma once

#include <QDialog>
#include "ui_PatientSelectionDialog.h"

class PatientSelectionDialog : public QDialog
{
	Q_OBJECT

public:
	PatientSelectionDialog(QWidget *parent = Q_NULLPTR);
	~PatientSelectionDialog();

private:
	Ui::PatientSelectionDialog ui;
};
