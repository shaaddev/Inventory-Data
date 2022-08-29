// final assignment -- the big one
// scripted by R.L.H -- 16 Jul 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct InventoryData{

    int item_num;
    char name[20];
    double unit_price;
    int min_lvl;
    int opt_lvl;
    int qty_hand;
    double total_values; // added in

} InventoryItems[10];

void mainmenu(void);
void submenu(void);
void inventory_data(struct InventoryData InventoryItems[10]);
void inventory_disp(struct InventoryData InventoryItems[10]);
void inventory_details(struct InventoryData InventoryItems[10]);
void inventory_stats_report(struct InventoryData InventoryItems[10]);
void out_of_stock(struct InventoryData InventoryItems[10]);
void reorder_items(struct InventoryData InventoryItems[10]);


void mainmenu(void){

    printf("\n\n-----MAINMENU-----\n");
    printf("1. Inventory Data\n");
    printf("2. Search Inventory by Item#\n");
    printf("3. View Inventory Reports\n"); // for the submenu
    printf("0. Quit\n");
}

void submenu(void){

    printf("\n\n-----SUB MENU-----\n");
    printf("1. Inventory Statistics Report\n");
    printf("2. Out of Stock Inventory Report\n"); 
    printf("3. Items for Reorder (File)\n");
    printf("4. Back to menu\n");
}

void inventory_data(struct InventoryData InventoryItems[10]){ // reading file to start the program

    FILE *fptr;
    
    int i;
    //char fname[20];
    

    char fname[20] = "i_Data.txt";    // ***************  Edit as required  -- Note text file with HEADER line
    
     printf("Filename  (i-Data.txt) - loaded : \n");
     // printf("Enter the filename you would like to open : ");
     // scanf("%s", fname);
     
     fptr = fopen(fname, "r");
        if (fptr == NULL){
            printf("Error!\nCannot Open File\nPlease Try Again !\n");
            exit(1);
        }
        
        char data[200];
       // fgets(data, 200, fptr);
        
            
       for (i = 0; i < 10; i++){
            fscanf(fptr,"%d %s %lf %d %d %d", &InventoryItems[i].item_num, InventoryItems[i].name, &InventoryItems[i].unit_price,
             &InventoryItems[i].min_lvl, &InventoryItems[i].opt_lvl, &InventoryItems[i].qty_hand);
        } 
        
    fclose (fptr);
    fptr = NULL;
}

void inventory_disp(struct InventoryData InventoryItems[10]){ // displaying the data in menu // display the data but with the total value in descending order

    
    int i, j, n = 10;

    struct InventoryData swap;
   
    for (i = 0; i < 10; i++){
        InventoryItems[i].total_values = InventoryItems[i].unit_price * InventoryItems[i].qty_hand;
    }
    
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - 1; j++){
            if (InventoryItems[j].total_values < InventoryItems[j + 1].total_values){
                swap = InventoryItems[j];
                InventoryItems[j] = InventoryItems[j + 1];
                InventoryItems[j + 1] = swap;
            }
        }
    } 
    

    printf("\nINFORMATION OF DATA\n\n");

    printf("%s %13s %17s %18s %20s %24s %28s\n", "Item#", "Name", "Unit Price", "Min Lev", "Opt Level", "Qty on Hand", "Total Values");
    for (i = 0; i < 10; i++){
        printf("%d %15s %14.2lf %18d %21d %23d %27.2lf\n", InventoryItems[i].item_num, InventoryItems[i].name, InventoryItems[i].unit_price, 
        InventoryItems[i].min_lvl, InventoryItems[i].opt_lvl, InventoryItems[i].qty_hand, InventoryItems[i].total_values);
    }

    
}

void inventory_details(struct InventoryData InventoryItems[10]){ // works fine apart from the else statement ending the program

    int input, loc, i; // loc = location
    //bool found = true; ///
    bool found = false; ///
    // Requires input of Item# to find a match and displays details of inventory matching the item#
    // Appropriate feedback needs to be displayed if match has not been found

    do
    {
    printf("Search Bar (Enter Item#) : ");
    scanf("%d", &input);
    printf("\n");

    for (i = 0; i < 10; i++){
        if(input == InventoryItems[i].item_num){
            loc = i;
            found = true;
        }
        
    }

    if (found){
        printf("%s %18s %20s %22s %23s %24s \n", "Name", "Unit Price", "Min Lev", "Opt Level", "Qty on Hand", "Total Values");
        printf("%s %12.2lf %20d %22d %23d %25.2lf\n\n", InventoryItems[loc].name, InventoryItems[loc].unit_price, InventoryItems[loc].min_lvl, 
        InventoryItems[loc].opt_lvl, InventoryItems[loc].qty_hand, InventoryItems[loc].total_values);
    }
    else {
        printf("Error!\nPlease Try Again");
    }
    
 
    printf("1. Main Menu : ");
    scanf("%d", &input);

    }
    while (input != 1);

}

void inventory_stats_report(struct InventoryData InventoryItems[10]){ // check stats == check stats == check stats
    
    // Displays a list of all inventory items with summary information at the bottom, itemizing:
    // Total Values of All Inventory
    // Average Value of All Inventory

    int i;
    double total_value, avg_value;

    total_value = 0;


    for (i = 0; i < 10; i++){
        total_value = total_value + InventoryItems[i].total_values;
    }

    avg_value = (total_value / 10);

    printf("\n%s %16s %19s %23s %25s\n", "Item#", "Name", "Unit Price", "Qty on Hand", "Total Value");

    for (i = 0; i < 10; i++){
        printf("%d %17s %20.2lf %22d %24.2lf\n", InventoryItems[i].item_num, InventoryItems[i].name, InventoryItems[i].unit_price, InventoryItems[i].qty_hand,
        InventoryItems[i].total_values);
    }   
    

    printf("\n------- Stats\n");
    printf("Total Value of All Inventory = %.2lf\n", total_value);
    printf("Average Value of All Inventory = %.2lf\n", avg_value);

    
}

void out_of_stock(struct InventoryData InventoryItems[10]){
    // Display details of all inventory items that have a Qty in Stock Balance of 0

    int loc; // loc = location

    printf("\n%s %16s %19s %23s %25s\n", "Item#", "Name", "Unit Price", "Qty on Hand", "Total Value");

    for (loc = 0; loc < 10; loc++){
        if (InventoryItems[loc].qty_hand == 0){
            printf("%d %17s %20.2lf %22d %24.2lf\n", InventoryItems[loc].item_num, InventoryItems[loc].name, InventoryItems[loc].unit_price, InventoryItems[loc].qty_hand,
         InventoryItems[loc].total_values);
        }
    }
    
    printf("\n\n");
    

}

void reorder_items(struct InventoryData InventoryItems[10]){ // calculations to be looked at

    FILE *fpoint;

    
    int loc;
    int reorder_amt, reorder_num = 0;
    double order_value = 0.00;

    

    printf("\n\nFile Processing...\n");
    fpoint = fopen("Orders.txt", "w");
        if (fpoint == NULL){
            printf("Error!\nCannot Open File!\nPlease Try Again\n");
            exit(1);
        }

        for (loc = 0; loc < 10; loc++){
            InventoryItems[loc].total_values = InventoryItems[loc].unit_price * InventoryItems[loc].qty_hand;
        }

        fprintf(fpoint, "%30s\n\n", "Inventory Order Report");

        fprintf(fpoint, "%s %16s %23s", "Item#", "Name", "Reorder Amt\n");
        for (loc = 0; loc < 10; loc++){
            if(InventoryItems[loc].qty_hand <= InventoryItems[loc].min_lvl){
                reorder_amt = (InventoryItems[loc].opt_lvl - InventoryItems[loc].qty_hand);
                reorder_num = reorder_num + reorder_amt; // counting the numbers to reorder
                order_value += InventoryItems[loc].total_values; // calculating the total value of items to reorder
        
            fprintf(fpoint, "%d %18s %20d\n", InventoryItems[loc].item_num, InventoryItems[loc].name, reorder_amt);

            }
            
        }
        fprintf(fpoint, "-----------------------------------------------");
        fprintf(fpoint, "\n\n%25s\n", "Statistics");
        fprintf(fpoint, "# Items to Reorder : %24d \n", reorder_num);
        fprintf(fpoint, "Total cost of Reorder Items : %15.2lf\n", order_value);
        fprintf(fpoint, "\n");

    fclose(fpoint);

    printf("File Created. \n");
    
    printf("\n\n%21s\n", "Statistics");
    printf("# Items on Reorder : %d \n", reorder_num);
    printf("Total cost of Reorder Items : %.2lf \n", order_value);
    printf("\n");

    /* 
    Create a file called "Orders.txt" and write a list of all Inventory Items that need to be reordered along wtih the quantity to be ordered
    
    . Item with current qty on hand balance of "Less than OR Equal to the mim level" need to be reordered
    . The Reorder amount is calculated as the Optimum Level - Quantity in Stock
    . Reorder Statistics to be displayed in Report  
    */
}

int main(){

    struct InventoryData InventoryItems[10];
    int choice;
    
    printf("Inventory Management System\n\n");
    printf("Press ENTER to continue...");

    getchar();

    inventory_data(InventoryItems);

    do{
    mainmenu();
    printf("Input : ");
    scanf("%d", &choice);
    printf("\n\n");


    switch(choice){
        case 1:
            inventory_disp(InventoryItems);
            break;
        case 2:
            inventory_details(InventoryItems);
            break;
        case 3:
            do{
            submenu();
            printf("Input : ");
            scanf("%d", &choice);

            switch(choice){
                case 1:
                    inventory_stats_report(InventoryItems);
                    break;
                case 2:
                    out_of_stock(InventoryItems);
                    break;
                case 3:
                    reorder_items(InventoryItems);
                    break;
                case 4:
                    break;   
                default:
                    printf("Error\nPlease Try Again.\n");
                    break;
            }
            }
            while (choice != 4);
            break;
        case 0: 
            printf("Goodbye. \n");
            return 0;
            break;
        default:
            printf("Please enter a VALID option !\n");
            break;
    }
    }
    while (choice != 0);

    return 0;
}