#include <iostream>
#include <regex>
#include <string>
#include <string.h>
using namespace std;
using namespace std::tr1;

int main() 
{ 
    const string str = "Subversion Subject Subvision SubCode ... etc"; 
    smatch mr; 
 
	regex rx("(s|S)ub([^ ]*)");
	if(regex_search(str, mr,rx))
	{
		cout << mr[0] << endl;
	} // Em chi co the lam duoc nhu the nay.
	return (0); 
} 

// Nhung bai tap con lai tuong tu, chi khac nhau o cho doan code regex khac nhau.

/*
	1. In ra một từ tiếng anh: [a-zA-Z]+
	2. in 1 số có 3 chữ số: [0-9]{3}

	3. 1 số có 1 hoặc 2 , 3 chữ số: [0-9]{1,3}
	4. Các từ về color: ((C|c)olou?r)
	5. Từ đầu câu: \. [A-Z][a-z]+
	6. một số nguyên: [1-9][0-9]*
	7. một số thực:  -?[1-9][0-9]*\.[0-9]*[1-9]
	8. địa chỉ mail: [a-zA-z0-9]+\.*[a-zA-Z]+@[a-z]+\.[a-z]+\.*[a-z]*
	9. IP: 
		C1: [0-2][0-9][0-9].[0-2][0-9][0-9].[0-2][0-9][0-9]
		C2: chưa nghĩ ra
	10. <b>.+</b>
*/

