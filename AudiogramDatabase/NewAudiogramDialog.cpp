#include "NewAudiogramDialog.h"
#include "PatientSelectionDialog.h"
#include "EarParamsDialog.h"

NewAudiogramDialog::NewAudiogramDialog(QColor airColor, QColor boneColor, QWidget *parent)
	: QDialog(parent), selectedSampleIdx(0)
{
	ui.setupUi(this);
	QValidator* idValidator = new QIntValidator(0, 999999999, this);
	ui.patientIDLE->setValidator(idValidator);
	ui.firstSampleRB->setChecked(true);
	ui.leftEarChart->setRenderHint(QPainter::Antialiasing);
	ui.rightEarChart->setRenderHint(QPainter::Antialiasing);

	airPen = QPen(airColor, 2, Qt::SolidLine);
	bonePen = QPen(boneColor, 2, Qt::DashLine);
	airBrush = airColor;
	boneBrush = createCrossBrush(boneColor);

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

const QPen& NewAudiogramDialog::getAirPen() const
{
	return airPen;
}

const QPen& NewAudiogramDialog::getBonePen() const
{
	return bonePen;
}

const QBrush& NewAudiogramDialog::getAirBrush() const
{
	return airBrush;
}

const QBrush& NewAudiogramDialog::getBoneBrush() const
{
	return boneBrush;
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

void NewAudiogramDialog::setAirPen(const QPen& pen)
{
	airPen = pen;
}

void NewAudiogramDialog::setBonePen(const QPen& pen)
{
	bonePen = pen;
}

void NewAudiogramDialog::setAirBrush(const QBrush& brush)
{
	airBrush = brush;
}

void NewAudiogramDialog::setBoneBrush(const QBrush& brush)
{
	boneBrush = brush;
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
	{
		selectedSampleIdx = 0;
	}
	else
	{
		selectedSampleIdx = 1;
	}
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

void NewAudiogramDialog::updateChart(QChartView* chartView, int earIdx)
{
	QChart* chart = new QChart;
	QLogValueAxis* xAxis = new QLogValueAxis;
	QValueAxis* yAxis = new QValueAxis;
	xAxis->setTitleText(tr("Frequency (Hz)"));
	xAxis->setMinorTickCount(1);
	xAxis->setBase(2);
	xAxis->setMin(Audiogram::DEFAULT_MIN_FREQUENCY);
	xAxis->setMax(Audiogram::DEFAULT_MAX_FREQUENCY);
	yAxis->setTitleText(tr("Level (dbHL)"));
	yAxis->setMinorTickCount(1);
	yAxis->setMin(-120);
	yAxis->setMax(5);
	yAxis->setTickAnchor(0);
	chart->addAxis(xAxis, Qt::AlignBottom);
	chart->addAxis(yAxis, Qt::AlignLeft);

	for (int sample : { 0, 1 })
	{
		const Ear& ear = earsInfo[sample][earIdx];
		addSeries(chart, xAxis, yAxis, ear.airCondPoints,
			airBrush, airPen, QScatterSeries::MarkerShapeCircle);
		addSeries(chart, xAxis, yAxis, ear.boneCondPoints,
			boneBrush, bonePen, QScatterSeries::MarkerShapeRectangle);
	}
	chart->legend()->setVisible(false);

	chartView->setChart(chart);
}

void NewAudiogramDialog::updateCharts(int earIdx)
{
	if (earIdx == Audiogram::LEFT_EAR || earIdx == Audiogram::BOTH_EARS)
		updateChart(ui.leftEarChart, Audiogram::LEFT_EAR);
	if (earIdx == Audiogram::RIGHT_EAR || earIdx == Audiogram::BOTH_EARS)
		updateChart(ui.rightEarChart, Audiogram::RIGHT_EAR);
}

void NewAudiogramDialog::addSeries(QChart* chart, QLogValueAxis* xAxis, QValueAxis* yAxis,
	const Ear::PointList& points, QBrush pointBrush,
	QPen linePen, QScatterSeries::MarkerShape shape) const
{
	// Main series for plotting
	QLineSeries* lineSeries = new QLineSeries;
	lineSeries->setPen(linePen);
	for (const QPoint& point : points)
		lineSeries->append(point);
	chart->addSeries(lineSeries);
	lineSeries->attachAxis(xAxis);
	lineSeries->attachAxis(yAxis);
	// We have to add separate scatter series for points because
	// line series doesn't allow to customize points
	QScatterSeries* scatterSeries = new QScatterSeries;
	scatterSeries->setPen(QPen(Qt::transparent));
	scatterSeries->setBrush(pointBrush);
	scatterSeries->setMarkerSize(15);
	scatterSeries->setMarkerShape(shape);
	for (const QPoint& point : points)
		scatterSeries->append(point);
	chart->addSeries(scatterSeries);
	scatterSeries->attachAxis(xAxis);
	scatterSeries->attachAxis(yAxis);
}

QBrush NewAudiogramDialog::createCrossBrush(QColor color)
{
	QImage crossImage(15, 15, QImage::Format_ARGB32);
	crossImage.fill(Qt::transparent);
	QPainter painter(&crossImage);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(color);
	painter.setBrush(color);
	painter.drawLine(0, 0, 14, 14);
	painter.drawLine(0, 14, 14, 0);
	return QBrush(crossImage);
}
