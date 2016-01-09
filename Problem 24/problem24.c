#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE  sizeof(digits) / sizeof(digits[0])
#define MAX_PERMU   1000000

/* Project Euler Problem 24: 
A permutation is an ordered arrangement of objects. For example, 3124
is one possible permutation of the digits 1, 2, 3 and 4. If all of the
permutations are listed numerically or alphabetically, we call it lexicographic order.

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9? */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int i = 1;
    while(i <= MAX_PERMU - 1)
    {
        /* Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation. */
        int j;
        int indexK = 0;
        for(j = 0; j < ARRAY_SIZE - 1; ++j)
        {
            if(digits[j] < digits[j + 1])
            {
                indexK = j;
            }
        }

        /* Find the largest index l greater than k such that a[k] < a[l]. */
        int indexL = 0;
        for(j = 0; j < ARRAY_SIZE; ++j)
        {
            if(digits[indexK] < digits[j])
            {
                indexL = j;
            }
        }

        /* Swap the value of a[k] with that of a[l]. */
        int tempVal = digits[indexK];
        digits[indexK] = digits[indexL];
        digits[indexL] = tempVal;

        /* Reverse the sequence from a[k + 1] up to and including the final element a[n]. */
        int k;
        for(j = indexK + 1, k = ARRAY_SIZE - 1; j < k; ++j, k--)
        {
            tempVal = digits[j];
            digits[j] = digits[k];
            digits[k] = tempVal;
        }

        ++i;
    }

    printf("The millionth permutation of the digits 0 to 9 in lexicographic order is ");
    for(i = 0; i < ARRAY_SIZE; ++i)
    {
        printf("%d", digits[i]);
    }
    printf(".\n");

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
