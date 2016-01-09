#include <stdio.h>
#include <time.h>

#define FIRST_FACTOR    999
#define SECOND_FACTOR   999
#define TEN             10

/* Project Euler Problem 4:
A palindromic number reads the same both ways.
The largest palindrome made from the product
of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the
product of two 3-digit numbers. */
int main()
{
    clock_t start = clock();

    int firstFactor;
    int secondFactor;

    int product;
    int productArray[6];
    int isPalindrome;

    int palindrome = 0;
    int firstPF;
    int secondPF;

    for(secondFactor = SECOND_FACTOR; secondFactor >= 100; secondFactor--)
    {
        for(firstFactor = FIRST_FACTOR; firstFactor >= 100; firstFactor--)
        {
            product = firstFactor * secondFactor;

            int tempValue = product;

            int count = 0;
            while(tempValue > 0)
            {
                productArray[count++] = tempValue % TEN;
                tempValue /= TEN;
            }

            int i, j;
            isPalindrome = 1;
            for(i = 0, j = sizeof(productArray) / sizeof(productArray[0]) - 1;
                i < (sizeof(productArray) / sizeof(productArray[0])) / 2; ++i, --j)
            {
                if(productArray[i] != productArray[j])
                {
                    isPalindrome = 0;
                }
            }

            if(isPalindrome && palindrome < product)
            {
                palindrome = product;
                firstPF = firstFactor;
                secondPF = secondFactor;
            }
        }
    }

    printf("The maximum palindromic value is %d, whose factors are %d and %d.\n", palindrome, firstPF, secondPF);

    clock_t stop = clock();
    printf("Program execution time took %f seconds.\n", ((double)stop - (double)start) * 1.0e-6);
    return 0;
}
