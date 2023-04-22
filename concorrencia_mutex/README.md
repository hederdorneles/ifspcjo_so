CONCURRENCY: MUTUAL EXCLUSION AND SYNCHRONIZATION



# Impementação problemática
[prod_cons_erro.c]

Nesta implementação, o produtor e o consumidor acessam a variável counter de forma concorrente sem nenhum mecanismo de sincronização. Isso pode causar uma condição de corrida, onde os dois threads atualizam a variável counter simultaneamente, resultando em um valor incorreto.

Para solucionar este problema, é necessário implementar um mecanismo de exclusão mútua, como o uso de semáforos ou mutexes, para garantir que apenas um thread possa acessar a variável counter de cada vez. Além disso, é necessário garantir que o produtor não tente adicionar um item ao buffer quando ele estiver cheio, e que o consumidor não tente remover um item do buffer quando ele estiver vazio.
