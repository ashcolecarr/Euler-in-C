#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define JANUARY     1
#define FEBRUARY    32
#define MARCH       (year % 4 == 0 ? 61 : 60)
#define APRIL       (year % 4 == 0 ? 92 : 91)
#define MAY         (year % 4 == 0 ? 122 : 121)
#define JUNE        (year % 4 == 0 ? 153 : 152)
#define JULY        (year % 4 == 0 ? 183 : 182)
#define AUGUST      (year % 4 == 0 ? 214 : 213)
#define SEPTEMBER   (year % 4 == 0 ? 245 : 244)
#define OCTOBER     (year % 4 == 0 ? 275 : 274)
#define NOVEMBER    (year % 4 == 0 ? 306 : 305)
#define DECEMBER    (year % 4 == 0 ? 336 : 335)

#define YEAR        (year % 4 == 0 ? 366 : 365)
#define WEEKDAYS    7

/* Project Euler Problem 19:
How many Sundays fell on the first of the month during
the twentieth century (1 Jan 1901 to 31 Dec 2000)? */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    int totalSundays = 0;

    /* The first Sunday in 1901 was 6 January. */
    int day = 6;

    int year;
    for(year = 1901; year < 2001; year++)
    {
        for(; day < YEAR; day += WEEKDAYS)
        {
            if(day == JANUARY || day == FEBRUARY || day == MARCH || day == APRIL ||
               day == MAY || day == JUNE || day == JULY || day == AUGUST ||
               day == SEPTEMBER || day == OCTOBER || day == NOVEMBER || day == DECEMBER)
            {
                totalSundays++;
            }
        }

        // Reset day counter for next year.
        day = day - YEAR;
    }

    printf("In the 20th century, there were %d Sundays on the first of the month.\n", totalSundays);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
