#include <stdio.h>
int main()
{
	char* myBuffer = new char[1024];
	myBuffer[0] = '\0';
	FILE* file = fopen("TranDanh.txt", "w");
	if(!file)
		perror("Cant open this fucking file to write something!\n");
	else
	{
		fputs("Tran Danh Danh Tran", file);
	}
	fclose(file);
	file = fopen("TranDanh.txt", "r");
	if(!file)
		perror("Cant open this fcking file to read something!");
	else
	{
		fgets(myBuffer, 1024, file);
	}
	puts(myBuffer);
	fclose(file);
	return 0;
}