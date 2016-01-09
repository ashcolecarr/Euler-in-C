#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 4000000

/* Project Euler Problem 2
By considering the terms in the Fibonacci sequence whose values do not exceed
four million, find the sum of the even-valued terms.*/
int main()
{
    int previousTerms[2] = { 0, 1 };

    int currentTerm = previousTerms[0] + previousTerms[1];
    int sum = 0;

    while(currentTerm < MAX_VAL)
    {
        if(currentTerm % 2 == 0)
        {
            sum += currentTerm;
        }

        previousTerms[0] = previousTerms[1];
        previousTerms[1] = currentTerm;
        currentTerm = previousTerms[0] + previousTerms[1];
    };

    printf("The sum of all even Fibonacci terms below %d is %d.\n", MAX_VAL, sum);
    return 0;
}
