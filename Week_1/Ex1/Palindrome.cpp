#include <iostream>
#include <assert.h>
#include <string.h>
#include <string>
using namespace std;

bool testPalindrome(const char* str);

int main()
{
	assert(testPalindrome("ABCBA"));
	assert(testPalindrome("ABCCBA"));
	assert(testPalindrome("\n\t\n"));
	assert(testPalindrome(""));
	assert(testPalindrome(" "));
	char* s = NULL;
	assert(testPalindrome(s));
	return 0;
}

bool testPalindrome(const char* str)
{
	assert(str != NULL);

	int count = strlen(str) / 2;

	for(int i = 0; i < count + 1; i ++)
	{
		if(str[i] == str[strlen(str) - i - 1])
		{
			return true;
		}
	}
	return false;
}

// Yêu cầu:
/*
	- Kiểm tra chuỗi có đối xứng không?
*/
// Ràng buộc:
/*
	- Chuỗi nhập vào không NULL
	- hàm trả về true nếu chuỗi đối xứng, false nếu không đối xứng
*/
// Bộ test:
/*
	Có trong hàm main
*/