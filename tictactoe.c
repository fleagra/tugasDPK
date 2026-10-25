#include <stdio.h>

char kotak[9];

void printKotak(void) {
    printf("\n %c | %c | %c \n---+---+---\n %c | %c | %c \n---+---+---\n %c | %c | %c \n\n",
           kotak[0], kotak[1], kotak[2],
           kotak[3], kotak[4], kotak[5],
           kotak[6], kotak[7], kotak[8]);
}

// kondisi menang
int telahMenang(void) {
    int garis[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // baris
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // kolom
        {0, 4, 8}, {2, 4, 6}              // diagonal
    };
    for (int i = 0; i < 8; i++) {
        if (kotak[garis[i][0]] == kotak[garis[i][1]] &&
            kotak[garis[i][1]] == kotak[garis[i][2]])
            return 1;
    }
    return 0;
}

int main(void) {
    char ulang = 'y';

    while (ulang == 'y' || ulang == 'Y') {
        for (int i = 0; i < 9; i++) kotak[i] = '1' + i;

        int giliran = 0, menang = 0;
        while (giliran < 9) {
            printKotak();
            char pemain = (giliran % 2 == 0) ? 'X' : 'O';
            int gerak;

            printf("Pemain %c, pilih kotak (1-9): ", pemain);
            if (scanf("%d", &gerak) != 1 || gerak < 1 || gerak > 9 || kotak[gerak - 1] > '9') {
                while (getchar() != '\n'); 
                printf("Gerakan invalid, coba lagi.\n");
                continue;
            }

            kotak[gerak - 1] = pemain;
            giliran++;

            if (telahMenang()) {
                printKotak();
                printf("Pemain %c menang!\n", pemain);
                menang = 1;
                break;
            }
        }

        if (!menang) {
            printKotak();
            printf("Hasilnya seri!\n");
        }

        printf("Main lagi? (y/n): ");
        scanf(" %c", &ulang);
    }

    printf("Terima kasih telah bermain!\n");
    return 0;
}