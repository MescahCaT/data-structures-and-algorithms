#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

SListTest1()
{
	PSL pheard = NULL;
	SLpushback(&pheard, 1);
	SLpushback(&pheard, 2);
	SLpushback(&pheard, 3);
	SLpushback(&pheard, 4);
	SLpushback(&pheard, 5);
	SLpushback(&pheard, 6);

	SLprint(pheard);
}

SListTest2()
{
	PSL pheard = NULL;
	SLpushback(&pheard, 1);
	SLpushback(&pheard, 2);
	SLpushback(&pheard, 3);
	SLpushback(&pheard, 4);
	SLpushback(&pheard, 5);
	SLpushback(&pheard, 6);
	SLprint(pheard);

	SLpushfront(&pheard, 2);
	SLpushfront(&pheard, 3);
	SLpushfront(&pheard, 4);
	SLpushfront(&pheard, 5);
	SLpushfront(&pheard, 6);
	SLprint(pheard);
}

SListTest3()
{
	PSL pheard = NULL;
	SLpushback(&pheard, 1);
	SLpushback(&pheard, 2);
	SLpushback(&pheard, 3);
	SLpushback(&pheard, 4);
	SLpushback(&pheard, 5);
	SLpushback(&pheard, 6);
	SLpushfront(&pheard, 2);
	SLpushfront(&pheard, 3);
	SLpushfront(&pheard, 4);
	SLpushfront(&pheard, 5);
	SLpushfront(&pheard, 6);
	SLprint(pheard);

	SLpopback(&pheard);
	SLpopback(&pheard);
	SLpopback(&pheard);
	SLpopback(&pheard);
	SLpopback(&pheard);
	SLprint(pheard);
	SLpopback(&pheard);
	SLpopback(&pheard);
	SLpopback(&pheard);	
	SLpopback(&pheard);
	SLpopback(&pheard);
	SLpopback(&pheard);
	SLprint(pheard);
	//SLpopback(&pheard);
	SLpopback(&pheard);
	SLpopback(&pheard);
	SLpopback(&pheard);
}

void SListTest4()
{
	PSL pheard = NULL;
	SLpushback(&pheard, 1);
	SLpushback(&pheard, 2);
	SLpushback(&pheard, 3);
	SLpushback(&pheard, 4);
	SLpushback(&pheard, 5);
	SLpushback(&pheard, 6);
	SLpushfront(&pheard, 2);
	SLpushfront(&pheard, 3);
	SLpushfront(&pheard, 4);
	SLpushfront(&pheard, 5);
	SLpushfront(&pheard, 6);
	SLprint(pheard);

	SLrestroy(&pheard);


}

SListTest5()
{
	PSL pheard = NULL;
	SLpushback(&pheard, 1);
	SLpushback(&pheard, 2);
	SLpushback(&pheard, 3);
	SLpushback(&pheard, 4);
	SLpushback(&pheard, 5);
	SLpushback(&pheard, 6);
	SLpushfront(&pheard, 2);
	SLpushfront(&pheard, 3);
	SLpushfront(&pheard, 4);
	SLpushfront(&pheard, 5);
	SLpushfront(&pheard, 6);
	SLprint(pheard);

	printf("nums %d's position = %d\n", 1, SLsearch(pheard, 1));
	printf("nums %d's position = %d\n", 2, SLsearch(pheard, 2));
	printf("nums %d's position = %d\n", 3, SLsearch(pheard, 3));
	printf("nums %d's position = %d\n", 4, SLsearch(pheard, 4));

	SLrestroy(&pheard);
}

SListTest6()
{
	PSL pheard = NULL;
	SLpushback(&pheard, 1);
	SLpushback(&pheard, 2);
	SLpushback(&pheard, 3);
	SLpushback(&pheard, 4);
	SLpushback(&pheard, 5);
	SLpushback(&pheard, 6);
	SLpushfront(&pheard, 2);
	SLpushfront(&pheard, 3);
	SLpushfront(&pheard, 4);
	SLpushfront(&pheard, 5);
	SLpushfront(&pheard, 6);
	SLprint(pheard);

	SLinsertAfter(&pheard, 5, 10);
	SLinsertAfter(&pheard, 5, 11);
	SLinsertAfter(&pheard, 5, 12);
	SLinsertAfter(&pheard, 5, 13);
	SLprint(pheard);
}

SListTest7()
{
	PSL pheard = NULL;
	SLpushback(&pheard, 1);
	SLpushback(&pheard, 2);
	SLpushback(&pheard, 3);
	SLpushback(&pheard, 4);
	SLpushback(&pheard, 5);
	SLpushback(&pheard, 6);
	SLpushfront(&pheard, 2);
	SLpushfront(&pheard, 3);
	SLpushfront(&pheard, 4);
	SLpushfront(&pheard, 5);
	SLpushfront(&pheard, 6);
	SLprint(pheard);

	SLinsertBefore(&pheard, 5, 10);
	SLinsertBefore(&pheard, 5, 11);
	SLinsertBefore(&pheard, 5, 12);
	SLinsertBefore(&pheard, 5, 13);
	SLinsertBefore(&pheard, 5, 14);
	SLprint(pheard);
}

SListTest8()
{
	PSL pheard = NULL;
	SLpushback(&pheard, 1);
	SLpushback(&pheard, 2);
	SLpushback(&pheard, 3);
	SLpushback(&pheard, 4);
	SLpushback(&pheard, 5);
	SLpushback(&pheard, 6);
	SLpushfront(&pheard, 2);
	SLpushfront(&pheard, 3);
	SLpushfront(&pheard, 4);
	SLpushfront(&pheard, 5);
	SLpushfront(&pheard, 6);
	SLprint(pheard);

	SLerase(&pheard, 5);
	SLerase(&pheard, 5);
	SLerase(&pheard, 5);
	SLerase(&pheard, 5);
	SLerase(&pheard, 5);
	SLerase(&pheard, 5);
	SLerase(&pheard, 5);
	SLprint(pheard);
}

int main()
{
	SListTest8();

	return 0;
}