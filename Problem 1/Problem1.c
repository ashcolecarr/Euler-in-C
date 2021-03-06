#include <stdio.h>

#define MAX_NUM 1000
#define MULTIPLE_1 3
#define MULTIPLE_2 5

/* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

   Find the sum of all the multiples of 3 or 5 below 1000. */
int main()
{
    int sum = 0;

    int i;
    for(i = 0; i < MAX_NUM; i++)
    {
	if(i % MULTIPLE_1 == 0 || i % MULTIPLE_2 == 0)
	{
	    sum += i;
	}
    }

    printf("The sum of all multiples of %d and %d below %d is %d.\n", MULTIPLE_1, MULTIPLE_2, MAX_NUM, sum);
    return 0;
}
