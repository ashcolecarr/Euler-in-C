#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define NUMBER  1000

/* There exists exactly one Pythagorean
triplet for which a + b + c = 1000.
Find the product abc. */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    int a, b, c;
    int product;
    int m, n, k;
    int found = 0;

    m = 2; n = 1; k = 1;
    while(!found)
    {
        do
        {
            for(n = m - 1; 0 < n; --n)
            {
                a = k * (pow(m, 2) - pow(n, 2));
                b = k * (2 * m * n);
                c = k * (pow(m, 2) + pow(n, 2));

                if(a + b + c == NUMBER)
                {
                    found = 1;
                    break;
                }
            }
            ++m;
        }
        while(NUMBER < a + b + c || !found);

        ++k;
    }

    product = a * b * c;

    printf("The product of abc where a + b + c = 1000 and ");
    printf("a^2 + b^2 = c^2 is %d.", product);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
