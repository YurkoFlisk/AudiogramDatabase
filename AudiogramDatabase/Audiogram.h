#pragma once

#include <vector>
#include <QtCore>

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

	PointList airCondPoints;
	PointList boneCondPoints;
	double normalSpeechThreshold;
	double whisperSpeechThreshold;
	TestResult occlusionAutophony;
	TestResult bingTest;
	TestResult federiciTest;
};

struct Audiogram
{
	static constexpr int NUM_SAMPLES = 2;
	static constexpr int LEFT_EAR = 0;
	static constexpr int RIGHT_EAR = 1;

	Ear earData[NUM_SAMPLES][2];
	Patient* patient;
};
