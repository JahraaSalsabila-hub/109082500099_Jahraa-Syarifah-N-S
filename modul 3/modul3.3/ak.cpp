#include <stdio.h>
#include <pthread.h>

#define LOOP 1000000

long long count = 0;

void *hitung(void *arg)
{
    for (int i = 0; i < LOOP; i++) {
        count++;
    }
    return NULL;
}

int main(void)
{
    pthread_t a, b;

    pthread_create(&a, NULL, hitung, NULL);
    pthread_create(&b, NULL, hitung, NULL);

    pthread_join(a, NULL);
    pthread_join(b, NULL);

    printf("Expected : %d\n", 2 * LOOP);
    printf("Actual   : %lld\n", count);

    return 0;
}