#include <stdio.h>
#include "menu.h"
#include "pesanan.h"

int main() {
    struct Menu daftarMenu[5] = {
        {1, "Nasi Goreng", 20000},
        {2, "Mie Ayam", 15000},
        {3, "Ayam Geprek", 18000},
        {4, "Es Teh Manis", 5000},
        {5, "Jus Alpukat", 10000}
    };

    int pilih;

    while (1) {
        printf("\n=== RESTORAN SYSTEM ===\n");
        printf("1. Buat Pesanan\n");
        printf("2. Booking Meja\n");
        printf("3. Game Diskon\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: buatPesanan(daftarMenu, 5); break;
            case 2: bookingMeja(); break;
            case 3: gameDiskon(); break;
            case 4: printf("Terima kasih!\n"); return 0;
            default: printf("Pilihan tidak valid!\n");
        }
    }
}
