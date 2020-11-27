#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

using namespace std;

int Len(const char* s, int k)
{
	if (*s != '\0')
		return Len(++s, ++k);
	else
		return k;
}

int Find_Dot(const char* s, int count, int i)
{	
	
	if (i != count - 4)
	{
		return Find_Dot(s, count, i + 1);
	}
	else
		if (s[i] == '.')
			return i;
		else
			return 0;
}

char* Change(char* s, char* dest, char* t, int i, int count) 
{
	if (s[i] != 0) {
		if (s[i] == '.') {
			strcat_s(t, strlen(s) - i, "**");
			Change(s, dest, t + 2, i + 1, count);
		}
		else {
			*t++ = s[i++];
			*t = '\0';
			return Change(s, dest, t, i, count);
		}
	}
	else
		return dest;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char str[101];
	const char c = '.';

	cout << " Введіть стрічку: " << endl;
	cin.getline(str, 100);

	cout << endl;

	int count = Len(str,0);
	cout << " length = " << Len(str, 0) << endl << endl;

	cout << " Номер 4-ої крапки з кінця: " << Find_Dot(str, count, 0) << endl << endl;

	char* dest1 = new char[151];
	dest1[0] = '/0';
	char* dest2 = Change(str, dest1, dest1, 0, count);
	cout << " Модифікована стрічка: " << dest2 << endl;

	return 0;
}