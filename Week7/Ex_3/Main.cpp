#include <stdio.h>

typedef struct JSONObjectStudent
{
	char* Name;
	int Age;
	char* ListSubjectName[3];
	float Point;
} JSONObjectStudent;

void InputJSONObjectStudent(JSONObjectStudent* jsonStudent);

void WriteObjectToJsonFile(const JSONObjectStudent jsonObject, const char* fileName);

int main()
{
	
	JSONObjectStudent* Student = new JSONObjectStudent;
	InputJSONObjectStudent(Student);
	WriteObjectToJsonFile(*Student, "json-student.json");
	delete Student;

	return 0;
}

void InputJSONObjectStudent(JSONObjectStudent* jsonStudent)
{
	jsonStudent->Name = new char[50];
	fflush(stdin);
	printf("Name: ");
	gets(jsonStudent->Name);
	printf("Age: ");
	scanf("%d", &jsonStudent->Age);
	for(int i = 0; i < 3; i++)
	{
		jsonStudent->ListSubjectName[i] = new char[50];
		printf("Subject %d: ", i);
		fflush(stdin);
		gets(jsonStudent->ListSubjectName[i]);
	}
	printf("Point: ");
	scanf("%f", &jsonStudent->Point); 
}

void WriteObjectToJsonFile(const JSONObjectStudent jsonObject, const char* fileName)
{
	FILE* jsonFile = fopen(fileName, "a");
	if(!jsonFile)
		perror("Can't open this file");
	else
	{
		fprintf(jsonFile, "{\n");
		fprintf(jsonFile, "\t\"Name\":\"%s\",\n", jsonObject.Name);
		fprintf(jsonFile, "\t\"Age\":%d,\n", jsonObject.Age);
		fprintf(jsonFile, "\t\"ListSubjectName\": [");
		fprintf(jsonFile, "\"%s\",", jsonObject.ListSubjectName[0]);
		fprintf(jsonFile, "\"%s\",", jsonObject.ListSubjectName[1]);
		fprintf(jsonFile, "\"%s\"],\n", jsonObject.ListSubjectName[2]);
		fprintf(jsonFile, "\t\"Point\":%0.2f\n", jsonObject.Point);
		fprintf(jsonFile, "}\n");
	}
	fclose(jsonFile);
}
