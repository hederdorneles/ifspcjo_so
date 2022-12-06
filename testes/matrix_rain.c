#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define matrix size and number of columns
#define ROWS 20
#define COLUMNS 50

// Function to print the matrix
void print_matrix(char matrix[ROWS][COLUMNS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to update the matrix with new characters
void update_matrix(char matrix[ROWS][COLUMNS]) {
    int i, j;
    // Shift all characters up by one row
    for (i = 0; i < ROWS - 1; i++) {
        for (j = 0; j < COLUMNS; j++)
        {
            matrix[i][j] = matrix[i + 1][j];
        }
    }

    // Generate new characters for the bottom row
    for (j = 0; j < COLUMNS; j++) {
        matrix[ROWS - 1][j] = rand() % 94 + 33; // Generate a random ASCII character between '!' and '~'
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    // Initialize matrix with spaces
    char matrix[ROWS][COLUMNS];
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            matrix[i][j] = ' ';
        }
    }

    // Run the matrix rain simulation
    while (1) {
        print_matrix(matrix);
        update_matrix(matrix);
        usleep(100000); // Sleep for 100ms to slow down the rain
    }
    
    return 0;
}
