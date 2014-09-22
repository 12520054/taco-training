#include <stdio.h>

void printLittleAddressValue(int* i);
//void printBigAddreeValue(int* i);

int main()
{
	int i = 256000;
	printLittleAddressValue(&i);
	return 0;
}
void printLittleAddressValue(int* i)
{
	char* c = (char*)i;
	printf("%x ",*c);
	printf("%x ",*(c + 1));
	printf("%x ",*(c + 1));
	printf("%x ",*(c + 1));
}