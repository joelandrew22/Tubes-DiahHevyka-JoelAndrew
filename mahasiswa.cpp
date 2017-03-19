#include <iostream>
#include "mahasiswa.h"
using namespace std;

void createList_mhs(List_mhs &L)
{
    L.First=NULL;
}
address alokasi_mhs(mahasiswa x)
{
    address P;
    P = new elmlist_mhs;
    P->info = x;
    P->next = NULL;

}
void dealokasi_mhs(address &P)
{
    delete P;
}
void insertFirst_mhs(List_mhs &L, address P)
{
    if(L.First == NULL){
        L.First = P;
    }else{
        P->next = L.First;
        L.First = P;
    }
}
void insertLast_mhs(List_mhs &L, address P)
{
    if(L.First == NULL){
        L.First = P;
    }else{
        address q = L.First;
        while(q->next != NULL){
            q=q->next;
        }
        q->next = P;
    }
}
address findElm_mhs(List_mhs L, mahasiswa x)
{
    address P;
    if(L.First == NULL){
        P = NULL;
    }else{
        P = L.First;
        while((P != NULL)  && P->info.nama != x.nama){
            P=P->next;
        }
    }
    return P;
}
void deleteFirst_mhs(List_mhs &L, address &P)
{
    if(L.First == NULL){
        cout<<"List kososng"<<endl;
    }else{
        P = L.First;
        L.First = P->next;
        P->next = NULL;

    }
}
void deleteLast_mhs(List_mhs &L, address &P)
{
    if(L.First == NULL){
        cout<<"List kosong"<<endl;
    }else{
        P=L.First;
        if(P->next == NULL){
            L.First = NULL;

        }else{
            address q=P;
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
    if(L.First==NULL){
        cout << "List kosong" <<endl;
    }else{
        address P = L.First;
        while(P!=NULL){
            cout << P->info.nim <<endl;
            cout << P->info.nama <<endl;
            cout << P->info.JK <<endl;
            cout << P->info.jurusan <<endl;
            cout << P->info.kelas <<endl;
            cout << P->info.alamat <<endl;
            P=P->next;
        }
        cout << endl;
    }
}
void insertAfter_mhs(address Prec, address P)
{
    P->next = Prec->next;
    Prec->next = P;
}
void deleteAfter_mhs(address Prec, address &P)
{
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}
