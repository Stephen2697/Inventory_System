#include <stdio.h>
#include "Symbolic_Naming_Scheme.h"

char Enter_Code(void)
{
	//Varaible Decalrations
	register int Index;

	/*Error checking variable, It will have four desired states;
	 State ZERO: 'Zero Value State' - No illegal entries have been made,
	 State ONE: 'One Value State' - Characters entered are NOT Digits,
	 State TWO: 'Two Value State' - Too Many Characters have been entered.
	 State THREE: 'Three Value State' - Too Few Characters have been entered.
	 State FOUR: 'Four Value State' - User Input is not the Key Code.*/
	short int illegal_entry_checker;
	
	char Unwanted_Chars;
	
	//Used to Store the Actual Key Code
	int Unique_Key[KEY_SIZE +1] = {UNIQUE_IDENTIFIER_KEY};
	
	//Used to Take in the User's Key Code
	char user_input[KEY_SIZE +1];
	
	printf("----\n");
	do
	{
		
		//Error Checking Initialisation
		*(user_input+KEY_SIZE) = *(user_input+(KEY_SIZE-1)) = '\0';
		
		//Error Checking Variable - Set to 0 to represent Zero Errors
		illegal_entry_checker = 0;
		
		//Take in User Code
		scanf("%5s", user_input);
		
		while ((Unwanted_Chars = getchar()) != '\n' && Unwanted_Chars != EOF );
		
		//In this case the user has triggered an error - The 5th array ( i.e. user_input[4]) location has been used - too many characters have been entered.
		if (*(user_input+KEY_SIZE) != '\0')
		{
			 /*Triggering State TWO: 'Two Value State' - Too Many Characters have been entered.*/
			illegal_entry_checker = 2;
		} //end if
		
		//In this case the user has entered no data in the 3rd postion i.e. user_input[2], meaning their code is too short to be correct.
		if (*(user_input+(KEY_SIZE-1)) == '\0')
		{
			//Triggering State THREE: 'Three Value State' - Too Few Characters have been entered.*/
			illegal_entry_checker = 3;
		} //end else if
		
		//Now that we have established the correct number of characters has been entered we check is each character a digit.
		else if (*(user_input+(KEY_SIZE-1)) != '\0')
		{
			
			for(Index=0; Index<KEY_SIZE; Index++)
			{
				//Turnary - Conditional Operator - If a digit is outisde the ASCII Range of an Integer (0-9) we trigger State ONE: 'One Value State' - Characters entered are NOT Digits. Otherwise nothing changes. Loops 4 times
				illegal_entry_checker = (*(user_input + Index)<48 || *(user_input + Index)>57 )? 1 : illegal_entry_checker;
				
			} //end for
		} //end else
		
		//checking if No errors have been triggered thus far..
		if (illegal_entry_checker == 0)
		{
			//Checking to see are Key Code & User Input Equal, if not Trigger State FOUR: 'Four Value State' - User Input is not the Key Code.
			for(Index=0; Index<KEY_SIZE; Index++)
			{
				
				//ASCII Values are converted to Integers by subtracting the ASCII 0 Value (48), using a Turnary Statement below we can accomplish this and then look for Unique Key equality.
				illegal_entry_checker = (*(Unique_Key +Index) != *(user_input + Index) - 48)? 4 : illegal_entry_checker;
				
			} //end for
		}
		
		//Now we breakdown and filter the Triggered Errors to provide user feedback
		if (illegal_entry_checker!=0)
		{
			/*Dealing With - State One: 'One Value State' - Characters entered are NOT Digits*/
			if (illegal_entry_checker == 1)
			{
				printf("\nInput Error - There Has Been Atleast One Illegal Character Entered, Please Try again - Perhaps Try Entering 1234!\n\n");
			} //end if
			
			/*Dealing With - State Two: 'Two Value State' - Too Many Characters have been entered.*/
			else if (illegal_entry_checker == 2)
			{
				printf("\nInput Error - There Have Been Too Many Characters Entered, Please Try again - Perhaps Try Entering 1234!\n\n");
			} //end else if
			
			/*Dealing With - State Three: 'Three Value State' - Too Few Characters have been entered.*/
			else if (illegal_entry_checker == 3)
			{
				printf("\nInput Error - Too Few Characters entered, Please Try again - Perhaps Try Entering 1234!\n\n");
			} //end else if
			
			/*Dealing With - State Four: 'Four Value State' - User Input is not the Key Code..*/
			else if (illegal_entry_checker == 4)
			{
				printf("\nInput Error - The Key Code You Have Entered Is Incorrect - Perhaps Try Entering 1234!\n\n");
			} //end else if
			
		} //end if
		
	} /*Loop Continues Until the Program returns State One: 'Zero Value State' - No illegal entries have been made */
	while (illegal_entry_checker!=0);
	
	return (CONTINUE);
}



	
	
