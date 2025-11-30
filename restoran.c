#include <stdio.h>
#include <stdlib.h>
#include "pesanMakanan.h"
#include "booking.h"
#include "pembayaran.h"
#include "riwayat.h"
#include "batalPesanan.h"


int totalPesanan = 0;
int totalBooking = 0;
int panjar = 0;

int main()
{
    int pilih;

    do
    {

        printf("=====================================\n");
        printf("welcome to RESTORAN 9Nine\n");
        printf("Alamat : JL.merdeka simpang3 usu\n");
        printf("=====================================\n");

        printf("1. Pesan Makanan\n");
        printf ("2. Batal Pesanan\n");
        printf("3. Booking Meja\n");
        printf("4. Pembayaran\n");
        printf("5. Lihat Riwayat\n");
        printf("6. Hapus Riwayat\n");
        printf("7. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);
        
        switch (pilih)
        {
        case 1:
           totalPesanan += pesanMakanan();
            break;
        case  2:
            batalPesanan(&totalPesanan);
            break;
        case 3:
            totalBooking = bookingMeja();
            break;
        case 4:
            pembayaran(totalPesanan,totalBooking,panjar);
            break;
        case 5:
            lihatRiwayat();
            break;
        case 6:
            hapusRiwayat(&totalPesanan, &totalBooking, &panjar);
            break;
        case 7:
            printf("==================================\n");
            printf("Terima kasih sudah berkunjung!\n");
            printf("==================================\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (pilih != 7);

    return 0;
}
