#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int rows, int cols, int [rows][cols]);
void printArray(int rows, int cols, int [rows][cols]);
int *findMaxIndexes(int rows, int cols, int [rows][cols]);
int *findMinIndexes(int rows, int cols, int [rows][cols]);
void swapMax(int rows, int cols, int [rows][cols]);
void swapMin(int rows, int cols, int [rows][cols]);

int main() {
    const int rows = 5;
    const int cols = 5;
    int array[rows][cols];

    fillArray(rows, cols, array);
    printArray(rows, cols, array);
    swapMax(rows, cols, array);
    swapMin(rows, cols, array);
    printArray(rows, cols, array);

    return 0;
}

void fillArray(int rows, int cols, int array[rows][cols]) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            array[i][j] = rand() % 100 - 20;
}

void printArray(int rows, int cols, int array[rows][cols]) {
    printf("Array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}

int *findMaxIndexes(int rows, int cols, int array[rows][cols]) {
    int max = array[0][0];
    int maxI, maxJ;
    static int indexes[2];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }
    
    indexes[0] = maxI;
    indexes[1] = maxJ;

    return indexes;
}

int *findMinIndexes(int rows, int cols, int array[rows][cols]) {
    int min = array[0][0];
    int minI, minJ;
    static int indexes[2];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] < min) {
                min = array[i][j];
                minI = i;
                minJ = j;
            }
        }
    }

    indexes[0] = minI;
    indexes[1] = minJ;
    
    return indexes;
}

void swapMax(int rows, int cols, int array[rows][cols]) {
    int *maxRow = findMaxIndexes(rows, cols, array);
    int temp;
    
    temp = array[maxRow[0]][0];
    array[maxRow[0]][0] = array[maxRow[0]][maxRow[1]];
    array[maxRow[0]][maxRow[1]] = temp;
}

void swapMin(int rows, int cols, int array[rows][cols]) {
    int *minRow = findMinIndexes(rows, cols, array);
    int temp;

    temp = array[minRow[0]][cols - 1];
    array[minRow[0]][cols - 1] = array[minRow[0]][minRow[1]];
    array[minRow[0]][minRow[1]] = temp;
}