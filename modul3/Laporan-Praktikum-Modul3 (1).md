# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Jahraa Syarifah N.S - 109082500099</p>

## Dasar Teori

### A. Abstract Data Type (ADT)<br/>
Abstract Data Type atau ADT adalah cara mendefinisikan sebuah tipe data beserta operasi-operasi dasarnya dalam satu kesatuan [3].

#### 1. Pengertian ADT
ADT adalah TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Di ADT yang lengkap, biasanya disertakan juga definisi invarian dari TYPE dan aksioma yang berlaku. ADT merupakan definisi yang STATIK [3].

#### 2. Type dan Primitif
Type pada ADT diterjemahkan jadi type bentukan di bahasa yang dipakai, kalau di C/C++ berarti `struct`. Sedangkan primitif dalam konteks prosedural diterjemahkan jadi fungsi atau prosedur. Type di dalam ADT juga boleh mengandung ADT lain, contohnya ADT waktu yang terdiri dari ADT jam dan ADT date, atau garis yang terdiri dari dua buah ADT point [3].

#### 3. Pengelompokan Primitif
Primitif dikelompokkan jadi beberapa macam [3]:
- Konstruktor/kreator, buat membentuk nilai type. Namanya biasanya diawali `Make` atau `create`.
- Selector, buat mengakses komponen type (biasanya diawali `Get`).
- Prosedur pengubah nilai komponen (biasanya diawali `Set`).
- Validator komponen, buat ngecek apakah nilai yang dimasukkan sesuai batasan.
- Destruktor/dealokator, buat "menghancurkan" objek sekaligus memori penyimpanannya.
- Baca/tulis, buat interface dengan perangkat input/output.
- Operator relasional, buat membandingkan type (lebih besar, lebih kecil, sama dengan, dst).
- Aritmatika dan konversi dari type tersebut ke tipe dasar atau sebaliknya.

### B. Implementasi ADT<br/>
ADT biasanya diimplementasikan jadi dua modul utama dan satu modul driver (program utama) [3].

#### 1. File Header (.h)
Isinya definisi/spesifikasi type dan header dari primitif (nama fungsi/prosedur beserta parameternya). Supaya nggak ke-include dua kali, file header diberi `#ifndef`, `#define`, dan `#endif` [3].

#### 2. File Body/Realisasi (.cpp)
Isinya kode dari primitif yang dideklarasikan di header. File ini harus meng-include file header-nya [3].

#### 3. File Driver (main.cpp)
Isinya program utama yang menjalankan ADT tadi. Di sini file header di-include lalu primitifnya dipanggil [3].

## Guided 

### 1. File Header (mahasiswa.h)

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
struct mahasiswa {
    char nim [10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);
#endif // MAHASISWA_H_INCLUDED
```
File ini isinya definisi type dan header primitif dari ADT mahasiswa. Type-nya berupa `struct mahasiswa` dengan tiga field, yaitu `nim` (array char 10), `nilai1`, dan `nilai2`. Di bawahnya ada deklarasi dua primitif. `inputMhs()` buat ngisi data mahasiswa, parameternya pakai `&` (call by reference) supaya nilai yang diinput kesimpan ke variabel aslinya di `main`. `rata2()` buat ngitung rata-rata, parameternya biasa aja karena cuma dibaca, nggak diubah. Baris `#ifndef`, `#define`, dan `#endif` dipakai biar file header ini nggak ke-include dua kali dan bikin error.

### 2. File Body (mahasiswa.cpp)

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs (mahasiswa &m) {
    cout << "input nim = " ;
    cin >> (m).nim;
    cout << "input nilai1 = " ;
    cin >> (m).nilai1;
    cout << "input nilai2 = " ;
    cin >> (m).nilai2;
}

float rata2 (mahasiswa m) {
    return ((m).nilai1 + (m).nilai2)/2.0;
}
```
File ini isinya realisasi dari dua primitif yang tadi dideklarasiin di `mahasiswa.h`. Makanya di atas ada `#include "mahasiswa.h"`, pakai tanda kutip ganda karena itu file buatan sendiri, bukan library bawaan kayak `<iostream>`. Di `inputMhs()`, program minta input nim, nilai1, dan nilai2 lewat `cin`, terus disimpan ke field `m`. Penulisan `(m).nim` artinya sama aja dengan `m.nim`. Di `rata2()`, nilai1 dan nilai2 dijumlah terus dibagi `2.0`, bukan `2`, supaya hasilnya tetap desimal. Kalau dibagi 2 biasa, hasilnya dibulatkan karena sama-sama int, misal 82.5 jadi 82.

### 3. File Driver (main.cpp)

```C++
#include  <iostream>
#include "mahasiswa.h"

using namespace std;

int main() 
{
    mahasiswa mhs;

    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs) << endl;

    return 0;
}
```
File ini adalah driver atau program utamanya. Di sini `mahasiswa.h` di-include supaya `main` kenal type `mahasiswa` dan dua primitifnya. Di dalam `main`, dibuat variabel `mhs` bertipe `mahasiswa`, terus dipanggil `inputMhs(mhs)` buat ngisi datanya dan `rata2(mhs)` buat nampilin rata-ratanya. Karena programnya kepisah jadi tiga file, ngecompile-nya harus nyertain dua file .cpp-nya, yaitu `g++ main.cpp mahasiswa.cpp -o main`. Kalau cuma `main.cpp`, bakal error karena `inputMhs` dan `rata2` nggak ketemu.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
#include <string>
using namespace std;

struct mahasiswa {
    string nama, nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    mahasiswa mhs[10];
    int n;

    do {
        cout << "Jumlah mahasiswa: ";
        cin >> n;
    } while (n < 1 || n > 10);

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin >> mhs[i].nama;
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        cout << "UTS   : ";
        cin >> mhs[i].uts;
        cout << "UAS   : ";
        cin >> mhs[i].uas;
        cout << "Tugas : ";
        cin >> mhs[i].tugas;
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << " | " << mhs[i].nim << " | "
             << mhs[i].uts << " | " << mhs[i].uas << " | "
             << mhs[i].tugas << " | " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul3/soal1/soal%201.png

Di soal ini dibuat `struct mahasiswa` yang isinya nama, nim, uts, uas, tugas, dan nilaiAkhir (materi struct Modul 1), terus dibuat array `mhs[10]` supaya bisa nyimpen maksimal 10 mahasiswa (materi array Modul 2). Jumlah mahasiswa diminta lewat `do...while` yang bakal ngulang terus kalau input kurang dari 1 atau lebih dari 10, jadi batas max 10-nya terjaga. Nilai akhir dihitung lewat fungsi `hitungNilaiAkhir()` sesuai rumus di soal, hasilnya di-`return` terus disimpan ke `mhs[i].nilaiAkhir`. Contohnya Andi: 0.3x80 + 0.4x85 + 0.3x90 = 24 + 34 + 27 = 85. Setelah semua data diinput, hasilnya ditampilkan per baris dengan urutan nama, nim, uts, uas, tugas, dan nilai akhir.

### 2. Buatlah ADT pelajaran (Type pelajaran berisi namaMapel : string dan kodeMapel : string, function create_pelajaran( namapel : string, kodepel : string ) → pelajaran, procedure tampil_pelajaran( input pel : pelajaran )) di dalam file "pelajaran.h". Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp". Cobalah hasil implementasi ADT pada file "main.cpp"

```C++
// pelajaran.h
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED

// pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

// main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul3/soal2/soal%202%20(2).png

Soal ini nerapin konsep ADT, jadi programnya dipisah jadi tiga file. `pelajaran.h` isinya type `pelajaran` (struct dengan `namaMapel` dan `kodeMapel`) dan header dua primitifnya. `pelajaran.cpp` isinya realisasi primitif itu. `create_pelajaran()` berperan sebagai konstruktor yang ngisi `namaMapel` dan `kodeMapel` lalu ngembaliin type `pelajaran`, sedangkan `tampil_pelajaran()` adalah prosedur buat nampilin isinya. `main.cpp` jadi driver yang manggil dua primitif itu. Di `pelajaran.h` dipasang `#ifndef`, `#define`, dan `#endif` biar header nggak ke-include dua kali. Buat ngecompile harus semua file .cpp-nya ikut, yaitu `g++ main.cpp pelajaran.cpp -o main`. Teks outputnya sengaja dibuat sama persis dengan contoh output di soal, termasuk tulisan "nilai" buat nampilin kode mapel.

### 3. Buatlah program dengan ketentuan : 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer; fungsi/prosedur yang menampilkan isi sebuah array integer 2D; fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu; fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

void tampil(int a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int a[3][3], int b[3][3], int baris, int kolom) {
    int temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    int *p1, *p2;
    int baris, kolom;

    cout << "Array A :\n";
    tampil(A);
    cout << "\nArray B :\n";
    tampil(B);

    cout << "\nTukar isi array A dan B pada posisi (0-2)\n";
    cout << "Baris : ";
    cin >> baris;
    cout << "Kolom : ";
    cin >> kolom;

    if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
        cout << "Posisi tidak valid!\n";
    } else {
        tukarArray(A, B, baris, kolom);
        cout << "\nSetelah ditukar, Array A :\n";
        tampil(A);
        cout << "\nSetelah ditukar, Array B :\n";
        tampil(B);
    }

    p1 = &A[0][0];
    p2 = &B[2][2];
    cout << "\nSebelum tukar pointer : *p1 = " << *p1 << ", *p2 = " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Setelah tukar pointer : *p1 = " << *p1 << ", *p2 = " << *p2 << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/modul3/soal%203/Screenshot%202026-10-11%20202905.png
Program ini punya dua array 2D `A` dan `B` ukuran 3x3 serta dua pointer integer `p1` dan `p2`. Prosedur `tampil()` dipakai buat nampilin isi array pakai dua `for` kayak di guided array 2D Modul 2. Prosedur `tukarArray()` nukar isi `A` dan `B` di posisi baris dan kolom yang sama, posisinya diinput user dan dicek dulu biar nggak keluar dari 0 sampai 2. Karena array di C++ otomatis dikirim sebagai alamat, perubahan di dalam prosedur langsung kebawa ke `A` dan `B` di `main`. Prosedur `tukarPointer()` mirip guided call by pointer di Modul 2, yang ditukar adalah nilai yang ditunjuk (`*x` dan `*y`), bukan pointer-nya. Di `main`, `p1` diarahkan ke `A[0][0]` dan `p2` ke `B[2][2]`, jadi setelah ditukar `*p1` jadi 90 dan `*p2` jadi 1.

## Kesimpulan
Dari praktikum modul 3 ini bisa disimpulkan kalau ADT adalah type beserta primitif-primitif (fungsi dan prosedur) yang bekerja pada type itu, seperti ADT `mahasiswa` di guided yang punya prosedur `inputMhs()` dan fungsi `rata2()`. Penerapannya dengan memisah program jadi file header (.h) yang isinya type dan header primitif, file body (.cpp) yang isinya realisasi primitif, dan file driver (main.cpp) sebagai program utamanya. Dengan begitu kode jadi lebih rapi dan gampang dipakai ulang. ADT ini juga dibangun dari materi sebelumnya, seperti `struct`, array, fungsi dan prosedur, serta pointer, dan semua latihan di modul ini sudah bisa dibuat dan jalan sesuai soal.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Laboratorium Informatika, Fakultas Informatika, Telkom University. "Modul 3 Abstract Data Type (ADT)", Praktikum Struktur Data.
