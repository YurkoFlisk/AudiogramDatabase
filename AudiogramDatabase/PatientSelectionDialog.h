#pragma once

#include <QDialog>
#include "ui_PatientSelectionDialog.h"

class PatientSelectionDialog : public QDialog
{
	Q_OBJECT

public:
	PatientSelectionDialog(bool selection, QWidget *parent = Q_NULLPTR);
	~PatientSelectionDialog();
	
	void sAdd();
	void sEdit();
	void sDelete();

	// Getters
	int getSelectedPatient() const;
	// Setters
	void setSelectedPatient(int);
private:
	Ui::PatientSelectionDialog ui;
	bool selection;
};
