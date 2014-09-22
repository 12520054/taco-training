#include <stdio.h>

class A
{
private:
public:
int (*foo)(int a);
int f(int a){}
};

int main()
{
	int a = 10;
	char* pa = (char*)&a;
	*(pa + 1) = 1;
	// = *(pa + 1) << 1;
	printf("%d", a);
	return 0;
}