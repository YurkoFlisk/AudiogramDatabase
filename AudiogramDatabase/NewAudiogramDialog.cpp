#include "NewAudiogramDialog.h"
#include "PatientSelectionDialog.h"
#include "EarParamsDialog.h"

GeneralizedLogTicker::GeneralizedLogTicker(qreal origin, qreal base, int subTickCount)
	: origin(origin), base(base), subTickCount(subTickCount)
{}

QVector<double> GeneralizedLogTicker::createTickVector(double tickStep, const QCPRange& range)
{
	const int lowerExp = floor(log(range.lower / origin) / log(base));
	const int upperExp = ceil(log(range.upper / origin) / log(base));
	QVector<double> ret;
	for (int i = lowerExp; i <= upperExp; ++i)
		ret.push_back(origin * std::pow(base, i));
	return ret;
}

int GeneralizedLogTicker::getSubTickCount(double tickStep)
{
	return subTickCount;
}

NewAudiogramDialog::NewAudiogramDialog(QColor firstColor, QColor secondColor, QWidget *parent)
	: QDialog(parent), selectedSampleIdx(0)
{
	ui.setupUi(this);
	QValidator* idValidator = new QIntValidator(0, 999999999, this);
	ui.patientIDLE->setValidator(idValidator);
	ui.firstSampleRB->setChecked(true);

	airPen[0] = QPen(firstColor, 2, Qt::SolidLine);
	airPen[1] = QPen(secondColor, 2, Qt::SolidLine);
	bonePen[0] = QPen(firstColor, 2, Qt::DashLine);
	bonePen[1] = QPen(secondColor, 2, Qt::DashLine);
	auto xTicker = QSharedPointer<GeneralizedLogTicker>(new GeneralizedLogTicker(1000));
	auto yTicker = QSharedPointer<QCPAxisTickerFixed>(new QCPAxisTickerFixed);
	yTicker->setTickStep(10);
	yTicker->setScaleStrategy(QCPAxisTickerFixed::ssNone);
	for (auto chart : { ui.leftEarCV, ui.rightEarCV })
	{
		chart->yAxis->setRangeReversed(true);

		chart->xAxis->setScaleType(QCPAxis::stLogarithmic);
		chart->yAxis->setScaleType(QCPAxis::stLinear);
		chart->xAxis->setTicker(xTicker);
		chart->yAxis->setTicker(yTicker);
		// Range endpoints are adjusted because major ticks should fit comfortably inside the range
		chart->xAxis->setRange(
			Audiogram::DEFAULT_MIN_FREQUENCY * 0.9,
			Audiogram::DEFAULT_MAX_FREQUENCY * 1.1);
		chart->yAxis->setRange(
			Audiogram::DEFAULT_MIN_LEVEL - 5,
			Audiogram::DEFAULT_MAX_LEVEL + 5);
		chart->xAxis->setLabel(tr("Frequency (Hz)"));
		chart->yAxis->setLabel(tr("Level (dbHL)"));
	}

	connect(ui.patientSelectPB, &QPushButton::clicked, this, &NewAudiogramDialog::sPatientSelect);
	connect(ui.leftEarPB, &QPushButton::clicked, this, &NewAudiogramDialog::sLeftEar);
	connect(ui.rightEarPB, &QPushButton::clicked, this, &NewAudiogramDialog::sRightEar);
	connect(ui.firstSampleRB, &QRadioButton::clicked, this, &NewAudiogramDialog::sSampleSelect);
	connect(ui.secondSampleRB, &QRadioButton::clicked, this, &NewAudiogramDialog::sSampleSelect);
}

NewAudiogramDialog::~NewAudiogramDialog()
{
}

int NewAudiogramDialog::getPatientID() const
{
	return ui.patientIDLE->text().toInt();
}

const Audiogram::EarList& NewAudiogramDialog::getEarsInfo() const
{
	return earsInfo;
}

Audiogram NewAudiogramDialog::getAudiogram() const
{
	return Audiogram(
		getPatientID(),
		getEarsInfo()
	);
}

const QPen& NewAudiogramDialog::getAirPen(int sample) const
{
	return airPen[sample];
}

const QPen& NewAudiogramDialog::getBonePen(int sample) const
{
	return bonePen[sample];
}

void NewAudiogramDialog::setPatientID(int id)
{
	ui.patientIDLE->setText(QString::number(id));
}

void NewAudiogramDialog::setEarsInfo(const Audiogram::EarList& ears)
{
	earsInfo = ears;
	updateCharts(Audiogram::BOTH_EARS);
}

void NewAudiogramDialog::setAudiogram(const Audiogram& ag)
{
	setPatientID(ag.patientID);
	setEarsInfo(ag.earsData);
}

void NewAudiogramDialog::setAirPen(int sample, const QPen& pen)
{
	airPen[sample] = pen;
}

void NewAudiogramDialog::setBonePen(int sample, const QPen& pen)
{
	bonePen[sample] = pen;
}

void NewAudiogramDialog::sPatientSelect()
{
	PatientSelectionDialog patientSel(true, this);
	patientSel.setSelectedPatient(ui.patientIDLE->text().toInt());
	if (patientSel.exec() != QDialog::Accepted)
		return;
	ui.patientIDLE->setText(QString::number(patientSel.getSelectedPatient()));
}

void NewAudiogramDialog::sLeftEar()
{
	if (editEarInfo(earsInfo[selectedSampleIdx][Audiogram::LEFT_EAR]))
		updateCharts(Audiogram::LEFT_EAR);
}

void NewAudiogramDialog::sRightEar()
{
	if (editEarInfo(earsInfo[selectedSampleIdx][Audiogram::RIGHT_EAR]))
		updateCharts(Audiogram::RIGHT_EAR);
}

void NewAudiogramDialog::sSampleSelect()
{
	if (ui.firstSampleRB->isChecked())
		selectedSampleIdx = 0;
	else
		selectedSampleIdx = 1;
}

constexpr int NewAudiogramDialog::getGraphIndex(int sample, int conductivity)
{
	if (conductivity != COND_AIR && conductivity != COND_BONE)
		return -1;
	return sample * 2 + conductivity;
}

bool NewAudiogramDialog::editEarInfo(Ear& ear)
{
	EarParamsDialog earParams(this);
	earParams.setEarInfo(ear);
	if (earParams.exec() != QDialog::Accepted)
		return false;
	ear = earParams.getEarInfo();
	return true;
}

void NewAudiogramDialog::setGraphData(QCPGraph* graph, const Ear::PointList& points)
{
	QVector<qreal> x, y;
	if (points.size() <= 1)
	{
		graph->setData(x, y);
		return;
	}
	for (const auto& point : points)
	{
		x.push_back(point.x());
		y.push_back(point.y());
	}
	graph->setData(x, y);
}

void NewAudiogramDialog::updateChart(QCustomPlot* chart, int earIdx)
{
	chart->clearGraphs();
	for (int sample : {0, 1})
	{
		const Ear& ear = earsInfo[sample][earIdx];
		QCPGraph* airGraph = chart->addGraph();
		QCPGraph* boneGraph = chart->addGraph();
		airGraph->setScatterStyle(QCPScatterStyle::ssDot);
		airGraph->setPen(airPen[sample]);
		boneGraph->setScatterStyle(QCPScatterStyle::ssCross);
		boneGraph->setPen(bonePen[sample]);
		setGraphData(airGraph, ear.airCondPoints);
		setGraphData(boneGraph, ear.boneCondPoints);
	}
	chart->replot();
}

void NewAudiogramDialog::updateCharts(int earIdx)
{
	if (earIdx == Audiogram::LEFT_EAR || earIdx == Audiogram::BOTH_EARS)
		updateChart(ui.leftEarCV, Audiogram::LEFT_EAR);
	if (earIdx == Audiogram::RIGHT_EAR || earIdx == Audiogram::BOTH_EARS)
		updateChart(ui.rightEarCV, Audiogram::RIGHT_EAR);
}