#include <stdio.h>

int (*Function)(int a,int b);

int add(int a,int b);
int sub(int a, int b);

int main()
{
	int a, b;
	char c;
	scanf("%d %d %c", &a, &b, &c);
	switch(c)
	{
	case '+':
		Function = &add;
		printf("The sum of a and b: %d\n", (*Function)(a,b));
		break;
	case '-':
		Function = &sub;
		printf("Sub of a and b: %d\n", (*Function)(a,b));
		break;
	default:
		printf("Un define this operator!\n");
		break;
	};
	return 0;
}
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}