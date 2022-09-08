/*
  Utilização de argumentos de linha de comando.
  O int argc é responsável por armazenar o tamanho do array,
  o que também determina a quantidade de parâmetros.

  Uso:
  $ ./exe arg1 arg2
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Nome do programa:\t\t[%s]\n", argv[0]);
    printf("Quantidade de parâmetros:\t[%d]\n", argc - 1);

    // Existindo argumentos podemos imprimi-los.
    if (argc > 1) {
        for (int i = 0; i < argc; i++) 
            printf("%s\n", argv[i]);
    }

    return 0;
}
