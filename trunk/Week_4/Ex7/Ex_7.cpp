#include <stdio.h>

int main()
{
	FILE* file = fopen("test.ini","r");
	if(!file)
		perror("Cant open this fucking file!");
	else
	{
		char* strBuffer = new char[1024];
		strBuffer[0] = '\0';
		FILE* file1 = fopen("output.txt", "wb");
		while(!feof(file))
		{
			fgets(strBuffer, 1024, file);
			fprintf(file1, strBuffer);
		};
		delete[] strBuffer;
	}
	fclose(file);
	return 0;
}