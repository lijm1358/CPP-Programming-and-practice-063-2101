#pragma once

/******************************************
* 모든 파일에 쓰일 수 있는 예외 상황들 정의
******************************************/

#include<iostream>

using namespace std;

void checkConsoleInput();

class consoleInputFailException
{
public:
	void showExceptionMessage();
	void clearBuffer();
};