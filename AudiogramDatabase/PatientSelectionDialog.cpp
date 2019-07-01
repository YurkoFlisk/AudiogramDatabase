#include "PatientSelectionDialog.h"

PatientSelectionDialog::PatientSelectionDialog(bool selection, QWidget *parent)
	: QDialog(parent), selection(selection)
{
	ui.setupUi(this);

	connect(ui.addPB, QPushButton::clicked, this, sAdd);
	connect(ui.editPB, QPushButton::clicked, this, sEdit);
	connect(ui.deletePB, QPushButton::clicked, this, sDelete);
}

PatientSelectionDialog::~PatientSelectionDialog()
{
}

void PatientSelectionDialog::sAdd()
{

}

void PatientSelectionDialog::sEdit()
{

}

void PatientSelectionDialog::sDelete()
{

}

int PatientSelectionDialog::getSelectedPatient() const
{
	const auto& selRows = ui.patientsTV->selectionModel()->selectedRows();
	if (selRows.empty())
		return -1;
	const int row = selRows.front().row();
	return ui.patientsTV->model()->data(ui.patientsTV->model()->index(row, 0)).toInt();
}

void PatientSelectionDialog::setSelectedPatient(int idx)
{
	auto indexes = ui.patientsTV->model();
	ui.patientsTV->selectRow(patientRow);
}
