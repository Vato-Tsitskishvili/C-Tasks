#include <stdio.h>

int main() {

    int grades[4][5] = {
        {99, 43, 51, 22, 11},
        {55, 34, 56, 45, 3},
        {2, 3, 56, 7, 4},
        {4, 76, 45, 96, 100}
    };

    for (int i = 1; i < 5; i++) {
        printf("student %d: ", i);
        for (int j = 0; j < 5; j++) {
            printf("%d ", grades[i - 1][j]);
        }
        printf("\n");
    }

    return 0;
}