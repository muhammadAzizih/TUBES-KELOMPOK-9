#ifndef MENU_H
#define MENU_H

struct Menu {
    int id;
    char nama[50];
    int harga;
};

void tampilkanMenu(struct Menu daftar[], int jumlah);

#endif
