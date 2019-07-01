#include "PointsEditorDialog.h"

PointsEditorDialog::PointsEditorDialog(std::vector<QPoint> points, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	ui.pointsTW->setColumnCount(2);
	ui.pointsTW->setHorizontalHeaderLabels(QStringList{tr("Frequency (Hz)"), tr("Level (dbHL)")});
	setPoints(points);
	
	connect(ui.addPB, QPushButton::clicked, this, sAdd);
	connect(ui.deletePB, QPushButton::clicked, this, sDelete);
}

PointsEditorDialog::~PointsEditorDialog()
{
}

std::vector<QPoint> PointsEditorDialog::getPoints() const
{
	auto pointsModel = ui.pointsTW->model();
	std::vector<QPoint> ret(pointsModel->rowCount());
	for (int i = 0; i < ret.size(); ++i)
	{
		ret[i].setX(pointsModel->data(pointsModel->index(i, 0)).toInt());
		ret[i].setY(pointsModel->data(pointsModel->index(i, 1)).toInt());
	}
	return ret;
}

void PointsEditorDialog::setPoints(const std::vector<QPoint>& points)
{
	ui.pointsTW->clearContents();
	auto pointsModel = ui.pointsTW->model();
	for (int i = 0; i < points.size(); ++i)
	{
		pointsModel->insertRow(i);
		pointsModel->setData(pointsModel->index(i, 0), points[i].x());
		pointsModel->setData(pointsModel->index(i, 1), points[i].y());
	}
}

void PointsEditorDialog::sAdd()
{
	auto selItems = ui.pointsTW->selectedItems();
	if (selItems.empty())
		ui.pointsTW->insertRow(ui.pointsTW->rowCount());
	else
		ui.pointsTW->insertRow(selItems[0]->row());
}

void PointsEditorDialog::sDelete()
{
	const int selectedRow = ui.pointsTW->selectedItems()[0]->row();
	ui.pointsTW->removeRow(selectedRow);
}
