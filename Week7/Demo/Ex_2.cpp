//#include <stdio.h>
//#include <conio.h>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int* Array;
//	int n;
//	scanf("%d", &n);
//	Array = new int[n];
//	for(int i = 0; i < n; i++)
//	{
//		scanf("%d", &Array[i]);
//	} // nhap du lieu
//
//	for(int i = 0; i < n - 1; i ++)
//	{
//		for(int j = i + 1; j < n; j++)
//		{
//			if(Array[i] < Array[j])
//			{
//				int Gemini = 0;
//				Gemini = Array[i];
//				Array[i] = Array[j];
//				Array[j] = Gemini;
//			}
//		}
//	} // Sort this array
//	
//	for(int i = 0; i < n; i++)
//		printf("%d ", Array[i]);
//
//	int Max = 1;
//	int TempMax = 0;
//	int index = 0;
//	for(int i = 0; i < n; i++)
//	{
//		TempMax = std::count(Array, Array + n, Array[i]);
//		if(TempMax > Max)
//		{
//			Max = TempMax; // dong code nay de cho zui ^^
//			index = i;
//		}
//	} // tim index co nhiu phan tu dong hang nhat
//
//	int indexMax;
//	for(int i = n - 2; i > -1; i--)
//	{
//		if(Array[i] != Array[i + 1])
//		{
//			indexMax = i + 1;
//			break;
//		}
//	}
//	
//	printf("\n%d %d\n", Array[index], indexMax + 1); // in ra gia tri phan tu co nhiu phan tu dong hang nhat
//	return 0;
//}