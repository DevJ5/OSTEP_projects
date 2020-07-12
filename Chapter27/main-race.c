#include <stdio.h>

#include "mythreads.h"

int balance = 0;
pthread_mutex_t lock;
// Compile time lock:
// pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* worker(void* arg) { 
    Pthread_mutex_lock(&lock);
    balance++;
    Pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    Pthread_create(&p, NULL, worker, NULL);

    // Runtime lock:
    int rc = pthread_mutex_init(&lock, NULL);
    assert(rc == 0);

    Pthread_mutex_lock(&lock);
    balance++;
    Pthread_mutex_unlock(&lock);
    Pthread_join(p, NULL);

    // Destroy the lock:
    pthread_mutex_destroy(&lock);
    return 0;
}
