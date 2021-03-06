#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define INCREMENT 2
#define SPIRAL_SIZE 1000
#define LOOP_TIMES 4
#define START_VALUE 2
#define INITIAL_SIZE 10

/* Project Euler Problem 28:
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way? */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    /* Set up storage to hold spiral values. */
    int spiralCurrent = 0;
    int spiralSize = INITIAL_SIZE;
    int *spiralValues = malloc(spiralSize * sizeof(int));

    if(spiralValues == NULL)
    {
	printf("Error: memory could not be allocated.\n");
	return 1;
    }

    /* Set up other values. */
    int spiralCounter = START_VALUE;
    int spiralSum = 0;

    spiralValues[spiralCurrent++] = 1;
    for(; spiralCounter <= SPIRAL_SIZE; spiralCounter += INCREMENT)
    {
	int addLoop;
	for(addLoop = 0; addLoop < LOOP_TIMES; ++addLoop)
	{
	    /* Add increment counter to previous number in storage and store the new number as the last value in the set of values. */
	    spiralValues[spiralCurrent] = spiralValues[spiralCurrent - 1] + spiralCounter;
	    spiralCurrent++;

	    if(spiralCurrent == spiralSize)
	    {
		spiralSize *= 2;
		spiralValues = realloc(spiralValues, spiralSize * sizeof(int));

		if(spiralValues == NULL)
		{
		    printf("Error: memory could not be allocated.\n");
		    return 1;
		}
	    }
	}
    }

    /* Sum up spiral values and print answer. */
    int sumCount;
    for(sumCount = 0; sumCount < spiralCurrent; sumCount++)
    {
	spiralSum += spiralValues[sumCount];
    }

    free(spiralValues);

    printf("The sum of the diagonal numbers in a %d by %d spiral is %d.\n", SPIRAL_SIZE, SPIRAL_SIZE, spiralSum);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
