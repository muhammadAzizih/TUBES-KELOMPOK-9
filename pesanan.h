#ifndef PESANAN_H
#define PESANAN_H

#include "menu.h"

struct Pesanan {
    char nama[50];
    int totalHarga;
    int meja;
};

void buatPesanan(struct Menu daftar[], int jumlah);
void bookingMeja();
void gameDiskon();

#endif
