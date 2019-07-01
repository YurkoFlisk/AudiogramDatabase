#pragma once

#include <QDialog>
#include "ui_EarParamsDialog.h"
#include "Audiogram.h"

class EarParamsDialog : public QDialog
{
	Q_OBJECT

public:
	EarParamsDialog(QWidget *parent = Q_NULLPTR);
	~EarParamsDialog();

	void updateCharts();
	// Getters
	std::vector<QPoint> getAirPoints() const;
	std::vector<QPoint> getBonePoints() const;
	double getNormalSpeechThreshold() const;
	double getWhisperSpeechThreshold() const;
	TestResult getAutophony() const;
	TestResult getBingTest() const;
	TestResult getFedericiTest() const;
	Ear getEarInfo() const;
	// Setters
	void setAirPoints(const std::vector<QPoint>&);
	void setBonePoints(const std::vector<QPoint>&);
	void setNormalSpeechThreshold(double);
	void setWhisperSpeechThreshold(double);
	void setAutophony(TestResult);
	void setBingTest(TestResult);
	void setFedericiTest(TestResult);
	void setEarInfo(const Ear&);

	void sAirPoints();
	void sBonePoints();
private:
	Ui::EarParamsDialog ui;
	std::vector<QPoint> airPoints;
	std::vector<QPoint> bonePoints;
};
