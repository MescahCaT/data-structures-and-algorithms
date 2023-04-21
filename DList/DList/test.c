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

	printf("the postion of '%d' is %d\n",6,DListSearch(pheard, 6));

	DListdestory(pheard,pheard);

}


DListTest2()
{

	PDL pheard;
	DLInit(&pheard);

	DLpushback(pheard, 1);
	DLpushback(pheard, 2);
	DLpushback(pheard, 3);
	DLpushback(pheard, 4);
	DLpushback(pheard, 5);
	DLpushback(pheard, 6);


	DLpushfront(pheard, 1);
	DLpushfront(pheard, 2);
	DLpushfront(pheard, 3);
	DLpushfront(pheard, 4);
	DLpushfront(pheard, 5);

	DLprint(pheard);

	DLInsert(pheard, 10, 0);
	DLprint(pheard);

}


DListTest3()
{

	PDL pheard;
	DLInit(&pheard);

	DLpushback(pheard, 1);
	DLpushback(pheard, 2);
	DLpushback(pheard, 3);
	DLpushback(pheard, 4);
	DLpushback(pheard, 5);
	DLpushback(pheard, 6);


	DLpushfront(pheard, 1);
	DLpushfront(pheard, 2);
	DLpushfront(pheard, 3);
	DLpushfront(pheard, 4);
	DLpushfront(pheard, 5);

	DLprint(pheard);

	DLerase(pheard, 16);
	DLprint(pheard);

}



int main()
{
	DListTest3();
	return 0;
}