#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int finish_time;
    int turnaround_time;
    float normalized_time;
    int arrival_time;
} Process;

void runRoundRobin(Process processes[], int num_processes, int quantum) {
    int current_time = 0;
    int completed_processes = 0;
    int i = 0;

    while (completed_processes < num_processes) {
        if (processes[i].remaining_time > 0) {
            int execution_time = (processes[i].remaining_time > quantum) ? quantum : processes[i].remaining_time;
            processes[i].remaining_time -= execution_time;
            current_time += execution_time;

            if (processes[i].remaining_time == 0) {
                completed_processes++;
                processes[i].finish_time = current_time;
                processes[i].turnaround_time = processes[i].finish_time;
                processes[i].normalized_time = (float) processes[i].turnaround_time / processes[i].burst_time;
            }
        }

        i = (i + 1) % num_processes;
    }
}

int main(int argc, char *argv[]) {
    int num_processes;
    int quantum;

    if (argc == 2) {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            printf("Não foi possível abrir o arquivo %s. Lendo da entrada padrão.\n", argv[1]);
            printf("Digite o número de processos: ");
            scanf("%d", &num_processes);

            printf("Digite o valor do quantum: ");
            scanf("%d", &quantum);
        } else {
            fscanf(file, "%d %d", &num_processes, &quantum);
            fclose(file);
        }
    } else {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        printf("Lendo da entrada padrão.\n");

        printf("Digite o número de processos: ");
        scanf("%d", &num_processes);

        printf("Digite o valor do quantum: ");
        scanf("%d", &quantum);
    }

    Process processes[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
        printf("Digite o tempo de chegada e o tempo de burst para o processo %d (Ex. X Y): ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);

        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].finish_time = -1;
        processes[i].turnaround_time = 0;
        processes[i].normalized_time = 0.0;
    }

    runRoundRobin(processes, num_processes, quantum);

    printf("\nTabela de Resultados:\n");
    printf("ID | Tempo de Chegada | Tempo de Término | Turnaround Time | Tempo Normalizado\n");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%2d |        %2d        |        %2d        |        %2d        |       %.2f\n", 
               processes[i].id, processes[i].arrival_time, processes[i].finish_time, processes[i].turnaround_time, processes[i].normalized_time);
    }

    return 0;
}
