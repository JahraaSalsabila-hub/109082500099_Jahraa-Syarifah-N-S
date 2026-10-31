# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List (Bagian Pertama)</h1>
<p align="center">Jahraa Syarifah N.S - 109082500099</p>

## Dasar Teori

### A. Doubly Linked List<br/>
Doubly linked list adalah linked list yang masing-masing elemennya punya 2 successor, yaitu successor yang menunjuk ke elemen sebelumnya (`prev`) dan successor yang menunjuk ke elemen sesudahnya (`next`) [1].
#### 1. Komponen Doubly Linked List
Komponen-komponennya ada `first` (pointer pada list yang menunjuk elemen pertama), `last` (pointer pada list yang menunjuk elemen terakhir), `next` (pointer pada elemen yang menunjuk elemen sesudahnya), dan `prev` (pointer pada elemen yang menunjuk elemen sebelumnya) [1]. Kalau list masih kosong, `first` dan `last` sama-sama berisi Nil.
#### 2. Struktur Data Doubly Linked List
Elemennya dibuat pakai `struct elmlist` yang isinya `info`, `next`, dan `prev`, sedangkan listnya dibuat pakai `struct list` yang isinya `first` dan `last`. Pointer ke elemen dibuat lewat `typedef struct elmlist *address`, dan list dianggap kosong kalau `L.first = Nil` [1].
#### 3. Perbedaan dengan Singly Linked List
Pada singly linked list tiap elemen cuma punya satu pointer `next` sehingga cuma bisa dibaca maju. Pada doubly linked list ada `prev` dan `last`, jadi list bisa ditelusuri maju dan mundur, dan ini bikin akses elemen jadi lebih mudah [1].

### B. Operasi pada Doubly Linked List<br/>
Operasi dasar pada doubly linked list sama kayak singly linked list, bedanya tiap kali nambah atau ngehapus elemen, pointer `next` dan `prev` harus diatur dua-duanya supaya sambungannya tetap benar [1].
#### 1. Insert
Insert first menaruh elemen baru di awal list, caranya `P->next = L.first;`, `(L.first)->prev = P;`, lalu `L.first = P;`. Insert last menaruh elemen baru di akhir list, caranya `P->prev = L.last;`, `(L.last)->next = P;`, lalu `L.last = P;`. Insert after menaruh elemen baru setelah elemen `R`, caranya `P->next = R->next;`, `P->prev = R;`, `(R->next)->prev = P;`, lalu `R->next = P;`. Insert before kebalikan dari insert after, bedanya cuma di pencarian elemennya [1].
#### 2. Delete
Delete first mengambil elemen pertama, caranya `P = L.first;`, `L.first = (L.first)->next;`, `P->prev = Nil;`, `(L.first)->prev = Nil;`, dan `P->next = Nil;`. Delete last mengambil elemen terakhir, caranya `P = L.last;`, `L.last = (L.last)->prev;`, `P->prev = Nil;`, dan `(L.last)->next = Nil;`. Delete after mengambil elemen `P` setelah elemen `R`, caranya `R->next = P->next;`, `(P->next)->prev = R;`, lalu `P->prev = Nil;` dan `P->next = Nil;`. Elemen yang sudah diambil dikembalikan memorinya lewat `dealokasi(P)`. Delete before kebalikan dari delete after, bedanya cuma di pencarian elemennya [1].
#### 3. Update, View, dan Searching
Proses pencarian, update data, dan view data pada dasarnya sama dengan proses pada singly linked list. Bedanya, di doubly linked list proses akses elemen lebih mudah karena bisa iterasi maju dan mundur. ADT-nya juga pada dasarnya sama dengan ADT pada singly linked list [1].

## Guided 

### 1. File Header (Doublylist.h)

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

#define Nil NULL

// Latihan 1
struct infotype
{
    std::string nopol;
    std::string warna;
    int thnBuat;
};
typedef struct elmlist *address;
struct elmlist
{
    infotype info;
    address next;
    address prev;
};
struct List
{
    address First;
    address Last;
};

// Latihan 1
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Latihan 2

address findElm(List L, std::string nopol);

// Latihan 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string nopol, bool &status);

#endif
```
File ini adalah header-nya, isinya definisi type dan deklarasi semua fungsi dan prosedur yang dipakai. #ifndef DOUBLYLIST_H dan #define DOUBLYLIST_H adalah header guard supaya file ini nggak ke-include lebih dari sekali. #define Nil NULL bikin kata Nil bisa dipakai buat pointer yang kosong. struct infotype isinya nopol, warna, dan tahun buat. address didefinisikan sebagai pointer ke elmlist, dan elmlist adalah isi tiap elemen list yang terdiri dari info (data kendaraan), next (pointer ke elemen sesudahnya), dan prev (pointer ke elemen sebelumnya). struct List punya dua pointer, yaitu First ke elemen pertama dan Last ke elemen terakhir. Di bagian bawah ada deklarasi CreateList, alokasi, dealokasi, printInfo, insertLast, findElm, deleteFirst, deleteLast, deleteAfter, dan deleteElm.`insertLast`, `findElm`, `deleteFirst`, `deleteLast`, dan `deleteAfter`.

### 2. File Body (Doublylist.cpp)

```C++
#include "Doublylist.h"

// Latihan 1
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil; 
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.Last;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    while (P != Nil) {
        std::cout << "no polisi : " << P->info.nopol << std::endl;   
        std::cout << "warna     : " << P->info.warna << std::endl;   
        std::cout << "tahun     : " << P->info.thnBuat << std::endl; 
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) { 
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;         
        (L.Last)->next = P;     
        L.Last = P;               
    }
}

// Latihan 2
address findElm(List L, std::string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Latihan 3
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.First; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;     
        (L.First)->prev = Nil; 
        P->next = Nil;         
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.Last; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;      
        (L.Last)->next = Nil; 
        P->prev = Nil;         
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;     
        (P->next)->prev = Prec; 
        P->next = Nil;            
        P->prev = Nil;           
    }
}

void deleteElm(List &L, std::string nopol, bool &status) {
    address P = findElm(L, nopol);
    status = false;

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P); 
        status = true;
    }
}
```
File ini isinya realisasi dari semua yang dideklarasiin di Doublylist.h, makanya di atas ada #include "Doublylist.h". CreateList() ngisi First dan Last dengan Nil supaya list kosong. alokasi() bikin elemen baru pakai new, ngisi info, dan next serta prev-nya Nil. dealokasi() ngebalikin memori elemen pakai delete. printInfo() nampilin data mulai dari Last terus mundur lewat prev, dan ada tambahan pengecekan kalau Last itu Nil maka muncul tulisan "List kosong.". insertLast() ngecek dulu apakah list kosong, kalau kosong First dan Last langsung diisi elemen baru, kalau nggak prev elemen baru disambungin ke Last, next dari Last yang lama diisi elemen baru, baru Last dipindah ke elemen baru. findElm() nelusurin list dari First sampai ketemu nopol yang sama dan ngembaliin alamatnya (atau Nil kalau nggak ada). Untuk proses hapus, ada deleteFirst(), deleteLast(), dan deleteAfter(). Selain itu ditambahkan prosedur gabungan deleteElm() yang bertugas mencari posisi elemen berdasarkan nopol yang mau dihapus, memanggil prosedur hapus sesuai posisinya, dan mengubah variabel status ke true kalau datanya berhasil dihapus.

### 3. File Driver (main.cpp)

```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan nomor polisi: "; cin >> data.nopol;
    cout << "masukkan warna kendaraan: "; cin >> data.warna;
    cout << "masukkan tahun kendaraan: "; cin >> data.thnBuat;
    if (findElm(L, data.nopol) == Nil) {
        P = alokasi(data); 
        insertLast(L, P);  
    } else {
        cout << "nomor polisi sudah terdaftar" << endl; 
    }
}

int main() {
    List L;
    CreateList(L); 
    address P;

    // Latihan 1
    inputData(L); 
    inputData(L); 
    inputData(L); 
    inputData(L); 

    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    // Latihan 2
    string nopolCari;
    cout << "\nMasukkan Nomor Polisi yang dicari : "; 
    cin >> nopolCari; 
    
    P = findElm(L, nopolCari); 
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl; 
        cout << "Warna        : " << P->info.warna << endl; 
        cout << "Tahun        : " << P->info.thnBuat << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }

    // Latihan 3
    string nopolHapus;
    bool hapusBerhasil;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;

    deleteElm(L, nopolHapus, hapusBerhasil); 

    if (hapusBerhasil) {
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
    }
    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    return 0;
}
```
File ini program utamanya, yang ngerjain tiga latihan sekaligus. Pertama, penginputan data dipisah ke fungsi inputData(). Di fungsi ini nopol, warna, dan tahun kendaraan diinput, terus otomatis dicek pakai findElm(). Kalau nopolnya udah ada muncul "nomor polisi sudah terdaftar" dan datanya nggak dimasukin, kalau belum ada dialokasiin lalu dimasukin pakai insertLast(). Di fungsi main(), inputData(L) ini dipanggil 4 kali berturut-turut. Terus list ditampilin pakai printInfo(). Kedua, nopol yang dicari diinput, dicari pakai findElm(), dan datanya ditampilin kalau ketemu, atau muncul pesan tidak ditemukan kalau nggak ada. Ketiga, nopol yang mau dihapus diinput lalu langsung diproses ke dalam prosedur deleteElm(). Prosedur ini akan mengubah nilai referensi hapusBerhasil jadi true kalau datanya berhasil dihapus. Berdasarkan hasilnya, program menampilkan pesan sukses atau pesan kalau nopol tidak ditemukan, lalu diakhiri dengan nampilin isi list kembali.

## Unguided 

### 1. Buatlah ADT Doubly Linked List sebagai berikut di dalam file "Buku.h" (Type infotype : buku < kodeBuku : string, judul : string, thnTerbit : integer >, Type address : pointer to ElmList, Type ElmList < info : infotype, next : address, prev : address >, Type List < First : address, Last : address >, procedure CreateList( input/output L : List ), function alokasi( x : infotype ) -> address, procedure dealokasi( input/output P : address ), procedure printInfo( input L : List ), procedure insertLast( input/output L : List, input P : address )). Buatlah implementasi ADT Doubly Linked List pada file "Buku.cpp" dan cobalah hasil implementasi ADT tersebut pada file "main.cpp". Pastikan sistem melakukan pengecekan duplikasi kodeBuku sebelum memasukkan data baru ke dalam list.

```C++
// Buku.h
#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
#define Nil NULL

struct buku {
    string kodeBuku;
    string judul;
    int thnTerbit;
};

typedef buku infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

#endif // BUKU_H_INCLUDED

// Buku.cpp
#include "Buku.h"

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    cout << "DATA LIST 1" << endl;
    address P = L.last;
    while (P != Nil) {
        cout << "kode buku : " << P->info.kodeBuku << endl;
        cout << "judul : " << P->info.judul << endl;
        cout << "tahun : " << P->info.thnTerbit << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    address Q = L.first;
    while (Q != Nil) {
        if (Q->info.kodeBuku == P->info.kodeBuku) {
            cout << "kode buku sudah terdaftar" << endl;
            dealokasi(P);
            return;
        }
        Q = Q->next;
    }
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

// main.cpp
#include "Buku.h"

int main() {
    List L;
    infotype x;
    createList(L);

    for (int i = 0; i < 4; i++) {
        cout << "masukkan kode buku: ";
        cin >> x.kodeBuku;
        cout << "masukkan judul buku: ";
        cin >> x.judul;
        cout << "masukkan tahun terbit: ";
        cin >> x.thnTerbit;
        insertLast(L, alokasi(x));
    }

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul%206/unguided/modul6.1.png

Soal ini mirip guided kendaraan, tapi datanya diganti jadi buku (`kodeBuku`, `judul`, `thnTerbit`) dan filenya jadi `Buku.h`, `Buku.cpp`, dan `main.cpp`. Di `main`, data diinput 4 kali lewat `for` dan tiap data langsung dialokasi pakai `alokasi()` terus dimasukin pakai `insertLast()`. Pengecekan duplikat kodeBuku dilakukan di dalam `insertLast()`. Sebelum nyambungin elemen baru, list ditelusurin dulu dari `first`, kalau ada `kodeBuku` yang sama muncul "kode buku sudah terdaftar" dan elemen barunya langsung di-`dealokasi()` (dibuang), kalau nggak ada yang sama elemen baru disambungin ke akhir list lewat `prev`, `next`, dan `last`. Makanya data B001 yang kedua ditolak dan list cuma berisi B001, B003, dan B004. `printInfo()` nampilin dari `last` mundur pakai `prev`, jadi urutan yang tampil B004, B003, B001 (kebalik dari urutan dimasukin).

### 2. Carilah elemen dengan kode buku B001 dengan membuat fungsi baru: fungsi findElm( L : List, x : infotype ) : address

```C++
// Buku.h
#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
#define Nil NULL

struct buku {
    string kodeBuku;
    string judul;
    int thnTerbit;
};

typedef buku infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, infotype x);

#endif // BUKU_H_INCLUDED

// Buku.cpp
#include "Buku.h"

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    cout << "DATA LIST 1" << endl;
    address P = L.last;
    while (P != Nil) {
        cout << "kode buku : " << P->info.kodeBuku << endl;
        cout << "judul : " << P->info.judul << endl;
        cout << "tahun : " << P->info.thnTerbit << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    address Q = L.first;
    while (Q != Nil) {
        if (Q->info.kodeBuku == P->info.kodeBuku) {
            cout << "kode buku sudah terdaftar" << endl;
            dealokasi(P);
            return;
        }
        Q = Q->next;
    }
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info.kodeBuku != x.kodeBuku) {
        P = P->next;
    }
    return P;
}

// main.cpp
#include "Buku.h"

int main() {
    List L;
    infotype x = {"", "", 0};
    createList(L);

    infotype b1 = {"B001", "Algoritma", 2020};
    infotype b2 = {"B003", "Struktur_Data", 2018};
    infotype b3 = {"B004", "Jaringan_Komputer", 2022};

    insertLast(L, alokasi(b1));
    insertLast(L, alokasi(b2));
    insertLast(L, alokasi(b3));

    cout << "Masukkan Kode Buku yang dicari : ";
    cin >> x.kodeBuku;

    address P = findElm(L, x);
    if (P != Nil) {
        cout << "Kode Buku : " << P->info.kodeBuku << endl;
        cout << "Judul : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
    } else {
        cout << "Kode buku " << x.kodeBuku << " tidak ditemukan" << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul%206/unguided/modul6.2.png

Soal ini nambah fungsi `findElm()` ke ADT yang dibuat di soal 1, jadi `Buku.h` dan `Buku.cpp` ditambahin fungsi itu. `findElm()` nelusurin list dari `first` pakai `while`, dan berhenti kalau udah ketemu elemen yang `kodeBuku`-nya sama dengan `x.kodeBuku` atau kalau udah sampai `Nil`. Setelah itu `P` langsung di-return, jadi kalau ketemu yang dikembalikan alamat elemennya dan kalau nggak ketemu yang dikembalikan `Nil`. Biar gampang ngetes, tiga buku awal (B001, B003, B004) langsung dimasukin di `main` tanpa input keyboard, jadi yang diinput cuma kode buku yang dicari. Kalau hasil `findElm()` bukan `Nil`, kode buku, judul, dan tahun terbit ditampilin dari `P->info`. Fungsi ini dibuat sebagai function (bukan prosedur) karena harus ngembaliin nilai berupa `address`.

### 3. Hapus elemen dengan kode buku B003 dengan membuat prosedur delete berikut: procedure deleteFirst( input/output L : List, input/output P : address ), procedure deleteLast( input/output L : List, input/output P : address ), procedure deleteAfter( input Prec : address, input/output P : address )

```C++
// Buku.h
#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
#define Nil NULL

struct buku {
    string kodeBuku;
    string judul;
    int thnTerbit;
};

typedef buku infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, infotype x);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif // BUKU_H_INCLUDED

// Buku.cpp
#include "Buku.h"

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    cout << "DATA LIST 1" << endl;
    address P = L.last;
    while (P != Nil) {
        cout << "Kode Buku : " << P->info.kodeBuku << endl;
        cout << "Judul : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    address Q = L.first;
    while (Q != Nil) {
        if (Q->info.kodeBuku == P->info.kodeBuku) {
            cout << "kode buku sudah terdaftar" << endl;
            dealokasi(P);
            return;
        }
        Q = Q->next;
    }
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info.kodeBuku != x.kodeBuku) {
        P = P->next;
    }
    return P;
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    if (L.first == L.last) {
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = P->next;
        L.first->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.last;
    if (L.first == L.last) {
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = P->prev;
        L.last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next->prev = Prec;
    P->prev = Nil;
    P->next = Nil;
}

// main.cpp
#include "Buku.h"

int main() {
    List L;
    infotype x = {"", "", 0};
    address P;
    createList(L);

    infotype b1 = {"B001", "Algoritma", 2020};
    infotype b2 = {"B003", "Struktur_Data", 2018};
    infotype b3 = {"B004", "Jaringan_Komputer", 2022};

    insertLast(L, alokasi(b1));
    insertLast(L, alokasi(b2));
    insertLast(L, alokasi(b3));

    cout << "Masukkan Kode Buku yang akan dihapus : ";
    cin >> x.kodeBuku;

    P = findElm(L, x);
    if (P != Nil) {
        if (P == L.first) {
            deleteFirst(L, P);
        } else if (P == L.last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan kode buku " << x.kodeBuku << " berhasil dihapus." << endl;
        printInfo(L);
    } else {
        cout << "Data dengan kode buku " << x.kodeBuku << " tidak ditemukan." << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan6_Modul6/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan6_Modul6/Output-Unguided3-2.png)

Soal ini nambah tiga prosedur hapus ke ADT soal 2, dan tiga buku awal (B001, B003, B004) juga langsung dimasukin di `main`. `deleteFirst()` dan `deleteLast()` ngambil elemen paling depan atau paling belakang dan nyimpen alamatnya di `P`, kalau list cuma punya satu elemen `first` dan `last` langsung diisi `Nil`. `deleteAfter()` ngambil elemen setelah `Prec` dengan cara `Prec->next` disambungin ke elemen sesudah `P`, dan `prev` elemen sesudahnya diarahin balik ke `Prec`. Di `main`, kode buku yang mau dihapus diinput, elemennya dicari pakai `findElm()`, lalu dicek posisinya. Kalau `first` dipanggil `deleteFirst()`, kalau `last` dipanggil `deleteLast()`, dan kalau di tengah dipanggil `deleteAfter(P->prev, P)`. B003 ada di tengah, jadi yang dipanggil `deleteAfter()` dengan B001 sebagai `Prec`. Setelah itu elemen di-`dealokasi()` dan list ditampilin lagi, sisa B004 lalu B001 karena `printInfo()` jalan mundur. Di soal ini tulisan di `printInfo()` pakai huruf kapital ("Kode Buku", "Judul", "Tahun Terbit") biar sama dengan contoh output soal.

## Kesimpulan
Dari praktikum modul 6 ini bisa disimpulkan kalau doubly linked list adalah linked list yang tiap elemennya punya dua pointer, yaitu `next` ke elemen sesudahnya dan `prev` ke elemen sebelumnya, dan listnya punya `first` serta `last`. Karena ada `prev` dan `last`, list bisa ditelusuri maju dan mundur, dan insert last bisa langsung lewat `last` tanpa nelusurin dari awal. Waktu insert dan delete, pointer `next` dan `prev` harus diatur dua-duanya biar sambungan list tetap benar, dan bagian first, last, atau tengah list butuh penanganan yang beda. Proses searching, update, dan view dasarnya sama dengan singly linked list. Semua latihan, yaitu ADT buku dengan pengecekan duplikat kode buku, pencarian elemen dengan `findElm()`, dan penghapusan elemen dengan `deleteFirst()`, `deleteLast()`, dan `deleteAfter()`, sudah bisa dibuat dan hasilnya sama dengan contoh output di soal.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
