#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "matkul.h"
#include "mahasiswa.h"

using namespace std;
typedef struct elm_relasi *address_relasi;
struct List_relasi{
    address_relasi First;
};
//struct infotype_relasi{
//    address_mhs nim;
//    string nama;
//    address_mtkl kode_mtkl;
//    string nama_mtkl;
//};

struct elm_relasi{
    address_mhs mhs;
    address_mtkl mtkl;
    address_relasi next;
};

void insertFirstRelasi(List_relasi R, List_mhs L, List_mtkl LC, relasi &r);
address_relasi alokasiRelasi(address_mhs mhs, address_mtkl mtkl);
address_relasi findElmRelasi(address_mhs L, int x);
void printInfoRelasi(List_mhs P, List_mtkl L);
void deleteRelasi(address_mhs P, address_mtkl L);

#endif // RELASI_H_INCLUDED
