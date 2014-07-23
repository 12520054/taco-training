#include <stdio.h>

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	char* c;
	for(int i = 0; i < 5; i++)
	{
		c = (char*)&arr[i];
		for(int j = 0; j < 4; j++)
		{
			*(c + j) += 1;

		}
		printf("%d ", arr[i]);
	}
}