#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rifheader.h"

address EntryAddress() {
    address newNode = (address)malloc(sizeof(ElmtList));
    if (newNode != NULL) {
        strcpy(newNode->nm, "");
        newNode->q = NULL;
    }
    return newNode;
}

void EntryNamaAwal(Kota daftarKota[], int idx, const char *nama) {
    address newNode = EntryAddress();
    if (newNode != NULL) {
        strcpy(newNode->nm, nama);
        newNode->q = daftarKota[idx].p; // node baru menunjuk ke head lama
        daftarKota[idx].p = newNode;    // node baru jadi head
    }
}

void EntryNamaAkhir(Kota daftarKota[], int idx, const char *nama) {
    address newNode = EntryAddress();
    if (newNode != NULL) {
        strcpy(newNode->nm, nama);
        if (daftarKota[idx].p == NULL) {
            daftarKota[idx].p = newNode;
        } else {
            address temp = daftarKota[idx].p;
            while (temp->q != NULL) {
                temp = temp->q;
            }
            temp->q = newNode;
        }
    }
}

void EntryNamaTengah(Kota daftarKota[], int idx, const char *nama) {
    address newNode = EntryAddress();
    if (newNode == NULL) return;
    strcpy(newNode->nm, nama);

    char referensi[100];
    printf("Masukkan nama setelah siapa nama ini disematkan: ");
    scanf("%s", referensi);

    address current = daftarKota[idx].p;

    while (current != NULL && strcmp(current->nm, referensi) != 0) {
        current = current->q;
    }

    if (current != NULL) {
        newNode->q = current->q;
        current->q = newNode;
    } else {
        printf("Nama yang dimasukkan tidak ditemukan.\n");
    }
}

void DelKt(Kota daftarKota[], int *nKota, const char *namaKota) {
    for (int i = 0; i < *nKota; i++) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            address temp = daftarKota[i].p;
            while (temp != NULL) {
                address del = temp;
                temp = temp->q;
                free(del);
            }

            // Geser array kota
            for (int j = i; j < *nKota - 1; j++) {
                daftarKota[j] = daftarKota[j + 1];
            }
            (*nKota)--;
            break;
        }
    }
}

void PrintNmprtKt(Kota daftarKota[], int nKota) {
    int totalKotaAktif = nKota;  // Kota aktif dihitung berdasarkan jumlah kota yang ada di array
    int totalNamaTerdaftar = 0;

    for (int i = 0; i < nKota; i++) {
        printf("%s:\n", daftarKota[i].kt);
        address temp = daftarKota[i].p;
        while (temp != NULL) {
            printf("  - %s\n", temp->nm);
            totalNamaTerdaftar++;  // Hitung total nama terdaftar
            temp = temp->q;
        }
    }

    printf("\nJumlah Kota Aktif: %d\n", totalKotaAktif);
    printf("Jumlah Nama Terdaftar: %d\n", totalNamaTerdaftar);
}


int CariIdxKota(Kota daftarKota[], int nKota, const char *namaKota) {
    for (int i = 0; i < nKota; i++) {
        if (strcmp(daftarKota[i].kt, namaKota) == 0) {
            return i;
        }
    }
    return -1;
}