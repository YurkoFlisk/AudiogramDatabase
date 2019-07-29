#pragma once

#include <QDialog>
#include <QStyledItemDelegate>
#include "ui_PointsEditorDialog.h"

class PointsModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	static constexpr int COLUMN_FREQUENCY = 0;
	static constexpr int COLUMN_LEVEL = 1;
	static constexpr int COLUMN_COUNT = 2;
	using PointList = std::vector<QPoint>;

	PointsModel(const PointList& points, QObject* parent = nullptr);
	
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
	bool insertRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
	bool removeRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
	// Getters
	const PointList& getPoints() const;
	// Setters
	void setPoints(const PointList&);
private:
	PointList points;
};

class PointsDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	PointsDelegate(QObject* parent = nullptr);
	QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;
	void setEditorData(QWidget* editor, const QModelIndex& index) const override;
	void setModelData(QWidget* editor, QAbstractItemModel* model,
		const QModelIndex& index) const override;
	void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;
};

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
	PointsModel pointsModel;
	PointsDelegate pointsDelegate;
	Ui::PointsEditorDialog ui;
};
