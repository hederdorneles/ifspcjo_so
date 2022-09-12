/*
 O fork duplica o processo, um processo chamado processo filho é criado.
 O pai continua sua execução do ponto onde o fork foi chamado.

 A chamada de sistema fork() retorna em caso de sucesso, 0
 para o processo filho e no processo Pai o PID do filho, caso contrário
 -1 é retornado ao processo Pai. 
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid_filho;

    printf("O ID do programa principal é %d\n", getpid());

    pid_filho = fork();
    if (pid_filho != 0) {
        printf("Este é o processo pai, com ID %d\n", getpid());
        printf("O processo filho é %d\n", pid_filho);
    } else
        printf("Este é um processo filho, com ID %d\n", getpid());
    return 0;
}
