#include <stdio.h>

// Function to calculate binomial coefficient using dynamic programming
int binomialCoeff(int n, int k) {
    int dp[n + 1][k + 1];

    // Fill in the table using bottom-up approach
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i && j <= k; j++) {
            // Base cases
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                // Recurrence relation: C(n, k) = C(n-1, k-1) + C(n-1, k)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k]; // Return the computed binomial coefficient
}

int main() {
    int n = 5, k = 2;

    int result = binomialCoeff(n, k);
    printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, result);

    return 0;
}
