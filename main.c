#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>

	FILE *fptr;
    uint8_t word_counter = 0;
	void filter (FILE *fptr)
	{
            //A system for detecting which rules existed and which didn't.
    uint8_t a_counter = 0;    //Does the word contain 1 or 2 'a's?
    uint8_t cei_counter = 0;  // Does the word contain a 'c' followed by either an 'e' or 'i'?
    uint8_t pmhw_counter = 0; //does the word contain any of the following letters`: p, m, h, or w?
    uint8_t ze_counter = 0;   //does the word contain a 'z' followed by an 'e'?
    uint8_t is_letter = 0;    //is the character a letter?
    char word [127] = {};
    char current_character = fgetc(fptr);
    int i;
    char previous_character;

     
    for (i = 0; current_character != ' ' && current_character != EOF ; i++)
    {
        word [i] = current_character;
        current_character = fgetc(fptr);
        
    }

    for (int p = 0; p < i; p++)
    {
        
        if (p>0)
        {
           previous_character = word[p-1];
        }
        
        if (isalpha(word[p]))
        {
            is_letter++;
        }
            if (word[p] == 'a')
            {
                a_counter++;
            }
                if (previous_character == 'c' && (word[p] == 'e' ||  word[p] == 'i'))
                {
                    cei_counter++;
                }
                    if (word[p] == 'p' || word[p] == 'm' || word[p] == 'h' || word[p] == 'w')
                    {
                       pmhw_counter++;
                    }
                        if (previous_character == 'z' && word[p] == 'e')
                        {
                            ze_counter++;
                        }
                        
                        
                    
                
            
        
    }
        if ((a_counter >0 && a_counter <3) && (cei_counter >0) && (pmhw_counter == 0) && (ze_counter == 0) && (is_letter == i) && (i <10 && i >2))
        {
            for (int o = 0; o < i; o++)
            {
                printf("%c", word[o]);
                
            }
                printf(" "); 
                word_counter++; 
        }

    
    

	}


	



void main(void)
{

    char filename[50];
    

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
        
    }
    printf("\n\nA totoal of %d words fit the rules\n\n", word_counter);
}


