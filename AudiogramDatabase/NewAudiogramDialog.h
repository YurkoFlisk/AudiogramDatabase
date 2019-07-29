#pragma once

#include <QDialog>
#include "Audiogram.h"
#include "ui_NewAudiogramDialog.h"

class NewAudiogramDialog : public QDialog
{
	Q_OBJECT

public:
	NewAudiogramDialog(QColor airColor, QColor boneColor, QWidget *parent = Q_NULLPTR);
	~NewAudiogramDialog();

	static QBrush createCrossBrush(QColor color);
	// Getters
	int getPatientID() const;
	const Audiogram::EarList& getEarsInfo() const;
	Audiogram getAudiogram() const;
	const QPen& getAirPen() const;
	const QPen& getBonePen() const;
	const QBrush& getAirBrush() const;
	const QBrush& getBoneBrush() const;
	// Setters
	void setPatientID(int);
	void setEarsInfo(const Audiogram::EarList&);
	void setAudiogram(const Audiogram&);
	void setAirPen(const QPen&);
	void setBonePen(const QPen&);
	void setAirBrush(const QBrush&);
	void setBoneBrush(const QBrush&);

	void sPatientSelect();
	void sLeftEar();
	void sRightEar();
	void sSampleSelect();
private:
	bool editEarInfo(Ear& ear);
	void updateChart(QChartView* chartView, int earIdx);
	void updateCharts(int earIdx);
	void addSeries(QChart* chart, QLogValueAxis* xAxis, QValueAxis* yAxis,
		const Ear::PointList& points, QBrush pointBrush,
		QPen linePen, QScatterSeries::MarkerShape pointShape) const;

	int selectedSampleIdx;
	QPen airPen;
	QPen bonePen;
	QBrush airBrush;
	QBrush boneBrush;
	Audiogram::EarList earsInfo;
	Ui::NewAudiogramDialog ui;
};
