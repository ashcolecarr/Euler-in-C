#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT   1000

/* Project Euler Problem 27: 
Find the product of the coefficients, a and b, for the quadratic expression that
produces the maximum number of primes for consecutive values of n, starting with n = 0. */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    /* Set prime counter, final counter, and product values. */
    int finalCount = 0;
    int product;

    int solution;
    int isPrime = 1;

    int a;
    /* Count from 0 to 999 for the a and b coefficients. */
    for(a = -(LIMIT - 1); a < LIMIT; a++)
    {
        int b;
        for(b = 0; b < LIMIT; b++)
        {
            /* Calculate solutions until they are no longer prime. */
            int n = 0;
	    isPrime = 1;
            while(isPrime)
            {
                /* n^2 + an + b */
                solution = abs((n * n) + (a * n) + b);

                int root = (int)(ceil(sqrt(solution)));

                int primeIndex = 2;
		if((solution % primeIndex == 0 && solution != 2) || solution < 2)
		{
		    isPrime--;
		}
		else
		{
		    for(primeIndex = 3; primeIndex <= root; primeIndex += 2)
		    {
			if(solution % primeIndex == 0)
			{
			    isPrime--;
			    break;
			}
		    }
		}

		n++;
            }

            /* Check if prime is greater than running total and get the product if so. */
            if(n > finalCount)
            {
                finalCount = n;
		product = a * b;
	    }
	}
    }

    printf("The product of the coefficients, a and b, for the quadratic expression that ");
    printf("produces the maximum number of primes for consecutive values of n is %d.\n", product);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
