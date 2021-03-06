#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
using namespace std;

string encodeCaesar(const char* plaintext, int shiftNumber);

char* _encodeCaesar(const char* plaintext, int shiftNumber);
// gán dãy số. 

int main()
{
	cout << encodeCaesar("aBcDeF %^&*()", 26000) << endl;
	return 0;
}


string encodeCaesar(const char* plaintext, int shiftNumber)
{
	string s = plaintext;
	
	int Num = shiftNumber % 26;

	for(int i = 0 ; i < s.length(); i++)
	{
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			if(s[i] >= 'a' && s[i] <= 'z')
			{
				int K = (int)'a' - 1;
				int T = (int)s[i] + Num;

				if(T > (int)'z')
				{
					T -= (int)'z';
					s[i] = char(T + ((int)'a' - 1));
				}
				else
				{
					s[i] = char(T);
				}
			}
			else
			{
				int K = (int)'A' - 1;
				
				int T = (int)s[i] + Num;

				if(T > (int)'Z')
				{
					T -= ((int)'Z');
					s[i] = char(T + ((int)'A' - 1));
				}
				else
				{
					s[i] = char(T);
				}
			}
		}
	}

	return s;
}