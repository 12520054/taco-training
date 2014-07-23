#include <stdio.h>
#include <iostream>

using namespace std;

int envaluePokerHandleLevel(const char* Hand);
char* NormalString(const char* Hand);

int NumPair(int** arrCard);
bool IsThreeOfAKind(int** arrCard);
bool IsStraight(int** arrCard); // Sanh~ Card
bool IsFlush(int** arrCard); // 5 la cung chat
bool IsFourOfAKind(int** arrCard); // 4 qui'

int main()
{
	char* s = "     2S 3C 4S 5S 6C         ";
	//cout << s << endl;
	cout << envaluePokerHandleLevel(s) << endl;
	return 0;
}

bool IsFourOfAKind(int** arrCard)
{
	if(arrCard[0][0] == arrCard[3][0] || arrCard[1][0] == arrCard[4][0])
		return true;
	return false;
}
bool IsThreeOfAKind(int** arrCard)
{
	if(!IsFourOfAKind(arrCard))
	{
		if(arrCard[0][0] == arrCard[2][0]|| arrCard[1][0] == arrCard[3][0] || arrCard[2][0] == arrCard[4][0])
			return true;
	}
	return false;
}
int NumPair(int** arrCard)
{
	int count = 0;
	if(!IsThreeOfAKind(arrCard) && !IsFourOfAKind(arrCard))
	{
		for(int i = 0; i < 4; i++)
		{
			if(arrCard[i][0] == arrCard[i + 1][0])
				count++;
		}
	}
	else
	{
		if(arrCard[0][0] == arrCard[1][0]
		|| arrCard[3][0] == arrCard[4][0])
			count = 1;
	}
	return count;
}

bool IsStraight(int** arrCard)
{
	int count = 0;

	for(int i = 0; i < 4; i++)
	{
		if(arrCard[i][0] + 1 == arrCard[i + 1][0])
			count++;
	}
	if(count == 4)
		return true;
	return false;
}
bool IsFlush(int** arrCard)
{
	int count = 0;
	for(int i = 0; i < 4; i++)
	{
		if(arrCard[i][1] == arrCard[i + 1][1])
			count++;
	}
	if(count == 4)
		return true;
	return false;
}
char* NormalString(const char* Hand)
{
	char* s;

	s = new char[strlen(Hand) + 1];
	s[strlen(Hand)] = '\0';

	for(int i = 0; i < strlen(Hand); i++)
	{
		s[i] = Hand[i];
	}

	while(s[0] == ' ')
	{
		s = s+1;
	};
	while(s[strlen(s) - 1] == ' ')
	{
		s[strlen(s) - 1] = '\0';
	};

	for(int i = 1; i < strlen(s) - 2; i++)
	{
		if(s[i] == ' ' && s[i + 1] == ' ')
		{
			for(int j = i + 1; j < strlen(s) - 1; j++)
			{
				s[j] = s[j + 1];
			}
			s[strlen(s) - 1] = '\0';
			i--;
		}
	}
	return s;
}

int envaluePokerHandleLevel(const char* Hand)
{

	char* s = NormalString(Hand);

	cout << s << endl;

	char* Poker[5];


	int startIndex = 0;
	int count = 0;

	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i] == ' ')
		{
			Poker[count] = new char[i - startIndex + 1];
			Poker[count][i - startIndex] = '\0';
			strncpy(Poker[count], s + startIndex, i - startIndex);
			count++;
			startIndex = i + 1;
		}
	}

	for(int i = strlen(s) - 1; i > 0; i--)
	{
		if(s[i] == ' ')
		{
			Poker[4] = new char[strlen(s) - i + 1];
			Poker[4][strlen(s) - i] = '\0';
			strncpy(Poker[4], s + i + 1, strlen(s) - i);
			break;
		}
	}

	// At here we have 5 c_String.
	// 1 c_string is a Poker card
	// Poker[0], Poker[1], Poker[2], Poker[3], Poker[4]

	//for(int i = 0; i < 5; i++)
	//	cout << Poker[i] <<endl;
	
	int** ArrCard = new int*[5];

	for(int i = 0; i < 5; i++)
	{
		ArrCard[i] = new int[2];
	}
	
	for(int i = 0; i < 5; i++)
	{
			switch(Poker[i][strlen(Poker[i]) - 1])
			{
			case 'S':
				ArrCard[i][1] = 1;
				break;
			case 'H':
				ArrCard[i][1] = 2;
				break;
			case 'D':
				ArrCard[i][1] = 3;
				break;
			case 'C':
				ArrCard[i][1] = 4;
				break;
			};

			 switch(Poker[i][0])
			 {
			 case '1':
				 ArrCard[i][0] = 10;
				 break;
			 case '2':
				 ArrCard[i][0] = 2;
				 break;
			 case '3':
				 ArrCard[i][0] = 3;
				 break;
			 case '4':
				 ArrCard[i][0] = 4;
				 break;
			 case '5':
				 ArrCard[i][0] = 5;
				 break;
			 case '6':
				 ArrCard[i][0] = 6;
				 break;
			 case '7':
				 ArrCard[i][0] = 7;
				 break;
			 case '8':
				 ArrCard[i][0] = 8;
				 break;
			 case '9':
				 ArrCard[i][0] = 9;
				 break;
			 case 'J':
			 case 'j':
				 ArrCard[i][0] = 11;
				 break;
			 case 'Q':
			 case 'q':
				 ArrCard[i][0] = 12;
				 break;
			 case 'K':
			 case 'k':
				 ArrCard[i][0] = 13;
				 break;
			 case 'A':
			 case 'a':
				 ArrCard[i][0] = 14;
				 break;
			 };
	}
	// now we have an array[5][2]
	// in a row of this array, 
	// the Arr[i][0] is the Number value of the Card number i
	// and Arr[i][1] is the second value of this Card

	//for(int i = 0; i < 5; i++)
	//{
	//	for(int j = 0; j < 2; j++)
	//		cout << ArrCard[i][j] << " ";
	//	cout <<endl;
	//}

	if(IsStraight(ArrCard) && IsFlush(ArrCard))
	{
		if(ArrCard[4][0] == 14) //  trong cay bai` co la A
			return 9;
		return 8;
	}

	if(IsFourOfAKind(ArrCard))
		return 7;
	if((IsThreeOfAKind(ArrCard) == true) && (NumPair(ArrCard) == 1))
		return 6;
	if(IsFlush(ArrCard))
		return 5;
	if(IsStraight(ArrCard))
		return 4;
	if(IsThreeOfAKind(ArrCard))
		return 3;
	if(NumPair(ArrCard) == 2)
		return 2;
	if(NumPair(ArrCard) == 1)
		return 1;
	return 0;
}
