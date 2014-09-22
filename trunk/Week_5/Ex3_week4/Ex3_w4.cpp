 // 
#include <stdio.h>
#include <string.h>
#include <string>
//#include <windows.h>
bool eraseComment(const char* fileName);

int main()
{
	char* fileName = new char[100];
	fflush(stdin);
	gets(fileName);
	eraseComment(fileName);
	delete [] fileName;
	return 0;
}

bool eraseComment(const char* fileName)
{
	FILE* sourceFile = fopen(fileName, "r");
	FILE* desFile = fopen("Templ.TaDa", "w");
	if(!sourceFile)
	{
		perror("Can't open this file");
		return false;
	}
	else
	{
		char curBuff, lastBuff = ' ';
		bool IsComment = false;
		curBuff = lastBuff = fgetc(sourceFile);
		while(!feof(sourceFile))
		{
			curBuff = fgetc(sourceFile);
			if(curBuff != EOF)
			{
				if(curBuff == lastBuff && curBuff == '/')
				{
					for(int i = 0; curBuff != '\n'; i++)
					{
						if(curBuff != EOF)
						{
							curBuff = fgetc(sourceFile);							
						}
					};
				}
				else
				{
					if(curBuff == '*' && lastBuff == '/')
					{
						while(curBuff != '/' && lastBuff != '*')
						{
							if(curBuff != EOF)
							{
								curBuff = fgetc(sourceFile);
							}
						};
						curBuff = fgetc(sourceFile);
						lastBuff = curBuff;
					}
					else
					{
						fprintf(desFile,"%c",lastBuff);
					}
				}
				lastBuff = curBuff;
			}
		};
		fclose(sourceFile);
		fclose(desFile);
		sourceFile = fopen(fileName, "w");
		desFile = fopen("Templ.TaDa","r");
		while(!feof(desFile))
		{
			curBuff = fgetc(desFile);
			if(curBuff != EOF)
				fprintf(sourceFile, "%c", curBuff);
		}
		fclose(sourceFile);
		fclose(desFile);
		remove("Templ.TaDa");
	}
	return true;
}