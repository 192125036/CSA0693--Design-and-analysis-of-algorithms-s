#include <stdio.h>

void generatePrimes(int n) {
    // Create a boolean array "isPrime[0..n]" and initialize all entries as true.
    // A value in isPrime[i] will finally be false if i is Not a prime, else true.
    int isPrime[n + 1];
    for (int i = 0; i <= n; i++) {
        isPrime[i] = 1;
    }
    
    for (int p = 2; p * p <= n; p++) {
        // If isPrime[p] is still true, then it is a prime.
        if (isPrime[p] == 1) {
            // Update all multiples of p.
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = 0;
            }
        }
    }

    // Print prime numbers.
    printf("Prime numbers between 2 and %d are:\n", n);
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("There are no prime numbers in the given range.\n");
    } else {
        generatePrimes(n);
    }

    return 0;
}
