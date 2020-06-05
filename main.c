#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>

		int i = 0;
	int a_raknare = 0;
	int cei_raknare = 0;
	int pmhw_raknare = 0;
	int ze_raknare = 0;
	char ord[10];
	char previous_character;

uint8_t filter (char tecken)
{
	if (isalpha(tecken)) 
	{

	while (c != ' ')
	{
		ord[i] = c;
		i++; 
	}
	
	if ((i >3) || (i <10)) //vi kollar så att det är bokstäver också ALPHANUMMER 
	{
		for (int Janne = 0; Janne< (sizeof (ord) / sizeof (char)); Janne++)
		{
			if (Janne > 0 )
			{
				previous_character = ord[Janne-1]
			}	
				if (ord [Janne] == 'a')
				{
					a_raknare++;
				}
					if (previous_character == 'c' && (ord [Janne] == 'e' || ord[Janne] == 'i'))
					{
						cei_raknare++;
					}
						if (ord[Janne] == 'p' || ord[Janne] == 'm' || ord[Janne] == 'h' || ord[Janne] == 'w') //UNSURE ABOUT THE INTERPRITATION OF THE 5TH REQUIERMETN
						{
							pmhw_raknare++;
						}
							if (previous_character == 'z' && ord[Janne] == 'e')
							{
								ze_raknare++;
							}
							
						
					
			
		}
		if (a_raknare == 1 || a_raknare == 2)
		{
			if (cei_raknare >0 )
			{
				if (pmhw_raknare == 0)
				{
					if (ze_raknare == 0)
					{
						for (int Janne = 0; Janne< (sizeof (ord) / sizeof (char)); Janne++)
						{
							printf("%c",ord[Janne]);
						}
							printf(" ");
						
					}
					else
					{
						printf("det får inte vara några z som följs utav ett e i orden\n")
					}
					
					
				}
				else
				{
					printf("det är ett p, m eller ett h i något utav orden\n")
				}
				
			}
			else
			{
				printf("det är inga ord som har ett c följt av ett e eller i\n");
			}
			
			
		}
		else
		{
			printf("fel antal A\n");
		}
		
		
	}
	else
	{
		printf("fel längd på orden\n");
	}
	}
	else
	{
		printf("")
	}
	

	
} 

int main() 
{ 
	FILE *fptr; 

	char filename[100], c; 

	//printf("print your filename\n"); 
	//canf("%s", filename); 

	
	fptr = fopen("text.txt", "r"); 
	if (fptr == NULL) 
	{ 
		printf("Cannot open file \n"); 
		exit(0); 
	} 

	c = fgetc(fptr); //fgetc(fptr);  
	while (c != EOF) 
	{ 
		if (filter(c))
		{
			printf ("%c", c);
		}
		
	
		c = fgetc(fptr); 
	} 

	fclose(fptr); 
	return 0; 
}
