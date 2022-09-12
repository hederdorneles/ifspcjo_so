/*
 Um padrão comum para executar um subprograma dentro de 
 um programa é primeiro fazer o fork do processo e depois 
 executar o subprograma. Isso permite que o programa 
 chamador continue a execução no processo pai enquanto 
 o programa chamador é substituído pelo subprograma no 
 processo filho.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int spawn(char *programa, char **arg_list) {
    pid_t pid_filho;

    pid_filho = fork();
    if (pid_filho != 0)
        return pid_filho;
    else{
        execvp(programa, arg_list);
        fprintf(stderr, "ocorreu um erro no execvp\n");
        abort();
    }
}

int main() {
    char *arg_list[] = {
        "ls",       // argv[0], nome do programa
        "-l",
        "/",
        NULL        // a lista de argumento termina com NULL
    };

    spawn("ls", arg_list);

    printf("Feito com o programa principal\n");
    return 0;
}
