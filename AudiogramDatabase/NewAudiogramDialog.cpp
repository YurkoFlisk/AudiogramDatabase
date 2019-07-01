#include "NewAudiogramDialog.h"
#include "PatientSelectionDialog.h"
#include "EarParamsDialog.h"

NewAudiogramDialog::NewAudiogramDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.patientSelectPB, QPushButton::clicked, this, &NewAudiogramDialog::sPatientSelect);
	connect(ui.leftEarPB, QPushButton::clicked, this, &NewAudiogramDialog::sLeftEar);
	connect(ui.rightEarPB, QPushButton::clicked, this, &NewAudiogramDialog::sRightEar);
	connect(ui.firstSampleRB, QRadioButton::clicked, this, &NewAudiogramDialog::sSampleSelect);
	connect(ui.secondSampleRB, QRadioButton::clicked, this, &NewAudiogramDialog::sSampleSelect);
}

NewAudiogramDialog::~NewAudiogramDialog()
{
}

void NewAudiogramDialog::sPatientSelect()
{
	PatientSelectionDialog patientSel(true, this);
	patientSel.setSelectedPatient(ui.patientIDLE->text().toInt());
	if (patientSel.exec() != QDialog::Accepted)
		return;
	ui.patientIDLE->setText(QString::number(patientSel.getSelectedPatient()));
}

void NewAudiogramDialog::sLeftEar()
{
	EarParamsDialog earParams(this);
	if (earParams.exec() != QDialog::Accepted)
		return;

}

void NewAudiogramDialog::sRightEar()
{
	EarParamsDialog earParams(this);
	if (earParams.exec() != QDialog::Accepted)
		return;

}

void NewAudiogramDialog::sSampleSelect()
{
	if (ui.firstSampleRB->isChecked())
	{

	}
	else
	{

	}
}
