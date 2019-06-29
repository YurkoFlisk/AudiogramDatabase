#pragma once

#include <QDialog>
#include "ui_EarParamsDialog.h"

class EarParamsDialog : public QDialog
{
	Q_OBJECT

public:
	EarParamsDialog(QWidget *parent = Q_NULLPTR);
	~EarParamsDialog();

private:
	Ui::EarParamsDialog ui;
};
