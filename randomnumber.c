#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Random(int l, int u,int count,int g)
{
	int num,i;
	for (i = 0; i < count; i++)
	{
		num = (rand() %(u- l+ 1)) + l;
		printf("Your guess is %d",g);
		printf("\n");
		printf("Random number : %d ", num);
	}
	if(num==g)
	{
		printf("\n");
		printf("You won the game..");
	}
	else
	{
		printf("\n");
		printf("You lost..better luck next time..");
	}
}

int main()
{
	int g,lower = 0, upper = 10, count = 1;
	printf("\t Guessing Game\n");
	printf("-----------------------\n");
	printf("Guess a number from 0-10 : ");
	scanf("%d",&g);
	srand(time(0));
	Random(lower, upper, count,g);
	return 0;
}

