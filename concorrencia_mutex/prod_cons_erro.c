/*
 Um problema comum que pode ocorrer em sistemas de produtor-consumidor 
 é a condição de corrida, onde dois ou mais threads acessam uma variável 
 compartilhada de forma concorrente, resultando em comportamento 
 indefinido ou incorreto. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int counter = 0;
int front = 0;
int rear = 0;

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 1000; // produz um item aleatório
        if (counter == BUFFER_SIZE) {
            printf("Buffer cheio!\n");
            continue;
        }
        buffer[rear] = item; // insere o item no buffer
        rear = (rear + 1) % BUFFER_SIZE; // atualiza o índice rear
        counter++;
        printf("Produced item %d\n", item);
    }
}

void *consumer(void *arg) {
    int item;
    while (1) {
        if (counter == 0) {
            printf("Buffer vazio!\n");
            continue;
        }
        item = buffer[front]; // remove o item do buffer
        front = (front + 1) % BUFFER_SIZE; // atualiza o índice front
        counter--;
        printf("Consumed item %d\n", item);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    return 0;
}
