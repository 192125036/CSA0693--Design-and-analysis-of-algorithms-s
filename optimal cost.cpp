#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to compare items by their value per unit weight
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    if (ratio1 > ratio2)
        return -1;
    else if (ratio1 < ratio2)
        return 1;
    return 0;
}

// Function to find the maximum value that can be obtained
double knapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += (double)items[i].value / items[i].weight * capacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter the values and weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = knapsack(capacity, items, n);
    printf("The maximum value that can be obtained is: %.2f\n", maxValue);

    return 0;
}
