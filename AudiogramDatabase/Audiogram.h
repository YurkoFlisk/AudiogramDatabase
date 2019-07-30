#pragma once

#include <array>
#include <vector>
#include <QtCore>
#include <QColor>

inline const QColor DEFAULT_SAMP1_COLOR = Qt::red;
inline const QColor DEFAULT_SAMP2_COLOR = Qt::blue;

enum TestResult {
	NOT_SET, POSITIVE, NEGATIVE, YES = POSITIVE, NO = NEGATIVE
};

struct Patient
{
	Patient() = default;
	Patient(QDate birthday, QString fullName, QString profession, QString address)
		: birthday(birthday), fullName(fullName), profession(profession), address(address)
	{}
	
	QDate birthday;
	QString fullName;
	QString profession;
	QString address;
};

struct Ear
{
	using PointList = std::vector<QPoint>;

	PointList airCondPoints = { {1000, 0} };
	PointList boneCondPoints = { {1000, 0} };
	double normalSpeechThreshold = 0.0;
	double whisperSpeechThreshold = 0.0;
	TestResult occlusionAutophony = NOT_SET;
	TestResult bingTest = NOT_SET;
	TestResult federiciTest = NOT_SET;
};

struct Audiogram
{
	static constexpr int NUM_SAMPLES = 2;
	static constexpr int NUM_EARS = 2;
	static constexpr int LEFT_EAR = 0;
	static constexpr int RIGHT_EAR = 1;
	static constexpr int BOTH_EARS = 2;
	static constexpr int DEFAULT_MIN_FREQUENCY = 250; // Hz
	static constexpr int DEFAULT_MAX_FREQUENCY = 8000; // Hz
	static constexpr int DEFAULT_MIN_LEVEL = -10; // dbHL
	static constexpr int DEFAULT_MAX_LEVEL = 120; // dbHL

	using PatientID = int;
	using EarList = std::array<std::array<Ear, NUM_EARS>, NUM_SAMPLES>;

	Audiogram() = default;
	Audiogram(PatientID patientID, const EarList& ears)
		: patientID(patientID), earsData(ears)
	{}

	EarList earsData;
	PatientID patientID;
};
