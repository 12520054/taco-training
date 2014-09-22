#ifndef __CSTRING_H__
#define __CSTRING_H__
#include "MyValue.h"
#include <string>
using namespace std;
class CString :
	public MyValue
{
	string mString;
public:
	CString(void);
	virtual ~CString(void);

	void Print();
	void setString(const string str);
	string getString();
};

#endif