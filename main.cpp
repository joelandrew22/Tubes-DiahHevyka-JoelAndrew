#include <iostream>
#include "matkul.h"

using namespace std;

void menu(List_mtkl &LC){
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
    cout<<"13.Urutkan data mahasiswa"<<endl;
    cout<<"0.Menu utama"<<endl;
    int pil;
    cout<<"Masukan Pilihan : ";
    cin>>pil;
    address_mtkl P;
    if(pil==1){
            
            }
    else if(pil==2){
        cout<<"Pilih data ingin di masukkan di bagian mana "<<endl;
            cout<<"1.Pertama"<<endl;
            cout<<"2.Setelah"<<endl;
            cout<<"3.Terakhir"<<endl;
            int men;
            cout<<"Masukan pilihan : ";
            cin>>men;
            matakuliah Matakuliah;
            if(men==1){
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
                        address_mtkl P = alokasi(Matakuliah);
                        insertFirst(LC, P);
                        cout<<endl;
                        cout<<"Ketik '0': ";
                        cin>>men;
                        if(men==0){
                            menu(LC);
                        }
            }
            else if(men==2){
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
                        cout<<"Masukan setelah KODE Matakuliah : ";
                        int x;
                        cin>>x;
                        address_mtkl Prec_C, P;
                        Prec_C = findElm(LC, x); 
                        P = alokasi(Matakuliah);
                        insertAfter(LC, Prec_C, P);
                        cout<<endl;
                          cin>>men;
                        if(men==0){
                            menu(LC);
                        }                                                          
            }
            else if(men==3){
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
                        P = alokasi(Matakuliah);
                        insertLast(LC, P);
                        cout<<endl;
                        cout<<"Ketik '0': ";
                        cin>>men;
                        if(men==0){
                            menu(LC);
                        }
        }
    }
    else if(pil==3){

    }
    else if(pil==4){
        printInfo(LC);
            cout<<endl;
            cout<<"Ketik '0': ";
            int men;
            cin>>men;
            if(men==0){
                menu(LC);
            }    
    }
}

int main()
{
    List_mtkl LC;
    menu(LC);

    return 0;
}

