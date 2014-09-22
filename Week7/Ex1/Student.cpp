#include "Student.h"

void PrintInfoStudent(const Student& s)
{
	printf("ID: %s\n", s.ID);
	printf("Name: %s\n", s.Name);
	printf("Age: %d\n", s.Age);
	printf("Point: %0.2f\n", s.Point);
}
void InputInfoStudent(Student& s)
{
	s.ID = new char[20];
	s.ID[0] = '\0';
	s.Name = new char[50];
	s.Name[0] = '\0';
	printf("ID: ");
	fflush(stdin);
	gets(s.ID);
	printf("Name: ");
	fflush(stdin);
	gets(s.Name);
	printf("Age: ");
	scanf("%d", &s.Age);
	printf("Point: ");
	scanf("%f", &s.Point);
}

void PrintListStudent(const vector<Student>& s)
{
	if(!s.empty())
	{
		for(int i = 0; i < s.size(); i++)
		{
			PrintInfoStudent(s[i]);
		}
	}
	else
		printf("Empty List!");
}

bool DeleteInfoStudent(vector<Student>& s, const char* _ID)
{
	int countStudent = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(strcmp(s[i].ID, _ID) == 0)
		{
			s.erase(s.begin() + i);
			countStudent++;
		}
	}
	if(countStudent)
		return true;
	else
		return false;
}
void SaveInfo(const Student& student, FILE* dbFile)
{
	fprintf(dbFile, "ID:%s|Name:%s|Age:%d|Point:%0.2f\n", student.ID, student.Name, student.Age, student.Point);
}
void LoadInfoFromString(Student& student, char* line)
{
	if(strlen(line) > 20)
	{
		char** token = new char*[4];
		token[0] = strtok(line, "|");
		token[1] = strtok(line + strlen(token[0]) + 1, "|");
		token[2] = strtok(line + strlen(token[0]) + strlen(token[1]) + 2, "|");
		token[3] = strtok(line + strlen(token[0]) + strlen(token[1]) + strlen(token[2]) + 3, "|");
		
		strcpy(student.ID, token[0] + 3);
		strcpy(student.Name, token[1] + 5);
		student.Age = atol(token[2] + 4);
		student.Point = atof(token[3] + 6);
	}
}
void LoadInfoFromFileToVector(vector<Student>& vctStudent)
{
	char line[256];
	line[0] = '\0';
	if(!vctStudent.empty())
	{
		vctStudent.clear();
	}
	FILE* dbFile = fopen(fileName, "r");
	while(!feof(dbFile))
	{
		Student s;
		s.ID = new char[20];
		s.Name = new char[50];
		s.Age = 0;
		s.Point = 0;
		fgets(line, 255, dbFile);
		LoadInfoFromString(s, line);
		vctStudent.push_back(s);
	}
	if(!vctStudent.empty())
		vctStudent.pop_back();
	fclose(dbFile);
}