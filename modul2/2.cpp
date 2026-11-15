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
