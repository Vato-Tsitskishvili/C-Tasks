#include <stdio.h>

int main() {

    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[3] = {};
    int C[3][3] = {
        {4, 3, 5},
        {4, 5, 3},
        {5, 6, 4}
    };
    int sum = 0, max = 0, maxI;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += A[j][i];
        }
        B[i] += sum;
        printf("%d ", B[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        if (B[i] > max) {
            max = B[i];
            maxI = i;
        }
    }
    printf("%d \n", maxI);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[j][0] = A[j][maxI];   
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}