#include <stdio.h>

/*
count all positive numbers in each column of A[4][3] array,
set those counters as a B[3] elements and display B[3] array
*/

int main() {

    int A[4][3];
    int B[3] = {};
    int counter;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (A[j][i] > 0) {
                counter++;
            }
            B[i] += counter;
            counter = 0;
            printf("%d ", B[i]);
        }
    }

    return 0;
}