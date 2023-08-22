#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 1; // 1 is always a divisor

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }

    return sum == num;
}

int main() {
    int lower, upper;

    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &lower, &upper);

    printf("Perfect numbers between %d and %d are:\n", lower, upper);
    for (int num = lower; num <= upper; num++) {
        if (isPerfect(num)) {
            printf("%d\n", num);
        }
    }

    return 0;
}
