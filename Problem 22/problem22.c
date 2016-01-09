#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define NAME_FILE       "names.txt"
#define MAX_NAME_SIZE   30
#define NAME_LIST_SIZE  sizeof(names) / (sizeof(names[0]))

int compare(const void * a, const void * b);

/* Project Euler Problem 22: 
Using names.txt, a text file containing over five-thousand first names,
begin by sorting it into alphabetical order. Then working out the alphabetical
value for each name, multiply this value by its alphabetical position
in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN,
which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file? */
int main()
{
    double timeTaken;
    clock_t start, end;
    start = clock();

    /* Scan file for commas to determine number of names to hold. */
    int nameCount = 0;
    FILE *nameFile;
    nameFile = fopen(NAME_FILE, "r");

    if(nameFile == NULL)
    {
        printf("File %s could not be opened.", NAME_FILE);
        return 1;
    }

    char fileChar;
    while((fileChar = fgetc(nameFile)) != EOF)
    {
        if(fileChar == ',')
        {
            ++nameCount;
        }
    }
    nameCount++;
    rewind(nameFile);

    /* Create the array of strings that will store the names. */
    char names[nameCount][MAX_NAME_SIZE];

    /* Read from the name file into the array. */
    char name[MAX_NAME_SIZE];

    int i;
    for(i = 0; i < NAME_LIST_SIZE; ++i)
    {
        int j = 0;
        char c;
        while((c = fgetc(nameFile)) != ',' && c != EOF)
        {
            if(c != '"')
            {
                name[j++] = c;
            }
        }
        name[j] = '\0';

        int k;
        for(k = 0; k <= j; ++k)
        {
            names[i][k] = name[k];
        }
    }

    fclose(nameFile);

    /* Sort the array alphabetically. */
    qsort(names, NAME_LIST_SIZE, sizeof(names[0]), compare);

    /* Calculate the name values. */
    int totalScore = 0;
    int nameScore;
    for(i = 0; i < NAME_LIST_SIZE; ++i)
    {
        nameScore = 0;

        int j = 0;
        while(names[i][j] != '\0')
        {
            nameScore += (names[i][j++] - 'A') + 1;
        }

        totalScore += (i + 1) * nameScore;
    }

    /*printf("The names in the file are:\n");
    int k;
    for(k = 0; k < NAME_LIST_SIZE; ++k)
    {
        printf("%s\n", names[k]);
    }*/

    printf("The total of all the name scores in the file %s is %d.\n", NAME_FILE, totalScore);

    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nProgram execution time took %f seconds.\n", timeTaken);
    return 0;
}

int compare(const void * a, const void * b)
{
    return strcmp(a, b);
}
