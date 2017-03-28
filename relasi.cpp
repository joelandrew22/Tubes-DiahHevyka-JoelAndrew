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

void deleterelasi(List_relasi &R, address_relasi &P)
{
    P->child = NULL;
    P->parent = NULL;
    dealokasi(P);
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

void deletebyrelasi(List_relasi &R, address_relasi &P)
{
    address_relasi Q;
    if(R.FirstR != NULL)
    {
        if(P == R.FirstR)
        {
            deleteFirst(R,P);
        }
        else
        {
            Q = R.FirstR;
            while(Q->next != P)
                Q = Q->next;
        }
        if(Q->next == P && P->next == NULL)
        {
            deleteLast(L,P);
        }
        else
        {
            Q->next = P->next;
            P->next = NULL;
        }
    }
    else
    {
        cout<<"List Kosong"<<endl;
    }
}

void printInfo(List_relasi R)
{

}
void deleteFirst(List_relasi &R, address_relasi &P)
{
    if(R.FirstR != NULL)
    {
        if(next->R.FirstR == NULL)
        {
            P = R.FirstR;
            R.FirstR = NULL;
        }
        else
        {
            P = R.FirstR;
            R.FirstR = P->next;
            P->next = NULL;
        }
    }
}
void deleteLast(List_relasi &R, address_relasi&P)
{
    if(R.FirstR != NULL)
    {
        if(next->R.FirstR == NULL)
        {
            deleteFirst(R,P);
        }
        else
        {
            address_relasi Q = R.FirstR;
            while(Q->next->next) != NULL)
            {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
        }
    }
}
void deleteAfter(address_relasi Prec, address_relasi &P)
{
    List_relasi R;
    if(R.FirstR!= NULL)
    {
        if(P->next == NULL)
        {
            deleteLast(R,P);
        }
        else if (P == R.FirstR)
        {
            deleteFirst(R,P);
        }
        else
        {
            Prec->next = P->next;
            P->next = NULL;
        }

    }
    else
    {
        cout<<"List Kosong"<<endl;
    }
}
address_relasi searchrelasi(List_relasi R, address_mhs Q,address_mtkl Z)
{
    if(R.FirstR != NULL)
    {
        address_relasi P = R.FirstR;
        while (P->next != NULL)
        {
            if(P->parent != Q && P->child != Z)
            {
                P = P->next;
            }
        }
        if(P->child == Z && P->parent == Q)
        {
            return P;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
        cout<<"List Kosong"<<endl;
    }
}
address_relasi searchrelasiparent(List_relasi R, address_mhs &P)
{
    if(R.FirstR != NULL)
    {
        address_relasi PR = R.FirstR;
        while(PR->next != NULL && PR->parent != P)
        {
            PR = PR->next;
        }
        if (PR->parent == P)
        {
            return PR;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        cout<<"List Kosong"<<endl;
        return NULL;
    }
}
address_relasi searchrelasichild(List_relasi R, address_mtkl P)
{
    if(R.FirstR != NULL)
    {
        address_relasi PR = R.FirstR;
        while(PR->next != NULL && PR->child != P)
        {
            PR = PR->next;
        }
        if (PR->child == P)
        {
            return PR;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}
void sortrelasi(List_relasi &R)
{
    address_relasi P,P1,P2;
    if(R.FirstR != NULL)
    {
        P = R.FirstR;
        while (P->next != NULL)
        {
            if(P->info->parent.id > P->info->next->parent.id)
            {
                P2 = R.FirstR;
                while(P2->next != P){
                    P2 = P2->next;
                }
                deleteAfter(P2,P);
                insertAfter(L,P->next,P);
            }
            P = P->next;
        }
    }
    else
    {
        cout<<"List Relasi Kosong"<<endl;
    }
}
