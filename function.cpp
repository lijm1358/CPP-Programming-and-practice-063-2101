
#include <iostream>
#include <Windows.h>
#include "LectureHandler.h"
//#include "Lecture.h"
//#include "User.h"
#include "UserHandler.h"
#include "comn_exception.h"

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
	int i;
	Lecture* tempLecture;

	cout << "--------------------------" << endl;
	cout << name << "님의 강의 목록" << endl;
	lectHdl.showLectureByProfName(name);	//받은 교수님의 이름과 일치하는 과목들을 전부 출력

	do
	{
		try
		{
			cout << "위의 강의목록 중, 성적 처리를 원하는 과목의 과목코드를 입력해주세요 (-1 입력으로 취소) : ";
			cin >> lectCode;						//출력된 과목들 중에서 과목 코드 입력
			checkConsoleInput();		// int형 정수에 대한 잘못된 cin 처리
			if (lectCode == -1)
			{
				system("cls");
				cout << "메뉴로 돌아갑니다." << endl;
				return;
			}
			tempLecture = lectHdl.findLecture(lectCode);	//입력받은 코드에 해당하는 강의를 반환
			if (tempLecture == NULL)
				throw lectCode;								//해당 과목이 없으면 예외 발생
			else if (strcmp(tempLecture->GetLecturer(), name))
				throw tempLecture;							//해당 과목이 자신이 만든 과목이 아니면 예외 발생
			studentIdArr = tempLecture->GetStudentID();		//해당 강의로부터 학번 배열 받아온 후 저장
			studentCount = tempLecture->GetStudentCnt();	//해당 강의로부터 수강중인 학생 수 받아온 후 저장
			if (studentCount == 0)
				throw tempLecture->GetLectureName();		//해당 과목을 듣는 학생이 없으면 예외 발생
		}
		catch (consoleInputFailException& e)
		{
			e.clearBuffer();
			e.showExceptionMessage();
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

	system("cls");
	do {
		try
		{
			cout << "----------------------------------------------------------" << endl;
			cout << tempLecture->GetLectureName() << "의 수강생" << endl;
			cout << "----------------------------------------------------------" << endl;
			for (i = 0; i < studentCount; i++)		//찾은 강의의 수강생 목록 출력
			{
				student* tempStudent = static_cast<student*>(userHdl.SearchUser(studentIdArr[i]));
				cout << "이름 : " << tempStudent->get_name() << " | 학번 : " << tempStudent->get_ID() << " | 전공 : " << tempStudent->get_major() << endl;
			}
			cout << "성적을 등록할 학생의 학번을 입력해주세요 : ";
			cin >> targetStudentId;
			checkConsoleInput();		// int형 정수에 대한 잘못된 cin 처리
			for (i = 0; i < studentCount && targetStudentId != studentIdArr[i]; i++);	//입력받은 학번이 위에 나온 수강생 목록에 포함된 학생인지 검사.
			if (i == studentCount)
				throw targetStudentId;
			cout << "해당 학생의 성적을 입력해주세요 : ";
			cin >> targetGrade;
			checkConsoleInput();		// int형 정수에 대한 잘못된 cin 처리
			static_cast<student*>(userHdl.SearchUser(targetStudentId))->Addgrade(targetGrade);
			system("cls");
			cout << "성적 입력 완료" << endl;
			break;
		}
		catch (consoleInputFailException& e)
		{
			e.clearBuffer();
			e.showExceptionMessage();
		}
		catch (int id)
		{
			cout << id << "에 해당하는 학생이 없거나, " << id << "에 해당하는 학생은 해당 수업을 듣지 않는 학생입니다." << endl;
		}
	} while (true);
}