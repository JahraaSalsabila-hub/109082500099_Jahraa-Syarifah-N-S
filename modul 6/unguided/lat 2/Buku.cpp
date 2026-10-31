#include "Buku.h"

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    cout << "DATA LIST 1" << endl;
    address P = L.last;
    while (P != Nil) {
        cout << "kode buku : " << P->info.kodeBuku << endl;
        cout << "judul : " << P->info.judul << endl;
        cout << "tahun : " << P->info.thnTerbit << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    address Q = L.first;
    while (Q != Nil) {
        if (Q->info.kodeBuku == P->info.kodeBuku) {
            cout << "kode buku sudah terdaftar" << endl;
            dealokasi(P);
            return;
        }
        Q = Q->next;
    }
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info.kodeBuku != x.kodeBuku) {
        P = P->next;
    }
    return P;
}
