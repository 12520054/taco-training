#include <stdio.h>
void swap(int* a, int* b);

int main()
{
	return 0;
}
void swap(int* a, int* b)
{
	*b = *a ^ *b;
	
}