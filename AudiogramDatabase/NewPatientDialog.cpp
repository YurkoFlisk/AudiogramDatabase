#include "NewPatientDialog.h"

NewPatientDialog::NewPatientDialog(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

QDate NewPatientDialog::getBirthday() const
{
	return ui.birthdayDE->date();
}

QString NewPatientDialog::getFullName() const
{
	return ui.nameLE->text();
}

QString NewPatientDialog::getProfession() const
{
	return ui.professionLE->text();
}

QString NewPatientDialog::getAddress() const
{
	return ui.addressLE->text();
}

Patient NewPatientDialog::getPatientInfo() const
{
	return Patient(
		getBirthday(),
		getFullName(),
		getProfession(),
		getAddress()
	);
}

void NewPatientDialog::setBirthday(const QDate& date)
{
	ui.birthdayDE->setDate(date);
}

void NewPatientDialog::setFullName(const QString& name)
{
	ui.nameLE->setText(name);
}

void NewPatientDialog::setProfession(const QString& prefession)
{
	ui.professionLE->setText(prefession);
}

void NewPatientDialog::setAddress(const QString& address)
{
	ui.addressLE->setText(address);
}

void NewPatientDialog::setPatientInfo(const Patient& patient)
{
	setBirthday(patient.birthday);
	setFullName(patient.fullName);
	setProfession(patient.profession);
	setAddress(patient.address);
}
