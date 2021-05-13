#include <iostream>
#include <fstream>
using namespace std;

int countStrings(const char* filename);

 int getStrings(const char* fname, char*** strings = nullptr)
{
    char** lines;
    int n = countStrings(fname);
    ifstream fin(fname); 
    lines = new char* [n];

    int len;
    char temp[100]; 

    for (int i = 0; i < n; i++)
    {
        fin.getline(temp, 100);

        for (len = 0; temp[len] != '\0'; len++);

        lines[i] = new char[len + 1];

        for (int j = 0; j < len; j++)
        {
            lines[i][j] = temp[j];
        }

        lines[i][len] = '\0'; 
    }

    fin.close();

    *strings = lines;

    return n;
}

 int countStrings(const char* filename)
 {
     ifstream fin(filename);

     int count = 0;
     char temp[100]; 

     while (!fin.eof())
     {
         count++;
         fin.getline(temp, 100);
     }

     fin.close();

     return count;
 }

 void deleteStrings(char** lines, int count)
 {
     if (lines)
     {
         for (int i = 0; i < count; i++)
         {
             delete lines[i];
         }
     }

     if (lines)
         delete[] lines;
 }

bool compareStrings(char* line1, char* line2, char* line3)
{
	if (strcmp(line1, line2) == 0)
	{
		if (strcmp(line2, line3) == 0) return true;
	}

	return false;
}

void writeArray(char* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void testTask2()
{
    int count1; 
    int count2;
    int count3;
    char** lines1; 
    char** lines2;
    char** lines3;
    char* resultStr;

    ofstream fout("out.txt");

    count1 = getStrings("in1.txt", &lines1);
    count2 = getStrings("in1.txt", &lines2);
    count3 = getStrings("in1.txt", &lines3);

    for (int i = 0; i < count1; i++)
    {
        for (int j = 0; i < count2; j++)
        {
            for (int k = 0; k < count3; k++)
            {
                if (compareStrings(lines1[i], lines2[j], lines3[k]))
                {
                    fout << lines1[i];
                }
            }
        }
    }

    deleteStrings(lines1, count1);
    deleteStrings(lines2, count2);
    deleteStrings(lines3, count3);
}


void main()
{
	testTask2();
}