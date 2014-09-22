#include "Number.h"
#include <stdio.h>
Number::Number(void)
{
}

Number::~Number(void)
{
}

void Number::setValue(int n)
{
	this->mNumber = n;
}
int Number::getValue()
{
	return this->mNumber;
}

void Number::Print()
{
	printf("%d", this->mNumber);
}