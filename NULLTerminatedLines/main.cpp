#include<iostream>
#include<windows.h>
using namespace std;

int StringLength(const char str[]);
char* to_upper(char str[]);//перевод строки в верхний регистр
char* to_lower(char str[]);//перевод строки в нижний регистр
char* shrink(char str[]);//удаление лишних пробелов
bool is_palindrome(char str[]);//проверка на палиндром

void main()
{
	setlocale(LC_ALL, "rus");
	//char str[] = { 'H','e','l','l','o',0};
	//char str[] = "Hello";
	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	//cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, SIZE);//ввод строки с пробелами
	SetConsoleCP(866);
	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;
	cout << StringLength(str) << endl;
	cout << is_palindrome(str) << endl;
}

int StringLength(const char str[])
{
	int count = 0;
	while (str[count]!='\0')
	{
		count++;
	}
	return count;
}

char* to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z')) str[i] -= 32;
		if ((str[i] >= 'а') && (str[i] <= 'я')) str[i] -= 32;
	}
	return str;
}

char* to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z')) str[i] += 32;
		if ((str[i] >= 'А') && (str[i] <= 'Я')) str[i] += 32;
	}
	return str;
}

char* shrink(char str[])
{
	int k = 0;
	for (int i = 0; i<StringLength(str); i++)
	{
		for (int k = i; k < StringLength(str); k++)
		{
			if ((str[k] == ' ') && (str[k + 1] == ' '))
			{
				for (int j = k; j < str[i] - 1; j++)
				{
					str[j] = str[j + 1];
				}
				str[StringLength(str)] = 0;
			}
		}
	}
	return str;
}

bool is_palindrome(char str[])
{
	for (int i = 0; i < (StringLength(str) / 2); i++)
	{
		if (str[i] != str[(StringLength(str) - i-1)]) return 0;
	}
	return 1;
}