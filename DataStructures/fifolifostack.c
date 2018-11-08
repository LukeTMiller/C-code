#include "Quemenu.h"
#include <math.h>
#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{

	time_t seconds;
	int r = 0;

	seconds = time(NULL);
	srand(seconds);

CONTINUE:
	printf("\nMenu:\n1 for a stack\n2 for a fifo que\n3 for a lifo que\n");
	scanf("%d", &r);

	if (r == 1)
	{
		stack(r);
	}
	else if (r == 2)
	{
		fifo(r);
	}
	else if (r == 3)
	{
		lifo(r);
	}
	else
	{
		printf("wrong input");
		goto CONTINUE;
	}

	return 0;
}