#include "SettingsDialog.h"
#include "LanguagesModel.h"

SettingsDialog::SettingsDialog(QWidget *parent, const QSettings& settings, const QString& langsPath)
	: QDialog(parent)
{
	ui.setupUi(this);
	initControls(settings, langsPath);
}

SettingsDialog::~SettingsDialog()
{
}

void SettingsDialog::initControls(const QSettings& settings, const QString& langsPath)
{
	ui.airCP->setColor(settings.value("airCondColor", DEFAULT_AIR_COLOR).value<QColor>());
	ui.boneCP->setColor(settings.value("boneCondColor", DEFAULT_BONE_COLOR).value<QColor>());

	const QString langCode = settings.value("lang", DEFAULT_LANG).toString();
	LanguagesModel* langsModel = new LanguagesModel(langsPath, this);
	ui.languageCB->setModel(langsModel);
	ui.languageCB->setCurrentIndex(langsModel->getRowByCode(langCode));
}

void SettingsDialog::dumpControls(QSettings& settings)
{
	settings.setValue("airCondColor", ui.airCP->getColor());
	settings.setValue("boneCondColor", ui.boneCP->getColor());
	settings.setValue("lang", ui.languageCB->currentData());
}
