#include <iostream>
using namespace std;

void tulis(int x);
int main() {
    int jum;
    cout << "jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    return 0;
}

void tulis(int x){
    for (int i=0; i<x; i++)
    cout << "baris ke-" << i+1 << endl;
}