#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define POWER   1000
#define NUMBER  2
#define TEN     10

/* Project Euler Problem 16:
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000? */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    int product = 0;
    int carry = 0;

    int productSize = 10;
    int *productArray = (int*)malloc(productSize * sizeof(int));
    int productElement = 0;

    if(productArray == NULL)
    {
        printf("Error: memory not allocated.");
        return 1;
    }

    productArray[productElement] = 1;

    int i, j;
    for(i = 0; i < POWER; i++)
    {
        for(j = 0; j <= productElement; j++)
        {
            product = productArray[j] * NUMBER;
            productArray[j] = carry + product % TEN;
            carry = product / TEN;
        }

        if(carry != 0)
        {
            if(productElement + 1 == productSize)
            {
                productArray = (int *)realloc(productArray, 2 * (productSize * sizeof(int)));
                productSize *= 2;
            }

            productArray[++productElement] = carry;
        }
        carry = 0;
    }

    int totalSum = 0;
    int k;
    for(k = 0; k <= productElement; k++)
    {
        totalSum += productArray[k];
    }

    free(productArray);

    printf("The sum of all the numbers in the result of %d^%d is %d.\n", NUMBER, POWER, totalSum);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
