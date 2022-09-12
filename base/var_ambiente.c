/*
  Acessando e imprimindo as variáveis de ambiente.
  Usando uma variável global chamada environ.
  Base: Livro Advanced Linux Programming
 */

#include <stdio.h>

extern char **environ;

int main() {
    char **var;
    for (var = environ; *var != NULL; ++var)
        printf("%s\n", *var);
    return 0;
}
