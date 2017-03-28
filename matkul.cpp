#include <iostream>
#include "matkul.h"

void createList(List_mtkl &LC){
    LC.First = NULL;
    LC.Last = NULL;
}

address_mtkl alokasi(matakuliah x){
    address_mtkl P;
    P = new elmlist_mtkl;
    P->info.kodematkul = x.kodematkul;
    P->info.namapengajar = x.namapengajar;
    P->info.sks = x.sks;
    P->info.namamatkul = x.namamatkul;
    P->info.ruangan = x.ruangan;
    P->info.jam = x.jam;
    P->next = NULL;
    P->Prev = NULL;
    return P;
}

void dialokasi_mtkl(address_mtkl &P){
    delete P;
}

void insertFirst(List_mtkl &LC, address_mtkl P){
    if (LC.First == NULL){
        LC.First = P;
        LC.Last = P;
    }else{
        P->next = LC.First;
        LC.First->Prev = P;
        LC.First = P;
    }
}

void insertLast(List_mtkl &LC, address_mtkl P){
    if(LC.First == NULL){
        insertFirst(LC, P);
    }else{
        LC.Last->next = P;
        P->Prev = LC.Last;
        LC.Last = P;
    }
}

void insertAfter(List_mtkl &LC, address_mtkl Prec_C, address_mtkl P){
    if(Prec_C == NULL){
        if(Prec_C->next == NULL){
            insertLast(LC, P);
        }else{
            P->next = Prec_C->next;
            P->Prev = Prec_C;
            Prec_C->next->Prev = P;
            Prec_C->next = P;
        }
    }else{
        cout<<"Gagal insert after, Prec NULL"<<endl;
    }
}

void deleteFirst(List_mtkl &LC, address_mtkl &P){
    if(LC.First == NULL){
        cout<<"No data"<<endl;
    }else if(LC.First == LC.Last){
        P = LC.First;
        LC.First = NULL;
        LC.Last = NULL;
    }else{
        P = LC.First;
        LC.First = P->next;
        LC.First->Prev = NULL;
        P->next = NULL;
    }
}

void deleteLast(List_mtkl &LC, address_mtkl &P){
    if(LC.First == NULL){
        cout<<"No data"<<endl;
    }else if( LC.First== LC.Last){
        P = LC.First;
        LC.First = NULL;
        LC.Last = NULL;
    }else{
        P = LC.Last;
        LC.Last = P->Prev;
        LC.Last->next = NULL;
        P->Prev = NULL;
    }
}

void deleteAfter(List_mtkl &LC, address_mtkl Prec_C, address_mtkl &P){
    if(LC.First != NULL){
        if(Prec_C != NULL && Prec_C != LC.Last){
            if(Prec_C->next == LC.Last){
                deleteLast(LC, P);
            }else{
                P = Prec_C->next;
                Prec_C->next = P->next;
                P->next->Prev = Prec_C;
                P->Prev = NULL;
                P->next = NULL;
            }
        }else{
            cout<<"Gagal delete after"<<endl;
        }
    }else{
        cout<<"Gagal delete after, list kosong"<<endl;
    }
}

address_mtkl findElm(List_mtkl &LC, int x){
    address_mtkl P;
    P = LC.First;
    if (LC.First==NULL)
    {
        P=NULL;
    }
    else
    {
        while((P!=NULL)&&(P->info.kodematkul!=x))
        {
            P=P->next;
        }
    }
    return P;
}

void printInfo(List_mtkl LC){
    address_mtkl P;
    P = LC.First;
    if(LC.First ==NULL){
        cout<<"List Kosong";
    }
    else{
        while(P != NULL){
            cout<<"Kode Matakuliah  : "<<info(P).kodematkul<<endl;
            cout<<"Nama Doesen      : "<<info(P).namapengajar<<endl;
            cout<<"Banyak SKS       : "<<info(P).sks<<endl;
            cout<<"Nama Matakuliah  : "<<info(P).namamatkul<<endl;
            cout<<"Ruangan          : "<<info(P).ruangan<<endl;
            cout<<"Jam masuk        : "<<info(P).jam<<endl;
            cout<<endl;
            cout<<endl;
            P = P->next;
        }
        cout<<endl;
    }
}
