#include <iostream>
using namespace std;

// 1. Call by Value: variabel asli TIDAK berubah
void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}



int main() {
    int a = 4, b = 6;

    // Tes Call by Value
    tukarValue(a, b);
    cout << "Setelah Call by Value     -> a = " << a << ", b = " << b << " (Tetap)" << endl;

   
    return 0;
}