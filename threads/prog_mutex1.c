/*
   Exemplo mutex adaptado do material TheGeekStuff
   Na execução do programa é possível verificar 
   na saída que count é atualizado antes da finalização
   da primeira thread.
 */
#include <stdio.h>
#include <string.h>
#include <pthread.h>

pthread_t tid[2];
int count;

void *t1(void *arg) {
    unsigned long i = 0;
    count += 1;

    printf("\nTrabalho %d iniciado\n", count);
    for(i=0; i<(0xFFFFFFFF);i++);
    printf("\nTrabalho %d finalizado\n", count);

    return NULL;
}

int main(void) {
    int err;
    for (int i=0; i < 2; i++){
        err = pthread_create(&(tid[i]), NULL, &t1, NULL);
        if (err != 0)
            printf("\nnão foi possível criar a thread :[%s]", strerror(err));
    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    return 0;
}
