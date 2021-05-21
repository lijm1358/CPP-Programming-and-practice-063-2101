#include <iostream>
#include "LectureHandler.h"

#define MAX_STRING_LENGTH 100

using namespace std;

int LectureHandler::lectureCodeSequence = 1;

void LectureHandler::addLecture()
{
	char name[MAX_STRING_LENGTH];
	char lecturer[MAX_STRING_LENGTH];
	char room[MAX_STRING_LENGTH];
	int limited;
	double time;

	//Lecture(const char* name, const char* lecturer, const char* room, int code, double time, int limited);
	cout << "이름 : ";
	cin >> name;
	cout << "교수 : ";
	cin >> lecturer;
	cout << "강의실 : ";
	cin >> room;
	cout << "강의 시간 : ";
	cin >> time;
	cout << "최대 수강 인원 : ";
	cin >> limited;
	lectureList[lectureCount] = new Lecture(name, lecturer, room, lectureCodeSequence, time, limited);
	lectureCodeSequence++;
	lectureCount++;
	cout << "과목 추가 완료";
}

void LectureHandler::showAllLecture() const
{
	int i;
	for(i=0; i<lectureCount; i++)
	{
		lectureList[i]->LectureAllInfoPrint();
	}
}

void LectureHandler::changeLectureInfo(Lecture& lect)
{
	int lectureCode;
	int changeCode;
	char lectName[MAX_STRING_LENGTH];
	char profName[MAX_STRING_LENGTH];
	char roomNum[MAX_STRING_LENGTH];
	double lectureTime;
	int maxStudent;

	lect.LectureAllInfoPrint();

	cout << "바꿀 강의 정보 (1. 강의이름 2. 교수 3. 강의실 4. 강의 시간 5. 최대 수강 인원) : ";
	cin >> changeCode;
	switch (changeCode)
	{
		case 1:
			cout << "강의 이름 : ";
			cin >> lectName;
			lect.ChangeLectureName(lectName);
			cout << "변경 완료" << endl;
			lect.LectureAllInfoPrint();
			break;
		case 2:
			cout << "교수명 : ";
			cin >> profName;
			lect.ChangeLecturer(profName);
			cout << "변경 완료" << endl;
			lect.LectureAllInfoPrint();
			break;
		case 3:
			cout << "강의실 : ";
			cin >> roomNum;
			lect.ChangeLectureRoom(roomNum);
			cout << "변경 완료" << endl;
			lect.LectureAllInfoPrint();
			break;
		case 4:
			cout << "강의 시간 : ";
			cin >> lectureTime;
			lect.ChangeLectureTime(lectureTime);
			cout << "변경 완료 " << endl;
			lect.LectureAllInfoPrint();
			break;
		case 5:
			cout << "최대 수강 인원 : ";
			cin >> maxStudent;
			lect.ChangeLimitedNum(maxStudent);
			cout << "변경 완료 " << endl;
			lect.LectureAllInfoPrint();
			break;
		default:
			cout << "잘못된 코드입니다." << endl;
	}
}

Lecture* LectureHandler::findLecture(int code) const
{
	int i;
	for (i = 0; i < lectureCount; i++)
	{
		if(lectureList[i]->GetLectureCode() == code)
		{
			return lectureList[i];
		}
	}
	return NULL;
}

Lecture* LectureHandler::findLecture(char* lectureName) const
{
	int i;
	for (i = 0; i < lectureCount; i++)
	{
		if (strcmp(lectureList[i]->GetLectureName(), lectureName) == 0)
		{
			return lectureList[i];
		}
	}
	return NULL;
}

LectureHandler::~LectureHandler()
{
	int i;
	for (i = 0; i < lectureCount; i++)
	{
		delete[] lectureList[i];
	}
}