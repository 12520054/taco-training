#include "CMap.h"
#include <time.h>
CMap::CMap()
{
	this->mCol = this->mRow = this->n = 0;
}

CMap::CMap(int Row, int Col)
{
	this->mCol = Col + 2;
	this->mRow = Row + 2;
	this->mArrMap = new int*[Row];
	for(int i = 0; i < mRow; i++)
		this->mArrMap[i] = new int[mCol];

	for(int i = 0; i < mRow; i ++)
		for(int j = 0; j < mCol; j++)
		{
			mArrMap[i][j] = 0;
		}
}

void CMap::Init(int num)
{
	this->n = num;
	srand(time(NULL));
	for(int i = 0; i < n; i++)
	{
F:
		int r = (rand() % (mRow - 1));
		int c = (rand() % (mCol -1));
		if(this->mArrMap[r][c] == -1 || r == 0 || c == 0)
			goto F;
		else
		{
		this->mArrMap[r][c] = -1;
		}

	}

	for(int i = 1; i < mRow - 1; i ++)
	{
		for(int j = 1; j < mCol - 1; j++)
		{
			if(mArrMap[i][j] == 0)
			{
				int x = 0;
				if(mArrMap[i - 1][j - 1] == -1)
					x += 1;				
				if(mArrMap[i - 1][j] == -1)
					x += 1;
				if(mArrMap[i - 1][j + 1] == -1)
					x += 1;
				if(mArrMap[i][j - 1] == -1)
					x += 1;
				if(mArrMap[i][j + 1] == -1)
					x += 1;
				if(mArrMap[i + 1][j + 1] == -1)
					x += 1;
				if(mArrMap[i + 1][j] == -1)
					x += 1;
				if(mArrMap[i + 1][j - 1] == -1)
					x += 1;							
				mArrMap[i][j] = x;
			}
		}
	}
}

void CMap::DrawMap()
{
	for(int i = 1; i < mRow -1; i ++)
	{
		for(int j = 1; j < mCol - 1; j++)
		{
			if(mArrMap[i][j] == -1)
			{
				cout << char(3) << " ";
			}
			else
				cout << mArrMap[i][j] << " ";
		}
		cout << endl;
	}
}

CMap::~CMap()
{
	for(int i = 0; i < mRow; i++)
	{
		delete []mArrMap[i];
	}
	delete [] mArrMap;
}