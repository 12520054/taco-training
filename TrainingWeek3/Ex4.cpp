#include <iostream>
#include <string.h>
#include <string>
using namespace std;

// :((

char* printReverseWords(const char* str);

int main()
{
	printf("%s\n", printReverseWords("Tran Huu Danh nguyen Hai Dang Nguyen TaCo"));
	return 0;
}

char* printReverseWords(const char* str)
{
	// bài tập giả sử bộ test là những bộ thỏa mãn điều kiện "xxxxxxxxxxxx yyyyyyyyyyy zzzzzzzzzzzzzzzzz"
	int n = strlen(str);
	char* s = new char[n + 1];

	int flag = n;
	int k = 0;

	for(int i = n - 1; i > -1; i--)
	{
		if(str[i] == ' ')
		{
			for(int j = i + 1; j < flag; j++)
			{
				s[k++] = str[j];
			}
			flag = n - k;
			s[k] = ' ';
			k++;
			//break;
		}
	}

	k--;
	for(int i = 0; i < n; i++)
	{
		if(str[i] == ' ')
		{
			for(int j = 0; j < i; j++)
			{
				s[k] = str[j];
				k++;
			}
			break;
		}
	}

	s[n] = '\0';
	return s;
	//int k = 0; // dem ky tu bat dau

	//int z = n; // vi tri lam moc

	//for(int i = n - 1; i > -1; i--)
	//{
	//	if(str[i] == ' ')
	//	{
	//		for(int j = i + 1; j < z; j++)
	//		{
	//			s[k] = str[j];
	//			k += 1;
	//		}
	//		z = n - k;
	//		s[k] = ' ';
	//		k+=1;
	//	}
	//}
	//k--;
	//for(int i = 0; i < n; i++)
	//{
	//	if(str[i] == ' ')
	//	{
	//		for(int j = 0; j < i; j++)
	//		{
	//			s[k] = str[j];
	//			k++;
	//		}
	//		break;
	//	}
	//}

}