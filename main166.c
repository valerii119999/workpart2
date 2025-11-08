#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Использование: %s \n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("error\n");
        return 1;
    }
    int N, M;
    fscanf(file,"%d", &N, &M);
 
    int **S = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        S[i] = (int*)malloc(M * sizeof(int));
        for (int j = 0; j < M; j++) {
            fscanf(file, "%d", &S[i][j]);
        }
    }
    fclose(file);

    int *C = (int*)malloc(N * sizeof(int));
    printf(" C (произведения строк): ");
    for (int i = 0; i < N; i++) {
        C[i] = 1;
        for (int j = 0; j < M; j++) {
            C[i] *= S[i][j];
        }
        printf("%d ", C[i]);
    }
    printf("\n");

    int max_positive = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] > 0 && (max_positive == -1 || S[i][j] > max_positive)) {
                max_positive = S[i][j];
            }
        }
    }
    if (max_positive == -1) {
        printf("positive elements not found\n");
    } else {
        printf("max positive element: %d\n", max_positive);
    }

    if (M >= 3) {
        printf("start S[0][2] = %d\n", S[0][2]);
        S[0][2] = max_positive;
        printf("finish S[0][2] = %d\n", S[0][2]);
    } else {
        printf("in first line 3 elements\n");
    }

    for (int i = 0; i < N; i++) {
        free(S[i]);
    }
    free(S);
    free(C);

    return 0;
}