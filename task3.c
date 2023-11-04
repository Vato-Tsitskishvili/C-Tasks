#include <stdio.h>

int main() {

    int C[5][5];
    int B[5] = {};
    int comparator = 0, maxCol, maxRow, temp;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("C[%d][%d] = ", i, j);
            scanf("%d", &C[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i + j == 4 && C[i][j] > comparator) {
                comparator = C[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    
    for (int i = 0; i < 5; i++) {
        B[i] += C[maxRow][i];
        printf("%d ", B[i]);
    }
    printf("\n\n");

    if (maxCol != 0) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                temp = C[j][0];
                C[j][0] = C[j][maxCol];
                C[j][maxCol] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}