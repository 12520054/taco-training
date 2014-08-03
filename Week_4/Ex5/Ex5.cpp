#include <stdio.h>
int main()
{
	int	width, height;

	FILE* file = fopen("TD.tga", "rb");
	if(!file)
		perror("Can't open this file!!\n");
	else
	{
		short buff;
		fseek(file, 12, 0);
		fread(&buff, 1, 2, file);
		printf("Width: %d\n", buff);
		fread(&buff, 1, 2, file);
		printf("Height: %d\n", buff);
	}
	fclose(file);
	return 0;
}