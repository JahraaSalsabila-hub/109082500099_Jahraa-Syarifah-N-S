#include "Singlylist.h"

//membuat list kosong
void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void deleteFirst(List &L) {
    address P = L.first;
    if (P != Nil) {
        L.first = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    address P = L.first;
    address Q = Nil;
    if (P != Nil) {
        while (P->next != Nil) {
            Q = P;
            P = P->next;
        }
        if (Q == Nil)
            L.first = Nil;
        else
            Q->next = Nil;
        dealokasi(P);
    }
}

void deleteAfter(address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        address P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.first;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void deleteList(List &L) {
    while (L.first != Nil) {
        deleteFirst(L);
    }
}
