#include <stdio.h>
#include <string.h>

int main() {

    char strArray[3][30];
    int positionsArray[30][2] = {}; 
    int arraySize = sizeof(positionsArray) / sizeof(positionsArray[0]);
    char symbol;
    double mean = 0;
    int count = 0;


    printf("Enter a symbol: ");
    scanf("%c", &symbol);
    
    for (int i = 0; i < 3; i++) {
        printf("Enter string: ");
        scanf("%s", strArray[i]);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; strArray[i][j] != '\0'; j++) {
            if (strArray[i][j] == symbol) {
                positionsArray[count][0] = i;
                positionsArray[count][1] = j;
                count++;
            }
        }
    }

    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < 2; j++) {
            if (positionsArray[i][j] % 2 == 1) {
                mean += positionsArray[i][j] / 2.0;
            }
        }
    }
    
    printf("mean is: %.2lf", mean);

    return 0;
}