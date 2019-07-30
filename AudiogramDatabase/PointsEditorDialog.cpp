#include <QSpinBox>
#include "PointsEditorDialog.h"

PointsEditorDialog::PointsEditorDialog(std::vector<QPoint> points, QWidget *parent)
	: QDialog(parent), pointsModel(points)
{
	ui.setupUi(this);
	ui.pointsTV->setModel(&pointsModel);
	ui.pointsTV->setItemDelegate(&pointsDelegate);
	
	connect(ui.addPB, &QPushButton::clicked, this, &PointsEditorDialog::sAdd);
	connect(ui.deletePB, &QPushButton::clicked, this, &PointsEditorDialog::sDelete);
}

PointsEditorDialog::~PointsEditorDialog()
{}

std::vector<QPoint> PointsEditorDialog::getPoints() const
{
	return pointsModel.getPoints();
}

void PointsEditorDialog::setPoints(const std::vector<QPoint>& points)
{
	pointsModel.setPoints(points);
}

void PointsEditorDialog::sAdd()
{
	const auto& selItems = ui.pointsTV->selectionModel()->selectedIndexes();
	if (selItems.empty())
		pointsModel.insertRow(pointsModel.rowCount());
	else
		pointsModel.insertRow(selItems[0].row());
}

void PointsEditorDialog::sDelete()
{
	const auto& selItems = ui.pointsTV->selectionModel()->selectedIndexes();
	if (selItems.empty())
		return;
	const int selectedRow = selItems.front().row();
	pointsModel.removeRow(selectedRow);
}

PointsModel::PointsModel(const PointList& pts, QObject* parent)
	: QAbstractTableModel(parent), points(pts)
{}

bool PointsModel::insertRows(int position, int rows, const QModelIndex& index)
{
	if (position < 0 || points.size() < position || rows < 0)
		return false;
	beginInsertRows(QModelIndex(), position, position + rows - 1);

	if (points.empty())
		points.insert(points.begin(), rows, QPoint(1000, 0));
	else if (position == points.size())
		points.insert(points.end(), rows, QPoint(points.back().x() * 2, 0));
	else if (position == 0)
		points.insert(points.begin(), rows, QPoint(points.front().x() / 2, 0));
	else
		points.insert(points.begin() + position, rows, QPoint((
			points[position].x() + points[position - 1].x()) / 2, 0));

	endInsertRows();
	return true;
}

bool PointsModel::removeRows(int position, int rows, const QModelIndex& index)
{
	if (position < 0 || points.size() <= position || rows < 0)
		return false;
	beginRemoveRows(QModelIndex(), position, position + rows - 1);

	points.erase(points.begin() + position, points.begin() + position + rows);

	endRemoveRows();
	return true;
}

const PointsModel::PointList& PointsModel::getPoints() const
{
	return points;
}

void PointsModel::setPoints(const PointList& pts)
{
	beginResetModel();
	points = pts;
	endResetModel();
}

int PointsModel::rowCount(const QModelIndex& parent) const
{
	return parent.isValid() ? 0 : points.size();
}

int PointsModel::columnCount(const QModelIndex& parent) const
{
	return parent.isValid() ? 0 : COLUMN_COUNT;
}

QVariant PointsModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();
	int row, col;
	switch (role)
	{
	case Qt::DisplayRole:
	case Qt::EditRole:
		row = index.row();
		col = index.column();
		if (row < 0 || points.size() <= row || col < 0 || COLUMN_COUNT <= col)
			return QVariant();
		if (col == 0)
			return points[row].x();
		else
			return points[row].y();
	case Qt::TextAlignmentRole:
		return Qt::AlignVCenter | Qt::AlignLeft;
	default:
		return QVariant();
	}
}

QVariant PointsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole || orientation != Qt::Horizontal
		|| section < 0 || section > 1)
		return QVariant();
	if (section == 0)
		return tr("Frequency, Hz");
	else
		return tr("Level, dBHL");
}

Qt::ItemFlags PointsModel::flags(const QModelIndex& index) const
{
	if (!index.isValid())
		return Qt::ItemIsEnabled;
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

bool PointsModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;
	const int row = index.row(), col = index.column();
	if (row < 0 || points.size() <= row || col < 0 || COLUMN_COUNT <= col)
		return false;
	QPoint& record = points[row];

	bool ok = false;
	const int val = value.toInt(&ok);
	if (!ok)
		return false;

	if (col == 0)
		record.setX(val);
	else
		record.setY(val);

	emit dataChanged(index, index, { role });
	return true;
}

PointsDelegate::PointsDelegate(QObject* parent)
	: QStyledItemDelegate(parent)
{}

QWidget* PointsDelegate::createEditor(QWidget* parent,
	const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QSpinBox* editor = new QSpinBox(parent);
	if (index.column() == PointsModel::COLUMN_FREQUENCY)
	{
		editor->setMinimum(0);
		editor->setMaximum(20000); // Hz
	}
	else
	{
		editor->setMinimum(-10);
		editor->setMaximum(200); // dbHL
	}
	return editor;
}

void PointsDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
	QSpinBox* editorSB = static_cast<QSpinBox*>(editor);
	editorSB->setValue(index.data(Qt::EditRole).toInt());
}

void PointsDelegate::setModelData(QWidget* editor, QAbstractItemModel* model,
	const QModelIndex& index) const
{
	QSpinBox* editorSB = static_cast<QSpinBox*>(editor);
	editorSB->interpretText();
	model->setData(index, editorSB->value(), Qt::EditRole);
}

void PointsDelegate::updateEditorGeometry(QWidget* editor,
	const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	editor->setGeometry(option.rect);
}
