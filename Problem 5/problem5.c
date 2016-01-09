#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START   2520

/* Project Euler Problem 5:
2520 is the smallest number that can be divided by
each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly
divisible by all of the numbers from 1 to 20?
*/
int main()
{
    clock_t start = clock();

    int factors[] = { 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20 };

    int smallest = START;
    int found;

    while(1)
    {
        found = 1;
        int count;
        for(count = 0; count < sizeof(factors) / sizeof(factors[0]); ++count)
        {
            if(smallest % factors[count] != 0)
            {
                found = 0;
                break;
            }
        }

        if(found)
        {
            break;
        }

        smallest += 20;
    };

    printf("The smallest positive integer divisible by the numbers 1 to 20 is %d.\n", smallest);

    clock_t stop = clock();
    printf("Program execution time took %f seconds.\n", ((double)stop - (double)start) * 1.0e-6);
    return 0;
}
