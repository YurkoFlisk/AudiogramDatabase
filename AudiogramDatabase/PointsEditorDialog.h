#pragma once

#include <QDialog>
#include "ui_PointsEditorDialog.h"

class PointsEditorDialog : public QDialog
{
	Q_OBJECT

public:
	PointsEditorDialog(std::vector<QPoint> points, QWidget *parent = Q_NULLPTR);
	~PointsEditorDialog();

	std::vector<QPoint> getPoints() const;
	void setPoints(const std::vector<QPoint>& points);

	void sAdd();
	void sDelete();
private:
	Ui::PointsEditorDialog ui;
};
