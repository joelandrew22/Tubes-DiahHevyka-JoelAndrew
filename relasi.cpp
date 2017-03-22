#include <iostream>
#include "relasi.h"
#include "mahasiswa.h"
#include "matkul.h"
using namespace std;

address_relasi alokasiRelasi(address_mhs mhs, address_mtkl mtkl)
{
    addrss_relasi R = new elm_relasi;
    info(R).mhs = mhs;
    info(R).mtkl = mtkl;
    next(R) = NULL;
    return R;
}

void dealokasiRelasi(adddress_relasi &P)
{
    delete P;
}

void insertFirstRelasi(address_mhs P, address_relasi L)
{
    if(L.First == NULL){
        L.First = P;
    }else{
        P->next = L.First;
        L.First = P;
    }
}

address_relasi findElmRelasi(address_mhs P, address_mtkl L)
{

}

void printInfoRelasi(List_mhs P, List_mtkl L)
{

}

void deleteRelasi(address_mhs P, address_mtkl L)
{

}
