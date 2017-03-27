
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

void isiRelasi(List_relasi R, List_mhs L, List_mtkl LC, relasi &r)
{
    string mhs,mtkl;
    address_mhs mhs;
    address_mtkl mtkl;

    printInfo_mhs(L);
    cout<<endl;
    cout<<endl;
    printInfo(LC);

    cout<<"RELASIKAN DATA "<<endl;
    cout<<"NIM Mahasiswa    = ";cin>>nim;
    cout<<"direlasikan dengan...."<<endl;
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

void insertFirst_relasi(List_relasi &R, address_relasi P)
{
    if(L.FirstR==NULL){
        L.FirstR = P;
    }
    else {
        nextR = L.FirstR;
        L.FirstR = P;
    }
}
void insertLast_relasi(List_relasi &R, address_relasi P)
{
    if(L.FirstR==NULL){
        insertFirst_relasi(L,P);
    }else{
        address_relasi Q = L.FirstR;
        while(Q->nextR!=NULL){
            Q = Q->nextR;
        }
        Q->nextR = P;
    }
}

void insertAfter_relasi(List_relasi &R, address_relasi prec, address_relasi P)
{
    if(L.FirstR!=NULL)
    {
        P->nextR = prec->nextR;
        prec->nextR = P;
    }else{
        insertFirst_relasi(R,P);
    }
}

address_relasi findElmRelasi(address_relasi R, address_mhs mhs, address_mtkl mtkl)
{

}

void printInfoRelasi(List_relasi R, address_mhs mhs, address_mtkl mtkl)
{

}

void deleteRelasi(address_mhs P, address_mtkl L)
{

}
