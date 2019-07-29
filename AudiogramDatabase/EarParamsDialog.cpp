#include "EarParamsDialog.h"
#include "PointsEditorDialog.h"

EarParamsDialog::EarParamsDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	ui.autophonyCB->addItem(tr("Not set"), NOT_SET);
	ui.autophonyCB->addItem(tr("Yes"), YES);
	ui.autophonyCB->addItem(tr("No"), NO);
	ui.autophonyCB->setCurrentIndex(0);

	ui.bingTestCB->addItem(tr("Not set"), NOT_SET);
	ui.bingTestCB->addItem(tr("Positive"), POSITIVE);
	ui.bingTestCB->addItem(tr("Negative"), NEGATIVE);
	ui.bingTestCB->setCurrentIndex(0);

	ui.federiciTestCB->addItem(tr("Not set"), NOT_SET);
	ui.federiciTestCB->addItem(tr("Positive (T > M)"), POSITIVE);
	ui.federiciTestCB->addItem(tr("Negative (T < M)"), NEGATIVE);
	ui.federiciTestCB->setCurrentIndex(0);

	connect(ui.airPointsPB, &QPushButton::clicked, this, &EarParamsDialog::sAirPoints);
	connect(ui.bonePointsPB, &QPushButton::clicked, this, &EarParamsDialog::sBonePoints);
}

EarParamsDialog::~EarParamsDialog()
{
}

void EarParamsDialog::updateCharts()
{
	// Currently, no charts in the dialog
}

std::vector<QPoint> EarParamsDialog::getAirPoints() const
{
	return airPoints;
}

std::vector<QPoint> EarParamsDialog::getBonePoints() const
{
	return bonePoints;
}

double EarParamsDialog::getNormalSpeechThreshold() const
{
	return ui.normalSpeechDSB->value();
}

double EarParamsDialog::getWhisperSpeechThreshold() const
{
	return ui.whisperSpeechDSB->value();
}

TestResult EarParamsDialog::getAutophony() const
{
	return TestResult(ui.autophonyCB->currentData().toInt());
}

TestResult EarParamsDialog::getBingTest() const
{
	return TestResult(ui.bingTestCB->currentData().toInt());
}

TestResult EarParamsDialog::getFedericiTest() const
{
	return TestResult(ui.federiciTestCB->currentData().toInt());
}

Ear EarParamsDialog::getEarInfo() const
{
	Ear ret;
	ret.airCondPoints = getAirPoints();
	ret.boneCondPoints = getBonePoints();
	ret.normalSpeechThreshold = getNormalSpeechThreshold();
	ret.whisperSpeechThreshold = getWhisperSpeechThreshold();
	ret.occlusionAutophony = getAutophony();
	ret.bingTest = getBingTest();
	ret.federiciTest = getFedericiTest();
	return ret;
}

void EarParamsDialog::setAirPoints(const std::vector<QPoint>& pts)
{
	airPoints = pts;
}

void EarParamsDialog::setBonePoints(const std::vector<QPoint>& pts)
{
	bonePoints = pts;
}

void EarParamsDialog::setNormalSpeechThreshold(double sTH)
{
	sTH = std::clamp(sTH, ui.normalSpeechDSB->minimum(), ui.normalSpeechDSB->maximum());
	ui.normalSpeechDSB->setValue(sTH);
}

void EarParamsDialog::setWhisperSpeechThreshold(double sTH)
{
	sTH = std::clamp(sTH, ui.whisperSpeechDSB->minimum(), ui.whisperSpeechDSB->maximum());
	ui.whisperSpeechDSB->setValue(sTH);
}

void EarParamsDialog::setAutophony(TestResult tr)
{
	ui.autophonyCB->setCurrentIndex(ui.autophonyCB->findData(tr));
}

void EarParamsDialog::setBingTest(TestResult tr)
{
	ui.bingTestCB->setCurrentIndex(ui.bingTestCB->findData(tr));
}

void EarParamsDialog::setFedericiTest(TestResult tr)
{
	ui.federiciTestCB->setCurrentIndex(ui.federiciTestCB->findData(tr));
}

void EarParamsDialog::setEarInfo(const Ear& ear)
{
	setAirPoints(ear.airCondPoints);
	setBonePoints(ear.boneCondPoints);
	setNormalSpeechThreshold(ear.normalSpeechThreshold);
	setWhisperSpeechThreshold(ear.whisperSpeechThreshold);
	setAutophony(ear.occlusionAutophony);
	setBingTest(ear.bingTest);
	setFedericiTest(ear.federiciTest);
}

void EarParamsDialog::sAirPoints()
{
	PointsEditorDialog pointsEditor(airPoints, this);
	if (pointsEditor.exec() != QDialog::Accepted)
		return;
	airPoints = pointsEditor.getPoints();
	updateCharts();
}

void EarParamsDialog::sBonePoints()
{
	PointsEditorDialog pointsEditor(bonePoints, this);
	if (pointsEditor.exec() != QDialog::Accepted)
		return;
	bonePoints = pointsEditor.getPoints();
	updateCharts();
}
