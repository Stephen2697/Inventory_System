
void Record_Inventory(Inventory_Struct* PTR_Assets)
{
    
    int Index = 0;
    int Item_counter=0;
    FILE* Inventory_Record;
    
    char Filename[TEXT_FIELD_MAX] = {"/Users/Stephen/Inventory_Record.txt"};
    
    //variable declared of type time_t
    time_t raw_time;
    
    //call time() function, passing the address of struct variable raw_time
    time( &raw_time);
    
    //pointer to struct tm called timeinfo
    struct tm * timeinfo;
    
    //Struct pointer takes in return of localtime() which is passed the address of raw_time
    timeinfo = localtime(&raw_time);
   
    //open File
    Inventory_Record = fopen(Filename, "a+");
    
    //error checking of file opening
    if(ferror(Inventory_Record) == 0)
    {
        
        ftell(Inventory_Record);
        fprintf(Inventory_Record, "\n--------------------------------------------\n***Time and Date Of Backup:***\n%s\n--------------------------------------------\n", asctime(timeinfo));
        
        
        //Establish the number of Elements In the Inventory at this time of running.
        for (Index=0; Index<DEMO_MAX; Index++)
        {
            Item_counter += (*(PTR_Assets+Index)->Model_Name != '\0') ? 1 : 0;
            
        } //end for
        
        for (Index=0; Index<Item_counter; Index++)
        {
            ftell(Inventory_Record);
            fprintf(Inventory_Record, "Item Number [%d]\nItem Name: [%s]\nItem Cost: EURO [%.2lf]\nItem Quantity: [%d]\n--------------------------------------------\n", Index+1, (PTR_Assets+(Index))->Model_Name, (PTR_Assets+(Index))->Item_Cost, (PTR_Assets+(Index))->Item_Quantity);
            ftell(Inventory_Record);
            
        }//end for
        
    printf("\nWe Have Successfully Backed Up Your Inventory Data.\n");
        
    }//end if
 
    else if (ferror(Inventory_Record) != 0)
    {
        printf("\nUnfortunately We Could Not Back Up Your Inventory Data,\nPlease Try Again...\n");
    }//end else
    
    
}// end Record function
