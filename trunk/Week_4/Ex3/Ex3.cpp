// This program can erase a comment in a cpp/h file or more type file
//  but it can't erase a block of comment

#include <stdio.h>
#include <string>
#include <string.h>

bool eraseComment(char* fileName);

int main()
{

	char* strFile = new char[20];
	gets(strFile);
	if(eraseComment(strFile))
	{
		printf("erase comment complete");
		delete[] strFile;
	}
	else
	{
		printf("Can't erase Comment in this fucking file\n");
		delete[] strFile;
		return 0;
	}
	return 0;
}

bool eraseComment(char* fileName)
{
	FILE* sourceFile = fopen(fileName, "r");
	FILE* desFile = fopen("Template.txt", "w");

	if(!sourceFile)
	{
		perror("Can't open this file");
		return false;
	}
	else
	{
		char* strBuff = new char[1024];
		while(!feof(file))
		{
			fgets(strBuff, 1024, file);
			for(int i = 0; i < strlen(strBuff); i++)
			{
				if(strBuff[i] == '/')
				{
					if(strBuff[i + 1] == '/')
					{
						strBuff[i] = '\0';
						//  do something to puts the c_string s affter process in new file.
					} 
					if(strBuff[i + 1] == '*')
					{
						// fuck some code
					}
				}
			}
			fputs(strBuff, file1);
		}
		
		fclose(file);
		fclose(file1);

		file = fopen(fileName, "w");
		file1 = fopen("Template.txt", "r");

		while(!feof(file1))
		{
			fgets(strBuff, 1024, file1);
			fputs(strBuff, file);
		};

		fclose(file);
		fclose(file1);
		delete[] strBuff;
		remove("Template.txt");
		return true;
	}
}