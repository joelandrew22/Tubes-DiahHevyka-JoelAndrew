#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

using namespace std;

typedef struct elmlist_mhs *address_mhs;

struct info_mhs{
    int nim;
    string nama;
    string alamat;
    string JK;
    string jurusan;
    string kelas;
};


struct elmlist_mhs{
    info_mhs info;
    address_mhs next;
};

typedef struct elmlist_mtkl *address_mtkl;

struct info_mtkl{
    int nim;
    string nama;
    string alamat;
    string JK;
    string jurusan;
    string kelas;
};


struct elmlist_mtkl{
    info_mtkl info;
    address_mtkl next;
};


struct List_mhs{
    address_mhs First;
};


#endif // RELASI_H_INCLUDED
