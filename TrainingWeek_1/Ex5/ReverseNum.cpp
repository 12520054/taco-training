#include <iostream>
#include <assert.h>
using namespace std;

int reverseDigits(int n);

int main()
{
	cout << reverseDigits(1234)<<endl;
	cout << reverseDigits(9999)<<endl;
	cout << reverseDigits(12340)<<endl; 

	return 0;
}

int reverseDigits(int n)
{

	int m = 0;
	int count = 0;
	if(n < 10)
		m = n;
	else
	{
		do
		{
			m = m*10 + n%10;
			n /= 10;
		}while(n > 0);
	}

	return m;
}

// yêu cầu
	/*
		trả về số bị đảo ngược lại so với số cũ
	*/
// ràng buộc
	/*
		- Tham số nhập vào là số nguyên dương
	*/