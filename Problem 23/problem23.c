#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM     28123
#define INIT_SIZE   10

/* Project Euler Problem 23: 
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum
of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can
be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis
even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers. */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    int abundantElem = 0;
    int abundantSize = INIT_SIZE;
    int *abundants = malloc(abundantSize * sizeof(int));

    if(abundants == NULL)
    {
        printf("Error: memory could not be allocated.  Program will now exit.\n");
        return 1;
    }

    /* Calculate and store all the abundant numbers. */
    int i;
    int divisorSum;
    for(i = 12; i <= MAX_NUM; ++i)
    {
        divisorSum = 0;
        int j;
        int maxVal = (int)(sqrt(i));
        for(j = 1; j <= maxVal; ++j)
        {
           if(i % j == 0)
           {
               divisorSum += j;

               if(i / j != i && i / j != j)
               {
                   divisorSum += i / j;
               }
           }
        }

        if(divisorSum > i)
        {
            abundants[abundantElem++] = i;

            if(abundantElem == abundantSize)
            {
                abundantSize *= 2;
                abundants = realloc(abundants, abundantSize * sizeof(int));

                if(abundants == NULL)
                {
                    printf("Error: memory could not be allocated.  Program will now exit.\n");
                    return 1;
                }
            }
        }
    }

    /* Mark all numbers which can be expressed as the sum of two abundant numbers. */
    int markedNums[MAX_NUM + 1];
    for(i = 0; i < abundantElem; ++i)
    {
        markedNums[i] = 0;
    }

    for(i = 0; i < abundantElem; ++i)
    {
        int j;
        for(j = i; j < abundantElem; ++j)
        {
            if(abundants[i] + abundants[j] <= MAX_NUM)
            {
                markedNums[abundants[i] + abundants[j]] = 1;
            }
            else
            {
                break;  /* Don't need to count any higher. */
            }
        }
    }

    free(abundants);

    int finalTotal = 0;
    for(i = 0; i < sizeof(markedNums) / sizeof(markedNums[0]); ++i)
    {
        if(!markedNums[i])
        {
            finalTotal += i;
        }
    }

    printf("The sum of all positive integers which cannot be written ");
    printf("as the sum of two abundant numbers is %d.\n", finalTotal);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
