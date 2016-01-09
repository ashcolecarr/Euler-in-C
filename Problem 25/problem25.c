#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUMBER_OF_DIGITS    1000
#define ARRAY_SIZE          sizeof(fibonacci) / sizeof(fibonacci[0])

/* Project Euler Problem 25:
What is the first term in the Fibonacci sequence to contain 1000 digits? */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    /* Set up three arrays for Fn, Fn-1, and Fn-2. */
    int fibonacci[NUMBER_OF_DIGITS];
    int fibonacciMinus1[NUMBER_OF_DIGITS];
    int fibonacciMinus2[NUMBER_OF_DIGITS];

    int i;
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        fibonacci[i] = fibonacciMinus1[i] = fibonacciMinus2[i] = 0;
    }

    fibonacciMinus1[0] = 1;
    fibonacciMinus2[0] = 1;

    int fibonacciPos = 0;
    int fibonacciMinus1Pos = 0;

    int fibonacciTerm = 2;

    int digitSum = 0;
    int carry;
    /* Keep adding up fibonacci numbers until the 1000th digit is reached. */
    while(fibonacciPos < ARRAY_SIZE - 1)
    {
        carry = 0;

        int arrayIndex;

        /* Add Fn-1 and Fn-2 and store the result in Fn. */
        for(arrayIndex = 0; arrayIndex <= fibonacciMinus1Pos; arrayIndex++)
        {
            digitSum = fibonacciMinus1[arrayIndex] + fibonacciMinus2[arrayIndex] + carry;
            fibonacci[arrayIndex] = digitSum % 10;

            carry = digitSum / 10;
        }

        if(carry != 0)
        {
            fibonacci[++fibonacciPos] = carry;
        }

        for(arrayIndex = 0; arrayIndex <= fibonacciPos; arrayIndex++)
        {
            fibonacciMinus2[arrayIndex] = fibonacciMinus1[arrayIndex];

            fibonacciMinus1[arrayIndex] = fibonacci[arrayIndex];
            fibonacciMinus1Pos = fibonacciPos;
        }

        fibonacciTerm++;
    }

    printf("The first term in the Fibonacci sequence to contain %d digits is %d.\n", NUMBER_OF_DIGITS, fibonacciTerm);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
