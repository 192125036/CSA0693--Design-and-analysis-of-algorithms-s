#include <stdio.h>
#include <limits.h>

// Function to calculate the optimal binary search tree cost
int optimalBSTCost(int keys[], int freq[], int n) {
    int dp[n+1][n+1]; // Dynamic programming table

    // Initialize the diagonal elements (single nodes)
    for (int i = 0; i < n; i++) {
        dp[i][i] = freq[i];
    }

    // Fill the table in a bottom-up manner
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Calculate the sum of frequencies in the range (i, j)
            int freqSum = 0;
            for (int k = i; k <= j; k++) {
                freqSum += freq[k];
            }

            // Try all possible roots in the range and find the optimal cost
            for (int r = i; r <= j; r++) {
                int cost = dp[i][r - 1] + dp[r + 1][j] + freqSum;
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1]; // Optimal cost for the whole tree
}

int main() {
    int keys[] = {10, 20, 30};
    int freq[] = {2, 3, 1};
    int n = sizeof(keys) / sizeof(keys[0]);

    int result = optimalBSTCost(keys, freq, n);
    printf("Optimal Binary Search Tree Cost: %d\n", result);

    return 0;
}
