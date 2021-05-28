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
	char* name = prof.get_name();			//로그인 한 교수님의 이름을 받아서 저장
	int lectCode;
	int studentCount = 0;
	int targetStudentId;
	int targetGrade;
	int* studentIdArr;
	Lecture* tempLecture;

	cout << "--------------------------" << endl;
	cout << name << "님의 강의 목록" << endl;
	lectHdl.showLectureByProfName(name);	//받은 교수님의 이름과 일치하는 과목들을 전부 출력

	do
	{
		try
		{
			cout << "위의 강의목록 중, 성적 처리를 원하는 과목의 과목코드를 입력해주세요 : ";
			cin >> lectCode;						//출력된 과목들 중에서 과목 코드 입력
			tempLecture = lectHdl.findLecture(lectCode);	//입력받은 코드에 해당하는 강의를 반환
			if (tempLecture == NULL)
				throw lectCode;
			else if (strcmp(tempLecture->GetLecturer(), name))
				throw tempLecture;
			studentIdArr = tempLecture->GetStudentID();		//해당 강의로부터 학번 배열 받아온 후 저장
			studentCount = tempLecture->GetStudentCnt();	//해당 강의로부터 수강중인 학생 수 받아온 후 저장
			if (studentCount == 0)
				throw tempLecture->GetLectureName();
		}
		catch (int lectCode)
		{
			cout << "강의 코드 " << lectCode << "에 해당하는 강의가 없습니다." << endl;
		}
		catch (Lecture* lect)
		{
			cout << "강의 \"" << lect->GetLectureName() << "\"는 " << name << "님의 강의가 아닙니다." << endl;
		}
		catch (char* lectName)
		{
			cout << "강의 " << lectName << "의 수강생이 존재하지 않습니다." << endl;
		}
	} while (studentCount == 0);

	cout << endl << tempLecture->GetLectureName() << "의 수강생" << endl;
	for (int i = 0; i < studentCount; i++)
	{
		student* tempStudent = static_cast<student*>(userHdl.SearchUser(studentIdArr[i]));
		cout << "이름 : " << tempStudent->get_name() << " | 학번 : " << tempStudent->get_ID() << " | 전공 : " << tempStudent->get_major() << endl;
	}
	cout << "성적을 등록할 학생의 학번을 입력해주세요 : ";
	cin >> targetStudentId;
	cout << "해당 학생의 성적을 입력해주세요 : ";
	cin >> targetGrade;
	static_cast<student*>(userHdl.SearchUser(targetStudentId))->Addgrade(targetGrade);
	cout << "성적 입력 완료" << endl;
	cout << "--------------------------" << endl;
}