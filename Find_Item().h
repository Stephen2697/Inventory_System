void Find_Item(Inventory_Struct* PTR_Assets)
{
    int Index;
	int Item_counter = 0;
	int Search_counter=0;
    char User_Input[TEXT_FIELD_MAX];
	char *Match_Substring[DEMO_MAX];
	int Match_Flagger[DEMO_MAX] ={0};
	int No_Matches=0;
    
    //Establish the number of Elements In the Inventory at this time of running.
    for (Index=0; Index<DEMO_MAX; Index++)
    {
        Item_counter += (*(PTR_Assets+Index)->Model_Name != '\0') ? 1 : 0;
        
    } //end for
	
	printf("\nEnter A Search Phrase To Search For Your Inventry Item:\n");
	
	do
	{
		
		//Utilising fgets to format input to set length whilst also allowing whitespace data to be read in.
		fgets (User_Input, TEXT_FIELD_MAX-1, stdin);

		//Now we must remove the newline character which may be stored as a result of the above fgets() function.
		//If statement checks that the length of string is greater than 0 and the last character is actually the newline specifier which we wish to remove, if so then we put the null terminator in manually.
		if ((strlen(User_Input)>0) && (User_Input[strlen (User_Input) - 1] == '\n'))
		{
			User_Input[strlen (User_Input) - 1] = '\0';
			
		}//end if
		
		if ((strlen(User_Input) < 2))
		{
			printf("\nPlease Enter A Search Phrase With More Characters\n");
		}
		
	}while (strlen(User_Input)<2);
	
	for (Index=0; Index<Item_counter; Index++)
	{
		//perform the string-substring comparison
		Match_Substring[Index] = strstr((PTR_Assets+Index)->Model_Name, User_Input);
		
		//If we have a match in string - substring comparisons then increment No_Matches - i.e. counting the number of partial & exact matches that occur in one variable. We detect match if the Match_Substring is not NULL.
		No_Matches += (Match_Substring[Index] != NULL) ? 1 : 0;
		
		//Now we create a map of the Match_Substring[] in an integer array Match_Flagger[], we assign a specified value when a partial match is found and if not - nothing is changed and we loop again.
		Match_Flagger[Index] = (Match_Substring[Index] != NULL) ? -99 : Match_Flagger[Index];
		
	} //end for
	
	printf("\nNumber Of Matches Found: %d\n", No_Matches);
	
	//print out search results
	if (No_Matches > 0)
	{
		for (Index=0; Index<Item_counter; Index++)
		{
			
			if (Match_Flagger[Index] == -99)
			{
				Search_counter++;
				
				printf("\n-----------------------\n-----------------------\nSearch Result [%d]:\nItem Name: [%s]\nItem Cost: [%.2lf]\nItem Quantity: [%d]\n", Search_counter, (PTR_Assets+Index)->Model_Name, (PTR_Assets+Index)->Item_Cost, (PTR_Assets+Index)->Item_Quantity);
				
				//Match_Flagger[Index] = 0;
				
			}//end if
		} //end for
	} //end if
	
	
} //end Find_Item()
