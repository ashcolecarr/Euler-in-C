#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_VAL 1000

/* Number counts in letters*/
#define ONE         3
#define TWO         3
#define THREE       5
#define FOUR        4
#define FIVE        4
#define SIX         3
#define SEVEN       5
#define EIGHT       5
#define NINE        4
#define TEN         3

#define ELEVEN      6
#define TWELVE      6
#define THIRTEEN    8
#define FOURTEEN    8
#define FIFTEEN     7
#define SIXTEEN     7
#define SEVENTEEN   9
#define EIGHTEEN    8
#define NINETEEN    8

#define TWENTY      6
#define THIRTY      6
#define FORTY       5
#define FIFTY       5
#define SIXTY       5
#define SEVENTY     7
#define EIGHTY      6
#define NINETY      6

#define HUNDRED     7
#define THOUSAND    8
#define AND         3

int numberWordCount(int);

/* Project Euler Problem 17:
If the numbers 1 to 5 are written out in words:
one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19
letters used in total.  If all the numbers from 1 to 1000 (one thousand)
inclusive were written out in words, how many letters would be used?
Note: spaces and hyphens are ignored, but not the "and." */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    int totalLetters = 0;

    int i;
    for(i = 1; i <= MAX_VAL; i++)
    {
        if(i < 20)
        {
            totalLetters += numberWordCount(i);
        }
        else if(20 <= i && i < 100)
        {
            totalLetters += numberWordCount((i / 10) * 10);
            totalLetters += numberWordCount(i % 10);
        }
        else if(100 <= i && i < 1000)
        {
            totalLetters += numberWordCount(i / 100);
            totalLetters += numberWordCount(100);

            /* Accounting for the "and" in the number. */
            if(i % 100 != 0)
            {
                totalLetters += numberWordCount(-1);
            }

            if(i % 100 < 20)
            {
                totalLetters += numberWordCount(i % 100);
            }
            else if(i % 100 >= 20)
            {
                totalLetters += numberWordCount(((i % 100) / 10) * 10);
                totalLetters += numberWordCount((i % 100) % 10);
            }
        }
        else if(i == 1000)
        {
            totalLetters += numberWordCount(i / 1000);
            totalLetters += numberWordCount(i);
        }
    }

    printf("The numbers from %d to %d, inclusive, written out as words ", 1, MAX_VAL);
    printf("would total %d letters.", totalLetters);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}

int numberWordCount(int number)
{
    switch(number)
    {
        case 1:
            return ONE;
        case 2:
            return TWO;
        case 3:
            return THREE;
        case 4:
            return FOUR;
        case 5:
            return FIVE;
        case 6:
            return SIX;
        case 7:
            return SEVEN;
        case 8:
            return EIGHT;
        case 9:
            return NINE;
        case 10:
            return TEN;
        case 11:
            return ELEVEN;
        case 12:
            return TWELVE;
        case 13:
            return THIRTEEN;
        case 14:
            return FOURTEEN;
        case 15:
            return FIFTEEN;
        case 16:
            return SIXTEEN;
        case 17:
            return SEVENTEEN;
        case 18:
            return EIGHTEEN;
        case 19:
            return NINETEEN;
        case 20:
            return TWENTY;
        case 30:
            return THIRTY;
        case 40:
            return FORTY;
        case 50:
            return FIFTY;
        case 60:
            return SIXTY;
        case 70:
            return SEVENTY;
        case 80:
            return EIGHTY;
        case 90:
            return NINETY;
        case 100:
            return HUNDRED;
        case 1000:
            return THOUSAND;
        case -1:
            return AND;
        default:
            return 0;
    }
}
