#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AudiogramDatabase.h"

class AudiogramDatabase : public QMainWindow
{
	Q_OBJECT

public:
	static constexpr char SETTINGS_FILE[] = "settings.ini";

	AudiogramDatabase(QWidget *parent = Q_NULLPTR);
	void loadConfig(void);

private:
	Ui::AudiogramDatabaseClass ui;
};
