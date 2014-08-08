#include <stdio.h>
#include <windows.h>
void PermisionManager(char* n);
void PrintMenu();
void setRead(char* n);
void setWrite(char* n);
void setExe(char* n);
void removeRead(char* n);
void removeWrite(char* n);
void removeExe(char* n);
bool checkRead(char* n);
bool checkWrite(char* n);
bool checkExe(char* n);
bool checkReadAndWrite(char* n);
int main()
{
	int n = 0;
	printf("Input your current Permision: ");
	do
	{
		scanf("%d", &n);
	}while(n < 1 || n > 7);
	PermisionManager((char*)&n);
	return 0;
};


void PrintMenu()
{
	printf("1.  Set Read Permission\n");
	printf("2.  Set Write Permission\n");
	printf("3.  Set Execute Permission\n");
	printf("4.  Remove Read Permission\n");
	printf("5.  Remove Write Permission\n");
	printf("6.  Remove Execute Permission\n");
	printf("7.  Check Read Permission\n");
	printf("8.  Check Write Permission\n");
	printf("9.  Check Execute Permission\n");
	printf("10. Check Read and Write Permission\n");
	printf("11. Exit\n");
}

bool checkRead(char* n)
{
	return (*n >> 2);
}
bool checkWrite(char* n)
{
	return ((*n >> 1) % 2);
}
bool checkExe(char* n)
{
	return *n % 2;
}
bool checkReadAndWrite(char* n)
{
	return ((*n >> 2) && ((*n >> 1) % 2));
}
void setRead(char* n)
{
	int i;
	printf("1: set read OK\n2: set read NONE\n");
	printf("Input your choice: ");
	scanf("%d", &i);
	switch(i)
	{
		case 1:
			if(!checkRead(n))
			{
				*n = *n | 1 << 2;
			}
			break;
		case 2:
			if(checkRead(n))
			{
				*n = ~(~*n | 1 << 2);
			}
			break;
		default:
			break;
	};
}

void setWrite(char* n)
{
	int i;
	printf("1: set write OK\n2: set write NONE\n");
	printf("Input your choice: ");
	scanf("%d", &i);
	switch(i)
	{
		case 1:
			if(!checkWrite(n))
			{
				*n = *n | 1 << 1;
			}
			break;
		case 2:
			if(checkWrite(n))
			{
				*n = ~(~*n | 1 << 1);
			}
			break;
		default:
			break;
	};
};
void setExe(char* n)
{
	int i;
	printf("1: set Exe OK\n2: set Exe NONE\n");
	printf("Input your choice: ");
	scanf("%d", &i);
	switch(i)
	{
		case 1:
			if(!checkExe(n))
			{
				*n = *n | 1;
			}
			break;
		case 2:
			if(checkExe(n))
			{
				*n = ~(~*n | 1);
			}
			break;
		default:
			break;
	};
};
void removeRead(char* n)
{
	if(checkRead(n))
	{
		*n = ~(~*n | 1 << 2);
	}
}
void removeWrite(char* n)
{
	if(checkWrite(n))
	{
		*n = ~(~*n | 1 << 1);
	}
}
void removeExe(char* n)
{
	if(checkExe(n))
	{
		*n = ~(~*n | 1);
	}
}
void PermisionManager(char* n)
{
	bool isLoop = true;
	while(isLoop)
	{
		system("cls");
		printf("Current Permission: %d\n", *n);
		PrintMenu();
		int k = 0;
		printf("Choose command: ");
		do
		{
			scanf("%d", &k);
		}while(k < 1 || k > 11);

		switch(k)
		{
		case 1:
			setRead(n);
			system("pause");
			break;
		case 2:
			setWrite(n);
			system("pause");
			break;
		case 3:
			setExe(n);
			system("pause");
			break;
		case 4:
			removeRead(n);
			system("pause");
			break;
		case 5:
			removeWrite(n);
			system("pause");
			break;
		case 6:
			removeExe(n);
			system("pause");
			break;
		case 7:
			if(checkRead(n))
			{
				printf("Can read\n");
			}
			else
				printf("Can't read\n");
			system("pause");
			break;
		case 8:
			if(checkWrite(n))
			{
				printf("Can Write\nn");
			}
			else
				printf("Can't Write\n");
			system("pause");
			break;
		case 9:
			if(checkExe(n))
			{
				printf("Can Execute\nn");
			}
			else
				printf("Can't Execute\n");
			system("pause");
			break;
		case 10:
			if(checkReadAndWrite(n))
				printf("Can read and write\n");
			else
				printf("Can't read or write\n");
			system("pause");
			break;
		case 11:
			isLoop = !isLoop;
			break;
		default:
			break;
		};
	}
}