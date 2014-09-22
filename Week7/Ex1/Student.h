#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

#define fileName "students.tacodb"

using namespace std;

typedef struct
{
	char*	ID;
	char*	Name;
	int		Age;
	float	Point;
} Student;

void PrintInfoStudent(const Student& s);
void InputInfoStudent(Student& s);
void PrintListStudent(const vector<Student>& s);
bool DeleteInfoStudent(vector<Student>& s,const char* _ID);
void SaveInfo(const Student& student, FILE* dbFile);
void LoadInfoFromString(Student& student, char* line);
void LoadInfoFromFileToVector(vector<Student>& vctStudent);