#include "AudiogramDatabase.h"
#include "SettingsDialog.h"
#include <qsettings.h>

AudiogramDatabase::AudiogramDatabase(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	loadConfig();
}

void AudiogramDatabase::loadConfig(void)
{
	QSettings settings(SETTINGS_FILE, QSettings::IniFormat);
	settings.value();
}
