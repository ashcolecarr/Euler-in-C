#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 2000000

typedef struct
{
    int *array;
    size_t current;
    size_t size;
} Array;

void initArray(Array *a, size_t initSize);
void insertArray(Array *a, int element);
void freeArray(Array *a);

/* Project Euler Problem 10:
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million. */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    Array primes;
    initArray(&primes, 5);
    insertArray(&primes, 2);
    insertArray(&primes, 3);

    double primeSum = primes.array[0] + primes.array[1];

    int number = primes.array[1];
    int primeFound;

    while(number < MAX_NUM)
    {
        number += 2;
        primeFound = 1;
        int i;
        int numRoot = ceil(sqrt(number));
        for(i = 0; i < primes.current && primes.array[i] <= numRoot; ++i)
        {
            if(number % primes.array[i] == 0)
            {
                primeFound = 0;
                break;
            }
        }

        if(primeFound)
        {
            insertArray(&primes, number);
            primeSum += number;
        }
    }

    freeArray(&primes);

    printf("The sum of all the primes below %d is %.0f.\n", MAX_NUM, primeSum);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}

void initArray(Array *a, size_t initSize)
{
  a->array = (int *)malloc(initSize * sizeof(int));
  a->current = 0;
  a->size = initSize;
}

void insertArray(Array *a, int element)
{
  if (a->current == a->size)
  {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->current++] = element;
}

void freeArray(Array *a)
{
  free(a->array);
  a->array = NULL;
  a->current = a->size = 0;
}
