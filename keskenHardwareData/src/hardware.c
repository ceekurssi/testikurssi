#include "hardware.h"

struct HardwareData {
    int idNumber;
    char toolName[30];
    int quantity;
    double cost;
};

void textFile(FILE* file) {
    FILE* write;
    HardwareData data = {0, "", 0, 0.0};

    if ((write = fopen("hardware.txt", "w")) == NULL) {
        printf("File could not be opened");
    } else {
        rewind(file);
        fprintf(write, "%s%s%s%s", "id", "Tool name", "Quantity", "Cost");

        while (!feof(file)) {
            fread(&data, sizeof (HardwareData), 1, file);
            if (data.idNumber != 0) {
                fprintf(write, "%d%s%d%f", data.idNumber, data.toolName, data.quantity, data.cost);
            }
        }
        fclose(write);
    }
}

void updateRecord(FILE* file) {
    int id;
    int quantity;
    double cost;

    HardwareData data = {0, "", 0, 0.0};
    printf("Enter id to update (1-100): ");
    scanf("%d", &id);

    fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
    fread(&data, sizeof (HardwareData), 1, file);

    if (data.idNumber == 0) {
        printf("No data found\n");
    } else {
        printf("%d%s%d%f\n", data.idNumber, data.toolName, data.quantity, data.cost);
        printf("Enter new quantity: ");
        scanf("%d", &quantity);
        data.quantity = quantity;
        printf("\nEnter new price: ");
        scanf("%lf", &cost);
        data.cost = cost;
        printf("%d%s%d%f\n", data.idNumber, data.toolName, data.quantity, data.cost);
        fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
        fwrite(&data, sizeof (HardwareData), 1, file);
    }

}

void newRecord(FILE* file) {
    HardwareData data = {0, "", 0, 0.0};
    int id;
    
    printf("Enter new id (1-100): ");
    scanf("%d", &id);
    
    fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
    fread(&data, sizeof (HardwareData), 1, file);
    
    if (data.idNumber != 0) {
        printf("Id already contains information.\n");
    } else {
        printf("Enter new name, quantity and price: ");
        scanf("%s%d%lf", &data.toolName, &data.quantity, &data.cost);
        data.idNumber = id;
        fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
        fwrite(&data, sizeof (HardwareData), 1, file);
    }

}

void deleteRecord(FILE* file) {
    HardwareData data;
    HardwareData blankData = {0, "", 0, 0.0};
    int id;
    
    printf("Enter id to delete (1-100): ");
    scanf("%d", &id);
    
    fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
    fread(&data, sizeof (HardwareData), 1, file);
    
    if (data.idNumber == 0) {
        printf("No data found\n");
    } else {
        fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
        fwrite(&blankData, sizeof (HardwareData), 1, file);
    }
    

}
