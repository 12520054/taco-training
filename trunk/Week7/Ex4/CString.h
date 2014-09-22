#pragma once
#include "value.h"
#include <string>
using namespace std;
class String :
	public Value
{
	string mString;
public:
	String(void);
	virtual ~String(void);

	void Print();
	void setString(const string str);
	string getString();
};
