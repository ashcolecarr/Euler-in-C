#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <time.h>

#define NUMBER  600851475143.0

double getFactor(double number);

/* Project Euler Problem 3: 
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143? */
int main()
{
    clock_t start = clock();
    
    printf("The largest prime factor of %1.0f is %1.0f.\n", NUMBER, getFactor(NUMBER));

    clock_t stop = clock();
    double timeTaken = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution took %f seconds.\n", timeTaken);
    return 0;
}

double getFactor(double number)
{
    double factor = 2;

    while(fmod(number, factor) > DBL_EPSILON)
    {
        if(factor - 2.0 < DBL_EPSILON)
        {
            ++factor;
        }
        else
        {
            factor += 2;
        }
    }

    if(factor > (number / 2))
    {
        return factor;
    }
    else
    {
        return getFactor(number / factor);
    }
}
