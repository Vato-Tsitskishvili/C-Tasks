#include <stdio.h>

int main() {

    int A[3][3];
    int arraySize = 9;
    int B[9] = {};
    int temp;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
            B[i * 3 + j] = A[i][j];
        }
    }
    
    for (int i = 1; i < arraySize; i++) {
        for (int j = 0; j < arraySize - i; j++) {
            if (B[j] > B[j + 1]) {
                temp = B[j];
                B[j] = B[j + 1];
                B[j + 1] = temp;
            }
        }
        printf("%d ", B[i]);
    }

    return 0;
}