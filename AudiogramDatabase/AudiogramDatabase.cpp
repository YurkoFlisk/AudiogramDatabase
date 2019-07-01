#include "AudiogramDatabase.h"
#include "LanguagesModel.h"
#include "SettingsDialog.h"
#include "AboutDialog.h"
#include "NewAudiogramDialog.h"
#include "PatientSelectionDialog.h"
#include <QSettings>

AudiogramDatabase::AudiogramDatabase(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	loadConfig();

	connect(ui.actionNew, QAction::triggered, this, sNew);
	connect(ui.actionExit, QAction::triggered, this, sExit);
	connect(ui.actionAbout, QAction::triggered, this, sAbout);
	connect(ui.actionOptions, QAction::triggered, this, sSettings);
	connect(ui.actionPatients, QAction::triggered, this, sPatients);
}

void AudiogramDatabase::loadConfig(void)
{
	QSettings settings(SETTINGS_FILE, QSettings::IniFormat);
	setLanguage(settings.value("lang").toString());
}

void AudiogramDatabase::setLanguage(QString langCode)
{
	QTranslator* translator = new QTranslator();
	LanguagesModel languages(LANGUAGES_CONFIG);
	QString path = languages.getPathByCode(langCode);
	translator->load(path);
	QApplication::installTranslator(translator);
}

void AudiogramDatabase::sNew()
{
	NewAudiogramDialog newAudiogramDialog(this);
	if (newAudiogramDialog.exec() != QDialog::Accepted)
		return;

}

void AudiogramDatabase::sExit()
{
	close();
}

void AudiogramDatabase::sAbout()
{
	AboutDialog aboutDialog(this);
	aboutDialog.exec();
}

void AudiogramDatabase::sSettings()
{
	QSettings settings(SETTINGS_FILE, QSettings::IniFormat);
	SettingsDialog settingsDialog(this, settings, LANGUAGES_CONFIG);
	if (settingsDialog.exec() != QDialog::Accepted)
		return;
	settingsDialog.dumpControls(settings);
}

void AudiogramDatabase::sPatients()
{
	PatientSelectionDialog patientSelectionDialog(this);
	patientSelectionDialog.exec();
}
