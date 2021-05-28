﻿#include <iostream>
#include <cctype>
#include <string>
#include "LectureHandler.h"

#define MAX_STRING_LENGTH 100

using namespace std;

int LectureHandler::lectureCodeSequence = 1;

void LectureHandler::addLecture(professor& prof)
{
	char name[MAX_STRING_LENGTH];
	char lecturer[MAX_STRING_LENGTH];
	char room[MAX_STRING_LENGTH];
	int limited;
	string time;
	char* time_cp;

	//Lecture(const char* name, const char* lecturer, const char* room, int code, double time, int limited);
	cout << "--------------------------" << endl;
	cout << "강의명 : ";
	cin >> name;
	do
	{
		try
		{
			cout << "강의 시간 (24시간, 형식 : HHMM~HHMM): ";
			cin >> time;
			checkTimeStringFormat(time); // 입력받은 강의시간이 형식에 맞는지, 잘못된 점이 없는지 확인.
			time_cp = new char[time.length() + 1];
			strcpy(time_cp, time.c_str());
			break;
		}
		catch (TimeInputException& e)
		{
			e.showExceptionMessage();
		}
	} while (true);		
	do
	{
		cin.clear();
		try
		{
			cout << "수강 제한 인원 : ";
			cin >> limited;
			if (cin.fail())
				throw MAX_STRING_LENGTH;
			break;
		}
		catch (int expn)
		{
			cin.clear();
			cin.ignore(expn, '\n');
			cout << "잘못된 입력입니다." << endl;
		}
	} while (true);
	strcpy(lecturer, prof.get_name());
	cout << "강의실 : ";
	cin >> room;

	lectureList[lectureCount] = new Lecture(name, lecturer, room, lectureCodeSequence, time_cp, limited);
	lectureCodeSequence++;
	lectureCount++;
	cout << endl << "과목 추가 완료" << endl;
	cout << "--------------------------" << endl;
	delete[] time_cp;
}

void LectureHandler::showAllLecture() const
{
	cout << "--------------------------" << endl;
	cout << "강의 목록" << endl;
	int i;
	for (i = 0; i < lectureCount; i++)
	{
		lectureList[i]->LectureAllInfoPrint();
	}
}

void LectureHandler::changeLectureInfo(Lecture& lect)
{
	int out;
	int lectureCode;
	int changeCode;
	char lectName[MAX_STRING_LENGTH];
	char profName[MAX_STRING_LENGTH];
	char roomNum[MAX_STRING_LENGTH];
	char lectureTime[MAX_STRING_LENGTH];
	int maxStudent;

	lect.LectureAllInfoPrint();

	cout << "--------------------------" << endl;
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
		out = false;
		do
		{
			try
			{
				cout << "강의 시간 (24시간, 형식 : HHMM~HHMM): ";
				cin >> lectureTime;
				checkTimeStringFormat(lectureTime);
				lect.ChangeLectureTime(lectureTime);
				cout << "변경 완료 " << endl;
				lect.LectureAllInfoPrint();
				out = true;
			}
			catch (TimeInputException& e)
			{
				e.showExceptionMessage();
			}
		} while (!out);		// 입력받은 강의시간이 형식에 맞는지, 잘못된 점이 없는지 확인.
		break;
	case 5:
		do
		{
			cin.clear();
			try
			{
				cout << "최대 수강 인원 : ";
				cin >> maxStudent;
				lect.ChangeLimitedNum(maxStudent);
				cout << "변경 완료 " << endl;
				lect.LectureAllInfoPrint();
				if (cin.fail())
					throw MAX_STRING_LENGTH;
				break;
			}
			catch (int expn)
			{
				cin.clear();
				cin.ignore(expn, '\n');
				cout << "잘못된 입력입니다." << endl;
			}
		} while (true);
		break;
	default:
		cout << "잘못된 코드입니다." << endl;
	}
	cout << "--------------------------" << endl;
}

void LectureHandler::showLectureByProfName(char* profName) const
{
	int i;
	for (i = 0; i < lectureCount; i++)
	{
		if (strcmp(lectureList[i]->GetLecturer(), profName) == 0)
		{
			lectureList[i]->LectureAllInfoPrint();
		}
	}
}

int LectureHandler::getLectureCount() const
{
	return lectureCount;
}

Lecture* LectureHandler::findLecture(int code) const
{
	int i;
	for (i = 0; i < lectureCount; i++)
	{
		if (lectureList[i]->GetLectureCode() == code)
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
		delete lectureList[i];
	}
}

// 입력받은 강의 시간 string을 확인, 정해진 형식 및 규칙을 따르는지 확인 (LectureHandler 클래스의p public멤버변수만 사용할 함수이므로 private선언.)
// HHMM~HHMM 입력이 아닌, 다른 길이의 문자열이나 가운데 문자 ~를 받지 않으면 WrongTimeFormatException 발생
// H,M이 숫자가 아니면 InvalidTimeValueException발생
// 0<=HH<=23, 0<=MM<=59범위를 만족하지 않으면 TimeOutofBoundException발생
// 앞에 입력한 시간보다 뒤에 입력한 시간이 더 앞서있으면 WrongTimeFormatException발생
void LectureHandler::checkTimeStringFormat(string time)
{

	if (time.length() != 9)
	{
		throw WrongTimeFormatException();
	}
	else if (time.at(4) != '~')
	{
		throw WrongTimeFormatException();
	}
	else
	{
		for (unsigned int i = 0; i < time.length(); i++)
		{
			if (!isdigit(time.at(i)) && (i != 4))
			{
				throw InvalidTimeValueException();
			}
		}
	}

	if ((stringToInteger(time.substr(0, 2)) < 0) || (stringToInteger(time.substr(0, 2)) > 23) ||
		stringToInteger(time.substr(5, 2)) < 0 || stringToInteger(time.substr(5, 2)) > 23 ||
		stringToInteger(time.substr(2, 2)) < 0 || stringToInteger(time.substr(2, 2)) > 59 ||
		stringToInteger(time.substr(2, 2)) < 0 || stringToInteger(time.substr(7, 2)) > 59)
	{
		throw TimeOutouBoundException();
	}
	else if (stringToInteger(time.substr(0, 4)) >= stringToInteger(time.substr(5, 4)))
	{
		throw WrongTimeOrderException();
	}
}

int stringToInteger(char* str)
{
	int ret = 0;
	int mul = 1;
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		ret += (*(str + i)) * mul;
		mul *= 10;
	}
	return ret;
}

int stringToInteger(string str)
{
	int ret = 0;
	int mul = 1;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		ret += (str.at(i) - '0') * mul;
		mul *= 10;
	}
	return ret;
}

void WrongTimeFormatException::showExceptionMessage() const
{
	cout << "잘못된 시간 형식입니다." << endl;
}

void InvalidTimeValueException::showExceptionMessage() const
{
	cout << "시간 입력 부분에 숫자가 입력되어야 합니다." << endl;
}

void TimeOutouBoundException::showExceptionMessage() const
{
	cout << "시간 범위가 잘못되었습니다." << endl;
}

void WrongTimeOrderException::showExceptionMessage() const
{
	cout << "시간 순서가 올바르지 않습니다." << endl;
}