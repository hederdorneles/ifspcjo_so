/*
 Exemplo de processo que pega o PPID (Parent PID)
 e utiliza para executar um kill, o que em um processo
 executado no terminal (bash), acaba por finalizar a
 sessão.

 Descomentar system para funcionar.

 */

#include <stdio.h>  // printf
#include <unistd.h> // getpid
#include <stdlib.h> // system


int main() {
    int ppid = getppid();

    printf("Finalizando em 3...\n");
    sleep(3);
    char str[30];
    sprintf(str, "kill -9 %d", ppid);
    puts(str);
    //system(str);
    return 0;
}
