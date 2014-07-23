#include <iostream>
#include <string.h>
#include <string>

using namespace std;

string capitalizeWords(const char* str);

int main()
{
	char *s = "tran danh uIT 5%%% %^* ()) 9 00 - - == =    pp p p pp p ";
	cout << capitalizeWords(s) << endl;
	return 0;
}

string capitalizeWords(const char* str)
{
	string s = str;
	s[0] = toupper(s[0]);
	for(int i = 1; i < s.length() - 1; i++)
	{
		if(s[i] == ' ')
		{
			s[i+1] = toupper(s[i+1]);
		}
	}
	return s;
}