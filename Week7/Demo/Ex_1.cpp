//#include <stdio.h>
//
//int main()
//{
//	int* Array = 0;
//	int n = 3;
//	
//	scanf("%d", &n);
//	Array = new int[n];
//	for(int i = 0; i < n; i++)
//	{
//		scanf("%d", &Array[i]);
//	}
//
//	int Max = 1;
//	int lastMax = 1;
//	for(int i = 1; i < n; i++)
//	{
//		if(Array[i] > Array[i - 1])
//			lastMax += 1;
//		else
//		{
//			if(lastMax > Max)
//			{
//				Max = lastMax;
//			}
//			lastMax = 1;
//		}
//	}
//	
//	printf("%d", Max);
//	return 0;
//}