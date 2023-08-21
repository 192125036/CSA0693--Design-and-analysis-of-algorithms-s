#include <stdio.h>

struct MaxMin {
    int max;
    int min;
};

struct MaxMin findMaxMin(int arr[], int left, int right) {
    struct MaxMin result, leftResult, rightResult;

    if (left == right) {
        result.max = arr[left];
        result.min = arr[left];
        return result;
    }

    int mid = (left + right) / 2;
    leftResult = findMaxMin(arr, left, mid);
    rightResult = findMaxMin(arr, mid + 1, right);

    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;
    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;

    return result;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct MaxMin result = findMaxMin(arr, 0, n - 1);

    printf("Maximum value: %d\n", result.max);
    printf("Minimum value: %d\n", result.min);

    return 0;
}
