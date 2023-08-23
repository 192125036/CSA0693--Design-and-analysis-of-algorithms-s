#include <stdio.h>

long binomialCoeff(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

void printPascalTriangle(int numRows) {
    for (int line = 0; line < numRows; line++) {
        for (int space = 0; space < numRows - line; space++)
            printf(" ");
        for (int i = 0; i <= line; i++)
            printf("%ld ", binomialCoeff(line, i));
        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    printPascalTriangle(numRows);

    return 0;
}
