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
        if(L.First == NULL){L.First = P;
        P->next = NULL;
        }else{
            P->next = L.First;
            L.First = P;
        }
}
void insertLast_mhs(List_mhs &L, address_mhs P)
{
    if(L.First == NULL){
        insertFirst_mhs(L,P);
    }else{
        address_mhs Q = L.First;
        while(Q->next != NULL){
            Q=Q->next;
        }
        Q->next = P;
        P->next = NULL;
    }
}
address_mhs findElm_mhs(List_mhs L, int x)
{
    address_mhs Q;
    if(L.First == NULL){
        Q = NULL;
    }else{
        Q = L.First;
        while((Q != NULL)  && Q->info.nim != x){
            Q=Q->next;
        }
    }
    return Q;
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
    if(L.First==NULL){
        cout << "List kosong" <<endl;
    }else{
        address_mhs P = L.First;
        while(P!=NULL){
            cout << "NIM Mahasiswa     :"<<P->info.nim <<endl;
            cout << "Nama Mahasiswa    :"<<P->info.nama <<endl;
            cout << "Jenis Kelamin     :"<<P->info.JK <<endl;
            cout << "Jurusan Mahasiswa :"<<P->info.jurusan <<endl;
            cout << "Kelas Mahasiswa   :"<<P->info.kelas_mhs <<endl;
            cout << "Alamat Mahasiswa  :"<<P->info.alamat <<endl;
            P=P->next;
        }
        cout << endl;
    }
}
void insertAfter_mhs(List_mhs &L,address_mhs Q, address_mhs P)
{
    P->next = Q->next;
    Q->next = P;
}
void deleteAfter_mhs(address_mhs Prec, address_mhs &P)
{
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}
