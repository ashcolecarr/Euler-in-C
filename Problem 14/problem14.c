#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define UPPER_LIMIT     1000000

/* Project Euler Problem 14:
It can be seen that this sequence (starting at 13 and finishing at 1)
contains 10 terms. Although it has not been proved yet (Collatz Problem),
it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain? */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    unsigned int tempVal;
    unsigned int storedVal;
    int tempCount = 0;
    int storedCount = 0;

    int i;
    for(i = UPPER_LIMIT - 1; 2 <= i; --i)
    {
        tempCount = 0;
        tempVal = i;

        if(tempVal * 3 < UPPER_LIMIT)
        {
            break;
        }

        while(tempVal > 1)
        {
            if(tempVal % 2 == 0) // if even
            {
                tempVal /= 2;
            }
            else // if odd
            {
                tempVal = 3 * tempVal + 1;
            }
            tempCount++;
        }
        tempCount++;

        if(tempCount > storedCount)
        {
            storedCount = tempCount;
            storedVal = i;
        }
    }

    printf("The number under %d with the longest Collatz chain is %d, ", UPPER_LIMIT, storedVal);
    printf("with %d values.\n", storedCount);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
