#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int m = ~n + 1;
	printf("%d %x\n", n, n);
	printf("%d %x", m, m);
	//char char s;
	return 0;
}