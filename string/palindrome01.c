/* This piece of program takes a user input String and tests it for being Palindrome 
by reverrsiong it and checking of the String   */

#include<stdio.h>

//Function declarations
int get_len(char*);


int main()
{
	
	//Initializing the variables
	char arrStr[100] = {'\0'}; 
	char arr_revStr[100] = {'\0'};
	int i, lenStr = 0, comChar = 0;

	//Taking user input
	printf("Enter a string to test\n");
	gets(arrStr);

	//Determing the lenghth of the string
	lenStr = get_len(arrStr); 	
	printf("The length of the given string %s is: %d\n", arrStr, lenStr);
	
	//reversing the string
	for(i = lenStr -1; i >= 0; i--)
	{
		arr_revStr[lenStr - i -1] = arrStr[i];	
	}
	
	//Determinung the length of the reversed string
	lenStr = get_len(arr_revStr);
	printf("The reversed string is %s with length %d\n", arr_revStr, lenStr);
	

	//Comparing both: the given string and the reversed string to test
	for(comChar = 1, i = 0; i < lenStr; i ++)
	{
		if(arr_revStr[i] != arrStr[i])
		{
			comChar = 0;
		}
	}
	
	if (comChar == 1)
	{
		printf("The given string is a palindrome\n");
	}
	else
	{
		printf("The given string is not a palindrome\n");
	}
	
	return 0;
}



//Function to find the length of a string
int get_len(char *ptr_strArr)
{
    int l=0;

	//Increment the counter until found NULL
    while(*ptr_strArr != '\0')
    {
        ptr_strArr++;
        l++;
    }

	return l;
}
