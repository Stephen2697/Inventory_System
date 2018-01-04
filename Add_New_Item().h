#include "Symbolic_Naming_Scheme.h"

/*
 Function Name: Add_New_Item()
 Functionality: This Function works with the specific Struct Array Variable declared in Main() to facilitate the action of adding elements to the user's Inventory at their request. This Function is menu driven and Input Validation is Utilised Extensively in areas such as preventing buffer overflow and prevention of memory segmentation issues which may arise where the size of user input strings are greater than the memory allocated to the character array.
 Function Arguements: Pointer to the Address of a Struct Array [Inventory_Struct* PTR_Assets]
 Function Returns: None - [void]
 */


void Add_New_Item(Inventory_Struct* PTR_Assets)
{
	//Variable declarations
	int Index=0;
	char Unwanted_Chars;
	
	//Align Index with the earliest free inventory slot...
	while ((PTR_Assets+Index)->Item_Quantity !=0)
	{
		Index++;
	}
	
	//Provide User Feedback & Prompt to input data
	printf("\nTo Add New Inventory Items - Please Follow These Steps:\n");
	printf("\nEnter The Name Of The IT Asset You Wish To Add To The Inventory:  \n");
	
	//Utilising fgets to format input to set length whilst also allowing whitespace data to be read in.
	fgets (PTR_Assets[Index].Model_Name, TEXT_FIELD_MAX-1, stdin);
	
	//Now we must remove the newline character which may be stored as a result of the above fgets() function.
	//If statement checks that the length of string is greater than 0 and the last character is actually the newline specifier which we wish to remove, if so then we put the null terminator in manually.
	if ((strlen(PTR_Assets[Index].Model_Name)>0) && (PTR_Assets[Index].Model_Name[strlen (PTR_Assets[Index].Model_Name) - 1] == '\n'))
	{
		PTR_Assets[Index].Model_Name[strlen (PTR_Assets[Index].Model_Name) - 1] = '\0';
		
	}//end if
	
	//...More user feedback
	printf("\nEnter The Cost Of [%s]:  \n", PTR_Assets[Index].Model_Name);
	
	//Input the cost of the item, using the double specifier to maintain post decimal point accuracy.
	scanf("%lf", &PTR_Assets[Index].Item_Cost);
	
	//Clear the input buffer of any unwanted data
	while ((Unwanted_Chars = getchar()) != '\n' && Unwanted_Chars != EOF );
	
	//...More user feedback
	printf("\nEnter The Quantity Of The IT Asset [%s]:  \n", PTR_Assets[Index].Model_Name);
	
	//Input Integer Data of the Quantity of Items in stock
	scanf("%d", &PTR_Assets[Index].Item_Quantity);
	
	//Clear the input buffer of any unwanted data
	while ((Unwanted_Chars = getchar()) != '\n' && Unwanted_Chars != EOF );
	
	//Summarise the Inputted Data for the user
	printf("\nSuccessfully Added The Following Inventory Item:\nName:[%s]\nCost: [€%.2lf]\nQuantity Of Items: [%d]\n", PTR_Assets[Index].Model_Name, PTR_Assets[Index].Item_Cost, PTR_Assets[Index].Item_Quantity);
	
	
}// end Add_New_Item()
