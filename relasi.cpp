#include <iostream>
#include "relasi.h"
#include "mahasiswa.h"
#include "matkul.h"
using namespace std;

void createList_relasi

(List_relasi &R)
{
    R.FirstR=NULL;
}

address_relasi alokasiRelasi

(address_mhs P, address_mtkl L)
{
    address_relasi Q = new

elm_relasi;
    Q->child = L;
    Q->parent = P;
    Q->next = NULL;
    return Q;
}
void dealokasi(address_relasi &P)
{
    delete P;
}

void insertFirst(List_relasi &R, address_relasi P)
{
    if (R.FirstR == NULL)
    {
        R.FirstR = P;
        P->next = NULL;
    }
    else
    {

        P->next = R.FirstR;
        R.FirstR = P;
    }
}
void insertLast(List_relasi &R, address_relasi P)
{
    if (R.FirstR == NULL)
    {
        insertFirst(R,P);
    }
    else
    {
        address_relasi Q = R.FirstR;
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
        P->next = NULL;

    }
}

void insertAfter(List_relasi R, address_relasi &Prec,

address_relasi &P)
{
    if(R.FirstR == NULL){
        insertFirst(R,P);
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

address_relasi findElm_R(List_relasi R, address_mhs P, address_mtkl

C)
{
    address_relasi Q = R.FirstR;
    while(Q != NULL)
    {
        if(Q->parent==P && Q->child== C)
        {
            return Q;
        }
        Q = Q->next;
    }
    return NULL;
}

void deletebyrelasi(List_relasi &R, address_relasi &P);
void deleterelasi(List_relasi &R, address_relasi &P);
void printInfo(List_relasi R);
void deleteFirst(List_relasi &R, address_relasi &P);
void deleteLast(List_relasi &R, address_relasi&P);
void deleteAfter(address_relasi Prec, address_relasi &P);
address_relasi searchrelasi(List_relasi R, address_mhs Q,

address_mtkl Z);
address_relasi searchrelasiparent(List_relasi R, address_mhs &P);
address_relasi searchrelasichild(List_relasi R, address_mtkl P);
void sortrelasi(List_relasi &R);
