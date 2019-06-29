#pragma once

#include <QtWidgets/QDialog>
#include "ui_NewPatientDialog.h"

class NewPatientDialog : public QDialog
{
	Q_OBJECT

public:
	NewPatientDialog(QWidget* parent = Q_NULLPTR);

private:
	Ui::NewPatientDialog ui;
};
