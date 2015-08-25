#include <stdio.h>
#include "hardware.h"

/*(Hardware Inventory) You’re the owner of a hardware store and need to keep an inventory that can tell you what tools you have,
 *  how many you have and the cost of each one.
 *  Write a program that initializes the file "hardware.dat" to 100 empty records, 
 * lets you input the data concerning each tool, enables you to list all your tools, 
 * lets you delete a record for a tool that you no longer have and lets you update any information in the file. 
 * The tool identification number should be the record number.*/

int enterChoice(void);

int main(void) {
    FILE* file;
    int choice;
    
    if ((file = fopen("hardware.dat", "rb+")) == NULL){
        printf("File could not be opened.\n");
    } else {
        while ((choice = enterChoice()) != 5){
            switch (choice) {
                case 1:
                    textFile(file);
                    break;
                case 2:
                    updateRecord(file);
                    break;
                case 3:
                    newRecord(file);
                    break;
                case 4:
                    deleteRecord(file);
                    break;
                default:
                    printf("Incorrect choice\n");
                    break;
            }
        }
        fclose(file);
    }
    
    return 0;
}

int enterChoice(void){
    int choice;
    
    printf("\nEnter your choice:\n"
            "1 - store a formatted text file of hardware called \"hardware.txt\" for printing\n"
            "2 - update a record\n"
            "3 - add new record\n"
            "4 - delete a record\n"
            "5 - end program\n");
    
    scanf("%d", &choice);
    return choice;
}
