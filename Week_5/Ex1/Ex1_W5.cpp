#include <stdio.h>

void changIntoLittleEndian(int* i);
void Swap(char* a, char* b);
int main()
{
	int i = 0x11223344;
	printf("%x\n", i);
	changIntoLittleEndian(&i);
	printf("%x", i);
	return 0;
}
 
void Swap(char* a, char* b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}

void changIntoLittleEndian(int* i)
{
	char* c = (char*)&(*i);
	Swap(c, c + 3);
	Swap(c + 1, c + 2);
}