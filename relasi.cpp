
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

void insertRelasi(address_mhs P, address_relasi L)
{
    string mhs,mtkl;
    address_mhs mhs;
    address_mtkl mtkl;

    printInfo_mhs(L);
    printInfo(LC);

    cout<<"RELASIKAN DATA "<<endl;
    cout<<"NIM Mahasiswa        = ";cin>>nip;
    cout<<"direlasikan dengan......"<<endl;
    mhs = findElm_mhs(L,nim);
    if(mhs!=NULL) {
        cout<<"Kode Matakuliah  = ";cin>>kode;
        mtkl = findElm(LC,kode);
        if(mtkl!=NULL) {
            relasi.mhs = mhs;
            relasi.mtkl = mtkl;
            cout<<"DATA TERSIMPAN!!!"<<endl;
        }
        else {
            cout<<"KODE MATAKULIAH TIDAK ADA!!"<<endl;
        }

    }
    else {
        cout<<"KODE MATAKULIAH TIDAK ADA!!"<<endl;

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
