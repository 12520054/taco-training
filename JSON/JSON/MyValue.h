#ifndef __MYVALUE_H__
#define __MYVALUE_H__

class MyValue
{
public:
	MyValue() {}
	virtual ~MyValue() {}
	virtual void Print() = 0;
};

#endif