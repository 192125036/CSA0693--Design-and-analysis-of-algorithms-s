#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compareItems(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    return ratioB - ratioA;
}

int knapsackGreedy(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compareItems);

    int totalValue = 0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter the values and weights of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int maxValue = knapsackGreedy(capacity, items, n);
    printf("Maximum value that can be obtained: %d\n", maxValue);

    return 0;
}
