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
