#include <stdio.h>

void multiplyMatrices(int A[][100], int B[][100], int result[][100], int m, int n, int p, int q) {
    if (n != p) {
        printf("Matrices cannot be multiplied.\n");
        return;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n, p, q;
    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &m, &n);
    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Matrices cannot be multiplied.\n");
        return 1;
    }

    int A[100][100], B[100][100], result[100][100];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    multiplyMatrices(A, B, result, m, n, p, q);

    printf("Resultant matrix:\n");
    displayMatrix(result, m, q);

    return 0;
}
