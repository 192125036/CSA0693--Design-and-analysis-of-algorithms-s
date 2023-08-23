#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int min = numbers[0];
    int max = numbers[0];

    printf("Minimum and maximum value sequences:\n");
    for (int i = 1; i < n; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        if (numbers[i] > max) {
            max = numbers[i];
        }
        printf("Minimum: %d, Maximum: %d\n", min, max);
    }

    return 0;
}
