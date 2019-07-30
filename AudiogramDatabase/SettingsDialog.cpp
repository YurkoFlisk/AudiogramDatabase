#include "SettingsDialog.h"
#include "LanguagesModel.h"
#include "Audiogram.h"

SettingsDialog::SettingsDialog(QWidget *parent, const QSettings& settings, const QString& langsPath)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.cancelPB, &QPushButton::clicked, this, &SettingsDialog::sCancel);
	connect(ui.okPB, &QPushButton::clicked, this, &SettingsDialog::sOk);

	initControls(settings, langsPath);
}

SettingsDialog::~SettingsDialog()
{
}

void SettingsDialog::initControls(const QSettings& settings, const QString& langsPath)
{
	ui.airCP->setColor(settings.value("firstSampColor", DEFAULT_SAMP1_COLOR).value<QColor>());
	ui.boneCP->setColor(settings.value("secondSampColor", DEFAULT_SAMP2_COLOR).value<QColor>());

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

void SettingsDialog::sOk()
{
	accept();
}

void SettingsDialog::sCancel()
{
	reject();
}
