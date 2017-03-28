#include <iostream>
#include "matkul.h"
#include"mahasiswa.h"
#include "relasi.h"

using namespace std;

void menu( List_relasi &R, List_mtkl &LC, List_mhs &L){
    cout<<"PILIHAN MENU : "<<endl;
    cout<<"1.Masukan data mahasiswa"<<endl;
    cout<<"2.Masukan data matakuliah"<<endl;
    cout<<"3.Tampilkan data mahasiswa"<<endl;
    cout<<"4.Tampilkan data matakuliah"<<endl;
    cout<<"5.Mencari data mahasiswa"<<endl;
    cout<<"6.Mencari data matakuliah"<<endl;
    cout<<"7.Gabungkan data mahasiswa dan matakuliah "<<endl;
    cout<<"8.Tampilkan data hasil penggabungan"<<endl;
    cout<<"9.Mencari data yang di gabungkan"<<endl;
    cout<<"10.Hapus data yang di gabungkan"<<endl;
    cout<<"11.Hapus data mahasiswa"<<endl;
    cout<<"12.Hapus data matakuliah"<<endl;
    cout<<"13.Sorting Relasi Penggabungan"<<endl;
    cout<<"0.Menu utama"<<endl;
    int pil;
    cout<<endl;
    cout<<"Masukan Pilihan : ";
    cin>>pil;
    cout<<endl;
    cout<<endl;
    mahasiswa Mahasiswa;
    int men,x,xx;
    address_mtkl PC = NULL;
    address_mtkl cariMtkl;
    matakuliah XC;
    address_mhs PP = NULL;
    address_mhs carimhs;
    mahasiswa XP;
    address_relasi PR = NULL;
    address_mtkl caric;
    address_mhs carip;
    if(pil==1){
        cout<<"Masukan NIM MAhasiswa    : ";
        cin>>Mahasiswa.nim;
        cout<<"Masukan Nama Mahasiswa   : ";
        cin>>Mahasiswa.nama;
        cout<<"Alamat Mahasiswa         : ";
        cin>>Mahasiswa.alamat;
        cout<<"Jenis Kelamin            : ";
        cin>>Mahasiswa.JK;
        cout<<"Jurusan                  : ";
        cin>>Mahasiswa.jurusan;
        cout<<"Kelas                    : ";
        cin>>Mahasiswa.kelas_mhs;
        address_mhs P;
        address_mhs Q;
         if(L.First == NULL){
             P =  alokasi_mhs(Mahasiswa);
                insertFirst_mhs(L,P);
            }
            else{
            Q=L.First;
            while(Q!=NULL && (Q->info.nim != Mahasiswa.nim))
            {
                Q=Q->next;
            }
            if (Q!=NULL)
            {
                cout<<endl;
                cout<<"NIM sudah digunakan";
            }
            else
            {
        P =  alokasi_mhs(Mahasiswa);
        address_mhs Q;
            if(L.First == NULL){
                insertFirst_mhs(L,P);
            }
            else if(P->info.nim < L.First->info.nim ){
                insertFirst_mhs(L,P);
            }else{
                Q = L.First;
                while( Q->next != NULL && (Q->next)->info.nim < P->info.nim){
                    Q = Q->next;
                }
                if(Q->next != NULL){
                    insertAfter_mhs(L,Q,P);
                }else{
                    insertLast_mhs(L,P);
                }
            }
        }
      } 
      cout<<endl;
            cout<<"Ketik '0': ";
            cin>>men;
            if(men==0){
            menu(R,LC,L);
            }    
    }
            
    else if(pil==2){
            address_mtkl Q;
            matakuliah Matakuliah;
            cout<<"Masukan Kode Matakuliah  : ";
            cin>>Matakuliah.kodematkul;
            cout<<"Masukan Nama Dosen       : ";
            cin>>Matakuliah.namapengajar;
            cout<<"Banyak SKS               : ";
            cin>>Matakuliah.sks;
            cout<<"Masukan Nama Matakuliah  : ";
            cin>>Matakuliah.namamatkul;
            cout<<"Masukan ruangan          : ";
            cin>>Matakuliah.ruangan;
            cout<<"Masukan Jam              : ";
            cin>>Matakuliah.jam;
            address_mtkl P;
            if(LC.First == NULL){
                P = alokasi(Matakuliah);
                    insertFirst(LC,P);
                }
            else{
            Q=LC.First;
            while(Q!=NULL && (Q->info.kodematkul != Matakuliah.kodematkul))
            {
                Q=Q->next;
            }
            if (Q!=NULL)
            {
                cout<<endl;
                cout<<"Kode Matakuliah sudah digunakan";
            }
            else
            {
                P = alokasi(Matakuliah);
            
            address_mtkl Q;
                if(LC.First == NULL){
                    insertFirst(LC,P);
                }
                else if(P->info.kodematkul < LC.First->info.kodematkul ){
                    insertFirst(LC,P);
                }else{
                    Q = LC.First;
                    while( Q->next != NULL && (Q->next)->info.kodematkul < P->info.kodematkul){
                        Q = Q->next;
                }
                if(Q->next != NULL){
                    P->next = Q->next;
                    P->Prev = Q;
                    (Q->next)->Prev = P;
                    Q->next = P;
                }else{
                    insertLast(LC,P);
                }
            }
        }  
            
    }
    cout<<endl;
    cout<<"Ketik '0': ";
    cin>>men;
    if(men==0){
        menu(R,LC,L);
    }
}

    else if(pil==3){
        printInfo_mhs(L);
            cout<<endl;
            cout<<"Ketik '0': ";
            int men;
            cin>>men;
            if(men==0){
                menu(R,LC,L);
            }
    }
    else if(pil==4){
        printInfo(LC);
            cout<<endl;
            cout<<"Ketik '0': ";
            int men;
            cin>>men;
            if(men==0){
                menu(R,LC,L);
            }
    }
    else if(pil==5){
        cout<<"Masukan NIM Mahasiswa : ";
        cin>>x;
        address_mhs P;
    if(L.First == NULL){
        P = NULL;
    }else if(L.First != NULL){
        P = L.First;
        while((P != NULL)  && P->info.nim != x){
            P=P->next;
        }
        if(P!=NULL){
        cout<<"Data di temukan : "<<endl;
        cout << "NIM Mahasiswa     :"<<P->info.nim <<endl;
        cout << "Nama Mahasiswa    :"<<P->info.nama <<endl;
        cout << "Jenis Kelamin     :"<<P->info.JK <<endl;
        cout << "Jurusan Mahasiswa :"<<P->info.jurusan <<endl;
        cout << "Kelas Mahasiswa   :"<<P->info.kelas_mhs <<endl;
        cout << "Alamat Mahasiswa  :"<<P->info.alamat <<endl;
        }else{
            cout<<endl;
            cout<<"Data tidak ditemuka";
        }
    }
    cout<<endl;
    cout<<"Ketik '0': ";
    int men;
    cin>>men;
    if(men==0){
        menu(R,LC,L);
    }
}
    else if(pil==6){
        cout<<"Masukan Kode Matakuliah : ";
        cin>>x;
        address_mtkl P;
    if(LC.First == NULL){
        P = NULL;
    }else if(LC.First != NULL){
        P = LC.First;
        while((P != NULL)  && P->info.kodematkul != x){
            P=P->next;
        }
        if(P!=NULL){
        cout<<"Data di temukan  : "<<endl;
        cout<<"Kode Matakuliah  : "<<info(P).kodematkul<<endl;
        cout<<"Nama Doesen      : "<<info(P).namapengajar<<endl;
        cout<<"Banyak SKS       : "<<info(P).sks<<endl;
        cout<<"Nama Matakuliah  : "<<info(P).namamatkul<<endl;
        cout<<"Ruangan          : "<<info(P).ruangan<<endl;
        cout<<"Jam masuk        : "<<info(P).jam<<endl;
    }else {
        cout<<endl;
        cout<<"Data tidak ditemukan";
    }
    }
    cout<<endl;
    cout<<"Ketik '0': ";
    int men;
    cin>>men;
    if(men==0){
        menu(R,LC,L);
    }
    }
    else if(pil==7){
            cout<<"Merelasikan MAhasiswa dengan MAtakuliah yang di ambil"<<endl;
            cout<<"Masukkan NIM             : ";
            cin>>xx;
            cout<<"Masukkan Kode Matkul     :";
            cin>>x;
            
            address_mtkl P;
            address_mhs Q;
            address_relasi PR;
            
            if(LC.First == NULL){
                P = NULL;
            }else{
                P = LC.First;
                while((P != NULL)  && P->info.kodematkul != x){
                    P=P->next;
                }
            }
            
            caric = P;
            if(L.First == NULL){
                Q = NULL;
            }else{
                Q = L.First;
                while((Q != NULL)  && Q->info.nim != xx){
                    Q=Q->next;
                }
            }
            
                carip = Q;
                if(carip != NULL && caric != NULL)
                {   
                    PR = alokasiRelasi(carip,caric);
                    insertLast(R,PR);
                    cout<<"NIM : "<<info(carip).nim<<" dengan Kode Matkul : "<<info(caric).kodematkul<<" berhasil direlasikan "<<endl;
                }
                else
                {   
                    cout<<"NIM / Kode Matkul Tidak Ditemukan!!"<<endl;
                } 
            cout<<endl;
            int men;
            cout<<"Ketik '0': ";
            cin>>men;
            if(men==0){
                menu(R,LC,L);
            }  
        }
            
    
    else if(pil == 8){
        printInfo_R(R);
        cout<<endl;
            int men;
            cout<<"Ketik '0': ";
            cin>>men;
            if(men==0){
            menu(R,LC,L);
            }
    }
    else if(pil == 9){
        int k,l;
        cout<<"Masukan Nim Mahasiswa    : ";
        cin>>k;
        cout<<"Masukan Kode Matakuliah  : ";
        cin>>l;
        address_relasi DR;
        if(R.FirstR == NULL){
            DR = NULL;
            }else{
                DR = R.FirstR;
                while(( DR!= NULL)  && (DR->child->info.kodematkul != l || DR->parent->info.nim != k)){
                    DR=DR->next;
                }
                cout <<"NIM Mahasiswa       : "<<DR->parent->info.nim <<endl;
                cout<<"Nama Mahasiswa       : "<<DR->parent->info.nama<<endl;
                cout << "Kode Matakuliah    : "<<DR->child->info.kodematkul <<endl;
                cout<<"Nama Matakuliah      : "<<DR->child->info.namamatkul<<endl;
            }
            cout<<endl;
            int men;
            cout<<"Ketik '0': ";
            cin>>men;
            if(men==0){
            menu(R,LC,L);
            }
    }
    else if(pil == 10){
        int k,l;
        cout<<"Masukan Nim Mahasiswa    : ";
        cin>>k;
        cout<<"Masukan Kode Matakuliah  : ";
        cin>>l;
        address_relasi DR;
        if(R.FirstR == NULL){
            DR = NULL;
            }else{
                DR = R.FirstR;
                while(( DR!= NULL)  && (DR->child->info.kodematkul != l || DR->parent->info.nim != k)){
                    DR=DR->next;
                }
                deletebyrelasi(R,DR);
            } 
            cout<<endl;
            int men;
            cout<<"Ketik '0': ";
            cin>>men;
            if(men==0){
            menu(R,LC,L);
            }          
    }
    else if(pil == 11){
        int b;
        cout<<"Masukan NIM Mahasiswa : ";
        cin>>b;
        address_mhs P,W;
        address_relasi Q,C;
        if(L.First == NULL){
            P = NULL;
        }
        else if(L.First != NULL){
            P = L.First;
            while((P != NULL)  && P->info.nim != b){
                P=P->next;
            }
            if(P!=NULL){
                Q = R.FirstR;
                while(Q !=NULL){
                    if(Q->parent->info.nim == P->info.nim){
                        C = Q;
                        Q = Q->next;
                        deletebyrelasi(R,C);
                    }else{
                        Q = Q->next;
                    }
                }
        if(L.First != NULL)
        {
            if(P == L.First)
            {
                deleteFirst_mhs(L,P);
            }
            else
            {
                W = L.First;
                while(W->next != P)
                W = W->next;

                if(W->next == P && P->next == NULL)
                {
                    deleteLast_mhs(L,P);
                }
                else
                {
                    W->next = P->next;
                    P->next = NULL;
                }
            }
            cout<<"Data Berhasil Dihapus"<<endl;
            
        }
        else
        {
            cout<<"List Kosong"<<endl;
        }
            }else{
             cout<<"Data Tidak di temukan"<<endl;
            }
        cout<<endl;
            int men;
            cout<<"Ketik '0': ";
            cin>>men;
            if(men==0){
            menu(R,LC,L);
            }
    }
}
    else if(pil == 12){
        int b;
        cout<<"Masukan Kode Matakuliah : ";
        cin>>b;
        address_mtkl P,W;
        address_relasi Q,C;
        
        if(LC.First == NULL){
            P = NULL;
        }
        else if(LC.First != NULL){
            P = LC.First;
            while((P != NULL)  && P->info.kodematkul != b){
                P=P->next;
            }
            if(P!=NULL){
                Q = R.FirstR;
                while(Q !=NULL){
                    if(Q->child->info.kodematkul == P->info.kodematkul){
                        C = Q;
                        Q = Q->next;
                        deletebyrelasi(R,C);
                    }else{
                        Q = Q->next;
                    }
                }
               
        if(LC.First != NULL)
        {
            if(P == LC.First)
            {
                 
                deleteFirst(LC,P);

            }
            else
            {
                W = LC.First;
                while(W->next != P)
                W = W->next;

                if(W->next == P && P->next == NULL)
                {
                    deleteLast(LC,P);
                }
                else
                {
                    W->next = P->next;
                    P->next->Prev = W;
                    P->Prev = NULL;
                    P->next = NULL;
                }
            }
            cout<<"Data Berhasil Dihapus"<<endl;
        }
        else
        {
            cout<<"List Kosong"<<endl;
        }
            }else{
             cout<<"Data Tidak di temukan"<<endl;
            }
        cout<<endl;
            int men;
            cout<<"Ketik '0': ";
            cin>>men;
            if(men==0){
            menu(R,LC,L);
            }
    }
    }
    else if(pil == 13){
        sortrelasi(R);
        printInfo_R(R);
        cout<<endl;
            int men;
            cout<<"Ketik '0': ";
            cin>>men;
            if(men==0){
            menu(R,LC,L);
            }
    }
}


int main()
{
    List_mtkl LC;
    List_mhs L;
    List_relasi R;
    createList(LC);
    createList_mhs(L);
    createList_relasi(R);
    menu(R,LC,L);


    return 0;
}
