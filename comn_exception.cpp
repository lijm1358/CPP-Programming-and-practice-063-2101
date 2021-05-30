#include "comn_exception.h"

//std::cin 실패 시, consoleInputFailException발생
void checkConsoleInput()
{
	if (cin.fail())
		throw consoleInputFailException();
}

void consoleInputFailException::showExceptionMessage()
{
	cout << "잘못된 입력입니다." << endl;
}

void consoleInputFailException::clearBuffer()
{
	cin.clear();
	cin.ignore(10000, '\n');
}