#pragma once

#include <QDialog>
#include "ui_NewAudiogramDialog.h"

class NewAudiogramDialog : public QDialog
{
	Q_OBJECT

public:
	NewAudiogramDialog(QWidget *parent = Q_NULLPTR);
	~NewAudiogramDialog();

private:
	Ui::NewAudiogramDialog ui;
};
