#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Find the difference between the sum of the squares of
the first one hundred natural numbers and the square of the sum. */
int main()
{
    clock_t start = clock();

    int sumOfSquares = 0;
    int squareOfSum = 0;
    int difference;

    int i;
    for(i = 1; i <= 100; ++i)
    {
        sumOfSquares += (int)pow(i, 2);
        squareOfSum += i;
    }

    squareOfSum = (int)pow(squareOfSum, 2);

    difference = squareOfSum - sumOfSquares;

    printf("The difference between the sum of squares and ");
    printf("the square of the sum of 1 to 100 is %d.\n", difference);

    clock_t stop = clock();
    printf("Program execution time took %f seconds.\n", ((double)stop - (double)start) * 1.0e-6);
    return 0;
}
