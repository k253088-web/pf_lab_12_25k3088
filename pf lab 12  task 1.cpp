#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, p;
    int i, j, k;
    printf("Enter rows of A (m): ");
    scanf("%d", &m);
    printf("Enter columns of A / rows of B (n): ");
    scanf("%d", &n);
    printf("Enter columns of B (p): ");
    scanf("%d", &p);
   
    int **A = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
        A[i] = (int *)malloc(n * sizeof(int));

    int **B = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        B[i] = (int *)malloc(p * sizeof(int));
        
    int **C = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
        C[i] = (int *)malloc(p * sizeof(int));
        
    printf("\nEnter Matrix A (%dx%d):\n", m, n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
            
    printf("\nEnter Matrix B (%dx%d):\n", n, p);
    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
            scanf("%d", &B[i][j]);
            
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResultant Matrix C (%dx%d):\n", m, p);
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++)
            printf("%3d ", C[i][j]);
        printf("\n");
    }

    for (i = 0; i < m; i++)
        free(A[i]);
    free(A);
    for (i = 0; i < n; i++)
        free(B[i]);
    free(B);
    for (i = 0; i < m; i++)
        free(C[i]);
    free(C);

    return 0;
}
