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

	SettingsDialog(QWidget *parent, QSettings& settings);
	~SettingsDialog();
	void initControls(const QSettings& settings);
	void dumpControls(QSettings& settings);
private:
	Ui::SettingsDialog ui;
};
