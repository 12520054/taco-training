#ifndef __NUMBER_H__
#define __NUMBER_H__
#include "value.h"

class Number :
	public Value
{
	int mNumber;
public:
	void setValue(int n);
	int getValue();
	void Print();
	Number(void);
	virtual ~Number(void);
};
#endif