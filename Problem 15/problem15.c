#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <float.h>

#define GRID_X  20
#define GRID_Y  20

/* Project Euler Problem 15
Starting in the top left corner of a 2×2 grid, and only being
able to move to the right and down, there are exactly
6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid? */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    int oddSize = 10;
    double *oddRow = (double*)malloc(oddSize * sizeof(double));

    int evenSize = 10;
    double *evenRow = (double*)malloc(evenSize * sizeof(double));

    if(oddRow == NULL || evenRow == NULL)
    {
        printf("Error: memory not allocated.");
        return 1;
    }

    int rowCount = 2;
    double totalRoutes = 0;

    oddRow[0] = 1;
    oddRow[1] = 1;

    evenRow[0] = 1;

    /* Pascal's triangle is used to calculate the number of paths. */
    while(rowCount <= GRID_X + GRID_Y)
    {
        if(rowCount % 2 == 0)
        {
            evenRow[0] = 1;

            int i;
            for(i = 1; i < rowCount; i++)
            {
                if(i + 1 == evenSize)
                {
                    evenRow = (double *)realloc(evenRow, 2 * (evenSize * sizeof(double)));
                    evenSize *= 2;
                }

                evenRow[i] = oddRow[i - 1] + oddRow[i];
            }

            evenRow[rowCount] = 1;
        }
        else
        {
            oddRow[0] = 1;

            int i;
            for(i = 1; i < rowCount; i++)
            {
                if(i + 1 == oddSize)
                {
                    oddRow = (double *)realloc(oddRow, 2 * (oddSize * sizeof(double)));
                    oddSize *= 2;
                }

                oddRow[i] = evenRow[i - 1] + evenRow[i];
            }

            oddRow[rowCount] = 1;
        }

        rowCount++;
    }

    if((rowCount - 1) % 2 == 0)
    {
        int i;
        for(i = 0; i < rowCount - 1; i++)
        {
            if(totalRoutes < evenRow[i])
            {
                totalRoutes = evenRow[i];
            }
        }
    }
    else
    {
        int i;
        for(i = 0; i < rowCount - 1; i++)
        {
            if(totalRoutes < oddRow[i])
            {
                totalRoutes = oddRow[i];
            }
        }
    }

    printf("The number of paths for a grid of size %d by %d is %.0f.\n", GRID_X, GRID_Y, totalRoutes);

    free(oddRow);
    oddSize = 0;
    free(evenRow);
    evenSize = 0;

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}
