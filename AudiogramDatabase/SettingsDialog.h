#pragma once

#include <QDialog>
#include "ui_SettingsDialog.h"

class SettingsDialog : public QDialog
{
	Q_OBJECT

public:
	static constexpr char DEFAULT_LANG[] = "en";
	inline static const QColor DEFAULT_AIR_COLOR = Qt::red;
	inline static const QColor DEFAULT_BONE_COLOR = Qt::blue;

	SettingsDialog(QWidget *parent, const QSettings& settings, const QString& langsPath);
	~SettingsDialog();
	void initControls(const QSettings& setting, const QString& langsPath);
	void dumpControls(QSettings& settings);
private:
	Ui::SettingsDialog ui;
};
