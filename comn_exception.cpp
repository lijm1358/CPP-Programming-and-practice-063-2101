#include "comn_exception.h"

//std::cin ���� ��, consoleInputFailException�߻�
void checkConsoleInput()
{
	if (cin.fail())
		throw consoleInputFailException();
}

void consoleInputFailException::showExceptionMessage()
{
	cout << "�߸��� �Է��Դϴ�." << endl;
}

void consoleInputFailException::clearBuffer()
{
	cin.clear();
	cin.ignore(10000, '\n');
}