#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int n; // Number of cities
int graph[MAX_CITIES][MAX_CITIES]; // Distance matrix

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) { // All cities visited
        return graph[pos][0]; // Return to the starting city
    }

    int minCost = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // City not visited
            int newMask = mask | (1 << city);
            int newCost = graph[pos][city] + tsp(newMask, city);
            minCost = (newCost < minCost) ? newCost : minCost;
        }
    }

    return minCost;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startCity = 0; // Starting city is assumed to be 0
    int mask = 1 << startCity;

    int result = tsp(mask, startCity);
    printf("Minimum distance for the TSP: %d\n", result);

    return 0;
}
