#include "queue.h"

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);                                 // SOAL 2: Cek kosong
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_SIZE - 1);                       // SOAL 2: Cek tail mentok
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        if (Q.head > 0) {                                  // SOAL 2: Cek penuh semu
            int count = Q.tail - Q.head + 1;
            for (int i = 0; i < count; i++) {
                Q.info[i] = Q.info[Q.head + i];            // SOAL 2: Kompaksi (geser ke depan)
            }
            Q.head = 0;
            Q.tail = count - 1;
        } else {
            cout << "Queue Penuh!" << endl;                // SOAL 2: Benar-benar penuh
            return;
        }
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;                                          // SOAL 2: Tail bergerak maju
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong!" << endl;
        return -1;
    }
    
    infotype x = Q.info[Q.head];
    
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;                                          // SOAL 2: Head bergerak maju
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {           // SOAL 2: Cetak lurus (head ke tail)
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
