

void Edit_Item(Inventory_Struct* PTR_Assets, int* Item_counter)
{
    int Edit_selector;
    
    char Unwanted_Chars;
    
    do
    {
        printf("\nSelect Which Corresponding & Valid Item Number You Wish To Edit: \n");
        
        scanf("%d", &Edit_selector);
        
        
    } while(Edit_selector > *Item_counter || Edit_selector < 0);
    
    printf("\nYou Have Selected to Edit Item Number %d: [%s]\n", Edit_selector , PTR_Assets[Edit_selector-1].Model_Name);
    
    printf("\nRename Model Name: \n");
    
    /*Clear the input buffer of any unwanted data*/
    while ((Unwanted_Chars = getchar()) != '\n' && Unwanted_Chars != EOF );
    
    //Utilising fgets to format input to set length whilst also allowing whitespace data to be read in.
    fgets (PTR_Assets[Edit_selector-1].Model_Name, TEXT_FIELD_MAX-1, stdin);
    
    //Now we must remove the newline character which may be stored as a result of the above fgets() function.
    //If statement checks that the length of string is greater than 0 and the last character is actually the newline specifier which we wish to remove, if so then we put the null terminator in manually.
    if ((strlen(PTR_Assets[Edit_selector-1].Model_Name)>0) && (PTR_Assets[Edit_selector-1].Model_Name[strlen (PTR_Assets[Edit_selector-1].Model_Name) - 1] == '\n'))
    {
        PTR_Assets[Edit_selector-1].Model_Name[strlen (PTR_Assets[Edit_selector-1].Model_Name) - 1] = '\0';
        
    }//end if
    
    printf("\nEdit The Item's Cost: \n");
    scanf("%lf", &PTR_Assets[Edit_selector-1].Item_Cost);
    
    /*Clear the input buffer of any unwanted data*/
    while ((Unwanted_Chars = getchar()) != '\n' && Unwanted_Chars != EOF );
    
    printf("\nEdit The Item's Quantity: \n");
    scanf("%d", &PTR_Assets[Edit_selector-1].Item_Quantity);
    
    /*Clear the input buffer of any unwanted data*/
    while ((Unwanted_Chars = getchar()) != '\n' && Unwanted_Chars != EOF );
    
    printf("\nYou Have Successfully Edited This Inventory Asset\n");

    printf("\n-----------------------------\n-----------------------------\nItem Name: [%s]\nItem Cost: [%.2lf]\nItem Quantity: [%d]\n", (PTR_Assets[Edit_selector-1].Model_Name), (PTR_Assets[Edit_selector-1].Item_Cost), (PTR_Assets[Edit_selector-1].Item_Quantity));
    
}//end Edit_item()