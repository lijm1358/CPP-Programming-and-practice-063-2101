#include <iostream>
#include "LectureHandler.h"
#include "Lecture.h"
#include "User.h"

using namespace std;

void AddLecture(LectureHandler& lectHdl)
{
	lectHdl.addLecture();
}

void ShowAllLecture(LectureHandler& lectHdl)
{
	lectHdl.showAllLecture();
}

void ChangeLectureInfo(LectureHandler& lectHdl, professor& prof)
{
	int lectureCode;
	int isLecturerSame = -1;
	do
	{
		try
		{
			cout << "정보를 바꿀 강의의 코드를 입력해주세요 : ";
			cin >> lectureCode;
			Lecture* lect = lectHdl.findLecture(lectureCode);
			if (lect == NULL)
				throw lectureCode;
			isLecturerSame = strcmp(lect->GetLecturer(), prof.get_name());	//같으면 0
			if (isLecturerSame != 0)
			{
				cout << "입력받은 강의 코드에 해당하는 강의는 " << prof.get_name() << "님의 강의가 아닙니다." << endl;
			}
			else
			{
				lectHdl.changeLectureInfo(*lect);
			}
		}
		catch (int code)
		{
			cout << "해당 강의를 찾을 수 없습니다 : " << lectureCode << endl;
		}
	} while (isLecturerSame!=0);
}