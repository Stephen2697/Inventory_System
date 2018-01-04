#include "Symbolic_Naming_Scheme.h"

/*
 Function Name: Delete_Old_Item()
 Functionality: 
 Function Arguements: Pointer to the Address of a Struct Array [Inventory_Struct* PTR_Assets]
 Function Returns: None - [void]
 */

void Delete_Old_Item( Inventory_Struct* PTR_Assets, int* Item_counter)
{
	int Delete_selector;
	int Index;
	
	do
	{
		printf("\nUsing the 'Item Number' From The Menu Above Select A Valid Element You Wish To Delete\n");
		scanf("%d", &Delete_selector);
	
	} while ((Delete_selector<0) && (Delete_selector> *Item_counter));
	
	Delete_selector += -1;
	
	//move array elements up - overwrite & move contents up one position
	if (Delete_selector != (DEMO_MAX-1))
	{
		for (Index=Delete_selector; Index<DEMO_MAX-1; Index++)
		{
			strcpy((PTR_Assets+Index)->Model_Name, (PTR_Assets+(Index+1))->Model_Name);
			(PTR_Assets+Index)->Item_Cost = (PTR_Assets+(Index+1))->Item_Cost ;
			(PTR_Assets+Index)->Item_Quantity = (PTR_Assets+(Index+1))->Item_Quantity;

		}
        
        strcpy((PTR_Assets+(Index+1))->Model_Name, "\0");
        (PTR_Assets+(Index+1))->Item_Cost = 0;
        (PTR_Assets+(Index+1))->Item_Quantity = 0;
        
	}
	
	else
	{
		strcpy((PTR_Assets+Delete_selector)->Model_Name, "\0");
		(PTR_Assets+Delete_selector)->Item_Cost = 0;
		(PTR_Assets+Delete_selector)->Item_Quantity = 0;

	}
	
	Item_counter--;
	
}// end Delete_Old_Item()
