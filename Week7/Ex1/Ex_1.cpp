#include <stdio.h>
#include "Student.h"

void PrintMenu();

int main()
{
	vector<Student> vctStudent;
	Student s;
	PrintMenu();
	int k = 0;
	bool isLoop = true;
	char* keyID = new char[20];
	keyID[0] = '\0';

	FILE* dbFile;
	dbFile = fopen(fileName, "r");
	if(!feof(dbFile))
	{
		LoadInfoFromFileToVector(vctStudent);
	}
	fclose(dbFile);

	bool isSaved = false;

	while(isLoop)
	{
		do
		{
			printf("Ur choice: ");
			scanf("%d", &k);
		}while(k < 1 || k > 5);
		switch(k)
		{
		case 1:
			InputInfoStudent(s);
			vctStudent.push_back(s);
			isSaved = false;
			break;
		case 2:
			PrintListStudent(vctStudent);
			break;
		case 3:
			printf("Input Student ID: ");
			fflush(stdin);
			gets(keyID);
			DeleteInfoStudent(vctStudent, keyID);
			isSaved = false;
			break;
		case 4:
			dbFile = fopen(fileName, "w");
			for(int i = 0; i < vctStudent.size(); i++)
			{
				SaveInfo(vctStudent[i], dbFile);
			}
			fclose(dbFile);
			isSaved = true;
			break;
		case 5:
			isLoop = false;
			break;
		default:
			break;
		};
	};
	
	if(isSaved == false)
	{
		dbFile = fopen(fileName, "w");
		for(int i = 0; i < vctStudent.size(); i++)
		{
			SaveInfo(vctStudent[i], dbFile);
		}
		fclose(dbFile);
		isSaved = true;
	}

	return 0;
}

void PrintMenu()
{
	printf("1. input new Student\n");
	printf("2. print all list of student\n");
	printf("3. Del a student\n");
	printf("4. Save List of student\n");
	printf("5. Exit\n");
}