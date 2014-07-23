#include <iostream>
#include <string.h>
#include <string>
using namespace std;

// :((

char* printReverseWords(const char* str);

int main()
{
	char* s = printReverseWords("p                Tran Danh Huu Vu Thanh Nhan Binh Minh            ");
	printf("%s\n",s );
	delete []s;
	return 0;
}

char* printReverseWords(const char* str)
{
	int n = strlen(str);
	char* s = new char[n + 1];
	s[0] = '\0';

	int Num = 0;

	for(int i = n - 1; i > -1; i--)
	{
		if(str[i] == ' ')
		{
			strncat(s,str + i + 1, Num);
			strcat(s," ");
			Num = -1;
		}
		Num++;
	}

	Num = 0;
	for(int i = 0; i < n; i++)
	{
		if(str[i] == ' ')
		{
			strncat(s, str, Num);
			break;
		}
		Num++;
	}
	return s;
}