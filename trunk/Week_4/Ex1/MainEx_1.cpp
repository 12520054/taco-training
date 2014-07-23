#include <stdio.h>
#include <string>
#include <string.h>

void capitalizeString(const char* fileName);
int main()
{
	char* s = new char[50];
	fflush(stdin);
	gets(s);
	capitalizeString(s);
	delete[] s;
	return 0;
}

void capitalizeString(const char* fileName)
{
	FILE* sourceFile = fopen(fileName,"r");
	if(!sourceFile)
	{
		perror("Can't open this file");
		return;
	}
	FILE* desFile = fopen("Templ.Danh","w");
	char curBuff;
	char pre1Buff = ' ';
	char pre2Buff = ' ';
	bool IsCap = true;

	while(!feof(sourceFile))
	{
		curBuff = fgetc(sourceFile);

		if(curBuff != EOF)
		{
			if(pre1Buff == '.' || (pre1Buff == ' ' && pre2Buff == '.') || pre1Buff == '\n')
			IsCap = !IsCap;

			if(IsCap == true)
			{
				curBuff = toupper(curBuff);
				fprintf(desFile, "%c", curBuff);
				IsCap = false;
			}
			else
			{
				curBuff = tolower(curBuff);
				fprintf(desFile, "%c", curBuff);
			}
			pre2Buff = pre1Buff;
			pre1Buff = curBuff;
		};
	}
	fclose(sourceFile);
	fclose(desFile);

	sourceFile = fopen(fileName, "w");
	desFile = fopen("Templ.Danh", "r");
	while(!feof(desFile))
	{
		curBuff = fgetc(desFile);
		if(curBuff != EOF)
		{
			putc(curBuff, sourceFile);
		}
	};
	fclose(sourceFile);
	fclose(desFile);
	remove("Templ.Danh");
	
}
