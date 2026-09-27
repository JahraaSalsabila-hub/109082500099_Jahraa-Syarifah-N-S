#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua  : ";
    cin >> b;

    cout << "Hasil penjumlahan : " << a << " + " << b << " = " << (a + b) << endl;
    cout << "Hasil pengurangan : " << a << " - " << b << " = " << (a - b) << endl;
    cout << "Hasil perkalian   : " << a << " * " << b << " = " << (a * b) << endl;
    cout << "Hasil pembagian   : " << a << " / " << b << " = " << (a / b) << endl;

    return 0;
}
