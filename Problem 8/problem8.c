#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ADJACENT    13

/* Project Euler Problem 8
The four adjacent digits in the 1000-digit number
that have the greatest product are 9 � 9 � 8 � 9 = 5832.
Find the thirteen adjacent digits in the 1000-digit number
that have the greatest product. What is the value of this product? */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    char thousandDigits[] = "73167176531330624919225119674426574742355349194934"
        "96983520312774506326239578318016984801869478851843"
        "85861560789112949495459501737958331952853208805511"
        "12540698747158523863050715693290963295227443043557"
        "66896648950445244523161731856403098711121722383113"
        "62229893423380308135336276614282806444486645238749"
        "30358907296290491560440772390713810515859307960866"
        "70172427121883998797908792274921901699720888093776"
        "65727333001053367881220235421809751254540594752243"
        "52584907711670556013604839586446706324415722155397"
        "53697817977846174064955149290862569321978468622482"
        "83972241375657056057490261407972968652414535100474"
        "82166370484403199890008895243450658541227588666881"
        "16427171479924442928230863465674813919123162824586"
        "17866458359124566529476545682848912883142607690042"
        "24219022671055626321111109370544217506941658960408"
        "07198403850962455444362981230987879927244284909188"
        "84580156166097919133875499200524063689912560717606"
        "05886116467109405077541002256983155200055935729725"
        "71636269561882670428252483600823257530420752963450";

    int digits[ADJACENT];
    int sequence[ADJACENT];

    double finalProduct = 1;
    double tempProduct = finalProduct;

    int i, j, k;
    for(i = 0; i < sizeof(thousandDigits) / sizeof(thousandDigits[0]) - ADJACENT; ++i)
    {
        for(j = i, k = 0; j < i + ADJACENT; ++j, ++k)
        {
            if(thousandDigits[j] - '0' == 0)
            {
                /* Found a zero, so advance past the zero
                and clear the values. */
                i = j + 1;
                tempProduct = 1;
                break;
            }
            else
            {
                tempProduct *= digits[k] = thousandDigits[j] - '0';
            }
        }

        if(finalProduct < tempProduct)
        {
            finalProduct = tempProduct;
            int tally;
            for(tally = 0; tally < sizeof(digits) / sizeof(digits[0]); ++tally)
            {
                sequence[tally] = digits[tally];
            }
        }
        tempProduct = 1;
    }

    printf("The %d-digit sequence with the largest product is", ADJACENT);
    int count;
    for(count = 0; count < sizeof(digits) / sizeof(digits[0]); ++count)
    {
        printf(" %d", sequence[count]);
    }
    printf(" and the product is %.0f.\n", finalProduct);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
