/*
   Exemplo mutex adaptado do material TheGeekStuff
   Resolução: proteger as variáveis com mutex
 */
#include<stdio.h>
#include<string.h>
#include<pthread.h>

pthread_t tid[2];
int count;
pthread_mutex_t lock;

void *t1(void *arg) {
    pthread_mutex_lock(&lock);
    
    unsigned long i = 0;
    count += 1;
    printf("\nTrabalho %d iniciado\n", count);
    for(i=0; i<(0xFFFFFFFF);i++);
    printf("\nTrabalho %d finalizado\n", count);
    
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void) {
    int err;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n inicialização do mutex falhou.\n");
        return 1;
    }

    for (int i = 0; i < 2; i++) {
        err = pthread_create(&(tid[i]), NULL, &t1, NULL);
        if (err != 0)
            printf("\nnão foi possível criar a thread :[%s]", strerror(err));
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}
