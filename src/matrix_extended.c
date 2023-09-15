#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void mode1(int M, int N);

int input_static(int M, int N, int matrix[MAX][MAX]);
void maxmin_static(int M, int N, int matrix[MAX][MAX], int max[MAX], int min[MAX]);
void output_static(int M, int N, int matrix[MAX][MAX], int max[MAX], int min[MAX]);

void mode2(int M, int N);
void mode3(int M, int N);
void mode4(int M, int N);

int input_dynamic(int** matrix, int M, int N);
void maxmin_dynamic(int M, int N, int** matrix, int* max, int* min);
void output_dynamic(int M, int N, int** matrix, int* max, int* min);

void maxmin_dynamic();

int main() {
    int mode, M, N;
    if ((scanf("%d", &mode) == 1) && (getc(stdin) == '\n') && (mode >= 1) && (mode <= 4)) {

        if ((scanf("%d %d", &M, &N) == 2) && (M > 0) && (N > 0) && (getc(stdin) == '\n')) {

            switch (mode) {
            case 1:
                mode1(M, N);
                break;
            case 2:
                mode2(M, N);
                break;
            case 3:
                mode3(M, N);
                break;
            case 4:
                mode4(M, N);
                break;
            }
        } else printf("n/a");
    } else printf("n/a");
}

void mode1(int M, int N) {
    if ((M < MAX) && (N < MAX)) {
        int matrix[MAX][MAX], max[M], min[N];

        if (input_static(M, N, matrix) == 1) {
            maxmin_static(M, N, matrix, max, min);
            output_static(M, N, matrix, max, min);
        } else printf("n/a");
    } else printf("n/a");
}

int input_static(int M, int N, int matrix[MAX][MAX]) {
    int flag = 1;
    for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (scanf("%d", &matrix[i][j]) != 1) {
                    flag = 0;
                    break;
                }
            }
        }
    if (getc(stdin) != '\n') flag = 0;

    return flag;
}

void maxmin_static(int M, int N, int matrix[MAX][MAX], int max[MAX], int min[MAX]) {
    for (int i = 0; i < M; i++) {
        int max_v = matrix[i][0];
        for (int j = 0; j < N; j++) {
            if (max_v < matrix[i][j]) max_v = matrix[i][j];
        }
        max[i] = max_v;
    }

    for (int j = 0; j < N; j++) {
        int min_v = matrix[0][j];
        for (int i = 0; i < M; i++) {
            if (min_v > matrix[i][j]) min_v = matrix[i][j];
        }
        min[j] = min_v;
    }
}

void output_static(int M, int N, int matrix[MAX][MAX], int max[MAX], int min[MAX]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) 
            (j != N - 1) ? printf("%d ", matrix[i][j]) : printf("%d", matrix[i][j]);
        printf("\n");
    }
    
    for (int i = 0; i < M; i++) {
        (i != M - 1) ? printf("%d ", max[i]) : printf("%d\n", max[i]);
    }

    for (int j = 0; j < N; j++) {
        (j != N - 1) ? printf("%d ", min[j]) : printf("%d", min[j]);
    }

}

void mode2(int M, int N) {
    int** matrix = malloc((M + M * N) * sizeof(int));
    int* start = (int*) (matrix + M);
    for (int i = 0; i < M; i++) 
        matrix[i] = start + i * N;

    int* max = malloc(M * sizeof(int));
    int* min = malloc(N * sizeof(int));
    
    if (input_dynamic(matrix, M, N) == 1) {
        maxmin_dynamic(M, N, matrix, max, min);
        output_dynamic(M, N, matrix, max, min);
    } else printf("n/a");

    free(matrix);
    free(max);
    free(min);
}

void mode3(int M, int N) {
    int** matrix = malloc(M * sizeof(int));
    for (int i = 0; i < M; i++)
        matrix[i] = malloc(N * sizeof(int));

    int* max = malloc(M * sizeof(int));
    int* min = malloc(N * sizeof(int));
    
    if (input_dynamic(matrix, M, N) == 1) {
        maxmin_dynamic(M, N, matrix, max, min);
        output_dynamic(M, N, matrix, max, min);
    } else printf("n/a");

    for (int i = 0; i < M; i++)
        free(matrix[i]); 
    free(matrix);
    free(max);
    free(min);
}

void mode4(int M, int N) {
    int** matrix = malloc(M * sizeof(int));
    int* values = malloc(M * N * sizeof(int));
    for (int i = 0; i < M; i++)
        matrix[i] = values + i * N;

    int* max = malloc(M * sizeof(int));
    int* min = malloc(N * sizeof(int));
    
    if (input_dynamic(matrix, M, N) == 1) {
        maxmin_dynamic(M, N, matrix, max, min);
        output_dynamic(M, N, matrix, max, min);
    } else printf("n/a");

    free(values);
    free(matrix);
    free(max);
    free(min);
}

int input_dynamic(int** matrix, int M, int N) {
    int flag = 1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                flag = 0;
                break;
            }
        }
    }
    if (getc(stdin) != '\n') flag = 0;

    return flag;
}

void maxmin_dynamic(int M, int N, int** matrix, int* max, int* min) {
    for (int i = 0; i < M; i++) {
        int max_v = matrix[i][0];
        for (int j = 0; j < N; j++) {
            if (max_v < matrix[i][j]) max_v = matrix[i][j];
        }
        max[i] = max_v;
    }

    for (int j = 0; j < N; j++) {
        int min_v = matrix[0][j];
        for (int i = 0; i < M; i++) {
            if (min_v > matrix[i][j]) min_v = matrix[i][j];
        }
        min[j] = min_v;
    }
}

void output_dynamic(int M, int N, int** matrix, int* max, int* min) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) 
            (j != N - 1) ? printf("%d ", matrix[i][j]) : printf("%d", matrix[i][j]);
        printf("\n");
    }

    for (int i = 0; i < M; i++) {
        (i != M - 1) ? printf("%d ", max[i]) : printf("%d\n", max[i]);
    }

    for (int j = 0; j < N; j++) {
        (j != N - 1) ? printf("%d ", min[j]) : printf("%d", min[j]);
    }
}