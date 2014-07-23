#include <iostream>
#include "CMap.h"
using namespace std;



int main()
{
	CMap* Map = new CMap(10,10);
	Map->Init(10);
	Map->DrawMap();
	return 0;
}