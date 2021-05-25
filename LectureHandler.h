#pragma once
#pragma warning (disable:4996)

#include <string>
#include "Lecture.h"

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
	int checkTimeStringFormat(string);	// 강의 시간을 입력받았을 때, 해당 시간이 형식(HHMM~HHMM)에 맞는지 확인
public:
	LectureHandler() : lectureCount(0) {};
	void addLecture();
	void showAllLecture() const;
	void changeLectureInfo(Lecture&);
	Lecture* findLecture(int) const;
	Lecture* findLecture(char*) const;
	~LectureHandler();
};