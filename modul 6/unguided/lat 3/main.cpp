#include "Buku.h"

int main() {
    List L;
    infotype x = {"", "", 0};
    address P;
    createList(L);

    infotype b1 = {"B001", "Algoritma", 2020};
    infotype b2 = {"B003", "Struktur_Data", 2018};
    infotype b3 = {"B004", "Jaringan_Komputer", 2022};

    insertLast(L, alokasi(b1));
    insertLast(L, alokasi(b2));
    insertLast(L, alokasi(b3));

    cout << "Masukkan Kode Buku yang akan dihapus : ";
    cin >> x.kodeBuku;

    P = findElm(L, x);
    if (P != Nil) {
        if (P == L.first) {
            deleteFirst(L, P);
        } else if (P == L.last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan kode buku " << x.kodeBuku << " berhasil dihapus." << endl;
        printInfo(L);
    } else {
        cout << "Data dengan kode buku " << x.kodeBuku << " tidak ditemukan." << endl;
    }

    return 0;
}
