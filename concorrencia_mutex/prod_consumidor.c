/*
- A variável buffer é o buffer compartilhado pelos produtores
    e consumidores.
- A variável counter é o contador do número de itens no buffer.
- As variáveis front e rear são os índices do início e do fim 
    do buffer, respectivamente.
- Os semáforos mutex, full e empty são usados para garantir a 
    exclusão mútua e a sincronização entre os produtores e 
    consumidores.
- A função producer é a função que o produtor executa. 
    Ela produz um item aleatório, insere o item no buffer, 
    atualiza o contador, e imprime a mensagem "Produced item".
- A função consumer é a função que o consumidor executa. 
    Ela remove o item do início do buffer, atualiza o contador, 
    e imprime a mensagem "Consumed item".
- Na função main, inicializamos os semáforos com os valores 
    iniciais, criamos as threads do produtor e do consumidor, 
    e esperamos as threads terminarem de executar usando 
    pthread_join.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int counter = 0;
int front = 0;
int rear = 0;

sem_t mutex, full, empty;

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 1000; // produz um item aleatório
        sem_wait(&empty); // decrementa o semáforo empty
        sem_wait(&mutex); // decrementa o semáforo mutex
        buffer[rear] = item; // insere o item no buffer
        rear = (rear + 1) % BUFFER_SIZE; // atualiza o índice rear
        counter++;
        printf("Produced item %d\n", item);
        sem_post(&mutex); // incrementa o semáforo mutex
        sem_post(&full); // incrementa o semáforo full
    }
}

void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full); // decrementa o semáforo full
        sem_wait(&mutex); // decrementa o semáforo mutex
        item = buffer[front]; // remove o item do buffer
        front = (front + 1) % BUFFER_SIZE; // atualiza o índice front
        counter--;
        printf("Consumed item %d\n", item);
        sem_post(&mutex); // incrementa o semáforo mutex
        sem_post(&empty); // incrementa o semáforo empty
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;
    sem_init(&mutex, 0, 1); // inicializa o semáforo mutex com valor 1
    sem_init(&full, 0, 0); // inicializa o semáforo full com valor 0
    sem_init(&empty, 0, BUFFER_SIZE); // inicializa o semáforo empty com valor BUFFER_SIZE
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    return 0;
}
