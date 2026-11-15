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
