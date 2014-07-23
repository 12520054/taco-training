#include <stdio.h>

bool copyFile(const char* fileName);

int main()
{
	char* strFile = new char[50];
	gets(strFile);
	copyFile(strFile);
	return 0;
}

bool copyFile(const char* fileName)
{
	FILE* file = fopen(fileName, "r");

	if(!file)
		return false;

	FILE* file1 = fopen("Destination.TaDa", "w");

	char* strBuffer = new char[1024];
	while(!feof(file))
	{
		fgets(strBuffer, 1024, file);
		fputs(strBuffer, file1);
	}

	fclose(file);
	fclose(file1);
	delete[] strBuffer;
	return true;
}