// �������� ������� ������ ������� ��������� ������� � �����.� �������� ������� ��������� ������� ��������� 
// �����(C - style ������), � ������� ����� ������ ������.
// � �������� ������� ��������� ������ - ������(C - style ������), ������� ����� �����.������� ���������� �������
// ������� ��������� ������ - �������, ���� �� ������������ � ������(�������, ��� � C++ ������� ������� � 0), � - 1, 
// ���� ������� � ������ ���.
//
// ������, ��� ������ ������(������ ����� 0) ����� ����� � ����� ����� ������.
//
// ���������� � ���������� : ��� ���������� ������� ������� �� ������ ���������� ����� ��������������� 
// �������, ���� ��� ��� �����.������� ��� �������� ��� - ���� �� �����.������������� ������� main �� �����.

// ��������
// 1. ��������� ������ ������ �������� ������
// 2. ��������� ������ ������ �������
// 3. ���������� �������
// 4. ���� ������� ����� 
#include <iostream>

using namespace std;

int _strstr(const char *text, const char *pattern)
{ 
	//int counter = 0;
	for(int i = 0; text[i] != '\0'; ++i)
	{
		if (pattern[i] == '\0') return i;
		if (text[i] == pattern[0]) {
			for (int n = 0; pattern[n] != '\0'; ++n)
				if (text[i + n] != pattern[n]) break;
			return i;
		}
		/*else {
			counter = 0;
		}*/
	}
	return -1;
}

int main(int argc, char* argv[])
{
	char text[] = "Hello world!";
	char pat[] = "lo";
	cout << _strstr(text, pat) << endl;

	return 0;
}