#pragma once
#pragma warning (disable:4996)

#include <string>
#include "Lecture.h"
//#include "User.h"

class professor;

using namespace std;

int stringToInteger(char*);		// 입력받은 문자열을 정수로 변환
int stringToInteger(string);	// 입력받은 문자열을 정수로 변환

class LectureHandler
{
private:
	Lecture* lectureList[100];
	int lectureCount;
	static int lectureCodeSequence;
private:
	void checkTimeStringFormat(string);	// 강의 시간을 입력받았을 때, 해당 시간이 형식(HHMM~HHMM)에 맞는지 확인
public:
	LectureHandler() : lectureCount(0) { };
	void addLecture(professor& prof);
	void showAllLecture() const;
	void changeLectureInfo(Lecture&);
	void showLectureByProfName(char*) const;
	int getLectureCount() const;
	Lecture* findLecture(int) const;
	Lecture* findLecture(char*) const;
	~LectureHandler();
};

class TimeInputException 
{
public:
	virtual void showExceptionMessage() const = 0;
};

class WrongTimeFormatException : public TimeInputException
{
public:
	void showExceptionMessage() const;
};

class InvalidTimeValueException : public TimeInputException
{
public:
	void showExceptionMessage() const;
};

class TimeOutouBoundException : public TimeInputException
{
public:
	void showExceptionMessage() const;
};

class WrongTimeOrderException : public TimeInputException
{
public:
	void showExceptionMessage() const;
};