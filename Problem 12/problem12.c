#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define NUM_DIVISORS    501

/* We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors? */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    int divisorCount = 0;
    int naturalNum = 2;
    double triangleNumber = 1;

    while(divisorCount <= NUM_DIVISORS)
    {
        divisorCount = 0;
        triangleNumber += naturalNum;

        int i;
        double stopVal = sqrt(triangleNumber);
        for(i = 2; i <= stopVal; ++i)
        {
            if(fmod(triangleNumber, i) < DBL_EPSILON)
            {
                /* Every factor has another another number it multiplies by
                   to get the triangle number. */
                divisorCount += 2;
            }
        }

        naturalNum++;
    }

    printf("The first triangle number with %d divisors is %.0f.\n", NUM_DIVISORS, triangleNumber);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
