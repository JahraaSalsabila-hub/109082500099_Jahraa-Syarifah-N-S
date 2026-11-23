#include "queue.h"

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);                 // SOAL 1: Cek kosong
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_SIZE - 1);                       // SOAL 1: Cek tail mentok
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;                                      // SOAL 1: Tail bergerak maju
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x;
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong!" << endl;
        return -1;
    } else {
        x = Q.info[Q.head];
        
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            for (int i = Q.head; i < Q.tail; i++) {        // SOAL 1: Geser elemen ke kiri
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;                                      // SOAL 1: Tail mundur
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {           // SOAL 1: Cetak dari head ke tail
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
