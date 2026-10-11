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
