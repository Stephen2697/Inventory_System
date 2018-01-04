//PROGRAM TITLE: Inventory.c
//PROGRAM SPECIFICATION: (see GrpTasksOddTeams.pdf documentation)
//PROGRAM FUNCTION: Mimic Inventory System
//CREATION DATE: 08/04/2017
//LAST MODIFIED: 19/04/2017
//VERSION IDENTIFIER: 1.0
//AUTHOR: Stephen Alger ©
//PROGRAMMING LANGUAGE: C
//LICENSE: ALL RIGHTS RESERVED STEPHEN ALGER © 2017

//REFERENCES FOR CODE DESIGN
//1. 'A Guide To C Programming' - © Paul Kelly 2007


//INTEGRATED LIBRARIES & FILES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "Symbolic_Naming_Scheme.h"
#include "Structure_Templates.h"

#include "Edit_Item().h"
#include "Add_New_Item().h"
#include "Delete_Old_Item().h"
#include "Find_Item().h"
#include "Record_Inventory().h"
#include "Display().h"
#include "Enter_Code().h"


//FUNCTION PROTOTYPES
int Display( Inventory_Struct*);
void Add_New_Item( Inventory_Struct*);
void Delete_Old_Item( Inventory_Struct*, int*);
void Edit_Item(Inventory_Struct*, int*);
void Find_Item(Inventory_Struct*);
void Record_Inventory(Inventory_Struct*);
char Enter_Code(void);


int main()
{
    
	Inventory_Struct Assets[DEMO_MAX] = {'\0', 0, 0};
	Inventory_Struct *PTR_Assets = Assets;
	
	char Unwanted_Chars;
	char Loop;
	char Switch_Identifier[2];
	
	int Index= 0;
	int Item_counter;
	int No_Space_Flag;
	int Empty_Array_Flag = 0;
	
//	(PTR_Assets + (DEMO_MAX-1))->Item_Cost = UNCHANGED_NUM;
	
	printf("\nHello, Welcome To This Inventory System, Please Enter The Secure Unique Identifier Key:\n");
	
	Loop = Enter_Code();
	
	//Add 3 'pre-initialised contacts' Demo purposes
	strcpy((PTR_Assets+0)->Model_Name, "Apple Macbook 13");
	(PTR_Assets+Index)->Item_Cost = 1999.99;
	(PTR_Assets+Index)->Item_Quantity = 19;
	
	Index++;
	
	strcpy((PTR_Assets+1)->Model_Name, "Dell XPS 15");
	(PTR_Assets+Index)->Item_Cost = 1799.99;
	(PTR_Assets+Index)->Item_Quantity = 13;
	
	Index++;
	
	strcpy((PTR_Assets+2)->Model_Name, "HP Spectre 13");
	(PTR_Assets+Index)->Item_Cost = 1499.99;
	(PTR_Assets+Index)->Item_Quantity = 9;
	
	
	while (Loop == CONTINUE || Loop == CONTINUE_SMALL)
	{
		/*assign & re-assign Switch_Identifier[1] position to '\0', important for menu error checking*/
		*(Switch_Identifier+1) = '\0';
		
		No_Space_Flag = 0;
		
		/*Display Menu to User*/
		printf("\nChoose What You Would Like To Do:\n1. Add new item\n2. Delete old item\n3. Edit item\n4. Find item\n5. Record inventory\n");
		
		/*Take in the user's choice*/
		scanf("%2s", Switch_Identifier);
		
		/*Clear the input buffer of any unwanted data*/
		while ((Unwanted_Chars = getchar()) != '\n' && Unwanted_Chars != EOF );
		
		/*Simple error check - Exectute these statements only if the user has entered no more than one digit*/
		if (*(Switch_Identifier+1) =='\0')
		{
			//start the programme here....
			switch (*(Switch_Identifier+0))
			{
				//User Selects Option 1 - Add new item.
				case '1':
				{
					//Simple turnary conditon - if the last struct element is unchanged we know there is still free space within the struct array.
					No_Space_Flag = (*(PTR_Assets + (DEMO_MAX-1))->Model_Name != '\0')? 1 : 0;
					
					//check is there any space
					if (No_Space_Flag != 1)
					{
						
						printf("\nThere is space\n");
						
						//Call Add_New_Item function
						Add_New_Item(PTR_Assets);
						
					} //end if
					
					else
					{
						printf("\nThere is No space\n");
						
					} //end else
					
					break;
				} //end case one
				
				//User wishes to Delete an Old element of the inventory system
				case '2':
				{
					Empty_Array_Flag = (*(PTR_Assets + 0)->Model_Name != '\0') ? 0 : 1;
					
					if (Empty_Array_Flag == 0)
					{
						Item_counter = Display( PTR_Assets);
						
						Delete_Old_Item( PTR_Assets, &Item_counter);
						
					} //end if
					
					else
					{
						printf("\nThere Are No Inventory Listings To Delete\n");
					}
					
					break;
				}
                   
                //User wishes to edit an item in the inventory
                case '3':
                {
                    Empty_Array_Flag = (*(PTR_Assets + 0)->Model_Name != '\0') ? 0 : 1;
                    
                    if (Empty_Array_Flag == 0)
                    {
                        Item_counter = Display( PTR_Assets);
                        
                        Edit_Item(PTR_Assets, &Item_counter);
                        
                        printf("\nYour Updated Inventory...\n");
                        Item_counter = Display( PTR_Assets);
                        
                    } //end if
                    
                    else
                    {
                        printf("\nThere Are No Inventory Listings To Edit\n");
                    } //end else
					
					break;
                    
                }// end case 3
                    
                //User wishes to edit an item in the inventory
                case '4':
                {
					Empty_Array_Flag = (*(PTR_Assets + 0)->Model_Name != '\0') ? 0 : 1;
					
					if (Empty_Array_Flag == 0)
					{
						Find_Item( PTR_Assets);
					} //end if
					
					else
					{
						printf("\nThere Are No Inventory Listings To Search\n");
					} //end else
					
                    break;
                }
                    
                //User wishes to edit an item in the inventory
                case '5':
                {
					
					Empty_Array_Flag = (*(PTR_Assets + 0)->Model_Name != '\0') ? 0 : 1;
					
					if (Empty_Array_Flag == 0)
					{
						Record_Inventory( PTR_Assets);
					} //end if
					
					else
					{
						printf("\nThere Are No Inventory Listings To Search\n");
					} //end else
					
                    break;
                }
		
				default:
				{
                    /*provide user feedback*/
                    printf("\nError In Menu Selection, Try Again!\n");
                    
					break;
				} //end default
		
			}  //end switch
		}
		
		/*If Data has been entered in the Switch_Identifier[1] position...
		 This means that more than one character has been entered - invalid entry*/
		else
		{
			/*provide user feedback*/
			printf("\nError In Menu Selection, Try Again!\n");
			/*iterate the while loop once more i.e. re-output the menu*/
			Loop = CONTINUE;
		} //end else
	
	} //end while

	
	return 0;
	
	
} //end main()
