#include <stdio.h>
#include "menu.h"

void tampilkanMenu(struct Menu daftar[], int jumlah) {
    printf("\n=== DAFTAR MENU ===\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%d. %s - Rp%d\n", 
            daftar[i].id, 
            daftar[i].nama, 
            daftar[i].harga
        );
    }
}
