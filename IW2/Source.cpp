#include<iostream>
#include <fstream>
using namespace std;
#define SIZE 50

void deleteChars(char* str)
{
	char newstr[SIZE];
	int j = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			continue;
		}
		else
		{
			newstr[j++] = str[i];
		}
	}
	newstr[j] = '\0';
	strcpy_s(str, SIZE, newstr);
}

void testDeleteChars()
{
	char str[SIZE];
	cout << "Enter a string: " << endl;
	cin.getline(str, SIZE);

	deleteChars(str);

	cout << "\nString after deleting chars: \n";
	cout << str << '\n';
}

void downToUp(char ch)
{
	if (ch <= 'z' && ch >= 'a')
	{
		ch = 'A' + (ch - 'a');
	}
}

void reverseWords(char* str)
{
	char* pa, * pb;
	pa = str;

	char reversedStr[SIZE] = "";

	char wordList[10][SIZE];
	int k = 0;

	while (*pa)
	{
		pb = strchr(pa, ' ');
		strcpy_s(wordList[k], pb - pa, str);

		wordList[k][pb - pa] = '\0';
		k++;

		pa = pb + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		int j = 0;
		downToUp(wordList[i][j]);
	}

	for (int i = k - 1; i >= 0; i--)
	{
		strcat_s(reversedStr, wordList[i]);
		strcat_s(reversedStr, " ");
	}

	strcpy_s(str, SIZE, reversedStr);
}

void testReverseWords()
{
	ifstream fin("in.txt");
	char str[SIZE];

	fin.getline(str, SIZE);
	fin.close();

	reverseWords(str);

	ofstream fout;
	fout.open("out.txt");

	fout << str;

	fout.close();
}

void main()
{
	//testDeleteChars();

	testReverseWords();
}