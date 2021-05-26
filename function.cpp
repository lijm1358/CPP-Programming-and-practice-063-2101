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
			cout << "������ �ٲ� ������ �ڵ带 �Է����ּ��� : ";
			cin >> lectureCode;
			Lecture* lect = lectHdl.findLecture(lectureCode);
			if (lect == NULL)
				throw lectureCode;
			isLecturerSame = strcmp(lect->GetLecturer(), prof.get_name());	//������ 0
			if (isLecturerSame != 0)
			{
				cout << "�Է¹��� ���� �ڵ忡 �ش��ϴ� ���Ǵ� " << prof.get_name() << "���� ���ǰ� �ƴմϴ�." << endl;
			}
			else
			{
				lectHdl.changeLectureInfo(*lect);
			}
		}
		catch (int code)
		{
			cout << "�ش� ���Ǹ� ã�� �� �����ϴ� : " << lectureCode << endl;
		}
	} while (isLecturerSame!=0);
}