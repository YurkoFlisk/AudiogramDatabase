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

	connect(ui.newPB, &QPushButton::clicked, this, &AudiogramDatabase::sNew);
	connect(ui.editPB, &QPushButton::clicked, this, &AudiogramDatabase::sEdit);
	connect(ui.deletePB, &QPushButton::clicked, this, &AudiogramDatabase::sDelete);
	connect(ui.actionExit, &QAction::triggered, this, &AudiogramDatabase::sExit);
	connect(ui.actionAbout, &QAction::triggered, this, &AudiogramDatabase::sAbout);
	connect(ui.actionSettings, &QAction::triggered, this, &AudiogramDatabase::sSettings);
	connect(ui.actionPatients, &QAction::triggered, this, &AudiogramDatabase::sPatients);
}

AudiogramDatabase::~AudiogramDatabase()
{
	delete settings;
}

void AudiogramDatabase::loadConfig(void)
{
	settings = new QSettings(SETTINGS_FILE, QSettings::IniFormat);
	setLanguage(settings->value("lang").toString());
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
	const QColor firstSampColor = settings->value("firstSampColor", DEFAULT_SAMP1_COLOR).value<QColor>();
	const QColor secondSampColor = settings->value("secondSampColor", DEFAULT_SAMP2_COLOR).value<QColor>();
	NewAudiogramDialog newAudiogramDialog(firstSampColor,secondSampColor, this);
	if (newAudiogramDialog.exec() != QDialog::Accepted)
		return;

}

void AudiogramDatabase::sEdit()
{

}

void AudiogramDatabase::sDelete()
{

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
	SettingsDialog settingsDialog(this, *settings, LANGUAGES_CONFIG);
	if (settingsDialog.exec() != QDialog::Accepted)
		return;
	settingsDialog.dumpControls(*settings);
	settings->sync();
}

void AudiogramDatabase::sPatients()
{
	PatientSelectionDialog patientSelectionDialog(this);
	patientSelectionDialog.exec();
}
