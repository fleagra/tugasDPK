#include <stdio.h>

int main() {
    char pola[3][3] = {{'X', 'O', 'X'},{'O', 'X', 'O'},{'X', 'O', 'X'}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", pola[i][j]);
        }
        printf("\n");
    }

    return 0;
}