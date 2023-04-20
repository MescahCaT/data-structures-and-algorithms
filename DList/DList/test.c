#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"

void DListTest1()
{

	PDL pheard;
	DLInit(&pheard);

	//DLpushback(pheard, 1);
	//DLpushback(pheard, 2);
	//DLpushback(pheard, 3);
	//DLpushback(pheard, 4);
	//DLpushback(pheard, 5);
	//DLpushback(pheard, 6);

	//DLprint(pheard);

	DLpushfront(pheard, 1);
	DLpushfront(pheard, 2);
	DLpushfront(pheard, 3);
	DLpushfront(pheard, 4);
	DLpushfront(pheard, 5);

	DLprint(pheard);

	//DLpopfront(pheard);
	//DLpopfront(pheard);
	//DLpopfront(pheard);
	//DLprint(pheard);

	DLpopback(pheard);
	DLprint(pheard);

	DListdestory(pheard,pheard);

}


int main()
{
	DListTest1();

	return 0;
}