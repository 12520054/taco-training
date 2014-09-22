#include "CString.h"

CString::CString(void)
{
}

CString::~CString(void)
{
}

void CString::Print()
{
	printf("%s", mString.c_str());
}
string CString::getString()
{
	return mString;
}
void CString::setString(const string str)
{
	mString = str;
}