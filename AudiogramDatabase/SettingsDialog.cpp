#include "SettingsDialog.h"

SettingsDialog::SettingsDialog(QWidget *parent, QSettings& settings)
	: QDialog(parent)
{
	ui.setupUi(this);
	initControls(settings);
}

SettingsDialog::~SettingsDialog()
{
}

void SettingsDialog::initControls(const QSettings& settings)
{
	ui.airCP->setColor(settings.value("airCondColor", DEFAULT_AIR_COLOR).value<QColor>());
	ui.boneCP->setColor(settings.value("boneCondColor", DEFAULT_BONE_COLOR).value<QColor>());
	ui.languageCB->setCurrentIndex(settings.value("lang", DEFAULT_LANG));
}

void SettingsDialog::dumpControls(QSettings& settings)
{
	settings.setValue("airCondColor", ui.airCP->getColor());
	settings.setValue("boneCondColor", ui.boneCP->getColor());
	settings.setValue("lang", ui.languageCB->currentData());
}
