/* This piece of program takes two String user inputs and compares each of their Characters ignoring the Cases.

Author: MdHaq
*/

#include <stdio.h>
#include <stdlib.h>

//Function declarations
int get_len(char*);
char *get_str(void);
void strCap(char*);
int strComp(char*, char*);


int main (void)
{	

	//Getting the first string input
	char *str1 = get_str();

	//Getting the second string input
	char *str2 = get_str();

	//Printing both strings
	printf("The first string is %s\n", str1);
	printf("The second string is %s\n", str2);

	//Capitalizing both strings 
	strCap(str1);
	strCap(str2);

	//Printing both capitalized strings
	printf("The first capitalized string is %s\n", str1);
	printf("The second capitalized string is %s\n\n", str2);

	//Compare both strings
	int ret = strComp (str1, str2);
	if (ret == 0)
		printf("Both strings are equal (ignoring case) !!\n");
	else
		printf("Both strings are not equal !\n"); 

	//Freeing both char pointers
	free(str1);
	free(str2);

}


//Function to find the length of the string
int get_len(char *ptrStr)
{
	int l;
	while(*ptrStr != '\0')
	{
		l++;
		ptrStr++;
	}
	l = l-1;
	return l;
}


//Function to take string input from the user
char *get_str()
{
	//Declaring variables
	int i;
	int len1 = 0;
	int len2 = 0;

	char c;
	char *str_gs =NULL;
	char *str_gs_new = NULL;
		
	
	/* Initially allocatiing only a char Byte memory for the first string */
	str_gs = malloc(sizeof(str_gs));
	if(str_gs == NULL)
	{
		printf("Memory allocation failed, out of memory !\n");
		return NULL;
	}
	printf("Please enter the first string: \n");
	i = 0;
	while((c = getchar()) != '\n')
	{
		if(i == 0)
		{
			//Entering the input into an array of characters  
			str_gs[i] = c;
			i++;
			len1 = get_len(str_gs);
			
			/*Reallocating one char byte for each characterv entry */
			str_gs_new = realloc(str_gs, (len1 + 1) * (sizeof (str_gs_new)));
			if(str_gs_new == NULL)
			{
				printf("Memolry re-allocation failed, out of memory! Program exiting...\n");
				
				/* Since the program is exiting, the original allocation has to be freed */
				free(str_gs);
				return NULL;	
			}
			
		}
		else
		{
			//Entering the addtional inputs into the array of characters 
			str_gs_new[i] = c;
			i++;
			len1 = get_len(str_gs_new);

			/*Reallocating one char byte for each character entry */
			str_gs_new = realloc(str_gs_new, (len1 + 1) * (sizeof (str_gs_new)));
			if(str_gs_new == NULL)
			{
				printf("Memolry re-allocation failed, out of memory ! Program exiting...\n");
				
				/* Since the program is exiting, the original allocation has to be freed */
				free(str_gs_new);
				return NULL;
			}

		}		

	}
	return str_gs_new;
}
	

//Modifying all letters into Capital form
void strCap(char *capStr)
{
	//Rolling for all the characters in the given String
	while(*capStr)
	{
		//Testing non-capitalized characters in the string
		if(*capStr >= 'a' && *capStr <= 'z')
		{
			*capStr = *capStr - 32; 
		}
		capStr++;			
	}
}


//Comapring each character of both strings 
int strComp(char *compStr1, char *compStr2)
{
	//Rolling until both or one of the string hits the end
	while((*compStr1 != '\0') && (*compStr2 != '\0'))
	{
		//Comparing the characters of both strings
		if(*compStr1 != *compStr2)
			return -1;
		compStr1++;
		compStr2++;
	}

	/*Comparing the last chatacter if both have same numbers of characters*/ 
	if (*compStr1 == *compStr2)
		return 0;
	else
		return -1;
	
}




