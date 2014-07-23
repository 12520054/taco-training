#ifndef __MAP_H__
#define __MAP_H__

#include <iostream>
using namespace std;

class CMap
{
private:
	int mRow;
	int mCol;
	int n;
	int** mArrMap;
public:
	CMap();
	CMap(int Row, int Col);
	void Init(int num);
	void DrawMap();
	~CMap();
};

#endif