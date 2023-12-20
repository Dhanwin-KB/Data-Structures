#include <stdio.h>

int linearSearch(int arr[], int n, int x, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int x, int *comparisons) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        (*comparisons)++;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int sentinelSearch(int arr[], int n, int x, int *comparisons) {
    int last = arr[n - 1];
    arr[n - 1] = x;
    int i = 0;
    while (arr[i] != x) {
        (*comparisons)++;
        i++;
    }
    arr[n - 1] = last;
    if (i < n - 1 || arr[n - 1] == x)
        return i;
    return -1;
}

void bubbleSort(int arr[], int n, int *comparisons) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}

int main() {
    int a[25], n, keyword, choice, comparisons = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\n1. Linear Search\n2. Binary Search\n3. Sentinel Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter the element to search: ");
    scanf("%d", &keyword);

    switch (choice) {
        case 1:
            linearSearch(a, n, keyword, &comparisons);
            break;
        case 2:
            bubbleSort(a, n, &comparisons);
            binarySearch(a, n, keyword, &comparisons);
            break;
        case 3:
            sentinelSearch(a, n, keyword, &comparisons);
            break;
        default:
            printf("Invalid choice");
            return 1;
    }

    printf("Element comparisons: %d\n", comparisons);
    return 0;
}
