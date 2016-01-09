#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_NUM 10000

/* Project Euler Problem 21: 
Evaluate the sum of all the amicable numbers under 10000. */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    int amicableSum = 0;

    int divisorSum = 0;
    int amicableDivisorSum = 0;

    int i;
    for(i = 1; i <= MAX_NUM; i++)
    {
        int j;
        for(j = 1; j <= i / 2; j++)
        {
            if(i % j == 0)
            {
                divisorSum += j;
            }
        }

        int k;
        for(k = 1; k <= divisorSum / 2; k++)
        {
            if(divisorSum % k == 0)
            {
                amicableDivisorSum += k;
            }
        }

        if(i == amicableDivisorSum && divisorSum != i)
        {
            amicableSum += i;
        }

        divisorSum = amicableDivisorSum = 0;
    }

    printf("The sum of all amicable numbers under %d is %d.\n", MAX_NUM, amicableSum);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
