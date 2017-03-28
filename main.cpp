#include <iostream>
#include "matkul.h"
#include"mahasiswa.h"
#include "relasi.h"

using namespace std;

void menu( List_relasi &R, List_mtkl &LC, List_mhs &L){
    address_mtkl PC = NULL;
    address_mtkl cariMtkl;
    matakuliah XC;
    int x;

    address_mhs PP = NULL;
    address_mhs carimhs;
    mahasiswa XP;
    int xx;

    address_relasi PR = NULL;
    address_mtkl caric;
    address_mhs carip;

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
    cout<<"0.Menu utama"<<endl;
    int pil;
    cout<<"Masukan Pilihan : ";
    cin>>pil;
    mahasiswa Mahasiswa;
    int men;
    if(pil==1){
        cout<<"Masukan NIM MAhasiswa : ";
        cin>>Mahasiswa.nim;
        cout<<"Masukan Nama Mahasiswa : ";
        cin>>Mahasiswa.nama;
        cout<<"Alamat Mahasiswa : ";
        cin>>Mahasiswa.alamat;
        cout<<"Jenis Kelamin : ";
        cin>>Mahasiswa.JK;
        cout<<"Jurusan : ";
        cin>>Mahasiswa.jurusan;
        cout<<"Kelas : ";
        cin>>Mahasiswa.kelas_mhs;
        address_mhs P;
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
            cout<<endl;
            cout<<"Ketik '0': ";
            cin>>men;
            if(men==0){
            menu(R,LC,L);
        }
    }

    else if(pil==2){
            matakuliah Matakuliah;
            cout<<"Masukan Kode Matakuliah : ";
            cin>>Matakuliah.kodematkul;
            cout<<"Masukan Nama Dosen : ";
            cin>>Matakuliah.namapengajar;
            cout<<"Banyak SKS : ";
            cin>>Matakuliah.sks;
            cout<<"Masukan Nama Matakuliah : ";
            cin>>Matakuliah.namamatkul;
            cout<<"Masukan ruangan : ";
            cin>>Matakuliah.ruangan;
            cout<<"Masukan Jam : ";
            cin>>Matakuliah.jam;
            address_mtkl P;
            P = alokasi(Matakuliah);
            address_mtkl Q;
                if(LC.First == NULL){
                    insertFirst(LC,P);
                }
                if(P->info.kodematkul < LC.First->info.kodematkul ){
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
            cout<<endl;
            cout<<"Ketik '0': ";
            cin>>men;
            if(men==0){
             menu(R,LC,L);
            }
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
        int x;
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
        int x;
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
        cout<<"Data di temukan : "<<endl;
        cout<<"Kode Matakuliah : "<<info(P).kodematkul<<endl;
        cout<<"Nama Doesen : "<<info(P).namapengajar<<endl;
        cout<<"Banyak SKS : "<<info(P).sks<<endl;
        cout<<"Nama Matakuliah: "<<info(P).namamatkul<<endl;
        cout<<"Ruangan : "<<info(P).ruangan<<endl;
        cout<<"Jam masuk : "<<info(P).jam<<endl;
    }else {
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
            cout<<"Masukkan NIM: ";
            cin>>xx;
            cout<<"Masukkan Kode Matkul: :";
            cin>>x;
            carip = findElm_mhs(L,xx);
            caric = findElm_mtkl(LC,x);
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
    }

}

int main()
{

    List_mtkl LC;
    List_mhs L;
    List_relasi R;
    menu(R,LC,L);

    return 0;
}
