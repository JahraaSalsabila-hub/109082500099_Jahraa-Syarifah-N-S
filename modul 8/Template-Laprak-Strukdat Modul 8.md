# <h1 align="center">Laporan Praktikum Modul 8 QUEUE</h1>
<p align="center">Jahraa Syarifah N.S - 109082500099</p>

## Dasar Teori
# QUEUE (Antrean)

## 8.1 Pengertian Queue

Queue (dibaca: kyu) adalah struktur data linier yang bekerja seperti antrean dalam kehidupan sehari-hari, misalnya antrean pembelian tiket kereta api. Orang yang pertama kali datang akan dilayani pertama kali, dan orang yang terakhir datang akan dilayani terakhir. Prinsip ini disebut **FIFO (*First In First Out*)**.

Dalam implementasinya, Queue dapat dibangun menggunakan dua pendekatan, yaitu **array (tabel)** dan **linked list (pointer)**. Pada praktikum ini, fokus pembahasan adalah implementasi Queue menggunakan **linked list**, karena operasinya lebih sederhana: proses penghapusan (*delete*) hanya dilakukan di bagian **Head** (depan), dan proses penyisipan (*insert*) hanya dilakukan di bagian **Tail** (belakang). Queue dapat diterapkan pada *Singly Linked List* maupun *Doubly Linked List*.

---

## 8.2 Operasi-Operasi dalam Queue

Terdapat dua operasi utama dalam Queue, yaitu **Enqueue** (penyisipan) dan **Dequeue** (pengambilan).

### 8.2.1 Insert (Enqueue)

Operasi Enqueue selalu dilakukan pada bagian **akhir (tail)** antrean. Langkah-langkahnya adalah membuat elemen baru terlebih dahulu, lalu menghubungkan pointer `next` dari tail saat ini ke elemen baru tersebut, dan terakhir memperbarui posisi tail agar menunjuk ke elemen baru.

### 8.2.2 Delete (Dequeue)

Operasi Dequeue selalu dilakukan pada bagian **awal (head)** antrean. Langkah-langkahnya adalah menyimpan elemen head saat ini ke variabel penampung, memindahkan pointer head ke elemen berikutnya, memutuskan hubungan elemen yang dihapus dengan list (`next = Nil`), lalu mengembalikan elemen tersebut.

---

## 8.3 Primitif-Primitif dalam Queue

Primitif-primitif Queue disimpan dalam ADT (Abstract Data Type) yang terbagi ke dalam file `*.h` (header) dan `*.c` (implementasi). Primitif ini mencakup pengecekan kosong (`isEmpty`), pembuatan queue (`CreateQueue`), manajemen memori (`alokasi`, `dealokasi`), pencarian (`findElm`), penambahan (`insert`), penghapusan (`delete`), serta proses penampilan dan penghapusan seluruh elemen.

---

## 8.4 Queue (Representasi Tabel)

### 8.4.1 Pengertian

Representasi Queue menggunakan tabel (array) pada dasarnya sama dengan menggunakan pointer. Perbedaan utamanya terletak pada manajemen memori dan keterbatasan jumlah antrean. Pada representasi tabel, jumlah antrean terbatas dan tidak ada manajemen memori dinamis, sedangkan pada representasi pointer, jumlah antrean tak terbatas dan terdapat manajemen memori.

Terdapat tiga alternatif representasi tabel:

**A. Alternatif 1 (Head Diam, Tail Bergerak)**

Hanya indeks **TAIL** yang merepresentasikan elemen terakhir. **HEAD** selalu di-set sama dengan 1 jika Queue tidak kosong, dan `HEAD = 0` jika Queue kosong. Penambahan dilakukan dengan "memajukan" TAIL jika masih ada tempat. Penghapusan dilakukan dengan mengambil nilai elemen HEAD, menggeser semua elemen dari `HEAD+1` sampai `TAIL` satu langkah ke kiri, lalu TAIL "mundur". Cara ini mencerminkan pergeseran antrean di dunia nyata, tetapi **tidak efisien**.

**B. Alternatif 2 (Head Bergerak, Tail Bergerak)**

Baik **HEAD** maupun **TAIL** dapat bergerak. HEAD bergerak maju ketika elemen dihapus. Jika Queue kosong, `HEAD = 0`. Penambahan sama dengan Alternatif 1, yaitu "memajukan" TAIL. Penghapusan dilakukan dengan mengambil nilai elemen HEAD, lalu HEAD "maju". Algoritma ini efisien, tetapi dapat menimbulkan kondisi **"Queue penuh semu"**, yaitu saat TAIL sudah mencapai `IndexMax` padahal masih ada ruang kosong di depan. Solusinya adalah menggeser elemen ke depan hanya ketika TAIL mencapai `IndexMax`.

**C. Alternatif 3 (Circular Buffer)**

HEAD dan TAIL "berputar" mengelilingi indeks tabel. Jika TAIL atau HEAD mencapai `IdxMax`, maka indeks berikutnya (successor) adalah 1, bukan `IdxMax+1`. Representasi ini disebut **"circular buffer"**. Algoritma ini efisien karena tidak perlu melakukan pergeseran elemen seperti pada Alternatif 2. Salah satu variasinya adalah menggantikan representasi TAIL dengan **COUNT** (jumlah elemen), sehingga jumlah elemen diketahui secara eksplisit, tetapi penambahan elemen memerlukan kalkulasi TAIL.

### 8.4.2 Primitif-Primitif dalam Queue (Representasi Tabel)

Primitif-primitif pada Queue representasi tabel disimpan dalam ADT `queue.h`, mencakup operasi dasar seperti pembuatan queue kosong, pengecekan kosong/penuh, penambahan (`enqueue`), penghapusan (`dequeue`), dan penampilan informasi queue.



## Guided 1

### 1. Queue.h

```C++
/* File : queue.h
   Contoh ADT queue dengan representasi fisik pointer
   Representasi address dengan pointer
   Tipe info adalah integer */

#ifndef QUEUE_H_INCLUDE
#define QUEUE_H_INCLUDE

#include <iostream>
#define Nil NULL

typedef int infotype;
typedef struct elmQ *address;

struct elmQ {
    infotype info;
    address next;
};

/* Deklarasi tipe data queue, terdiri dari head dan tail, 
   queue kosong jika head = Nil */
struct queue {
    address head;
    address tail;
};

/* Prototype */

/********* Pengecekan apakah queue kosong ***********/
bool isEmpty(queue Q);
/* Mengembalikan nilai true jika queue kosong */

/********* Pembuatan queue kosong *********/
void CreateQueue(queue &Q);
/* I.S. sembarang
   F.S. terbentuk queue kosong */

/********* Manajemen memori *********/
address alokasi(infotype X);
/* Mengirimkan address dari alokasi elemen
   Jika alokasi berhasil, maka nilai address tidak Nil
   dan jika gagal, nilai address Nil */

void dealokasi(address P);
/* I.S. P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

/********* Pencarian sebuah elemen list *********/
address findElm(queue Q, infotype X);
/* Mencari apakah ada elemen queue dengan P->info = X
   Jika ada, mengembalikan address elemen tsb, dan Nil jika sebaliknya */

bool fFindElm(queue Q, address P);
/* Mencari apakah ada elemen queue dengan alamat P
   Mengembalikan true jika ada dan false jika tidak ada */

/********* Penambahan elemen **********/
void insert(queue &Q, address P);
/* I.S. sembarang, P sudah dialokasikan
   F.S. menempatkan elemen beralamat P pada akhir queue */

/********* Penghapusan sebuah elemen **********/
void del(queue &Q, address &P);
/* I.S. queue tidak kosong
   F.S. P menunjuk elemen pertama queue, head dari queue menunjuk pada 
        next elemen head yang lama. Queue mungkin menjadi kosong */

/********* Proses semua elemen queue **********/
void printInfo(queue Q);
/* I.S. queue mungkin tidak kosong
   F.S. jika queue tidak kosong, maka menampilkan semua info yang ada pada queue */

int nbList(queue Q);
/* Mengembalikan jumlah elemen pada queue */

void delAll(queue &Q);
/* Menghapus semua elemen pada queue dan semua elemen di-dealokasi */

#endif

```
File queue.h tersebut merupakan file header yang mendeklarasikan Abstract Data Type (ADT) Queue dengan representasi pointer (linked list) dan tipe data integer. Di dalamnya didefinisikan struktur elmQ sebagai node yang menyimpan info dan pointer next, tipe address sebagai pointer ke node tersebut, serta struktur queue yang terdiri dari head (elemen depan) dan tail (elemen belakang), di mana queue dianggap kosong jika head bernilai Nil. File ini juga memuat prototipe fungsi-fungsi dasar queue, yaitu pengecekan kosong (isEmpty), pembuatan queue kosong (CreateQueue), manajemen memori (alokasi dan dealokasi), pencarian elemen (findElm dan fFindElm), penambahan elemen di akhir (insert), pengambilan elemen di depan (del), serta fungsi untuk menampilkan seluruh info (printInfo), menghitung jumlah elemen (nbList), dan menghapus seluruh elemen beserta dealokasinya (delAll).


### 2. Queue.cpp

```C++
#include "queue.h"
using namespace std;

bool isEmpty(queue Q) {
    return (Q.head == Nil);
}

void CreateQueue(queue &Q) {
    Q.head = Nil;
    Q.tail = Nil;
}

address alokasi(infotype X) {
    address P = new (nothrow) elmQ;
    if (P != Nil) {
        P->info = X;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

address findElm(queue Q, infotype X) {
    address P = Q.head;
    while (P != Nil) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

bool fFindElm(queue Q, address P) {
    address R = Q.head;
    while (R != Nil) {
        if (R == P) {
            return true;
        }
        R = R->next;
    }
    return false;
}

void insert(queue &Q, address P) {
    if (P != Nil) {
        if (isEmpty(Q)) {
            Q.head = P;
            Q.tail = P;
        } else {
            (Q.tail)->next = P;
            Q.tail = P;
        }
    }
}

void del(queue &Q, address &P) {
    if (!isEmpty(Q)) {
        P = Q.head;
        if (Q.head == Q.tail) {
            Q.head = Nil;
            Q.tail = Nil;
        } else {
            Q.head = P->next;
        }
        P->next = Nil;
    } else {
        P = Nil;
    }
}

void printInfo(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
    } else {
        address P = Q.head;
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

int nbList(queue Q) {
    int jumlah = 0;
    address P = Q.head;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void delAll(queue &Q) {
    address P;
    while (!isEmpty(Q)) {
        del(Q, P);
        dealokasi(P);
    }
}

```
File queue.cpp tersebut merupakan implementasi dari prototipe yang dideklarasikan di queue.h, berisi definisi fungsi-fungsi ADT Queue dengan representasi pointer. Fungsi isEmpty mengecek apakah head bernilai Nil. CreateQueue menginisialisasi queue kosong dengan head dan tail bernilai Nil. alokasi membuat node baru menggunakan new (nothrow) dan mengisi info serta next, sedangkan dealokasi menghapus node dari memori. findElm mencari elemen berdasarkan nilai info dan mengembalikan address-nya, sementara fFindElm memeriksa keberadaan elemen berdasarkan address tertentu. insert menambahkan elemen di belakang (tail), dengan penanganan khusus jika queue masih kosong. del mengambil elemen depan (head) ke variabel P, menangani kasus queue berisi satu elemen maupun lebih, dan mengembalikan Nil jika queue kosong. printInfo menampilkan seluruh info elemen atau pesan "Queue kosong". nbList menghitung jumlah elemen, dan delAll menghapus seluruh elemen satu per satu sekaligus mendealokasinya hingga queue kosong.

### 3. Main.cpp

```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    queue Q;
    address P;

    CreateQueue(Q);
    cout << "IsEmpty : " << isEmpty(Q) << endl;
    printInfo(Q);

    insert(Q, alokasi(5));
    insert(Q, alokasi(2));
    insert(Q, alokasi(7));
    cout << "Setelah insert 5, 2, 7" << endl;
    printInfo(Q);
    cout << "nbList : " << nbList(Q) << endl;

    P = findElm(Q, 2);
    if (P != Nil) {
        cout << "findElm(2) ketemu, info = " << P->info << endl;
        cout << "fFindElm : " << fFindElm(Q, P) << endl;
    }
    if (findElm(Q, 9) == Nil) {
        cout << "findElm(9) tidak ketemu" << endl;
    }

    del(Q, P);
    cout << "Setelah delete, Elemen yang keluar = " << P->info << endl;
    dealokasi(P);
    printInfo(Q);

    delAll(Q);
    cout << "Setelah delAll" << endl;
    printInfo(Q);
    cout << "IsEmpty : " << isEmpty(Q) << endl;

    return 0;
}

```
File main.cpp tersebut merupakan program utama yang menguji seluruh fungsi ADT Queue yang telah diimplementasikan. Program dimulai dengan mendeklarasikan variabel Q bertipe queue dan P bertipe address, lalu memanggil CreateQueue(Q) untuk membentuk queue kosong. Selanjutnya program menampilkan status isEmpty dan isi queue melalui printInfo. Kemudian tiga elemen dengan nilai 5, 2, dan 7 disisipkan menggunakan insert dan alokasi, lalu ditampilkan isi queue beserta jumlah elemennya melalui nbList. Program kemudian menguji fungsi pencarian: findElm(Q, 2) untuk mencari elemen bernilai 2 dan menampilkan info serta hasil fFindElm, lalu findElm(Q, 9) untuk memastikan elemen bernilai 9 tidak ditemukan. Setelah itu, del(Q, P) dipanggil untuk mengambil elemen depan, menampilkan nilai elemen yang keluar, lalu dealokasi(P) membebaskan memori elemen tersebut, dan printInfo menampilkan sisa queue. Terakhir, delAll(Q) menghapus seluruh elemen, dilanjutkan pengecekan printInfo dan isEmpty untuk memastikan queue benar-benar kosong.

## Guided 2

### 1. Queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```
File `queue.h` tersebut merupakan file header yang mendeklarasikan ADT Queue dengan representasi **tabel (array)** menggunakan tipe data `string` sebagai isi elemennya. Di dalamnya didefinisikan konstanta `MAKSIMAL = 5` yang membatasi kapasitas maksimum queue, serta struktur `queue` yang berisi array `nama` berukuran 5 untuk menyimpan data, `head` sebagai indeks elemen depan, dan `tail` sebagai indeks elemen belakang. File ini juga memuat prototipe fungsi-fungsi dasar queue, yaitu `isFull` untuk mengecek apakah queue penuh, `isEmpty` untuk mengecek apakah queue kosong, `CreateQueue` untuk membentuk queue kosong, `enQueue` untuk menambahkan elemen di belakang, `deQueue` untuk mengambil elemen di depan, dan `viewQueue` untuk menampilkan seluruh isi queue.

### 2. Queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```
File `queue.cpp` tersebut merupakan implementasi ADT Queue dengan representasi tabel (array) yang menyediakan tiga alternatif mekanisme, di mana kode aktif menggunakan **Implementasi 1 (head diam, tail bergerak)**. Fungsi `isEmpty` mengecek queue kosong dengan kondisi `head == -1` dan `tail == -1`, sedangkan `isFull` mengecek apakah `tail` sudah mencapai `MAKSIMAL - 1`. `CreateQueue` menginisialisasi `head` dan `tail` menjadi -1. `enQueue` menambahkan elemen di belakang: jika queue kosong, `head` dan `tail` diset 0; jika tidak, `tail` bertambah, lalu data disimpan pada indeks `tail`. `deQueue` mengambil elemen depan dengan menggeser seluruh elemen satu langkah ke kiri (dari indeks 0 hingga `tail`), lalu `tail` berkurang; jika `tail` menjadi negatif, `head` dan `tail` di-reset ke -1. `viewQueue` menampilkan seluruh elemen dari `head` hingga `tail` dengan penomoran urut. Kode juga menyertakan versi komentar untuk Implementasi 2 (head dan tail bergerak) dan Implementasi 3 (circular buffer), yang dapat diaktifkan dengan menukar bagian kode yang dikomentari.

### 3. Main.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "Dimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
File `main.cpp` tersebut merupakan program utama untuk menguji ADT Queue representasi tabel yang telah diimplementasikan. Program dimulai dengan mendeklarasikan variabel `Q` bertipe `queue` dan memanggil `CreateQueue(Q)` untuk membentuk queue kosong. Selanjutnya, lima nama (Dimas, Arvin, Rizal, Hafizh, Fathur) dimasukkan melalui `enQueue`, dan percobaan keenam dengan nama "Daffa" akan gagal karena kapasitas maksimum (`MAKSIMAL = 5`) telah tercapai, sehingga muncul pesan "Queue sudah penuh". Setelah itu, `viewQueue` menampilkan seluruh isi queue. Program kemudian memanggil `deQueue` sebanyak empat kali untuk mengeluarkan empat elemen terdepan, dan `viewQueue` kembali menampilkan sisa queue. Dua baris `deQueue` terakhir dikomentari, sehingga tidak dieksekusi. Program ini menguji mekanisme **Implementasi 1** (head diam, tail bergerak), di mana setiap `deQueue` menggeser seluruh elemen ke kiri dan mengurangi `tail`.

## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”: 
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme 
queue Alternatif 1 (head diam, tail bergerak).

```C++
// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

#define MAX_SIZE 5

typedef int infotype;

struct Queue {
    infotype info[MAX_SIZE];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
```C++
// queue.cpp
#include "queue.h"

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);                 // SOAL 1: Cek kosong
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_SIZE - 1);                       // SOAL 1: Cek tail mentok
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;                                      // SOAL 1: Tail bergerak maju
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x;
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong!" << endl;
        return -1;
    } else {
        x = Q.info[Q.head];
        
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            for (int i = Q.head; i < Q.tail; i++) {        // SOAL 1: Geser elemen ke kiri
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;                                      // SOAL 1: Tail mundur
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {           // SOAL 1: Cetak dari head ke tail
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
```C++
// main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);

    cout << "------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "------------------" << endl;
    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    
    enqueue(Q, 4); printInfo(Q);
    
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul%208/Unguided%201%20Output-8-1.jpg.png

Baik, berikut adalah **revisi penjelasan singkat untuk Soal Nomor 1** yang sudah disesuaikan dengan kode terbaru (menggunakan mekanisme **Alternatif 1 murni**, di mana Head tetap diam di indeks 0 dan elemen digeser ke kiri saat dihapus):

**Penjelasan Singkat Soal 1:**
Soal 1 meminta kita membuat antrean (Queue) dengan prinsip FIFO menggunakan Array. Mekanisme yang diterapkan adalah **Alternatif 1**, di mana posisi `Head` selalu diam di indeks 0 dan `Tail` bergerak. Saat terjadi proses `dequeue` (penghapusan), semua elemen yang tersisa akan **digeser ke kiri** untuk mengisi kekosongan, sehingga `Tail` akan mundur.

**Alur Kode:**
*   **`queue.h`**: Mendefinisikan struct `Queue` (array `info` berukuran 5, `head`, dan `tail`) beserta prototipe fungsinya.
*   **`queue.cpp`**:
    *   `enqueue`: Menambah data di belakang dengan memajukan `tail`.
    *   `dequeue`: Mengambil data paling depan, lalu melakukan *looping* untuk menggeser semua elemen ke kiri, dan memundurkan `tail`. Jika antrean habis, `head` dan `tail` di-reset ke `-1`.
    *   `printInfo`: Mencetak nilai `H` (Head), `T` (Tail), dan isi antrean sesuai format gambar.
*   **`main.cpp`**: Menjalankan skenario uji coba (tambah 5, 2, 7 → hapus 5 → hapus 2 → tambah 4 → hapus 7 → hapus 4) untuk menghasilkan output yang persis sama dengan Gambar 8-17.


### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme 
queue Alternatif 2 (head bergerak, tail bergerak).

```C++
// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

#define MAX_SIZE 5

typedef int infotype;

struct Queue {
    infotype info[MAX_SIZE];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
```C++
// queue.cpp
#include "queue.h"

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);                                 // SOAL 2: Cek kosong
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_SIZE - 1);                       // SOAL 2: Cek tail mentok
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        if (Q.head > 0) {                                  // SOAL 2: Cek penuh semu
            int count = Q.tail - Q.head + 1;
            for (int i = 0; i < count; i++) {
                Q.info[i] = Q.info[Q.head + i];            // SOAL 2: Kompaksi (geser ke depan)
            }
            Q.head = 0;
            Q.tail = count - 1;
        } else {
            cout << "Queue Penuh!" << endl;                // SOAL 2: Benar-benar penuh
            return;
        }
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;                                          // SOAL 2: Tail bergerak maju
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong!" << endl;
        return -1;
    }
    
    infotype x = Q.info[Q.head];
    
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;                                          // SOAL 2: Head bergerak maju
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {           // SOAL 2: Cetak lurus (head ke tail)
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
```C++
// main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);

    cout << "------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "------------------" << endl;
    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    
    dequeue(Q);    printInfo(Q);
    
    enqueue(Q, 4); printInfo(Q);
    
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul%208/Unguided%202%20Output-8-1.jpg.png

Soal 2 meminta implementasi Queue menggunakan Array dengan mekanisme Alternatif 2 (Head bergerak, Tail bergerak). Berbeda dengan Alternatif 1, saat terjadi penghapusan (dequeue), posisi Head akan bergerak maju tanpa perlu menggeser elemen-elemen yang tersisa. Hal ini membuat proses penghapusan menjadi lebih efisien.

Alur Kode:

queue.h: Mendefinisikan struct Queue (array info berukuran 5, head, dan tail) beserta prototipe fungsinya.

queue.cpp:

enqueue: Menambah data di belakang dengan memajukan tail. Jika tail sudah mencapai ujung array tetapi masih ada ruang kosong di depan (karena Head sudah maju), fungsi ini akan melakukan kompaksi (menggeser semua elemen ke depan/indeks 0) agar data baru bisa masuk.

dequeue: Mengambil data paling depan dan memajukan head (Q.head++). Jika antrean habis, head dan tail di-reset ke -1.

printInfo: Mencetak nilai H, T, dan isi antrean dari indeks head sampai tail.

main.cpp: Menjalankan skenario uji coba yang sama (tambah 5, 2, 7 → hapus 1 → tambah 4 → hapus 2) untuk melihat pergerakan Head dan Tail.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme 
queue Alternatif 3 (head dan tail berputar).

```C++
// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

#define MAX_SIZE 5

typedef int infotype;

struct Queue {
    infotype info[MAX_SIZE];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
```C++
// queue.cpp
#include "queue.h"

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);                                // SOAL 3: Cek kosong
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX_SIZE == Q.head);           // SOAL 3: Cek penuh (sisa 1 slot)
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAX_SIZE;             // SOAL 3: Tail berputar (modulo)
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong!" << endl;
        return -1;
    }
    
    infotype x = Q.info[Q.head];
    
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX_SIZE;                 // SOAL 3: Head berputar (modulo)
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {                                    // SOAL 3: Iterasi melingkar
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % MAX_SIZE;                       // SOAL 3: Indeks berputar
        }
    }
    cout << endl;
}
```
```C++
// main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);

    cout << "------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "------------------" << endl;
    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    
    dequeue(Q);    printInfo(Q);
    
    enqueue(Q, 4); printInfo(Q);
    
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul%208/Unguided%203%20Output-8-1.jpg.png

Soal 3 meminta implementasi Queue menggunakan Array dengan mekanisme Alternatif 3 (Head dan Tail Berputar / Circular Buffer). Ini adalah metode paling efisien karena tidak memerlukan proses penggeseran elemen (baik menggeser ke kiri maupun kompaksi). Jika posisi head atau tail mencapai indeks terakhir array, posisi berikutnya akan berputar kembali ke indeks 0.

Alur Kode:

queue.h: Mendefinisikan struct Queue (array info berukuran 5, head, dan tail) beserta prototipe fungsinya.

queue.cpp:

enqueue: Menambah data di belakang. Jika tail mencapai batas akhir array, ia akan berputar ke awal menggunakan rumus modulo (Q.tail + 1) % MAX_SIZE.

dequeue: Mengambil data dari depan. Jika head mencapai batas akhir, ia juga berputar ke awal menggunakan rumus (Q.head + 1) % MAX_SIZE.

isFullQueue: Mengecek apakah slot berikutnya dari tail (jika diputar) posisinya sama dengan head. Jika iya, antrean dianggap penuh.

printInfo: Mencetak antrean secara melingkar, dimulai dari head dan berhenti saat mencapai tail.

main.cpp: Menjalankan skenario standar (tambah 5, 2, 7 → hapus 1 → tambah 4 → hapus 2) untuk membuktikan bahwa antrean berjalan dengan baik.
## Kesimpulan

Berdasarkan praktikum Modul 8 mengenai struktur data Queue (Antrean), dapat disimpulkan beberapa hal sebagai berikut:

1. **Konsep Dasar Queue:** Queue adalah struktur data linier yang menerapkan prinsip **FIFO (*First In First Out*)**, di mana elemen yang pertama kali dimasukkan akan menjadi elemen yang pertama kali dikeluarkan. Operasi utamanya terdiri dari `enqueue` (penambahan di bagian belakang/tail) dan `dequeue` (penghapusan di bagian depan/head).

2. **Implementasi Menggunakan Linked List (Pointer):** Pada Guided 1, Queue diimplementasikan menggunakan *Singly Linked List*. Metode ini sangat fleksibel dan dinamis karena ukuran antrean tidak terbatas (sesuai ketersediaan memori). Proses `insert` selalu dilakukan di `tail` dan `del` dilakukan di `head`, dengan manajemen memori menggunakan fungsi `alokasi` dan `dealokasi`.

3. **Implementasi Menggunakan Array (Tabel):** Pada Guided 2 dan Unguided, Queue diimplementasikan menggunakan Array yang memiliki kapasitas terbatas (statis). Terdapat tiga alternatif mekanisme yang dipelajari:
    *   **Alternatif 1 (Head Diam, Tail Bergerak):** Posisi `head` selalu tetap di indeks 0. Saat terjadi `dequeue`, seluruh elemen sisa harus digeser ke kiri. Metode ini mudah dipahami dan mencerminkan antrean di dunia nyata, namun **kurang efisien** karena membutuhkan waktu komputasi lebih untuk proses penggeseran elemen.
    *   **Alternatif 2 (Head Bergerak, Tail Bergerak):** Baik `head` maupun `tail` dapat bergerak maju. Saat `dequeue`, `head` maju tanpa menggeser elemen. Metode ini lebih efisien, namun dapat menimbulkan kondisi **"penuh semu"** (tail mentok di ujung array padahal di depan masih ada ruang kosong). Solusinya adalah dengan melakukan **kompaksi** (menggeser elemen ke depan) saat akan menambah data baru.
    *   **Alternatif 3 (Head dan Tail Berputar / *Circular Buffer*):** Merupakan metode **paling efisien** di antara ketiganya. Jika `head` atau `tail` mencapai indeks maksimal, posisi berikutnya akan berputar kembali ke indeks 0 menggunakan operasi modulo (`%`). Metode ini tidak memerlukan proses penggeseran elemen sama sekali, sehingga waktu eksekusi operasi `enqueue` dan `dequeue` menjadi konstan dan cepat.

4. **Pemilihan Metode:** Pemilihan antara representasi *pointer* (linked list) dan *tabel* (array), serta pemilihan alternatif mekanismenya, sangat bergantung pada kebutuhan program. Jika ukuran data dinamis dan tidak diketahui, *linked list* lebih tepat. Jika ukuran data sudah pasti dan membutuhkan akses cepat, *Circular Buffer* (Alternatif 3) pada array adalah pilihan terbaik.

## Referensi

[1] Triase. (2020). *Diktat Edisi Revisi: STRUKTUR DATA*. Medan: Universitas Islam Negeri Sumatera Utara Medan.

[2] Indahyati, Uce., & Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.

[3] Malik, D. S. (2018). *C++ Programming: From Problem Analysis to Program Design* (8th ed.). Boston: Cengage Learning.

[4] Karumanchi, N. (2016). *Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles* (5th ed.). CareerMonk Publications.

[5] Modul Praktikum Struktur Data. (2024). *Modul 8: QUEUE (Antrean)*. Program Studi Informatika, Fakultas Informatika, Universitas Telkom.
