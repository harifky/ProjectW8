#ifndef RIFHEADER_H
#define RIFHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KOTA 10
#define MAX_STRING 100

typedef char infotype[MAX_STRING];

typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype nm;     // Nama orang
    address q;       // Next node
} ElmtList;

typedef struct {
    infotype kt;     // Nama kota
    address p;       // Head of linked list
} Kota;

address EntryAddress();
void EntryNamaAwal(Kota daftarKota[], int idx, const char *nama);
void EntryNamaAkhir(Kota daftarKota[], int idx, const char *nama);
void EntryNamaTengah(Kota daftarKota[], int idx, const char *nama);
void DelKt(Kota daftarKota[], int *nKota, const char *namaKota);
void PrintNmprtKt(Kota daftarKota[], int nKota);
int CariIdxKota(Kota daftarKota[], int nKota, const char *namaKota);

#endif