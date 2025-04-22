#include <stdio.h>
#include <string.h>

#include "rifheader.h"

int main() {
    Kota daftarKota[MAX_KOTA] = {
        {"Bandung", NULL},
        {"Jakarta", NULL},
        {"Surabaya", NULL},
        {"Medan", NULL},
        {"Yogyakarta", NULL},
        {"Denpasar", NULL},
        {"Padang", NULL},
        {"Aceh", NULL},
        {"Semarang", NULL},
        {"Makasar", NULL}
    };

    int nKota = MAX_KOTA;

    int pilihan;
    char nama[MAX_STRING];
    char namaKota[MAX_STRING];

    do {
        printf("\n=====================================\n");
        printf("Daftar Kota dan Nama:\n");
        PrintNmprtKt(daftarKota, nKota);
        printf("=====================================\n");

        printf("\nMenu:\n");
        printf("1. Entry nama ke kota\n");
        printf("2. Hapus kota beserta datanya\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // Clear newline

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, MAX_STRING, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;

                // Pengecekan apakah kota ada dalam daftar
                int idx = -1;
                while (idx == -1) {
                    idx = CariIdxKota(daftarKota, nKota, namaKota);
                    if (idx == -1) {
                        printf("Kota tidak ditemukan. Masukkan nama kota yang valid: ");
                        fgets(namaKota, MAX_STRING, stdin);
                        namaKota[strcspn(namaKota, "\n")] = 0;
                    }
                }

                printf("Masukkan nama: ");
                fgets(nama, MAX_STRING, stdin);
                nama[strcspn(nama, "\n")] = 0;

                // Pengecekan nama tidak boleh kosong
                while (strlen(nama) == 0) {
                    printf("Nama tidak boleh kosong. Masukkan nama: ");
                    fgets(nama, MAX_STRING, stdin);
                    nama[strcspn(nama, "\n")] = 0;
                }

                printf("Pilih posisi nama:\n");
                printf("1. Awal\n");
                printf("2. Tengah\n");
                printf("3. Akhir\n");
                printf("Pilihan: ");
                int pos;
                scanf("%d", &pos);
                getchar(); // Clear newline

                if (pos == 1) {
                    EntryNamaAwal(daftarKota, idx, nama);
                } else if (pos == 2) {
                    EntryNamaTengah(daftarKota, idx, nama);
                } else if (pos == 3) {
                    EntryNamaAkhir(daftarKota, idx, nama);
                } else {
                    printf("Pilihan posisi tidak valid. Nama tidak dimasukkan.\n");
                }
                break;

            case 2:
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(namaKota, MAX_STRING, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;

                DelKt(daftarKota, &nKota, namaKota);
                break;

            case 0:
                printf("Terima kasih!\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 0);

    return 0;
}
