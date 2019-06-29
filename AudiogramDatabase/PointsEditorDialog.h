#pragma once

#include <QDialog>
#include "ui_PointsEditorDialog.h"

class PointsEditorDialog : public QDialog
{
	Q_OBJECT

public:
	PointsEditorDialog(QWidget *parent = Q_NULLPTR);
	~PointsEditorDialog();

private:
	Ui::PointsEditorDialog ui;
};
