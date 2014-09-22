#include "Number.h"
#include <stdio.h>

Number::Number()
{
	this->mNumber = 0;
}

Number::Number(const Number* n)
{
	this->mNumber = n->mNumber;
}

Number::~Number()
{
}

int Number::getValue()
{
	return this->mNumber;
}
void Number::setValue(int n)
{
	this->mNumber = n;
}
void Number::Print()
{
	printf("%d", mNumber); 
}