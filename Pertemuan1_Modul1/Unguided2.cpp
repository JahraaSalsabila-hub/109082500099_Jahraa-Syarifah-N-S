#include <iostream>
#include <string>
using namespace std;

string satuan[]  = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas",
                     "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh",
                     "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

string angkaKeKata(int n) {
    if (n == 0)   return "nol";
    if (n == 100) return "seratus";
    if (n < 10)   return satuan[n];
    if (n < 20)   return belasan[n - 10];

    int puluh = n / 10;
    int sisa  = n % 10;

    if (sisa == 0) return puluhan[puluh];
    return puluhan[puluh] + " " + satuan[sisa];
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar rentang 0-100!" << endl;
        return 0;
    }

    cout << angka << " : " << angkaKeKata(angka) << endl;
    return 0;
}
