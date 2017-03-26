#include <iostream>
#include "mahasiswa.h"
using namespace std;

void createList_mhs(List_mhs &L)
{
    L.First=NULL;
}
address_mhs alokasi_mhs(mahasiswa x)
{
    address_mhs P;
    P = new elmlist_mhs;
    P->info.nim = x.nim;
    P->info.nama = x.nama;
    P->info.alamat = x.alamat;
    P->info.JK = x.JK;
    P->info.jurusan = x.jurusan;
    P->info.kelas_mhs = x.kelas_mhs;
    P->next = NULL;

}
void dealokasi_mhs(address_mhs &P)
{
    delete P;
}
void insertFirst_mhs(List_mhs &L, address_mhs P)
{
        L.First = P;
        P->next = NULL;
}
void insertLast_mhs(List_mhs &L, address_mhs P)
{
    if(L.First == NULL){
        L.First = P;
    }else{
        address_mhs q = L.First;
        while(q->next != NULL){
            q=q->next;
        }
        q->next = P;
    }
}
address_mhs findElm_mhs(List_mhs L, mahasiswa x)
{
    address_mhs P;
    if(L.First == NULL){
        P = NULL;
    }else{
        P = L.First;
        while((P != NULL)  && P->info.nim != x.nim){
            P=P->next;
        }
    }
    return P;
}
void deleteFirst_mhs(List_mhs &L, address_mhs &P)
{
    if(L.First == NULL){
        cout<<"List kososng"<<endl;
    }else{
        P = L.First;
        L.First = P->next;
        P->next = NULL;

    }
}
void deleteLast_mhs(List_mhs &L, address_mhs &P)
{
    if(L.First == NULL){
        cout<<"List kosong"<<endl;
    }else{
        P=L.First;
        if(P->next == NULL){
            L.First = NULL;

        }else{
            address_mhs q=P;
            while(q->next->next != NULL){
                q=q->next;
            }
            P = q->next;
            q->next = NULL;

        }
    }
}
void printInfo_mhs(List_mhs L)
{
    address_mhs P;
    P = L.First;
    if(L.First==NULL){
        cout << "List kosong" <<endl;
    }else{
        while(P != NULL){
            cout << P->info.nim <<endl;
            cout << P->info.nama <<endl;
            cout << P->info.JK <<endl;
            cout << P->info.jurusan <<endl;
            cout << P->info.kelas_mhs <<endl;
            cout << P->info.alamat <<endl;
            P = P->next;
        }
        cout << endl;
    }
}
void insertAfter_mhs(address_mhs Prec, address_mhs P)
{
    P->next = Prec->next;
    Prec->next = P;
}
void deleteAfter_mhs(address_mhs Prec, address_mhs &P)
{
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}
