#include "Buku.h"

int main() {
    List L;
    infotype x;
    createList(L);

    for (int i = 0; i < 4; i++) {
        cout << "masukkan kode buku: ";
        cin >> x.kodeBuku;
        cout << "masukkan judul buku: ";
        cin >> x.judul;
        cout << "masukkan tahun terbit: ";
        cin >> x.thnTerbit;
        insertLast(L, alokasi(x));
    }

    printInfo(L);
    return 0;
}
