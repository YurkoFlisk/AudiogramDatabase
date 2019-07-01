#pragma once

#include <QtWidgets/QDialog>
#include "ui_NewPatientDialog.h"
#include "Audiogram.h"

class NewPatientDialog : public QDialog
{
	Q_OBJECT

public:
	NewPatientDialog(QWidget* parent = Q_NULLPTR);
	// Getters
	QDate getBirthday() const;
	QString getFullName() const;
	QString getProfession() const;
	QString getAddress() const;
	Patient getPatientInfo() const;
	// Setters
	void setBirthday(const QDate&);
	void setFullName(const QString&);
	void setProfession(const QString&);
	void setAddress(const QString&);
	void setPatientInfo(const Patient&);
private:
	Ui::NewPatientDialog ui;
};
