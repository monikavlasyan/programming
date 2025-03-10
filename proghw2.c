//ex1
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char ch;
    int row = 1, col = 1;  // Track row and column numbers
    char filename[] = __FILE__;  // This gets the current file name (works in GCC)

    // Open the current file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Searching for parentheses in file: %s\n\n", filename);
    printf("Parenthesis locations (row, column):\n");

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '{' || ch == '}') {
            printf("Found '%c' at row %d, column %d\n", ch, row, col);
        }

        // Update row and column based on character
        if (ch == '\n') {
            row++;
            col = 1;  // Reset column to 1 for the new row
        } else {
            col++;  // Increment column for each character
        }
    }

    // Close the file after reading
    fclose(file);

    return 0;
}

//ex2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024  // Max length for each line of the CSV

// Function to search and print rows based on the user's input
void searchCSV(FILE *file, int column, const char *search_value) {
    char line[MAX_LINE_LENGTH];
    int row_num = 0;

    // Skip the first line (column headers)
    if (fgets(line, sizeof(line), file) == NULL) {
        printf("Error reading file or empty file.\n");
        return;
    }

    // Read through each row in the CSV
    while (fgets(line, sizeof(line), file) != NULL) {
        row_num++;
        char *token;
        int current_col = 1;
        int found = 0;

        // Tokenize the row using ',' as delimiter
        token = strtok(line, ",\n");

        // Search in the specified column
        while (token != NULL) {
            if (current_col == column && strcmp(token, search_value) == 0) {
                found = 1;
                break;
            }
            token = strtok(NULL, ",\n");
            current_col++;
        }

        // If found, print the entire row
        if (found) {
            printf("Row %d: %s", row_num + 1, line);
        }
    }
}

int main() {
    FILE *file;
    char filename[100];
    int column;
    char search_value[100];

    // Get the file name from the user
    printf("Enter the CSV filename: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Get the column number and search value from the user
    printf("Enter the column number to search (1-based): ");
    scanf("%d", &column);

    printf("Enter the value to search for: ");
    scanf(" %99[^\n]", search_value);  // Read the search value with spaces

    // Search and print the matching rows
    printf("Searching for '%s' in column %d...\n", search_value, column);
    searchCSV(file, column, search_value);

    // Close the file
    fclose(file);
    return 0;
}

//ex3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse the string in-place using pointer arithmetic
void reverseString(char *str) {
    // Check if the string is NULL or empty
    if (str == NULL || *str == '\0') {
        printf("Error: String is empty or NULL.\n");
        return;
    }

    // Use two pointers to reverse the string
    char *start = str;  // Pointer to the start of the string
    char *end = str + strlen(str) - 1;  // Pointer to the end of the string

    // Swap characters until start and end pointers meet
    while (start < end) {
        // Swap the characters at the start and end pointers
        char temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers towards the center
        start++;
        end--;
    }
}

int main() {
    // Input string
    char str[100];

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if it's present
    str[strcspn(str, "\n")] = '\0';

    // Reverse the string
    reverseString(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}

//ex4
#include <stdio.h>
#include <string.h>

// Function to compress the string in-place
void compressString(char *str) {
    // Check for empty or NULL string
    if (str == NULL || *str == '\0') {
        printf("Error: String is empty or NULL.\n");
        return;
    }

    int length = strlen(str);
    int writeIndex = 0;  // Index to write compressed result
    int count = 1;  // To count occurrences of each character

    for (int i = 1; i <= length; i++) {
        // Check if current character is the same as the previous one
        if (str[i] == str[i - 1] && i < length) {
            count++;
        } else {
            // Write the current character to the result
            str[writeIndex++] = str[i - 1];

            // Write the count if it's greater than 1
            if (count > 1) {
                writeIndex += sprintf(&str[writeIndex], "%d", count);
            }

            // Reset count for the next character
            count = 1;
        }
    }

    // Null-terminate the compressed string
    str[writeIndex] = '\0';
}

int main() {
    // Input string
    char str[100];

    // Prompt the user to enter a string
    printf("Enter a string to compress: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if it's present
    str[strcspn(str, "\n")] = '\0';

    // Compress the string
    compressString(str);

    // Print the compressed string
    printf("Compressed string: %s\n", str);

    return 0;
}

//ex5
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define MAX 1000  // Maximum dimension size for testing

// Struct to pass arguments to the threads
typedef struct {
    int M, N, P;
    int (*A)[MAX];
    int (*B)[MAX];
    int (*C)[MAX];
    int row;
} ThreadData;

// Sequential matrix multiplication function
void multiplySequential(int M, int N, int P, int A[M][N], int B[N][P], int C[M][P]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function for thread execution to perform matrix multiplication row-wise
void* multiplyRow(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int row = data->row;
    int M = data->M, N = data->N, P = data->P;
    int (*A)[MAX] = data->A;
    int (*B)[MAX] = data->B;
    int (*C)[MAX] = data->C;

    // Perform the multiplication for the specific row assigned to the thread
    for (int j = 0; j < P; j++) {
        C[row][j] = 0;
        for (int k = 0; k < N; k++) {
            C[row][j] += A[row][k] * B[k][j];
        }
    }

    return NULL;
}

// Parallel matrix multiplication function
void multiplyParallel(int M, int N, int P, int A[M][N], int B[N][P], int C[M][P]) {
    pthread_t threads[M];
    ThreadData threadData[M];

    // Create threads to compute each row of matrix C
    for (int i = 0; i < M; i++) {
        threadData[i].M = M;
        threadData[i].N = N;
        threadData[i].P = P;
        threadData[i].A = A;
        threadData[i].B = B;
        threadData[i].C = C;
        threadData[i].row = i;

        // Create a new thread to compute the ith row of C
        pthread_create(&threads[i], NULL, multiplyRow, (void*)&threadData[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < M; i++) {
        pthread_join(threads[i], NULL);
    }
}

// Function to get the time in seconds
double getTime() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec + time.tv_usec / 1000000.0;
}

int main() {
    int M, N, P;

    // User input for matrix dimensions
    printf("Enter dimensions for matrix A (MxN) and matrix B (NxP):\n");
    printf("M (rows of A, rows of C): ");
    scanf("%d", &M);
    printf("N (columns of A, rows of B): ");
    scanf("%d", &N);
    printf("P (columns of B, columns of C): ");
    scanf("%d", &P);

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    
    // Initialize matrices A and B with random values
    srand(time(NULL));
    printf("Matrix A (%dx%d):\n", M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;  // Random values between 0 and 9
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B (%dx%d):\n", N, P);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            B[i][j] = rand() % 10;  // Random values between 0 and 9
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Sequential Matrix Multiplication
    double startTime = getTime();
    multiplySequential(M, N, P, A, B, C);
    double endTime = getTime();
    printf("\nTime taken for sequential matrix multiplication: %f seconds\n", endTime - startTime);

    // Parallel Matrix Multiplication
    double startParallelTime = getTime();
    multiplyParallel(M, N, P, A, B, C);
    double endParallelTime = getTime();
    printf("\nTime taken for parallel matrix multiplication: %f seconds\n", endParallelTime - startParallelTime);

    return 0;
}
