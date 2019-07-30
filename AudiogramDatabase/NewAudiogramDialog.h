#pragma once

#include <QDialog>
#include "Audiogram.h"
#include "ui_NewAudiogramDialog.h"

class GeneralizedLogTicker : public QCPAxisTicker
{
	Q_GADGET

public:
	GeneralizedLogTicker(qreal origin = 1, qreal base = 2, int subTickCount = 1);
	QVector<double> createTickVector(double tickStep, const QCPRange& range) override;
	int getSubTickCount(double tickStep) override;
private:
	qreal origin;
	qreal base;
	int subTickCount;
};

class NewAudiogramDialog : public QDialog
{
	Q_OBJECT

public:
	static constexpr int COND_AIR = 0;
	static constexpr int COND_BONE = 1;

	NewAudiogramDialog(QColor firstColor, QColor secondColor, QWidget *parent = Q_NULLPTR);
	~NewAudiogramDialog();

	// Getters
	int getPatientID() const;
	const Audiogram::EarList& getEarsInfo() const;
	Audiogram getAudiogram() const;
	const QPen& getAirPen(int sample) const;
	const QPen& getBonePen(int sample) const;
	// Setters
	void setPatientID(int);
	void setEarsInfo(const Audiogram::EarList&);
	void setAudiogram(const Audiogram&);
	void setAirPen(int sample, const QPen&);
	void setBonePen(int sample, const QPen&);

	void sPatientSelect();
	void sLeftEar();
	void sRightEar();
	void sSampleSelect();
private:
	constexpr int getGraphIndex(int sample, int conductivity);

	bool editEarInfo(Ear& ear);
	void setGraphData(QCPGraph* graph, const Ear::PointList& points);
	void updateChart(QCustomPlot* chart, int earIdx);
	void updateCharts(int earIdx);

	int selectedSampleIdx;
	QPen airPen[Audiogram::NUM_SAMPLES];
	QPen bonePen[Audiogram::NUM_SAMPLES];
	Audiogram::EarList earsInfo;
	Ui::NewAudiogramDialog ui;
};
