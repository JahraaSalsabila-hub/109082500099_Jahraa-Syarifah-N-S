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
