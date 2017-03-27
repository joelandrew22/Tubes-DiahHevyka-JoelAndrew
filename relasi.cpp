
#include <iostream>
#include "relasi.h"
#include "mahasiswa.h"
#include "matkul.h"
using namespace std;

void createList_relasi(List_relasi &R)
{
    L.First=NULL;
}

address_relasi alokasiRelasi(relasi x)
{
    addrss_relasi R = new elm_relasi;
    R->info=x;
    R->next= NULL;
    return R;
}

void insertRelasi(List_relasi R, List_mhs L, List_mtkl LC, relasi &r)
{
    string mhs,mtkl;
    address_mhs mhs;
    address_mtkl mtkl;

    printInfo_mhs(L);
    printInfo(LC);

    cout<<"RELASIKAN DATA "<<endl;
    cout<<"NIM Mahasiswa        = ";cin>>nim;
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
        cout<<"KODE MAHASISWA TIDAK ADA!!"<<endl;

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
