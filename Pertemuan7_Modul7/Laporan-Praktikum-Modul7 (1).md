# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori

### A. Stack<br/>
Stack merupakan salah satu bentuk struktur data yang prinsip operasinya seperti tumpukan [1].
#### 1. Pengertian Stack
Seperti halnya tumpukan, elemen yang bisa diambil terlebih dahulu adalah elemen yang paling atas, yaitu elemen yang terakhir kali masuk. Prinsip ini biasa disebut LIFO (Last In First Out) [1].
#### 2. Komponen Stack
Komponen-komponen pada stack pada dasarnya sama dengan komponen pada singly linked list, hanya saja akses pada stack cuma bisa dilakukan di awal stack. Di stack cuma ada satu komponen utama buat mengakses data, yaitu elemen paling awal yang disebut `Top` [1]. Elemennya dibuat pakai `struct elmStack` yang isinya `info` dan `next`, sedangkan stack-nya dibuat pakai `struct stack` yang isinya `Top` [1].
#### 3. Operasi Push dan Pop
Di stack ada dua operasi utama, yaitu push (penyisipan) dan pop (pengambilan) [1]. Push mirip insert first pada list biasa, caranya `P = alokasi(X);`, `P->next = Nil;`, `P->next = S.Top;`, lalu `S.Top = P;`. Pop mirip delete first pada list linear, caranya `P = S.Top;`, lalu `S.Top = (S.Top)->next;`, dan elemen `P` dikembalikan [1].

### B. Stack Representasi Tabel<br/>
Pada prinsipnya representasi stack pakai tabel sama kayak pakai pointer. Bedanya ada di pendeklarasian struktur datanya, yaitu pakai array berindeks dan jumlah tumpukannya terbatas [1].
#### 1. Struktur Stack Representasi Tabel
Stack punya indeks maksimum `Imax` (misalnya 10), dan stack dianggap kosong kalau `Top = 0` [1]. Datanya disimpan di array `info`, dan `Top` dipakai buat nunjukin posisi data paling atas.
#### 2. Push dan Pop pada Representasi Tabel
Push menyisipkan data dengan menggeser indeks `Top` ke indeks berikutnya, yaitu `Top = Top + 1`, lalu data disimpan di posisi `Top`. Pop mengambil data di indeks `Top`, caranya `Temp = S.Info[TOP]` lalu `TOP = TOP - 1`. Info di indeks `Top` sebelumnya nggak dihilangkan, cuma `Top`-nya yang bergeser [1].
#### 3. Primitif pada Stack
Primitif pada stack di antaranya `createStack()`, `isEmpty()`, `alokasi()`, `dealokasi()`, fungsi pencarian, dan fungsi primitif lainnya. Primitif stack lebih sedikit dibanding list lain karena operasinya cuma dilakukan terhadap elemen paling atas. Di representasi tabel nggak diperlukan manajemen memori (`alokasi()` dan `dealokasi()`), dan primitifnya disimpan di file `.h` dan `.cpp` [1].

## Guided 

### 1. File Header (stack.h)

```C++
/* file : stack.h
   contoh ADT stack dengan representasi tabel */
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype {
    char nim[20];
    char nama[20];
};
struct Stack {
    infotype info[10];
    int Top;
};

/* prototype */
/******** pengecekan apakah Stack kosong *********/
int isEmpty(Stack S);
/* mengembalikan nilai 0 jika stack kosong */

/******** pembuatan Stack ********/
void createStack(Stack &S);
/* I.S. sembarang
   F.S. terbentuk stack dengan Top=0 */

/******** penambahan elemen pada Stack ********/
void push(Stack &S, infotype X);
/* I.S. Stack mungkin kosong
   F.S. menambahkan elemen pada stack dengan nilai X, TOP=TOP+1 */

/******** penghapusan elemen pada Stack ********/
void pop(Stack &S, infotype &X);
/* I.S. stack tidak kosong
   F.S. nilai info pada indeks TOP disimpan pada X, kemudian TOP=TOP-1 */

/******** proses semua elemen Stack *********/
void viewStack(Stack S);
/* I.S. stack mungkin kosong
   F.S. jika stack tidak kosong menampilkan semua info yang ada pada stack
*/
#endif // STACK_H_INCLUDED
```
File ini adalah header-nya, isinya definisi type dan prototype semua fungsi dan prosedur stack. `#ifndef STACK_H_INCLUDED`, `#define STACK_H_INCLUDED`, dan `#endif` adalah header guard supaya file ini nggak ke-include lebih dari sekali. `struct infotype` isinya nim dan nama (masing-masing array char 20) yang jadi data tiap elemen stack. `struct Stack` punya `info`, yaitu array 10 elemen bertipe `infotype` buat nyimpen data, dan `Top`, yaitu penanda posisi data paling atas. Ini representasi tabel (array), jadi jumlah datanya terbatas maksimal 10. Di bawahnya ada prototype `isEmpty` (ngembaliin 0 kalau stack kosong), `createStack` (bikin stack dengan `Top = 0`), `push` (nambah data), `pop` (ngambil data, hasilnya disimpan di parameter `X` yang dikirim pakai `&`), dan `viewStack` (nampilin isi stack). Tiap prototype ada komentar I.S. (initial state) dan F.S. (final state) yang jelasin kondisi sebelum dan sesudah prosedur dijalankan.

### 2. File Body (stack.cpp)

```C++
#include "stack.h"

int isEmpty(Stack S) {
    /* Top = 0 berarti kosong, sesuai komentar di stack.h dikembalikan 0 */
    if (S.Top == 0) {
        return 0;
    } else {
        return 1;
    }
}

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype X) {
    if (S.Top < 10) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = X;   /* Top 1..10 dipetakan ke indeks array 0..9 */
    } else {
        cout << "Stack penuh, data tidak bisa ditambahkan" << endl;
    }
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S) != 0) {
        X = S.info[S.Top - 1];
        S.Top = S.Top - 1;
    } else {
        cout << "Stack kosong, tidak ada data yang bisa diambil" << endl;
    }
}

void viewStack(Stack S) {
    if (isEmpty(S) == 0) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "Isi stack (dari TOP):" << endl;
        for (int i = S.Top; i >= 1; i--) {
            cout << i << ". " << S.info[i - 1].nim << " - "
                 << S.info[i - 1].nama << endl;
        }
    }
}
```
File ini isinya realisasi dari semua prototype di `stack.h`, makanya di atas ada `#include "stack.h"`. `isEmpty()` ngecek `Top == 0`, kalau iya dikembalikan 0 (kosong) dan kalau nggak dikembalikan 1, jadi nilainya kebalikan dari biasanya, sesuai komentar di `stack.h`. `createStack()` ngisi `Top` dengan 0. `push()` ngecek dulu stack belum penuh (`Top < 10`), kalau belum `Top` ditambah 1 lalu data disimpan di `info[Top - 1]` karena `Top` mulai dari 1 sedangkan indeks array mulai dari 0, dan kalau udah penuh muncul pesan "Stack penuh". `pop()` ngecek stack nggak kosong lewat `isEmpty(S) != 0`, kalau nggak kosong data di `info[Top - 1]` disimpan ke `X` terus `Top` dikurangi 1, dan kalau kosong muncul pesan. `viewStack()` nampilin pesan "Stack kosong" kalau stack kosong, kalau nggak ia nampilin isi stack dari `Top` turun sampai 1 lengkap dengan nomor, nim, dan nama.

### 3. File Driver (main.cpp)

```C++
#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    infotype data, hasil;

    createStack(S);
    cout << "Stack baru dibuat, Top = " << S.Top << endl;
    viewStack(S);

    cout << endl << "--- Push 3 data ---" << endl;
    strcpy(data.nim, "103112400001");
    strcpy(data.nama, "Andi");
    push(S, data);

    strcpy(data.nim, "103112400002");
    strcpy(data.nama, "Budi");
    push(S, data);

    strcpy(data.nim, "103112400003");
    strcpy(data.nama, "Citra");
    push(S, data);
    viewStack(S);

    cout << endl << "--- Pop 1 data ---" << endl;
    pop(S, hasil);
    cout << "Data yang diambil: " << hasil.nim << " - " << hasil.nama << endl;
    viewStack(S);

    cout << endl << "--- Pop sampai kosong ---" << endl;
    pop(S, hasil);
    pop(S, hasil);
    pop(S, hasil);
    viewStack(S);

    return 0;
}
```
File ini program utamanya. Pertama stack dibuat lewat `createStack()` dan `Top`-nya ditampilin (0), terus `viewStack()` nampilin "Stack kosong". Setelah itu 3 data dimasukin pakai `push()`, yaitu Andi, Budi, dan Citra. Karena `nim` dan `nama` berupa array char, isinya diisi pakai `strcpy()` (makanya ada `#include <cstring>`), nggak bisa pakai `=`. Waktu `viewStack()` dipanggil, urutan yang tampil dari TOP, jadi Citra paling atas lalu Budi lalu Andi. Terus `pop()` dipanggil sekali, yang keambil Citra karena paling atas (LIFO), dan datanya ditampilin dari variabel `hasil`. Terakhir `pop()` dipanggil 3 kali padahal data tinggal 2, jadi dua data pertama keambil (Budi lalu Andi) dan pada pemanggilan ketiga muncul pesan "Stack kosong, tidak ada data yang bisa diambil", lalu `viewStack()` nampilin "Stack kosong". Karena programnya kepisah jadi dua file .cpp, ngecompile-nya harus nyertain dua-duanya, yaitu `g++ main.cpp stack.cpp -o main`.

## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file "stack.h" (Type infotype : integer, Type Stack < info : array [20] of integer, top : integer >, procedure CreateStack( input/output S : Stack ), procedure push( input/output S : Stack, input x : infotype ), function pop( input/output S : Stack ) → infotype, procedure printInfo( input S : Stack ), procedure balikStack( input/output S : Stack )). Buatlah implementasi ADT Stack menggunakan Array pada file "stack.cpp" dan "main.cpp" (push 3, 4, 8, pop, push 2, 3, pop, push 9, lalu printInfo, balikStack, dan printInfo lagi)

```C++
// stack.h
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif // STACK_H_INCLUDED

// stack.cpp
#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.info[S.top] = x;
        S.top++;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top > 0) {
        S.top--;
        return S.info[S.top];
    }
    cout << "Stack kosong" << endl;
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    for (int i = 0; i < S.top / 2; i++) {
        infotype temp = S.info[i];
        S.info[i] = S.info[S.top - 1 - i];
        S.info[S.top - 1 - i] = temp;
    }
}

// main.cpp
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/Pertemuan7_Modul7/Output-Unguided1-1.png

Soal ini bikin ADT stack pakai array, dipisah jadi tiga file kayak di Modul 3, yaitu `stack.h` buat type dan header prosedur, `stack.cpp` buat isinya, dan `main.cpp` buat program utamanya. Stack-nya berupa `struct Stack` yang punya `info` (array 20 integer) dan `top` yang nyimpen banyaknya data, jadi `top = 0` artinya stack kosong, sama kayak di guided. `createStack()` ngisi `top` dengan 0. `push()` nyimpen data di `info[top]` lalu `top` ditambah 1, dan kalau udah 20 data muncul "Stack penuh". `pop()` ngurangin `top` dulu lalu ngembaliin `info[top]`, jadi yang diambil selalu data paling atas (LIFO). `pop()` dibuat sebagai function karena data yang diambil harus di-return, dan kalau stack kosong muncul "Stack kosong". `printInfo()` nampilin isi dari atas ke bawah. Data yang masuk 3, 4, 8 lalu 8 diambil, masuk 2, 3 lalu 3 diambil, terus masuk 9, jadi isi stack-nya 3, 4, 2, 9 dan yang tampil dari TOP adalah 9 2 4 3. `balikStack()` nuker isi array dari ujung ke ujung (elemen pertama dengan terakhir, kedua dengan sebelum terakhir, dan seterusnya) pakai variabel `temp`, jadi setelah dibalik tampil 3 4 2 9.

### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer )

```C++
// stack.h
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
void pushAscending(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif // STACK_H_INCLUDED

// stack.cpp
#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.info[S.top] = x;
        S.top++;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top > 0) {
        S.top--;
        return S.info[S.top];
    }
    cout << "Stack kosong" << endl;
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    for (int i = 0; i < S.top / 2; i++) {
        infotype temp = S.info[i];
        S.info[i] = S.info[S.top - 1 - i];
        S.info[S.top - 1 - i] = temp;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (S.top < 20) {
        int i = S.top - 1;
        while (i >= 0 && S.info[i] > x) {
            S.info[i + 1] = S.info[i];
            i--;
        }
        S.info[i + 1] = x;
        S.top++;
    } else {
        cout << "Stack penuh" << endl;
    }
}

// main.cpp
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/Pertemuan7_Modul7/Output-Unguided2-1.png

Soal ini nambah prosedur `pushAscending()` ke ADT yang dibuat di soal 1. Prosedur ini masukin data ke tempat yang pas supaya isi stack selalu urut, yang paling kecil di bawah dan paling besar di TOP. Caranya, mulai dari data paling atas, tiap data yang lebih besar dari `x` digeser satu posisi ke atas pakai `while`, terus `x` ditaruh di tempat yang kosong dan `top` ditambah 1. Dengan data 3, 4, 8, 2, 3, 9, hasilnya dari TOP adalah 9 8 4 3 3 2, dan setelah `balikStack()` jadi 2 3 3 4 8 9.

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

```C++
// stack.h
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif // STACK_H_INCLUDED

// stack.cpp
#include "stack.h"

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.info[S.top] = x;
        S.top++;
    } else {
        cout << "Stack penuh" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top > 0) {
        S.top--;
        return S.info[S.top];
    }
    cout << "Stack kosong" << endl;
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    for (int i = 0; i < S.top / 2; i++) {
        infotype temp = S.info[i];
        S.info[i] = S.info[S.top - 1 - i];
        S.info[S.top - 1 - i] = temp;
    }
}

void getInputStream(Stack &S) {
    char c;
    while (cin.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            push(S, c - '0');
        }
    }
}

// main.cpp
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/Pertemuan7_Modul7/Output-Unguided3-1.png

Soal ini nambah prosedur `getInputStream()` ke ADT yang dibuat di soal 1. Prosedur ini baca input user karakter demi karakter pakai `cin.get(c)` dan berhenti kalau yang dibaca adalah tombol enter (`'\n'`). Tiap karakter angka diubah jadi angka aslinya lewat `c - '0'` terus di-`push()` ke stack, sedangkan karakter selain angka dilewati. Kalau user ngetik 4729601 lalu enter, isi stack dari TOP jadi 1 0 6 9 2 7 4, dan setelah `balikStack()` jadi 4 7 2 9 6 0 1.

## Kesimpulan
Dari praktikum modul 7 ini bisa disimpulkan kalau stack adalah struktur data yang cara kerjanya kayak tumpukan dengan prinsip LIFO (Last In First Out), jadi data yang diambil duluan adalah data paling atas yang terakhir masuk. Operasi utamanya ada push buat nambah data dan pop buat ngambil data, dan semuanya dilakukan di bagian TOP aja. Stack bisa dibuat pakai pointer, yang mirip singly linked list dengan insert first dan delete first, atau pakai tabel (array) yang jumlah datanya terbatas dan posisi paling atasnya dicatat di `Top`. Dengan array, operasi tambahan seperti membalik isi stack, memasukkan data secara urut, dan membaca input per karakter juga bisa dilakukan. Semua latihan sudah bisa dibuat dan hasilnya sama dengan output yang diharapkan di soal.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
