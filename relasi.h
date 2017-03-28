#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "matkul.h"
#include "mahasiswa.h"

using namespace std;
typedef struct elm_relasi *address_relasi;
struct relasi{
    int mhs;
    int mtkl;
};
struct List_relasi{
    address_relasi FirstR;
};

struct elm_relasi{
    address_relasi next;
    address_mhs parent;
    address_mtkl child;
};

void deletebyrelasi(List_relasi &R, address_relasi &P);
void deleterelasi(List_relasi &R, address_relasi &P);
address_relasi alokasiRelasi(address_mhs P, address_mtkl C);
address_relasi findElm_R(List_relasi R, address_mhs P, address_mtkl C);
void dealokasi(address_relasi &P);
void printInfo(List_relasi R);
void createList(List_relasi &R);
void insertFirst(List_relasi &R, address_relasi P);
void insertLast(List_relasi &R, address_relasi P);
void insertAfter(List_relasi R, address_relasi &Prec, address_relasi &P);
void deleteFirst(List_relasi &R, address_relasi &P);
void deleteLast(List_relasi &R, address_relasi&P);
void deleteAfter(address_relasi Prec, address_relasi &P);
address_relasi searchrelasi(List_relasi R, address_mhs Q, address_mtkl Z);
address_relasi searchrelasiparent(List_relasi R, address_mhs &P);
address_relasi searchrelasichild(List_relasi R, address_mtkl P);
void sortrelasi(List_relasi &R);

#endif // RELASI_H_INCLUDED
