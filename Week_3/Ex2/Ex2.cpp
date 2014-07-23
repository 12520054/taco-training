#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int countOccurrences(const char* str, const char* subStr);

int main()
{
	cout << countOccurrences("ABC ABC ABC", "ABC") << endl;
	return 0;
}

int countOccurrences(const char* str, const char* subStr)
{
	int N = 0;
	
	int strLen = strlen(str);
	int SubLen = strlen(subStr);

	for(int i = 0; i < strLen - SubLen + 1; i++)
	{
		if(str[i] == subStr[0])
		{
			if(strncmp((char*)(str + i), (char*)subStr, SubLen) == 0)
				N ++;
		}
	}

	return N;
}