#include <stdio.h>
#include <string.h>
#include <string>

int main()
{
	FILE* file = fopen("TextFile.txt", "r");
	char* strBuffer = new char[1024];
	while(!feof(file))
	{
		fgets(strBuffer, 1024, file);
		/*puts(strBuffer);*/ // don't use it. Because after u put this c_string on the screeen, it is auto endline.
		printf("%s", strBuffer);
	}
	fclose(file);
	delete[] strBuffer;
	return 0;
}