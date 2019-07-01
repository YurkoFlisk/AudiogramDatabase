#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AudiogramDatabase.h"

class AudiogramDatabase : public QMainWindow
{
	Q_OBJECT

public:
	static constexpr char SETTINGS_FILE[] = "settings.ini";
	static constexpr char LANGUAGES_CONFIG[] = "languages.cfg";

	AudiogramDatabase(QWidget *parent = Q_NULLPTR);
	void loadConfig(void);
	void setLanguage(QString langCode);

	void sNew();
	void sExit();
	void sAbout();
	void sSettings();
	void sPatients();
private:
	Ui::AudiogramDatabaseClass ui;
};
