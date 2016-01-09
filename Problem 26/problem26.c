#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define INITIAL_SIZE    10
#define MAX_NUMBER      1000

/* Project Euler Problem 26:
Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part. */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    /* Set up storage to hold the remainders. */
    int remainderCurrent = 0;
    int remainderSize = INITIAL_SIZE;
    int *remainders = malloc(remainderSize * sizeof(int));

    int cycleCount = 1;
    int remainderFound = 0;

    /* Repeat while count is less than maximum number. */
    int divisor;
    int dividend;

    int denominator;

    for(divisor = 2; divisor < MAX_NUMBER; divisor++)
    {
        dividend = 1;
        remainders[0] = 0;

        /* Repeat until divisor divides evenly into dividend. */
        while(dividend != 0)
        {
            /* If dividend is less than divisor, multiple it by 10 until
               it is greater than the divisor. */
            while(dividend < divisor)
            {
                dividend *= 10;
            }

            /* Divide divisor into new dividend and get the remainder,
               which will become the dividend. */
            dividend = dividend % divisor;

            /* Check remainder against those already stored. */
            int remainderIndex;
            for(remainderIndex = 0; remainderIndex < remainderCurrent; remainderIndex++)
            {
                if(remainders[remainderIndex] == dividend)
                {
                    remainderFound++;
                    break;
                }
            }

            if(remainderFound)
            {
                remainderFound--;
                break;
            }

            remainders[remainderCurrent++] = dividend;

            if(remainderCurrent == remainderSize)
            {
                remainderSize *= 2;
                remainders = realloc(remainders, remainderSize * sizeof(int));
            }
        }

        if(remainderCurrent >= cycleCount)
        {
            cycleCount = remainderCurrent;
            denominator = divisor;
        }

        remainderCurrent = 0;
    }

    /* Clean up and print answer. */
    free(remainders);

    printf("The value of d for which 1/d has the longest recurring sequence is %d.\n", denominator);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
