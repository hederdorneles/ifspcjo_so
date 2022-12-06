/*
 * Simulação do escalonamento FCFS
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Process structure
typedef struct process
{
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // CPU burst time
    int wait;       // Wait time
    int turn;       // Turnaround time
} process;

// FCFS scheduler function
void fcfs_scheduler(process* processes, int num_processes) {
    // Initialize current time to 0
    int current_time = 0;
    // Loop through processes
    for (int i = 0; i < num_processes; i++) {
        // Get process
        process* p = &processes[i];

        // Check if process has arrived
        if (p->arrival > current_time) {
            // Update current time to arrival time
            current_time = p->arrival;
        }

        // Calculate wait time
        p->wait = current_time - p->arrival;

        // Calculate turnaround time
        p->turn = p->wait + p->burst;

        // Update current time
        current_time += p->burst;
    }
}

// Main function
int main(void) {
    // Process array
    process processes[] = {
    {1, 0, 10, 0, 0},
    {2, 3, 5, 0, 0},
    {3, 6, 7, 0, 0},
    {4, 10, 4, 0, 0}
    };
    // Number of processes
    int num_processes = sizeof(processes) / sizeof(process);

    // Run FCFS scheduler
    fcfs_scheduler(processes, num_processes);

    // Print Gantt chart
    printf("Gantt Chart:\n");
    printf("|");
    for (int i = 0; i < num_processes; i++) {
        process* p = &processes[i];
        for (int j = 0; j < p->burst; j++)
        {
            printf("-");
        }
        printf("P%d", p->id);
        for (int j = 0; j < p->burst; j++) {
            printf("-");
        }
        printf("|");
    }
    printf("\n");

    // Print wait times
    printf("\nWait Times:\n");
    for (int i = 0; i < num_processes; i++) {
        process* p = &processes[i];
        printf("P%d: %d\n", p->id, p->wait);
    }

    // Print turnaround times
    printf("\nTurnaround Times:\n");
    for (int i = 0; i < num_processes; i++) {
        process* p = &processes[i];
        printf("P%d: %d\n", p->id, p->turn);
    }

    return 0;
}
