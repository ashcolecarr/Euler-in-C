#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define FACTORIAL   100
#define TEN         10

/* Project Euler Problem 20: Find the sum of the digits in the number 100! */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    int factorialSize = 10;
    int *factorial = (int*)malloc(factorialSize * sizeof(int));
    int factorialElement = 0;

    if(factorial == NULL)
    {
        printf("Error: memory not allocated.");
        return 1;
    }

    factorial[factorialElement] = 1;

    int product = 0;
    int carry = 0;

    int i, j;
    for(i = FACTORIAL; i > 0; i--)
    {
        for(j = 0; j <= factorialElement; j++)
        {
            product = factorial[j] * i;
            factorial[j] = (carry % TEN + product % TEN) % TEN;

            if((carry % TEN + product % TEN) >= TEN)
            {
                carry += ((carry % TEN + product % TEN) / TEN) * TEN;
            }
            carry /= TEN;
            carry = carry + product / TEN;
        }

        while(carry > 0)
        {
            if(factorialElement + 1 == factorialSize)
            {
                factorial = (int *)realloc(factorial, 2 * (factorialSize * sizeof(int)));
                factorialSize *= 2;
            }

            factorial[++factorialElement] = carry % TEN;
            carry /= TEN;
        }
    }

    int digitSum = 0;
    int k;
    for(k = 0; k <= factorialElement; k++)
    {
        digitSum += factorial[k];
    }

    free(factorial);

    printf("The sum of the digits in %d! is %d.\n", FACTORIAL, digitSum);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
