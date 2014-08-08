#include <stdio.h>
#include <string>
#include <string.h>

void ToUpperChar(char& c);

char* ToUpperString(const char* str);


int main()
{
	
	printf("%s", ToUpperString("i love c++ programming\n"));
	return 0;
}


void ToUpperChar(char& c)
{
	int n_char = int(c);
	if(n_char >= 97 && n_char <= 122)
	{
		n_char = n_char ^ 32;
		c = char(n_char);
	}
}

char* ToUpperString(const char* str)
{
	int n = strlen(str);
	char* _str;
	_str = new char[n + 1];
	_str[n] = '\0';
	for(int i = 0; i < n; i++)
	{
		_str[i] = str[i];
		ToUpperChar(_str[i]);
	}
	return _str;
}