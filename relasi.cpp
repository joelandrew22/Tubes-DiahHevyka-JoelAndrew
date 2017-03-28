#include <iostream>
#include "relasi.h"
#include "mahasiswa.h"
#include "matkul.h"
using namespace std;

void createList_relasi(List_relasi &R)
{
    R.FirstR=NULL;
}

address_relasi alokasiRelasi(address_mhs P, address_mtkl L)
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

void printInfo_R(List_relasi R){
    if(R.FirstR==NULL){
        cout << "List kosong" <<endl;
    }else{
        address_relasi P = R.FirstR;
        while(P!=NULL){
            cout << "NIM Mahasiswa      : "<<P->parent->info.nim <<endl;
            cout<<"Nama Mahasiswa       : "<<P->parent->info.nama<<endl;
            cout << "Kode Matakuliah    : "<<P->child->info.kodematkul <<endl;
            cout<<"Nama Matakuliah      : "<<P->child->info.namamatkul<<endl;
            cout<<endl;
            cout<<endl;
            P=P->next;
        }
        cout << endl;
    }
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

            if(Q->next == P && P->next == NULL)
            {
                deleteLast(R,P);
            }
            else
            {
                Q->next = P->next;
                P->next = NULL;
                deleterelasi(R,P);
            }
        }
        
    }
    else
    {
        cout<<"List Kosong"<<endl;
    }
}

void deleteFirst(List_relasi &R, address_relasi &P)
{
    if(R.FirstR != NULL)
    {
        if(R.FirstR->next == NULL)
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
        deleterelasi(R,P);
    }
}
void deleteLast(List_relasi &R, address_relasi&P)
{
    if(R.FirstR != NULL)
    {
        if(R.FirstR->next == NULL)
        {
            deleteFirst(R,P);
        }
        else
        {
            address_relasi Q = R.FirstR;
            while((Q->next)->next != NULL)
            {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
        }
        deleterelasi(R,P);
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

address_relasi findMinimum(List_relasi &R){
    address_relasi P = NULL;
    if(R.FirstR==NULL){
        cout<<"List Kosong"<<endl;
    }else{
        P = R.FirstR;
        address_relasi min = P;
        while(P->next != NULL ){
            P = P->next;
            if(P->parent->info.nim < min->parent->info.nim){
                  min = P;
            }                
        }
        P = min;
    }
    return P;
}

void sortrelasi(List_relasi &R)
{
    address_relasi P,A;
    address_mhs Q;
    address_mtkl Z;
    List_relasi C;
    createList_relasi(C);
    while(R.FirstR != NULL){
        P = findMinimum(R);
        Q = P->parent;
        Z = P->child;
        deletebyrelasi(R,P);
        A = alokasiRelasi(Q,Z);
        insertLast(C,A);
    }
    R=C;
}