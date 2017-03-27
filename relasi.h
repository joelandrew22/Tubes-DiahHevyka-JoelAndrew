#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "matkul.h"
#include "mahasiswa.h"

using namespace std;
typedef struct elm_relasi *address_relasi;
struct List_relasi{
    address_relasi FirstR;
};

struct elm_relasi{
    relasi infoR;
    address_relasi nextR;
};

void createList_relasi(List_relasi &R);
void isiRelasi(List_relasi R, List_mhs L, List_mtkl LC, relasi &r);
address_relasi alokasiRelasi(address_mhs mhs, address_mtkl mtkl);
address_relasi findElmRelasi(address_relasi R, address_mhs mhs, address_mtkl mtkl);
void insertFirst_relasi(List_relasi &R, address_relasi P);
void insertLast_relasi(List_relasi &R, address_relasi P);
void insertAfter_relasi(List_relasi &R, address_relasi prec, address_relasi P);
void printInfoRelasi(List_relasi R, address_mhs mhs, address_mtkl mtkl);
//void deleteRelasi(address_mhs P, address_mtkl L);

#endif // RELASI_H_INCLUDED
