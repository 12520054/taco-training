//#include <stdio.h>
//#include <string>
//#include <string.h>
//
//void capitalizeString(char* str);
//bool IsCharHight(char s);
//bool IsCharLow(char s);
//
//int main()
//{
//	char* strBuffer = new char[1024];
//	strBuffer[0] = '\0';
//	FILE* file= fopen("infile.txt", "r");
//	FILE* file2 = fopen("outfile.txt", "w");
//
//	while(!feof(file))
//	{
//		fgets(strBuffer, 1024,file);
//		capitalizeString(strBuffer);
//		/*fputs(strBuffer, file2);*/
//		fprintf(file2, strBuffer);
//	};
//	fclose(file);
//	fclose(file2);
//	delete[] strBuffer;
//	return 0;
//}
//
//void capitalizeString(char* str)
//{
//	str[0] = toupper(str[0]);
//
//	if(strlen(str) > 1)
//	{
//		for(int i = 1; i < strlen(str); i++)
//		{
//			if(IsCharHight(str[i]))
//			{
//				str[i] = tolower(str[i]);
//			}
//		}
//		for(int i = 1; i < strlen(str) - 2; i++)
//		{
//			if(str[i] == '\.' && str[i + 1] == ' ')
//			{
//				str[i + 2] = toupper(str[i + 2]);
//			}
//		}
//	}
//}
//
//bool IsCharLow(char s)
//{
//	return (s >= 'a' || s <= 'z');
//}
//bool IsCharHight(char s)
//{
//	return (s >= 'A' || s <= 'B');
//}