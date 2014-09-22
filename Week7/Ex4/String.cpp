#include "CString.h"

String::String(void)
{
}

String::~String(void)
{
}

void String::Print()
{
	printf("%s", mString.c_str());
}
string String::getString()
{
	return mString;
}
void String::setString(const string str)
{
	mString = str;
}