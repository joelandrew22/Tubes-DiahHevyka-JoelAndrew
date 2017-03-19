#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDE
using namespace std;

typedef struct elmlist_mhs *address_mhs;

struct mahasiswa{
    int nim;
    string nama;
    string alamat;
    string JK;
    string jurusan;
    string kelas;
};


struct elmlist_mhs{
    mahasiswa info;
    address_mhs next;
};

struct List_mhs{
    address_mhs First;
};

void createList_mhs(List_mhs &L);
address alokasi_mhs(mahasiswa x);
void dealokasi_mhs(address &P);
void insertFirst_mhs(List_mhs &L, address_mhs P);
void insertLast_mhs(List_mhs &L, address_mhs P);
address_mhs findElm_mhs(List_mhs L, mahasiswa x);
void deleteFirst_mhs(List_mhs &L, address_mhs &P);
void deleteLast_mhs(List_mhs &L, address &P);
void printInfo_mhs(List_mhs L);
void insertAfter_mhs(address Prec, address_mhs P);
void deleteAfter_mhs(address Prec, address_mhs &P);

#endif // MAHASISWA_H_INCLUDED

