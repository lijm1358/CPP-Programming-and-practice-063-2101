#include <iostream>
#include "LectureHandler.h"
#include "Lecture.h"
#include "User.h"
#include "UserHandler.h"

using namespace std;

void AddLecture(LectureHandler& lectHdl, professor& prof)
{
	lectHdl.addLecture(prof);
}

void ShowAllLecture(LectureHandler& lectHdl)
{
	lectHdl.showAllLecture();
}


void AddGrade(LectureHandler& lectHdl, UserHandler& userHdl, professor& prof)
{
	char* name = prof.get_name();			//�α��� �� �������� �̸��� �޾Ƽ� ����
	int lectCode;
	int studentCount = 0;
	int targetStudentId;
	int targetGrade;
	int* studentIdArr;
	Lecture* tempLecture;

	cout << "--------------------------" << endl;
	cout << name << "���� ���� ���" << endl;
	lectHdl.showLectureByProfName(name);	//���� �������� �̸��� ��ġ�ϴ� ������� ���� ���

	do
	{
		try
		{
			cout << "���� ���Ǹ�� ��, ���� ó���� ���ϴ� ������ �����ڵ带 �Է����ּ��� : ";
			cin >> lectCode;						//��µ� ����� �߿��� ���� �ڵ� �Է�
			tempLecture = lectHdl.findLecture(lectCode);	//�Է¹��� �ڵ忡 �ش��ϴ� ���Ǹ� ��ȯ
			if (tempLecture == NULL)
				throw lectCode;
			else if (strcmp(tempLecture->GetLecturer(), name))
				throw tempLecture;
			studentIdArr = tempLecture->GetStudentID();		//�ش� ���Ƿκ��� �й� �迭 �޾ƿ� �� ����
			studentCount = tempLecture->GetStudentCnt();	//�ش� ���Ƿκ��� �������� �л� �� �޾ƿ� �� ����
			if (studentCount == 0)
				throw;
		}
		catch (int lectCode)
		{
			cout << "���� �ڵ� " << lectCode << "�� �ش��ϴ� ���ǰ� �����ϴ�." << endl;
		}
		catch (Lecture* lect)
		{
			cout << "���� \"" << lect->GetLectureName() << "\"�� " << name << "���� ���ǰ� �ƴմϴ�." << endl;
		}
		catch (...)
		{
			cout << "�ش� ������ �������� �������� �ʽ��ϴ�." << endl;
		}
	} while (studentCount == 0);
	
	cout << endl << tempLecture->GetLectureName() << "�� ������" << endl;
	for (int i = 0; i < studentCount; i++)
	{
		student* tempStudent = static_cast<student*>(userHdl.SearchUser(studentIdArr[i]));
		cout << "�̸� : " << tempStudent->get_name() << " | �й� : " << tempStudent->get_ID() << " | ���� : " << tempStudent->get_major() << endl;
	}
	cout << "������ ����� �л��� �й��� �Է����ּ��� : ";
	cin >> targetStudentId;
	cout << "�ش� �л��� ������ �Է����ּ��� : ";
	cin >> targetGrade;
	static_cast<student*>(userHdl.SearchUser(targetStudentId))->Addgrade(targetGrade);
	cout << "���� �Է� �Ϸ�" << endl;
	cout << "--------------------------" << endl;
}