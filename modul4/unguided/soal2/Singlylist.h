#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
#include <iostream>
using namespace std;
#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(address Prec);
int nbList(List L);
void deleteList(List &L);

#endif // SINGLYLIST_H_INCLUDED
