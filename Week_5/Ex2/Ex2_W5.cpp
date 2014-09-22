#include <stdio.h>
#define N 5
void Add_1(int* arr, int n);

int main()
{
	int* Arr = new int[N];
	for(int i = 0; i < N; i++)
		*(Arr + i) = i+123;
	Add_1(Arr, N);
	for(int i = 0; i < N; i++)
		printf("%d ", *(Arr + i));
	delete[] Arr;
	return 0;
}
void Add_1(int* arr, int n) // using for an arr has n element
{
	char* c;
	for(int i = 0; i < n; i++)
	{
		c = (char*)(arr + i);
		*c += 1;
		if (*c == ' ')
			*(c + 1) += 1;

		if(*(c + 1) == ' ')
			*(c + 2) += 1;

		if(*(c + 2) == ' ')
			*(c + 3) += 1;
	}
}