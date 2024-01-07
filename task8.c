#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    char str1[50];
    char str2[50];
    int num;
};

void printData(struct Data*, int);

int main() {

    struct Data data;
    char answer;
    struct Data *dataArray = NULL;
    int arraySize = 0;

    FILE *fileData1_a = fopen("data1.txt", "a");

    if (fileData1_a == NULL) {
        fprintf(stderr, "Error opening data1.txt for writing");
        return 1;
    }
    
    do {
        printf("Enter the first string: ");
        fgets(data.str1, sizeof(data.str1), stdin);
        data.str1[strlen(data.str1) - 1] = '\0';

        printf("Enter the second string: ");
        fgets(data.str2, sizeof(data.str2), stdin);
        data.str2[strlen(data.str2) - 1] = '\0';

        printf("Enter an integer: ");
        scanf("%d", &data.num);
        getchar();

        fprintf(fileData1_a, "%s %s %d\n", data.str1, data.str2, data.num);

        printf("Do you want to continue entering data? (y/n): ");
        scanf("%c", &answer);
        getchar();
    } while (answer == 'Y' || answer == 'y');
    
    fclose(fileData1_a);

    FILE *fileData1_r = fopen("data1.txt", "r");
    if (fileData1_r == NULL) {
        printf("Error opening data1.txt for reading.\n");
        return 1;
    }

    FILE *fileData2_a = fopen("data2.txt", "a");
    if (fileData2_a == NULL) {
        printf("Error opening data2.txt for writing.\n");
        fclose(fileData1_r);
        return 1;
    }

    FILE *fileData3_a = fopen("data3.txt", "a");
    if (fileData3_a == NULL) {
        printf("Error opening data3.txt for writing.\n");
        fclose(fileData1_r);
        fclose(fileData2_a);
        return 1;
    }
    
    while (fscanf(fileData1_r, "%s %s %d", data.str1, data.str2, &data.num) == 3) {
        printf("%s %s %d\n", data.str1, data.str2, data.num);
        fprintf(fileData2_a, "%s %s\n", data.str1, data.str2);
        fprintf(fileData3_a, "%d\n", data.num);

        dataArray = realloc(dataArray, (arraySize + 1) * sizeof(struct Data));
        strcpy(dataArray[arraySize].str1, data.str1);
        strcpy(dataArray[arraySize].str2, data.str2);
        dataArray[arraySize].num = data.num;
        arraySize++;
    }
    
    printData(dataArray, arraySize);
    
    fclose(fileData1_r);
    fclose(fileData2_a);
    fclose(fileData3_a);
    
    free(dataArray);
    dataArray = NULL;
    
    return 0;
}

void printData(struct Data *dataArray, int size) {
    printf("\nData in the array:\n");
    for (int i = 0; i < size; i++) {
        printf("%s %s %d\n", dataArray[i].str1, dataArray[i].str2, dataArray[i].num);
    }
}