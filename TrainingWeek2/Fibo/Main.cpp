#include <iostream>
using namespace std;

unsigned long Fibo(unsigned long n);

unsigned long CaculateFibo(unsigned long n,unsigned long* Arr);
int main()
{

	cout << sizeof(unsigned long) <<endl;
	return 0;
}

unsigned long Fibo(unsigned long n)
{
	if(n == 1 || n == 2)
		return 1;
	else
	{
		unsigned long* Arr = new unsigned long[n + 1];
		for(int i = 0; i < n + 1; i++)
		{
			*(Arr + i) = -1;
		}
		return CaculateFibo(n,Arr);
	}
}

unsigned long CaculateFibo(unsigned long n, unsigned long* Arr)
{
	if(*(Arr + n - 1) != -1)
	{
		*(Arr + n) = *(Arr + n - 1) + *(Arr + n - 2);
		return *(Arr + n);
	}
	else
	{}
}