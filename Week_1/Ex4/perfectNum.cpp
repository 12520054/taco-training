#include <iostream>
#include <assert.h>
using namespace std;


bool isPerfectNumber(int n);

int main()
{
	assert(isPerfectNumber(6));
	assert(!isPerfectNumber(1));
	assert(!isPerfectNumber(3));
	assert(!isPerfectNumber(0));
	assert(!isPerfectNumber(-1));

	return 0;
}

bool isPerfectNumber(int n)
{
	if(n < 0)
		return false;
	int s = 0;
	for(int i = 1; i < n/2 + 1; i++)
	{
		if(n%i == 0)
			s += i;
	}
	if(s == n)
		return true;
	return false;
}

// yêu cầu
	/*
		- Kiểm tra số có phải perfect không?
	*/
// Ràng buộc
	/*
		- Nhập vào là 1 số nguyên > 0
		- trả về true nếu đúng là số perfect, false nếu ngược lại
	*/