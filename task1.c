#include <stdio.h>

/*
A[3][3] მასივი, ინდექსები გადავაანგარიშოთ, 
რომ გადავწეროთ B[9]-ში და ისე დავასორტიროთ და B[9] დავბეჭდოთ B[3][3]-ის სახით
*/

int main() {

    int A[3][3];
    int arraySize = 9;
    int B[9] = {};
    int C[3][3] = {};
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
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = B[i * 3 + j];
            printf("%d ", C[i][j]);
        }
    }

    return 0;
}