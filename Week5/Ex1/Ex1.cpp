#include <stdio.h>

void Swap(char* a, char* b);

int main()
{
	int a = 0x12345678;
	char* s = (char*)&a;
	Swap(s, s + 3);
	Swap(s + 1, s + 2);
	printf("%x", a);
	return 0;
}

void Swap(char* a, char* b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}