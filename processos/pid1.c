/*
 Obtendo o PID do processo em execução.
 Execute esse comando em segundo plano inserindo o símbolo & 
 ao executar o programa.
 Exemplo: 
 $ ./exe &
 
 Para matar o processo use o comando kill com o PID impresso.
 */

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Meu PID é: %d\n", getpid());
    for(;;);
}
