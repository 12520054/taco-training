#include <stdio.h>
#include <string.h>
#include <string>

int main()
{
	printf("Input fileName link: ");
	char* fileName = new char[50];
	char c_Buffer;
	fflush(stdin);
	gets(fileName);
	FILE* file = fopen(fileName, "rb");
	if(!file)
	{
		perror("Can't find this fucking file");
		return 69;
	}
	else
	{
		while(!feof(file))
		{
			c_Buffer = fgetc(file);
			printf("%d ",c_Buffer);
		};
	}
	fclose(file);
	return 0;
}