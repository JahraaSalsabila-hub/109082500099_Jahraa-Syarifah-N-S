# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Jahraa Syarifah N.S - 109082500099</p>

## Dasar Teori

### A. Searching pada Singly Linked List<br/>
Searching merupakan operasi dasar pada list yang dilakukan dengan cara mencari node tertentu di dalam list [1].
#### 1. Pengertian Searching
Proses searching berjalan dengan mengunjungi setiap node, mulai dari node pertama, dan berhenti setelah node yang dicari ketemu [1]. Kalau sudah sampai node terakhir (yang `next`-nya `Nil`) tapi belum ketemu juga, berarti node yang dicari nggak ada di dalam list.
#### 2. Fungsi Pencarian pada ADT List
Di ADT list ada beberapa fungsi buat pencarian. `findElm(L, X)` mencari elemen list yang info-nya sama dengan X, kalau ada dikembalikan alamat elemennya dan kalau nggak ada dikembalikan `Nil`. `fFindElm(L, P)` ngecek apakah ada elemen dengan alamat P, hasilnya true atau false. `findBefore(L, P)` mengembalikan alamat elemen sebelum P, dan hasilnya `Nil` kalau P ada di awal list [1].
#### 3. Cara Mencari Node
Pencarian node bisa dilakukan berdasarkan beberapa hal. Kalau berdasarkan data, isi tiap node dibandingkan dengan data yang dicari, misalnya nama buah. Kalau berdasarkan alamat, alamat tiap node dibandingkan dengan alamat yang dicari. Kalau berdasarkan range, semua node ditelusuri dan yang datanya masuk rentang tertentu (misalnya harga di antara dua nilai) ditampilkan, jadi hasilnya bisa lebih dari satu node.

### B. Update pada Singly Linked List<br/>
Update merupakan operasi dasar pada list yang dipakai buat mengubah data yang ada di dalam node [1].
#### 1. Pengertian Update
Dengan operasi update kita bisa mengubah data-data node yang ada di dalam list, dan proses update biasanya diawali dengan pencarian terhadap data yang mau diubah [1]. Yang diubah cuma isi datanya, jadi jumlah node dan sambungan `next` antar node nggak berubah.
#### 2. Update First, Update Last, dan Update After
Update first mengubah data node pertama, caranya langsung lewat `first`. Update last mengubah data node terakhir, caranya menelusuri list sampai ketemu node yang `next`-nya `Nil`. Update after mengubah data node yang ada setelah node tertentu, jadi node sebelumnya harus diketahui dulu.
#### 3. Hubungan Searching dengan Operasi Lain
Dengan melakukan searching, operasi lain seperti insert after, delete after, dan update jadi lebih mudah karena alamat node yang dituju bisa didapat dulu lewat pencarian [1]. Semua operasi dasar ini termasuk primitif dari ADT singly linked list yang disimpan di file `.h` dan `.cpp` [1].

## Guided 

### 1. File Header (listBuah.h)

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```
File ini adalah header-nya, isinya definisi type dan deklarasi semua fungsi dan prosedur yang dipakai. `#ifndef LISTBUAH_H`, `#define LISTBUAH_H`, dan `#endif` adalah header guard supaya file ini nggak ke-include lebih dari sekali. `#define Nil NULL` bikin kata `Nil` bisa dipakai buat pointer yang kosong. `struct buah` isinya nama, jumlah, dan harga buah, terus dikasih nama lain `dataBuah` lewat `typedef`. `address` didefinisikan sebagai pointer ke `struct node`, dan `struct node` adalah isi tiap elemen list yang terdiri dari `isidata` (data buah) dan `next` (pointer ke node berikutnya). `struct linkedlist` cuma punya `first`, yaitu pointer ke node pertama. Di bagian bawah ada deklarasi semua fungsi dan prosedur yang dibagi jadi tiga kelompok. Materi Modul 4 isinya `isEmpty`, `createList`, `alokasi`, `dealokasi`, `printList`, insert (first, after, last), delete (first, last, after), `nbList`, dan `deleteList`. Materi Modul 5 bagian update ada `updateFirst`, `updateLast`, dan `updateAfter`, sedangkan bagian searching ada `FindNodeByData`, `FindNodeByAddress`, dan `FindNodeByRange`.

### 2. File Body (listBuah.cpp)

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```
File ini isinya realisasi dari semua yang dideklarasiin di `listBuah.h`, makanya di atas ada `#include "listBuah.h"`. Bagian awal sampai `deleteList()` adalah materi Modul 4, isinya mirip guided sebelumnya cuma datanya diganti jadi data buah, dan `delFirst()`, `delLast()`, `delAfter()`, serta `deleteList()` sekarang nampilin pesan kalau berhasil. Bagian materi Modul 5 dimulai dari update. `updateFirst()` minta input nama, jumlah, dan harga buat node pertama lewat `cin` yang langsung disimpan ke `List.first->isidata`. `updateLast()` nelusurin list dulu sampai node terakhir (yang `next`-nya `Nil`) baru minta input. `updateAfter()` ngupdate node setelah `nodePrev`, dan ngecek dulu apakah `nodePrev` valid. Lalu bagian searching. `FindNodeByData()` nelusurin list sambil ngitung posisi dan ngebandingin nama buah dengan data yang dicari, kalau ketemu langsung berhenti pakai `break` dan nampilin posisinya, kalau sampai habis belum ketemu muncul pesan tidak ditemukan. `FindNodeByAddress()` caranya sama tapi yang dibandingin adalah alamat node. `FindNodeByRange()` nelusurin semua node dan nampilin yang harganya ada di antara `hargaAwal` dan `hargaAkhir`, nggak pakai `break` karena yang masuk range bisa lebih dari satu.

### 3. File Driver (main.cpp)

```C++
  #include "listBuah.h"

  #include<iostream>
  using namespace std;

  int main(){
      linkedlist List;
      address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
      createList(List);

      dataBuah dtBuah;

      nodeA = alokasi("Jeruk", 100, 3000);
      nodeB = alokasi("Apel", 75, 4000);
      nodeC = alokasi("Pir", 87, 5000);
      nodeD = alokasi("Semangka", 43, 11500);
      nodeE = alokasi("Durian", 15, 31450);

      insertFirst(List, nodeA);
      insertLast(List, nodeB);
      insertAfter(List, nodeC, nodeA);
      insertAfter(List, nodeD, nodeC);
      insertLast(List, nodeE);

      cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
      printList(List);
      cout << "jumlah node : " << nbList(List) << endl;
      cout << endl;

      updateFirst(List);
      printList(List);
      updateLast(List);
      printList(List);
      updateAfter(List, nodeD);
      printList(List);

      cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
      printList(List);
      cout << "jumlah node : " << nbList(List) << endl;
      cout << endl;

      FindNodeByData(List, "kelapa");
      FindNodeByAddress(List, nodeC);
      FindNodeByRange(List, 5000, 10000);

      delFirst(List);
      printList(List);
      delLast(List);
      printList(List);
      delAfter(List, nodeD, nodeC);
      printList(List);

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
File ini program utamanya. Pertama dibuat list kosong lewat `createList()`, terus lima node dialokasi dengan data Jeruk, Apel, Pir, Semangka, dan Durian. Node dimasukin ke list, `nodeA` pakai `insertFirst`, `nodeB` pakai `insertLast`, `nodeC` disisip setelah `nodeA`, `nodeD` disisip setelah `nodeC`, dan `nodeE` pakai `insertLast`, jadi urutannya Jeruk, Pir, Semangka, Apel, Durian dengan jumlah node 5. Setelah itu `updateFirst()`, `updateLast()`, dan `updateAfter(List, nodeD)` dipanggil, jadi data node pertama, node terakhir, dan node setelah Semangka bisa diubah lewat input keyboard, dan tiap habis update list ditampilin lagi pakai `printList()`. Lalu tiga pencarian dijalankan, `FindNodeByData` buat nyari buah bernama "kelapa", `FindNodeByAddress` buat nyari `nodeC`, dan `FindNodeByRange` buat nyari buah dengan harga 5000 sampai 10000. Setelah itu dilakukan delete pakai `delFirst()`, `delLast()`, dan `delAfter()`, terakhir `deleteList()` ngapus semua node sampai `printList()` nampilin "List kosong." dan jumlah node 0. Karena programnya kepisah jadi dua file .cpp, ngecompile-nya harus nyertain dua-duanya, yaitu `g++ main.cpp listBuah.cpp -o main`.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file "Singlylist.h" (Type infotype : int, Type address : pointer to ElmList, Type ElmList < info : infotype, next : address >, Type List : < First : address >, procedure CreateList( input/output L : List ), function alokasi( x : infotype ) → address, procedure dealokasi( input/output P : address ), procedure printInfo( input L : List ), procedure insertFirst( input/output L : List, input P : address )). Kemudian buat implementasi ADT Singly Linked list pada file "Singlylist.cpp". Adapun isi data 9, 12, 8, 0, 2 (First menunjuk ke 9). Cobalah hasil implementasi ADT pada file "main.cpp" (P1 sampai P5 dialokasi dengan nilai 2, 0, 8, 12, 9 dan masing-masing langsung di-insertFirst, lalu printInfo(L))

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

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

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
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul%205/soal1/5.1.png


Soal ini bikin ADT singly linked list dengan cara dipisah jadi tiga file, `Singlylist.h` buat type dan header prosedur, `Singlylist.cpp` buat isi prosedurnya, dan `main.cpp` buat program utamanya. Di header ada `struct ElmList` (isinya `info` dan `next`) dan `struct List` yang cuma punya `first`, sedangkan `address` dibuat lewat `typedef` sebagai pointer ke `ElmList`. `createList()` ngisi `first` dengan `Nil` supaya list kosong. `alokasi()` bikin node baru pakai `new`, terus ngisi `info` dan `next`-nya `Nil`. `dealokasi()` ngebalikin memori node pakai `delete`. `insertFirst()` nyambungin `next` node baru ke `first` yang lama, baru `first` dipindah ke node baru. Karena tiap node dimasukin di awal, urutannya jadi kebalik, nilai yang dimasukin 2, 0, 8, 12, 9 jadi tampil 9 12 8 0 2. `printInfo()` nelusurin list dari `first` pakai `while` sampai ketemu `Nil`. File ini jadi dasar buat dua soal berikutnya.

### 2. Carilah elemen dengan info 8 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address

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
address findElm(List L, infotype x);

#endif // SINGLYLIST_H_INCLUDED

// Singlylist.cpp
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info != x) {
        P = P->next;
    }
    return P;
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

    address cari = findElm(L, 8);
    if (cari != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul%205/soal2/5.2.png

Soal ini nambah fungsi `findElm()` ke ADT yang dibuat di soal 1, jadi `Singlylist.h` dan `Singlylist.cpp` ditambahin fungsi itu. `findElm()` nelusurin list dari `first` pakai `while`, dan berhenti kalau udah ketemu node yang `info`-nya sama dengan `x` atau kalau udah sampai `Nil`. Setelah perulangan selesai, `P` langsung di-return, jadi kalau ketemu yang dikembalikan alamat node-nya dan kalau nggak ketemu yang dikembalikan `Nil`. Di `main`, hasil `findElm(L, 8)` disimpan di `cari`, terus dicek, kalau bukan `Nil` berarti 8 ada di list dan yang tampil "8 ditemukan dalam list". Pencarian ini dibuat sebagai function (bukan prosedur) karena harus ngembaliin nilai berupa `address`.

### 3. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).

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
int totalInfo(List L);

#endif // SINGLYLIST_H_INCLUDED

// Singlylist.cpp
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

int totalInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total = total + P->info;
        P = P->next;
    }
    return total;
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

    cout << "Total info dari kelima elemen adalah " << totalInfo(L) << endl;
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul%205/soal3/5.3.png

Soal ini nambah fungsi `totalInfo()` ke ADT yang dibuat di soal 1. Caranya mirip pencarian, list ditelusurin dari `first` pakai `while` sampai `Nil`, tapi bedanya tiap node nggak dicari, `info`-nya langsung dijumlahin ke variabel `total`. Karena list-nya isinya 9, 12, 8, 0, 2, hasilnya 9 + 12 + 8 + 0 + 2 = 31. Nilai `total` di-return, terus ditampilin di `main` lewat `cout`.

## Kesimpulan
Dari praktikum modul 5 ini bisa disimpulkan kalau searching dipakai buat nyari node tertentu di list dengan nelusurin node satu-satu dari `first` sampai ketemu atau sampai `Nil`. Hasil pencarian bisa berupa posisi node, alamat node, atau daftar node yang masuk range tertentu, dan hasilnya bisa dipakai buat operasi lain kayak update, insert after, dan delete after. Update dipakai buat ngubah isi data node tanpa ngubah sambungan antar node di list. Semua latihan, yaitu ADT singly linked list, pencarian elemen dengan `findElm()`, dan penjumlahan info semua elemen, sudah bisa dibuat dan hasilnya sama dengan output yang diharapkan di soal.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
