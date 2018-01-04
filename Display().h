#include "Symbolic_Naming_Scheme.h"

int Display( Inventory_Struct* PTR_Assets)
{
	//Variable Declarations
	register int Index = 0;
	int item_counter=0;
	
	//Establish the number of Elements In the Inventory at this time of running.
	for (Index=0; Index<DEMO_MAX; Index++)
	{
		item_counter += (*(PTR_Assets+Index)->Model_Name != '\0') ? 1 : 0;
		
	} //end for
	
	//Provide the neccessary user output
	printf("\nHere are your %d Inventory Listings:\n", item_counter);
	
	//Output all of the Inventory Assets Information:
	for (Index=0; Index<DEMO_MAX; Index++)
	{
		if (*(PTR_Assets+Index)->Model_Name != '\0')
		{
			printf("\n-----------------------------\n-----------------------------\nItem Number: [%d]\nName: [%s]\nCost: [€%.2lf]\nQuantity: [%d]\n", (Index+1), (PTR_Assets+Index)->Model_Name, (PTR_Assets+Index)->Item_Cost, (PTR_Assets+Index)->Item_Quantity);
		} //end if
		
	} //end for
	
	printf("\n-----------------------------\n");
	
	return(item_counter);
	
} //end Display()
