#include <stdio.h>

int main() {
    int num;
    unsigned long long factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }

    printf("Factorial of %d is %llu\n", num, factorial);

    return 0;
}
