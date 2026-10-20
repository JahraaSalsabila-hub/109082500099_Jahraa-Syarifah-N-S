# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Jahraa Syarifah N.S - 109082500099</p>

## Dasar Teori

### A. Linked List dan Singly Linked List<br/>
Linked list (biasa disebut list saja) adalah salah satu bentuk struktur data berupa serangkaian elemen data yang saling berkait dan bersifat fleksibel karena bisa tumbuh dan mengerut sesuai kebutuhan [3].
#### 1. Linked List dengan Pointer
Data yang disimpan di linked list bisa berupa data tunggal (misalnya satu `string`) atau data majemuk/record (misalnya data mahasiswa yang isinya nama dan NIM). Linked list bisa dibuat pakai array atau pointer. Di praktikum ini dipakai pointer karena array bersifat statis sedangkan pointer dinamis, dan data di linked list yang saling bergandengan lebih gampang ditangani pakai pointer [3]. Elemen yang diakses lewat pointer bisa pakai tanda `->` atau tanda titik [3].
#### 2. Singly Linked List
Singly linked list adalah model linked list yang cuma punya satu arah pointer. Tiap elemennya terdiri dari data dan successor, yaitu bagian penghubung ke elemen berikutnya. Sifatnya, cuma butuh satu pointer, node terakhir menunjuk ke Nil, cuma bisa dibaca maju, dan lebih gampang kalau mau nyisip atau ngehapus di tengah list [3]. Istilah yang dipakai ada `first/head` (pointer ke elemen pertama), `next` (pointer ke elemen sesudahnya), `Nil/NULL` (tidak mengacu ke mana pun), dan node (tempat nyimpen data) [3].
#### 3. Operasi pada Linked List
Operasi yang umum ada pada linked list yaitu pembuatan list (Create List), penyisipan elemen (Insert), penghapusan elemen (Delete), penelusuran dan penampilan isi list (View), pencarian elemen (Searching), dan pengubahan isi elemen (Update) [3].

### B. Operasi Dasar Singly Linked List<br/>
Operasi-operasi dasar tadi disebut primitif, dan primitif list disimpan dalam ADT list yang terdiri dari file `.h` dan `.cpp` [3].
#### 1. Pembentukan Komponen List
`createList()` buat membuat list kosong dengan mengisi `first` dengan Nil. `alokasi()` buat mengalokasikan memori satu elemen, di C++ pakai `new` (contohnya `P = new ElmList;`). `dealokasi()` buat mengembalikan memori elemen ke sistem, di C++ pakai `delete` (contohnya `delete P;`). Ada juga `isEmpty()` buat ngecek list kosong atau nggak, hasilnya true kalau kosong [3].
#### 2. Insert
Insert first menaruh elemen baru di awal list, caranya `P->next = L.first;` lalu `L.first = P;`. Insert last menaruh elemen baru di akhir list, caranya cari elemen terakhir (misal `Q`) lalu `Q->next = P;`. Insert after menaruh elemen baru setelah node tertentu (`Q`), caranya `P->next = Q->next;` lalu `Q->next = P;` [3].
#### 3. Delete
Delete first mengambil elemen pertama, caranya `P = L.first;` lalu `L.first = (L.first)->next;` dan `P->next = Nil;`. Delete last menghapus elemen terakhir, caranya cari elemen terakhir `P` dan elemen sebelumnya `Q`, lalu `Q->next = Nil;`. Delete after menghapus node setelah node tertentu, caranya node sebelumnya disambungkan langsung ke node sesudah node yang dihapus. Elemen yang sudah diambil dibebaskan memorinya pakai `dealokasi()`, sedangkan buat membebaskan semua elemen sekaligus dipakai `delAll(L)` sehingga list jadi kosong [3].

## Guided 

### 1. File Header (list.h)

```C++
//hear guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isis setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct LinkedList { //ini linked listnya
    address first;
};

//semua function & prosedure yang akan dipakai
bool isEmpty(LinkedList list);
void createList(LinkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(LinkedList list);
void insertFirst(LinkedList &list, address nodeBaru);
void insertAfter(LinkedList &list, address nodeBaru, address Prev);
void insertLast(LinkedList &list, address nodeBaru);

void delFirst(LinkedList &list);
void delLast(LinkedList &list);
void delAfter(LinkedList &list, address nodeHapus, address nodePrev);
int nbList(LinkedList list);
void deleteList(LinkedList &list);

#endif
```
File ini adalah header-nya, isinya definisi type dan deklarasi semua fungsi dan prosedur yang dipakai. Bagian `#ifndef LIST_H`, `#define LIST_H`, dan `#endif` adalah header guard supaya file ini nggak ke-include lebih dari sekali. `#define Nil NULL` bikin kata `Nil` bisa dipakai buat pointer yang kosong. `struct mahasiswa` isinya nama, nim, dan umur, terus dikasih nama lain `dataMahasiswa` lewat `typedef`. `address` didefinisikan sebagai pointer ke `struct node`. `struct node` adalah isi tiap elemen linked list, terdiri dari `isidata` (data mahasiswa) dan `next` (pointer ke node berikutnya). `struct LinkedList` cuma punya `first`, yaitu pointer ke node pertama. Di bagian bawah ada deklarasi `isEmpty`, `createList`, `alokasi`, `dealokasi`, `printList`, `insertFirst`, `insertAfter`, `insertLast`, `delFirst`, `delLast`, `delAfter`, `nbList`, dan `deleteList`.

### 2. File Body (list.cpp)

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(LinkedList List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(LinkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(LinkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(LinkedList &List){
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(LinkedList &List){
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil; // Ini sepertinya List.first = Nil; pada praktek benarnya
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

void delAfter(LinkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(LinkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(LinkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(LinkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```
File ini isinya realisasi dari semua yang dideklarasiin di `list.h`, makanya di atas ada `#include "list.h"`. `isEmpty()` ngecek list kosong atau nggak lewat `List.first == Nil`. `createList()` ngisi `first` dengan `Nil`. `alokasi()` bikin node baru pakai `new`, ngisi nama, nim, umur, dan `next`-nya `Nil`. `dealokasi()` ngebebasin memori node pakai `delete`. Buat insert, `insertFirst()` nyambungin node baru ke `first` yang lama lalu `first` dipindah ke node baru, `insertAfter()` nyisipin node baru setelah `Prev`, dan `insertLast()` nelusurin list sampai node terakhir lalu nyambungin node baru di situ. Buat delete, `delFirst()` ngapus node pertama, `delLast()` ngapus node terakhir sambil nyimpen node sebelumnya di `nodePrev`, dan `delAfter()` ngapus node setelah `nodePrev`. `printList()` nelusurin list dan nampilin nama, nim, dan usia tiap node, `nbList()` ngitung jumlah node, dan `deleteList()` ngapus semua node sampai list kosong.

### 3. File Driver (main.cpp)

```C++
#include "list.h"

#include <iostream>
using namespace std;

int main(){
    LinkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
File ini program utamanya. Pertama dibuat list kosong lewat `createList()`, terus lima node dialokasi dengan data Dhimas, Arvin, Rizal, Satrio, dan Joshua. Node dimasukin ke list, `nodeA` pakai `insertFirst`, `nodeB` pakai `insertLast`, `nodeC` disisip setelah `nodeA`, `nodeD` disisip setelah `nodeC`, dan `nodeE` pakai `insertLast`, jadi urutannya Dhimas, Rizal, Satrio, Arvin, Joshua dengan jumlah node 5. Setelah itu dilakukan delete, `delFirst()` ngapus Dhimas, `delLast()` ngapus Joshua, dan `delAfter()` ngapus node setelah `nodeC` yaitu Satrio, sehingga sisa Rizal dan Arvin dengan jumlah node 2. Terakhir `deleteList()` ngapus semua node, jadi `printList()` nampilin "List kosong." dan jumlah node jadi 0. Karena programnya kepisah jadi dua file .cpp, ngecompile-nya harus nyertain dua-duanya, yaitu `g++ main.cpp list.cpp -o main`.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file "Singlylist.h" (Type infotype : int, Type address : pointer to ElmList, Type ElmList < info : infotype, next : address >, Type List : < First : address >, procedure CreateList( input/output L : List ), function alokasi( x : infotype ) → address, procedure dealokasi( input/output P : address ), procedure printInfo( input L : List ), procedure insertFirst( input/output L : List, input P : address )). Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file "Singlylist.cpp". Kemudian buat program utama didalam file "main.cpp" dengan implementasi sebagai berikut : (P1 sampai P5 dialokasi dengan nilai 2, 0, 8, 12, 9 dan masing-masing langsung di-insertFirst, lalu printInfo(L))

```C++
// Singlylist.h
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
#include <iostream>
using namespace std;
#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif // SINGLYLIST_H_INCLUDED

// Singlylist.cpp
#include "Singlylist.h"

//membuat list kosong
void createList(List &L) {
    L.first = Nil;
}

//membuat node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

//menghapus node dari memori
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

//menampilkan isi list
void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

//menambah node di awal list
void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

// main.cpp
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul4/unguided/soal1/soal%201.laprak6.png


Soal ini bikin ADT singly linked list dengan cara dipisah jadi tiga file kayak di Modul 3, yaitu `Singlylist.h` buat type dan header prosedur, `Singlylist.cpp` buat isi prosedurnya, dan `main.cpp` buat program utamanya. Di header ada `struct ElmList` (isinya `info` dan `next`) dan `struct List` yang cuma punya `first`, sedangkan `address` dibuat lewat `typedef` sebagai pointer ke `ElmList`. `createList()` ngisi `first` dengan `Nil` supaya list kosong. `alokasi()` bikin node baru pakai `new` (materi pointer Modul 2), terus ngisi `info` dan `next`-nya `Nil`. `dealokasi()` ngebalikin memori node pakai `delete`. `insertFirst()` nyambungin `next` node baru ke `first` yang lama, baru `first` dipindah ke node baru. Karena tiap node dimasukin di awal, urutannya jadi kebalik, nilai yang dimasukin 2, 0, 8, 12, 9 jadi tampil 9 12 8 0 2. `printInfo()` nelusurin list dari `first` pakai `while` sampai ketemu `Nil` sambil nampilin `info` tiap node.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

```C++
// Singlylist.h
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
#include <iostream>
using namespace std;
#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(address Prec);
int nbList(List L);
void deleteList(List &L);

#endif // SINGLYLIST_H_INCLUDED

// Singlylist.cpp
#include "Singlylist.h"

//membuat list kosong
void createList(List &L) {
    L.first = Nil;
}

//membuat node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

//menghapus node dari memori
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

//menampilkan isi list
void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

//menambah node di awal list
void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

//menghapus node pertama
void deleteFirst(List &L) {
    address P = L.first;
    if (P != Nil) {
        L.first = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

//menghapus node terakhir
void deleteLast(List &L) {
    address P = L.first;
    address Q = Nil;
    if (P != Nil) {
        while (P->next != Nil) {
            Q = P;
            P = P->next;
        }
        if (Q == Nil)
            L.first = Nil;
        else
            Q->next = Nil;
        dealokasi(P);
    }
}

//menghapus node setelah node Prec
void deleteAfter(address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        address P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

//menghitung jumlah node
int nbList(List L) {
    int jumlah = 0;
    address P = L.first;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

//menghapus semua node
void deleteList(List &L) {
    while (L.first != Nil) {
        deleteFirst(L);
    }
}

// main.cpp
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L);    //hapus node 9
    deleteLast(L);     //hapus node 2
    deleteAfter(P4);   //hapus node 8 (setelah node 12)

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul4/unguided/soal2/soal%202.laprak6.png

Soal 2 lanjutan dari soal 1, jadi `Singlylist.h` dan `Singlylist.cpp` ditambahin prosedur hapus, sedangkan `main.cpp` isinya sama sampai node dibuat. `deleteFirst()` mindahin `first` ke node berikutnya lalu node pertama di-dealokasi. `deleteLast()` nelusurin list sampai node terakhir sambil nyimpen node sebelumnya di `Q`, terus `Q->next` diisi `Nil` dan node terakhir di-dealokasi. Kalau list cuma punya satu node, `first` langsung diisi `Nil`. `deleteAfter()` ngapus node setelah `Prec` dengan cara `Prec->next` disambungin ke node sesudah node yang dihapus. Di `main`, dipakai `deleteAfter(P4)` karena `P4` nunjuk ke node 12, jadi yang kehapus node 8. Urutan hapusnya 9 (first), 2 (last), lalu 8 (setelah 12), sisanya 12 dan 0, makanya `nbList()` yang ngitung node pakai `while` hasilnya 2. Terakhir `deleteList()` ngulang `deleteFirst()` sampai list kosong, jadi jumlah node jadi 0.

## Kesimpulan
Dari praktikum modul 4 ini bisa disimpulkan kalau singly linked list adalah kumpulan node yang tersambung satu arah lewat pointer `next`, dengan `first` sebagai penunjuk node pertama dan node terakhir yang `next`-nya `Nil`. Node dibuat pakai `new` dan dibebasin pakai `delete`, jadi ukuran list bisa nambah dan berkurang sesuai kebutuhan, beda sama array yang ukurannya tetap. Operasi dasarnya ada insert dan delete (first, last, after), view buat nampilin isi list, dan ngitung jumlah node. Penerapannya juga masih pakai konsep ADT dari Modul 3, yaitu dipisah jadi file header, file body, dan file main. Semua latihan sudah bisa dibuat dan hasilnya sama dengan output yang diharapkan di soal.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Laboratorium Informatika, Fakultas Informatika, Telkom University. "Modul 4 Singly Linked List (Bagian Pertama)", Praktikum Struktur Data.
