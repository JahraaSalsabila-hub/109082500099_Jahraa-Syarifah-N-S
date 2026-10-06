# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Jahraa Syarifah N.S - 109082500099</p>

## Dasar Teori

### A. Array<br/>
Array adalah kumpulan data dengan nama yang sama dan setiap elemennya punya tipe data yang sama. Buat ngakses tiap elemennya kita pakai indeks dari elemen itu [1]. Di C++ elemen array disimpan di memori secara berurutan dan indeksnya mulai dari 0, jadi array dengan 5 elemen indeks terakhirnya adalah 4 [1].

#### 1. Array Satu Dimensi
Array satu dimensi hanya terdiri dari satu larik data. Cara deklarasinya `tipe_data nama_var[ukuran]`, misalnya `int nilai[10];` artinya array `nilai` punya 10 elemen bertipe integer [1]. Mengisi dan membaca elemennya lewat indeks, contohnya `nilai[4] = 90;` atau `cin >> nilai[4];`.

#### 2. Array Dua Dimensi
Array dua dimensi bentuknya mirip tabel, jadi ada indeks baris dan indeks kolom. Cara deklarasi, inisialisasi, dan menampilkannya sama kayak array satu dimensi, bedanya indeks yang dipakai ada dua [1]. Contoh `int data_nilai[4][3];` lalu `data_nilai[2][0] = 10;` artinya mengisi baris ke-2 kolom ke-0 dengan 10.

#### 3. Array Berdimensi Banyak
Kalau indeksnya lebih dari dua, namanya array berdimensi banyak. Deklarasinya `tipe_data nama_var[ukuran1][ukuran2]...[ukuranN];`, contoh `int data_rumit[4][6][6];` [1]. Makin banyak dimensinya makin susah dibayangkan, tapi cara aksesnya tetap sama, tinggal nambah indeks.

### B. Pointer<br/>
Semua data yang dipakai program disimpan di memori (RAM). Memori bisa dibayangkan sebagai array satu dimensi yang gede banget, dan tiap selnya punya alamat (address) yang unik [1].

#### 1. Data dan Alamat Memori
Waktu variabel dideklarasikan, OS akan nyariin tempat kosong di memori buat variabel itu. Alamat dari sebuah variabel bisa dilihat pakai operator `&` di depan nama variabelnya, contoh `cout << &j;` [1].

#### 2. Pointer dan Array
Pointer adalah variabel yang isinya alamat memori variabel lain, jadi lewat pointer kita bisa ngakses nilai variabel yang ditunjuk [1]. Deklarasinya `tipe *nama_variabel;`, misalnya `int *p_int;`. Lalu `p_int = &j;` membuat p_int menunjuk ke j, dan `*p_int` dipakai buat ngambil nilai yang ditunjuk. Pointer sama array berhubungan erat. Kalau `pa = &a[0];` maka `pa + i` adalah alamat `a[i]` dan `*(pa + i)` adalah isi dari `a[i]` [1].

#### 3. Pointer dan String
String di C++ pada dasarnya array of char yang diakhiri karakter `'\0'` [1]. Deklarasinya misal `char nama[50];` atau langsung `char nama[] = "strukdat";`. Ada beda penting antara `char amessage[] = "now is the time";` (array, isinya boleh diubah per karakter) dan `char *pmessage = "now is the time";` (pointer ke string konstan, pointer-nya boleh diarahkan ke tempat lain tapi isi stringnya tidak boleh diubah) [1].

### C. Fungsi dan Prosedur<br/>
Fungsi adalah blok kode yang dibuat untuk ngerjain tugas tertentu. Tujuannya biar program lebih terstruktur dan nggak ada kode yang diulang-ulang [1][2].

#### 1. Fungsi
Bentuk umumnya `tipe_keluaran nama_fungsi(daftar_parameter) { ... }`. Fungsi mengembalikan sebuah nilai lewat `return`, contohnya fungsi `maks3()` yang ngembaliin nilai terbesar dari tiga bilangan [1].

#### 2. Prosedur
Prosedur itu fungsi yang tidak mengembalikan nilai, di C++ ditulis dengan tipe `void`. Prosedur cuma menjalankan tugasnya (misal nampilin sesuatu ke layar) tanpa `return` nilai [1].

#### 3. Parameter Fungsi
Parameter formal adalah variabel di daftar parameter saat fungsi didefinisikan, sedangkan parameter aktual adalah nilai atau variabel yang dikirim waktu fungsi dipanggil. Ada tiga cara ngelewatin parameter [1]:
- Call by value: nilai parameter aktual disalin ke parameter formal, jadi variabel aslinya tidak berubah.
- Call by pointer: yang dikirim alamat variabel (`&a`), jadi variabel aslinya bisa berubah lewat `*px`.
- Call by reference: parameter dideklarasikan pakai `&` (contoh `int &px`), pemanggilannya biasa saja tapi variabel aslinya tetap bisa berubah.

### D. Materi Modul 1 yang Dipakai di Modul 2<br/>
Program di modul ini masih pakai dasar dari Modul 1, jadi aku rangkum bagian yang kepakai aja.

#### 1. Input dan Output
`cout` buat nampilin data dan `cin` buat minta input dari keyboard dengan bentuk `cin >> nama_variabel;` [1]. Escape sequence kayak `\n` (baris baru) dan `\t` (tab) dipakai buat ngatur tampilan [1].

#### 2. Operator
Operator aritmatika (`+ - * / %`), assignment (`=`, `+=`), dan operator logika (`&&`, `||`) [1]. Ada juga operator unary tipe (type cast), misalnya `(float)` supaya hasil pembagian nggak dibulatkan ke bilangan bulat [1].

#### 3. Kondisional dan Perulangan
Pernyataan `switch-case` dipakai kalau pilihannya banyak, tiap `case` diakhiri `break` dan ada `default` kalau nggak ada yang cocok [1]. Perulangan ada `for`, `while`, dan `do...while`. Bedanya, `do...while` pasti jalan minimal satu kali karena kondisinya dicek di bawah [1]. Konstanta bisa dibuat pakai `#define` atau `const` [1].

## Guided 

### 1. Array Satu Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 85;
    nilai[2] = 90;
    nilai[3] = 75;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "index ke-" << i << " = " << nilai[i] << endl;
    }

    return 0;
}
```
Output :
```
index ke-0 = 80
index ke-1 = 85
index ke-2 = 90
index ke-3 = 75
index ke-4 = 95
```
Di program ini dibuat array `nilai` dengan 5 elemen. Tiap elemen diisi satu-satu lewat indeksnya (mulai dari 0 sampai 4), terus ditampilkan pakai `for` dari i = 0 sampai i < 5. Karena indeks mulai dari 0, elemen terakhir ada di `nilai[4]`.

### 2. Array Dua Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 85, 90},
        {75, 80, 85},
        {90, 95, 100}
    };

    // menampilkan seluruh isi array 2 dimensi
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }

    // mengakses elemen tertentu
    cout << nilai[0][0] << endl;
    cout << nilai[1][1] << endl;
    cout << nilai[2][2] << endl;

    return 0;
}
```
Output :
```
80 85 90 
75 80 85 
90 95 100 
80
80
100
```
Array `nilai[3][3]` diisi langsung waktu dideklarasi, bentuknya 3 baris 3 kolom. Buat nampilin semuanya dipakai dua `for`, yang luar buat baris (`i`) dan yang dalam buat kolom (`j`). Setelah itu diakses juga tiga elemen diagonal, yaitu `nilai[0][0]`, `nilai[1][1]`, dan `nilai[2][2]`.

### 3. Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        }
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << data[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << data[0][1][1] << endl;

    return 0;
}
```
Output :
```
1 2 3 
4 5 6 
7 8 9 

10 11 12 
13 14 15 
16 17 18 

5
```
Array `data[2][3][3]` bisa dibayangin sebagai 2 tabel yang masing-masing ukurannya 3x3. Karena ada tiga indeks, perulangannya juga ada tiga tingkat (`i`, `j`, `k`). Di akhir diambil `data[0][1][1]`, yaitu tabel pertama, baris kedua, kolom kedua, hasilnya 5.

### 4. Array Empat Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][2][2] = {
        {
            {
                {1, 2},
                {3, 4}
            },
            {
                {5, 6},
                {7, 8}
            }
        },
        {
            {
                {9, 10},
                {11, 12}
            },
            {
                {13, 14},
                {15, 16}
            }
        }
    };

    cout << data[0][0][0][0] << endl; // 1
    cout << data[1][1][1][1] << endl; // 16

    return 0;
}
```
Output :
```
1
16
```
Ini contoh array berdimensi banyak yang lebih rumit, 4 indeks dan totalnya 2x2x2x2 = 16 elemen yang diisi angka 1 sampai 16. Elemen paling pertama `data[0][0][0][0]` isinya 1 dan elemen paling akhir `data[1][1][1][1]` isinya 16.

### 5. Alamat Memori (Pointer 1)

```C++
#include <iostream>
using namespace std;

int main() {
    char a;
    int j;
    char arr[6];

    arr[3] = 'b';
    a = 'u';
    j = 10;

    cout << a << endl;                  // nilai variabel a
    cout << (void*)&a << endl;          // alamat variabel a

    cout << j << endl;                  // nilai variabel j
    cout << &j << endl;                 // alamat variabel j

    cout << arr[3] << endl;             // nilai arr[3]
    cout << (void*)&(arr[4]) << endl;   // alamat arr[4]

    return 0;
}
```
Output (alamatnya contoh aja, tiap komputer dan tiap run bisa beda) :
```
u
0x61ff0f
10
0x61ff08
b
0x61ff04
```
Program ini buat ngelihat nilai sama alamat dari variabel. Operator `&` dipakai buat dapetin alamat. Khusus variabel bertipe `char`, kalau langsung `cout << &a` yang keluar bukan alamat tapi karakter aneh, karena `cout` nganggep `char*` itu string. Makanya di-cast dulu jadi `(void*)` biar yang tampil alamatnya.

### 6. Pointer (Pointer 2)

```C++
#include <iostream>
using namespace std;

int main() {
    int x, y;
    int *px;

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x= " << &x << endl;
    cout << "Isi px= " << px << endl;
    cout << "Isi X= " << x << endl;
    cout << "Nilai yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;

    return 0;
}
```
Output (alamat contoh) :
```
Alamat x= 0x61ff0c
Isi px= 0x61ff0c
Isi X= 87
Nilai yang ditunjuk px= 87
Nilai y= 87
```
`px` adalah pointer ke int. Setelah `px = &x`, isi `px` sama persis dengan alamat `x`, makanya dua baris pertama outputnya sama. `*px` ngambil nilai yang ditunjuk yaitu 87, lalu nilai itu disalin ke `y`.

### 7. Pointer dan Array (Pointer 3)

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai[MAX];

    static int nilai_tahun[MAX][MAX] = {
        {0, 2, 2, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 3, 3, 3, 0},
        {4, 4, 0, 0, 4},
        {5, 0, 0, 0, 5}
    };

    // inisialisasi array satu dimensi
    for (i = 0; i < MAX; i++) {
        cout << "masukkan nilai ke-" << i + 1 << endl;
        cin >> nilai[i];
    }

    cout << "\ndata nilai siswa :\n";

    // menampilkan array satu dimensi
    for (i = 0; i < MAX; i++)
        cout << "nilai k-" << i + 1 << "=" << nilai[i] << endl;

    cout << "\nnilai tahunan : \n";

    // menampilkan array dua dimensi
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            cout << nilai_tahun[i][j];
        cout << "\n";
    }

    return 0;
}
```
Contoh masukan dan output :
```
masukkan nilai ke-1
80
masukkan nilai ke-2
85
masukkan nilai ke-3
90
masukkan nilai ke-4
75
masukkan nilai ke-5
95

data nilai siswa :
nilai k-1=80
nilai k-2=85
nilai k-3=90
nilai k-4=75
nilai k-5=95

nilai tahunan : 
02200
01110
03330
44004
50005
```
Program ini gabungan array 1 dimensi dan 2 dimensi. Ukuran array dibuat lewat `#define MAX 5`, jadi kalau mau ganti ukuran tinggal ubah di satu tempat. Array `nilai` diisi dari keyboard, sedangkan `nilai_tahun` sudah diisi dari awal. Dua-duanya ditampilkan pakai perulangan.

### 8. Pointer dan String (Pointer 4)

```C++
#include <iostream>
using namespace std;

int main() {
    char nama[] = "strukdat";

    cout << nama << endl;
    cout << nama[3] << endl;

    return 0;
}
```
Output :
```
strukdat
u
```
String di C++ itu array of char, jadi `cout << nama` langsung nampilin seluruh kata "strukdat". Buat ngambil satu huruf pakai indeks, `nama[3]` hasilnya `u` karena urutannya s(0) t(1) r(2) u(3).

### 9. Call by Pointer

```C++
#include <iostream>
using namespace std;

/* prototype fungsi */
void tukar(int *x, int *y);

int main() {
    int a, b;
    a = 4;
    b = 6;

    cout << "kondisi sebelum ditukar \n";
    cout << " a = " << a << " b = " << b << endl;

    tukar(&a, &b);

    cout << "kondisi setelah ditukar \n";
    cout << " a = " << a << " b = " << b << endl;

    return 0;
}

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

    cout << "nilai akhir pada fungsi tukar \n";
    cout << " x = " << *x << " y = " << *y << endl;
}
```
Output :
```
kondisi sebelum ditukar 
 a = 4 b = 6
nilai akhir pada fungsi tukar 
 x = 6 y = 4
kondisi setelah ditukar 
 a = 6 b = 4
```
Di sini yang dikirim ke fungsi `tukar` adalah alamat `a` dan `b` (`&a`, `&b`). Fungsinya nulis langsung ke alamat itu lewat `*x` dan `*y`, jadi nilai `a` dan `b` di `main` ikut tertukar.

### 10. Call by Reference

```C++
#include <iostream>
using namespace std;

/* prototype fungsi */
void tukar(int &x, int &y);

int main() {
    int a, b;
    a = 4;
    b = 6;

    cout << "kondisi sebelum ditukar \n";
    cout << " a = " << a << " b = " << b << endl;

    tukar(a, b);

    cout << "kondisi setelah ditukar \n";
    cout << " a = " << a << " b = " << b << endl;

    return 0;
}

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;

    cout << "nilai akhir pada fungsi tukar \n";
    cout << " x = " << x << " y = " << y << endl;
}
```
Output :
```
kondisi sebelum ditukar 
 a = 4 b = 6
nilai akhir pada fungsi tukar 
 x = 6 y = 4
kondisi setelah ditukar 
 a = 6 b = 4
```
Hasilnya sama kayak call by pointer, bedanya penulisannya lebih simpel. Parameter dibuat `int &x, int &y` jadi `x` dan `y` itu sebenarnya nama lain dari `a` dan `b`. Waktu dipanggil cukup `tukar(a, b)`, nggak perlu `&` dan nggak perlu `*` di dalam fungsi.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
#include <iostream>
#define MAX 3
using namespace std;

/* prototype prosedur */
void inputMatriks(int m[MAX][MAX], char nama);
void tampilMatriks(int m[MAX][MAX]);
void penjumlahan(int a[MAX][MAX], int b[MAX][MAX]);
void pengurangan(int a[MAX][MAX], int b[MAX][MAX]);
void perkalian(int a[MAX][MAX], int b[MAX][MAX]);

int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int pilihan;
    char ulang;

    inputMatriks(A, 'A');
    inputMatriks(B, 'B');

    do {
        cout << "\n--- Menu Operasi Matriks 3x3 ---\n";
        cout << "1. Penjumlahan\n";
        cout << "2. Pengurangan\n";
        cout << "3. Perkalian\n";
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                penjumlahan(A, B);
                break;
            case 2:
                pengurangan(A, B);
                break;
            case 3:
                perkalian(A, B);
                break;
            default:
                cout << "Menu tidak ada!!!\n";
        }

        cout << "\nKembali ke menu? (y/n) : ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}

/* badan prosedur */
void inputMatriks(int m[MAX][MAX], char nama) {
    cout << "Masukkan elemen matriks " << nama << " (3x3) :\n";
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << nama << "[" << i << "][" << j << "] = ";
            cin >> m[i][j];
        }
    }
}

void tampilMatriks(int m[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void penjumlahan(int a[MAX][MAX], int b[MAX][MAX]) {
    int hasil[MAX][MAX];
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            hasil[i][j] = a[i][j] + b[i][j];

    cout << "\nHasil penjumlahan A + B :\n";
    tampilMatriks(hasil);
}

void pengurangan(int a[MAX][MAX], int b[MAX][MAX]) {
    int hasil[MAX][MAX];
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            hasil[i][j] = a[i][j] - b[i][j];

    cout << "\nHasil pengurangan A - B :\n";
    tampilMatriks(hasil);
}

void perkalian(int a[MAX][MAX], int b[MAX][MAX]) {
    int hasil[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < MAX; k++)
                hasil[i][j] += a[i][k] * b[k][j];
        }
    }

    cout << "\nHasil perkalian A x B :\n";
    tampilMatriks(hasil);
}
```
### Output Unguided 1 :

Contoh masukan : matriks A = 1 2 3 / 4 5 6 / 7 8 9, matriks B = 9 8 7 / 6 5 4 / 3 2 1, lalu pilih menu 1, 2, dan 3 (tiap selesai jawab `y` buat balik ke menu, terakhir `n`).

Contoh keluaran :
```
Masukkan elemen matriks A (3x3) :
A[0][0] = 1
A[0][1] = 2
A[0][2] = 3
A[1][0] = 4
A[1][1] = 5
A[1][2] = 6
A[2][0] = 7
A[2][1] = 8
A[2][2] = 9
Masukkan elemen matriks B (3x3) :
B[0][0] = 9
B[0][1] = 8
B[0][2] = 7
B[1][0] = 6
B[1][1] = 5
B[1][2] = 4
B[2][0] = 3
B[2][1] = 2
B[2][2] = 1

--- Menu Operasi Matriks 3x3 ---
1. Penjumlahan
2. Pengurangan
3. Perkalian
Pilih menu : 1

Hasil penjumlahan A + B :
10	10	10	
10	10	10	
10	10	10	

Kembali ke menu? (y/n) : y

--- Menu Operasi Matriks 3x3 ---
1. Penjumlahan
2. Pengurangan
3. Perkalian
Pilih menu : 2

Hasil pengurangan A - B :
-8	-6	-4	
-2	0	2	
4	6	8	

Kembali ke menu? (y/n) : y

--- Menu Operasi Matriks 3x3 ---
1. Penjumlahan
2. Pengurangan
3. Perkalian
Pilih menu : 3

Hasil perkalian A x B :
30	24	18	
84	69	54	
138	114	90	

Kembali ke menu? (y/n) : n
```

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/Screenshot%202026-10-06%20024103.png

Soal ini nyambung ke array dua dimensi di Modul 2, jadi matriks 3x3 disimpan di `int A[3][3]` dan `int B[3][3]`, ukurannya dibuat lewat `#define MAX 3` kayak di guided. Tiap operasi dibuat prosedur sendiri (`void`), jadi pakai materi prosedur Modul 2. Dari Modul 1 yang kepakai itu `cin` dan `cout`, `switch-case` buat menunya, `for` bersarang buat ngisi dan nampilin matriks, operator aritmatika (`+`, `-`, `*`), serta `do...while` biar menunya bisa diulang. Kondisi ulangnya pakai operator logika `||` (`ulang == 'y' || ulang == 'Y'`). Penjumlahan dan pengurangan cukup dua `for` karena elemen yang dihitung posisinya sama. Perkalian butuh tiga `for`, yaitu `hasil[i][j]` = jumlah `a[i][k] * b[k][j]` untuk k dari 0 sampai 2. Contohnya `hasil[0][0]` = 1x9 + 2x6 + 3x3 = 30.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
#include <iostream>
using namespace std;

/* prototype prosedur */
void tukarPointer(int *x, int *y, int *z);
void tukarReference(int &x, int &y, int &z);

int main() {
    int a, b, c;

    cout << "Masukkan nilai a = ";
    cin >> a;
    cout << "Masukkan nilai b = ";
    cin >> b;
    cout << "Masukkan nilai c = ";
    cin >> c;

    // ---------- call by pointer ----------
    int p1 = a, p2 = b, p3 = c;
    cout << "\n=== Call by Pointer ===\n";
    cout << "kondisi sebelum ditukar \n";
    cout << " a = " << p1 << " b = " << p2 << " c = " << p3 << endl;

    tukarPointer(&p1, &p2, &p3);

    cout << "kondisi setelah ditukar \n";
    cout << " a = " << p1 << " b = " << p2 << " c = " << p3 << endl;

    // ---------- call by reference ----------
    int r1 = a, r2 = b, r3 = c;
    cout << "\n=== Call by Reference ===\n";
    cout << "kondisi sebelum ditukar \n";
    cout << " a = " << r1 << " b = " << r2 << " c = " << r3 << endl;

    tukarReference(r1, r2, r3);

    cout << "kondisi setelah ditukar \n";
    cout << " a = " << r1 << " b = " << r2 << " c = " << r3 << endl;

    return 0;
}

/* nilai x pindah ke y, y pindah ke z, z pindah ke x */
void tukarPointer(int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;

    cout << "nilai akhir pada fungsi tukar \n";
    cout << " x = " << *x << " y = " << *y << " z = " << *z << endl;
}

void tukarReference(int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;

    cout << "nilai akhir pada fungsi tukar \n";
    cout << " x = " << x << " y = " << y << " z = " << z << endl;
}
```
### Output Unguided 2 :

Contoh masukan : a = 4, b = 6, c = 8

Contoh keluaran :
```
Masukkan nilai a = 4
Masukkan nilai b = 6
Masukkan nilai c = 8

=== Call by Pointer ===
kondisi sebelum ditukar 
 a = 4 b = 6 c = 8
nilai akhir pada fungsi tukar 
 x = 6 y = 8 z = 4
kondisi setelah ditukar 
 a = 6 b = 8 c = 4

=== Call by Reference ===
kondisi sebelum ditukar 
 a = 4 b = 6 c = 8
nilai akhir pada fungsi tukar 
 x = 6 y = 8 z = 4
kondisi setelah ditukar 
 a = 6 b = 8 c = 4
```

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/Screenshot%202026-10-06%20025330.png

Soal ini lanjutan dari guided call by pointer dan call by reference yang tadinya nukar 2 variabel, sekarang jadi 3. Cara tukarnya digeser berputar, nilai `a` pindah ke `b`, `b` pindah ke `c`, dan `c` pindah ke `a`, makanya butuh satu variabel `temp` buat nyimpen nilai pertama biar nggak ketimpa. Di versi pointer (Modul 2) yang dikirim alamat variabelnya (`&p1, &p2, &p3`) dan nilainya diubah lewat `*x, *y, *z`. Di versi reference parameternya pakai `&` jadi pemanggilannya biasa aja. Dari Modul 1 yang kepakai itu deklarasi variabel dan `cin`/`cout` buat input dan nampilin nilai. Nilai awal disalin dulu ke dua set variabel supaya dua cara itu dites pakai input yang sama.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}. Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :

```
--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata
```

```C++
#include <iostream>
#define MAX 10
using namespace std;

/* prototype fungsi dan prosedur */
int cariMinimum(int arr[], int n);
int cariMaksimum(int arr[], int n);
void hitungRataRata(int arr[], int n);

int main() {
    int arrA[MAX] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;
    char ulang;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. cari nilai maksimum\n";
        cout << "3. cari nilai minimum\n";
        cout << "4. Hitung nilai rata - rata\n";
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array : ";
                for (int i = 0; i < MAX; i++)
                    cout << arrA[i] << " ";
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, MAX) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, MAX) << endl;
                break;
            case 4:
                hitungRataRata(arrA, MAX);
                break;
            default:
                cout << "Menu tidak ada!!!\n";
        }

        cout << "\nKembali ke menu? (y/n) : ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}

/* badan fungsi dan prosedur */
int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks)
            maks = arr[i];
    }
    return maks;
}

void hitungRataRata(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    float rata = (float)total / n;
    cout << "Nilai rata-rata = " << rata << endl;
}
```
### Output Unguided 3 :

Contoh masukan : pilih menu 1, 2, 3, lalu 4 (arrA sudah ditentukan di program jadi yang diinput cuma pilihan menu, tiap selesai jawab `y` buat balik ke menu, terakhir `n`).

Contoh keluaran :
```
--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata
Pilih menu : 1
Isi array : 11 8 5 7 12 26 3 54 33 55 

Kembali ke menu? (y/n) : y

--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata
Pilih menu : 2
Nilai maksimum = 55

Kembali ke menu? (y/n) : y

--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata
Pilih menu : 3
Nilai minimum = 3

Kembali ke menu? (y/n) : y

--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata
Pilih menu : 4
Nilai rata-rata = 21.4

Kembali ke menu? (y/n) : n
```

##### Output 1
https://github.com/JahraaSalsabila-hub/109082500099_Jahraa-Syarifah-N-S/blob/main/Screenshot%202026-10-06%20024209.png

Soal ini pakai array satu dimensi (Modul 2), `arrA` langsung diisi sesuai soal. `cariMaksimum()` dan `cariMinimum()` dibuat sebagai fungsi karena harus ngembaliin nilai lewat `return`, sedangkan `hitungRataRata()` dibuat sebagai prosedur (`void`) karena hasilnya langsung ditampilkan di dalamnya. Cara cari maks dan min-nya, elemen pertama dianggap yang terbesar (atau terkecil) dulu, lalu dibandingin satu-satu sama elemen berikutnya, kalau ketemu yang lebih besar (atau lebih kecil) nilainya diganti. Rata-ratanya didapat dari total 214 dibagi 10 elemen jadi 21.4, dan totalnya di-cast pakai `(float)` (operator unary tipe dari Modul 1) supaya hasil baginya nggak dibulatkan jadi 21. Dari Modul 1 juga kepakai `switch-case` buat menu sesuai soal, `for` buat nampilin dan nyari nilai, serta `do...while` dengan kondisi `||` biar menunya bisa diulang tanpa nambah pilihan di luar menu soal.

## Kesimpulan
Dari praktikum modul 2 ini bisa disimpulkan kalau array dipakai buat nyimpen banyak data bertipe sama dalam satu nama variabel dan diakses lewat indeks, mulai dari satu dimensi sampai berdimensi banyak. Pointer menyimpan alamat memori variabel lain dan nilainya bisa diakses lewat tanda `*`, sedangkan alamat sebuah variabel didapat lewat `&`. Fungsi dan prosedur bikin program lebih rapi dan nggak banyak kode yang diulang, dan buat ngubah nilai variabel asli dari dalam fungsi bisa pakai call by pointer atau call by reference, beda sama call by value yang cuma menyalin nilai. Materi Modul 1 seperti `switch-case`, perulangan, operator, dan `cin`/`cout` tetap kepakai di semua latihan, jadi Modul 2 ini bisa dibilang lanjutan dari Modul 1. Semua latihan (operasi matriks, tukar tiga variabel, dan menu array) sudah bisa dibuat dan jalan sesuai soal.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
