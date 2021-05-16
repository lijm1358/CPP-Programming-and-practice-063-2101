#pragma once
#pragma warning (disable:4996)

#include <iostream>
#include <cstring>
#include "Lecture.h"

class LectureHandler
{
private:
	Lecture* lectureList[100];
	int lectureCount;
	static int lectureCodeSequence;
public:
	LectureHandler() : lectureCount(0) {};
	void addLecture();
	void showAllLecture();
	void changeLectureInfo(Lecture&);
	Lecture* findLecture(int) const;
	Lecture* findLecture(char*) const;
	~LectureHandler();
};