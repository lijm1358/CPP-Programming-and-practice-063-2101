#pragma once

/******************************************
* ��� ���Ͽ� ���� �� �ִ� ���� ��Ȳ�� ����
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