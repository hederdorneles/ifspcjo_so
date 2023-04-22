CONCURRENCY: MUTUAL EXCLUSION AND SYNCHRONIZATION

Produtor-consumidor é um padrão de projeto utilizado em programação concorrente e paralela para coordenar a comunicação e sincronização entre threads. Ele é baseado em uma analogia com uma linha de produção, em que há um ou mais produtores que geram dados ou informações, e um ou mais consumidores que recebem e processam esses dados.

No contexto de programação concorrente, o produtor-consumidor envolve dois ou mais threads que compartilham um buffer ou fila de tamanho limitado, onde o produtor insere dados e o consumidor os retira para processamento. O objetivo é garantir que o produtor e o consumidor trabalhem de forma sincronizada e segura, evitando problemas de condição de corrida ou inconsistência de dados.

Para implementar o padrão produtor-consumidor, é necessário utilizar mecanismos de sincronização, como semáforos ou mutexes, para garantir que apenas um thread possa acessar o buffer de cada vez. Também é comum utilizar variáveis de condição para notificar quando o buffer está cheio ou vazio, permitindo que o produtor espere quando o buffer estiver cheio e o consumidor espere quando o buffer estiver vazio.


# Impementação problemática
Código fonte: [prod_cons_erro.c](prod_cons_erro.c) 

Nesta implementação, o produtor e o consumidor acessam a variável counter de forma concorrente sem nenhum mecanismo de sincronização. Isso pode causar uma condição de corrida, onde os dois threads atualizam a variável counter simultaneamente, resultando em um valor incorreto.

Para solucionar este problema, é necessário implementar um mecanismo de exclusão mútua, como o uso de semáforos ou mutexes, para garantir que apenas um thread possa acessar a variável counter de cada vez. Além disso, é necessário garantir que o produtor não tente adicionar um item ao buffer quando ele estiver cheio, e que o consumidor não tente remover um item do buffer quando ele estiver vazio.

O código 'prod_cons_erro.c' apresenta uma condição de corrida, onde os threads produtor e consumidor podem acessar a variável ´´counter´´ de forma concorrente e sem mecanismos de sincronização adequados. Essa condição pode resultar em comportamento indefinido ou incorreto, como a perda de dados ou o acesso a áreas de memória inválidas.

Além disso, o código não lida com a situação em que o buffer está cheio ou vazio. Se o produtor tentar inserir um item quando o buffer está cheio, ou se o consumidor tentar remover um item quando o buffer está vazio, o programa pode entrar em um loop infinito, causando um problema de bloqueio ou deadlocks.

Para resolver esses problemas, é necessário implementar mecanismos de sincronização, como semáforos ou mutexes, para garantir que o acesso ao buffer e à variável counter seja feito de forma exclusiva. Também é necessário implementar condições para detectar quando o buffer está cheio ou vazio, para que o produtor e o consumidor possam esperar ou notificar uns aos outros adequadamente.

# Implementação com semáforo

Código fonte: [prod_cons_sem.c](prod_cons_sem.c)

Um semáforo é uma variável especial que pode ser usada para garantir a exclusão mútua e sincronização entre threads. No contexto do produtor-consumidor, podemos utilizar semáforos para controlar o acesso ao buffer e para controlar o número de espaços vazios no buffer (empty).
