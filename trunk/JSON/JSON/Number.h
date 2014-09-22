#ifndef __NUMBER_H__
#define __NUMBER_H__
#include "MyValue.h"

class Number : public MyValue
{
private:
	int mNumber;
public:
	Number();
	Number(const Number* n);
	virtual ~Number();

	void setValue(int n);
	int getValue();
	void Print();
};
#endif