//#include <stdio.h>
//#include <conio.h>
//#include <algorithm>
//using namespace std;
//
//int countElement(int* Array, int n, int Element)
//{
//	int count = 0;
//	for(int i = 0; i < n; i++)
//	{
//		if(Array[i] == Element)
//		{
//			count += 1;
//		};
//	}
//	return count;
//}
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
//	int		count = 0;
//	float	MaxAverage = 0.0;
//	float	lastMaxAverage = 0.0;
//	int		MaxElement = 0;
//	for(int i = 0; i < n; i++)
//	{
//		count = std::count(Array, Array + n, Array[i]);
//		lastMaxAverage = (float)Array[i]*count / n;
//		if(lastMaxAverage > MaxAverage)
//		{
//			MaxAverage = lastMaxAverage;
//			MaxElement = Array[i];
//		}
//	}
//	printf("\n\n%d", MaxElement);
//	return 0;
//}