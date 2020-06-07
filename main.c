#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>

	FILE *fptr;


	



void main(void)
{

    char filename[50];
    uint8_t word_counter = 0;

    printf("enter the filename for the file you wish to scan.\n");
    scanf("%s", filename);

    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    while (!feof(fptr))
    {
        filter(fptr);
        word_counter++;
    }
    printf("\n\nA totoal of %d words fit the rules\n\n", word_counter);
}


