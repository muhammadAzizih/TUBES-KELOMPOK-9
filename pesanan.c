#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "pesanan.h"

/// ----------------------------------------
/// Fungsi pengganti strcasestr untuk Windows
/// ----------------------------------------
char *my_strcasestr(const char *haystack, const char *needle) {
    if (!haystack || !needle) return NULL;

    size_t len_h = strlen(haystack);
    size_t len_n = strlen(needle);

    for (size_t i = 0; i <= len_h - len_n; i++) {
        int cocok = 1;
        for (size_t j = 0; j < len_n; j++) {
            if (tolower(haystack[i+j]) != tolower(needle[j])) {
                cocok = 0;
                break;
            }
        }
        if (cocok) return (char*)&haystack[i];
    }
    return NULL;
}

/// ---------------------------------------------------
/// FITUR UTAMA PEMESANAN
/// ---------------------------------------------------
void buatPesanan(struct Menu daftar[], int jumlah) {
    char input[50];
    struct Pesanan p;
    p.totalHarga = 0;

    printf("\nMasukkan nama Anda: ");
    scanf(" %[^\n]", p.nama);

    tampilkanMenu(daftar, jumlah);

    while (1) {
        printf("\nMasukkan nama menu (ketik 'selesai' untuk selesai): ");
        scanf(" %[^\n]", input);

        if (my_strcasestr(input, "selesai"))
            break;

        int ditemukan = 0;
        for (int i = 0; i < jumlah; i++) {
            if (my_strcasestr(daftar[i].nama, input)) {
                p.totalHarga += daftar[i].harga;
                printf("Ditambahkan: %s - Rp%d\n", daftar[i].nama, daftar[i].harga);
                ditemukan = 1;
                break;
            }
        }

        if (!ditemukan)
            printf("Menu tidak ditemukan!\n");
    }

    printf("\nTotal harga pesanan: Rp%d\n", p.totalHarga);
}

/// ---------------------------------------------------
/// FITUR BOOKING MEJA
/// ---------------------------------------------------
void bookingMeja() {
    char nama[50];
    int meja;

    printf("\n=== BOOKING MEJA ===\n");
    printf("Nama pemesan: ");
    scanf(" %[^\n]", nama);

    printf("Nomor meja (1-20): ");
    scanf("%d", &meja);

    printf("Meja %d berhasil dipesan atas nama %s!\n", meja, nama);
}

/// ---------------------------------------------------
/// GAME DISKON RANDOM
/// ---------------------------------------------------
void gameDiskon() {
    srand(time(NULL));

    int angka = rand() % 10 + 1;
    int tebakan;

    printf("\n=== GAME DISKON ===\n");
    printf("Tebak angka 1-10 untuk dapat diskon!\n");

    printf("Masukkan tebakan: ");
    scanf("%d", &tebakan);

    if (tebakan == angka) {
        printf("SELAMAT! Anda mendapat diskon 50%%!\n");
    } else {
        printf("Salah! Angka benar: %d. Coba lagi lain waktu.\n", angka);
    }
}
