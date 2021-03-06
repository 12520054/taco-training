#include <iostream>
#include <assert.h>
using namespace std;
#define COUNT 10
int binarySearch(const int* arr, int numElenments);

int main()
{
	int* a = new int[COUNT];	

	for(int i = 0; i < COUNT; i++)
		a[i] = i;

	cout << binarySearch(a, 3);
	return 0;
}

int binarySearch(const int* arr, int numElements)
{
	assert(arr != NULL);
	if(COUNT == 0)
	{
		if(arr[0] == numElements)
			return 0;
		else
			return -1;
	}
	else
	{
		int Left, Right, Mid;
		Left = 0;
		Right = COUNT;

		while(Left < Right)
		{
			Mid = (Left + Right) / 2;
			if(arr[Mid] == numElements)
				return Mid;
			else
			{
				if(numElements < arr[Mid])
					Right = Mid - 1;
				else
					Left = Mid + 1;
			}

		}
	}
	return -1;
}

// Yêu cầu
 /*
	- Thực hiện thuạt toán binary Search theo numElement
 */
// Ràng buộc
	/*
		- mảng vào không NULL
		- MẢng đầu vào phải là mảng thứ tự tăng dần
		- trả về VỊ TRÍ CỦA PHẦN TỬ
	*/