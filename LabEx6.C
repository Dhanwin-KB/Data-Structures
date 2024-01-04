#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct FinancialRecord 
{
    int month;
    double expenses;
};
double generateRandomExpense() 
{
    return (rand() % 1000) + 500.0;
}
struct FinancialRecord generateRandomMonth(int month) 
{
    struct FinancialRecord record;
    record.month = month;
    record.expenses = generateRandomExpense();
    return record;
}
void writeToFile(const char* filename, struct FinancialRecord data[], int size) 
{
    FILE* file = fopen(filename, "wb");
    if (!file) 
    {
        fprintf(stderr, "Error opening file for writing.\n");
        exit(EXIT_FAILURE);
    }
    fwrite(data, sizeof(struct FinancialRecord), size, file);
    fclose(file);
}
void readFromFile(const char* filename, struct FinancialRecord data[], int size) 
{
    FILE* file = fopen(filename, "rb");
    if (!file) 
    {
        fprintf(stderr, "Error opening file for reading.\n");
        exit(EXIT_FAILURE);
    }
    fread(data, sizeof(struct FinancialRecord), size, file);
    fclose(file);
}
void merge(struct FinancialRecord arr[], int left, int mid, int right, int* comparisons) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    struct FinancialRecord* L = (struct FinancialRecord*)malloc(n1 * sizeof(struct FinancialRecord));
    struct FinancialRecord* R = (struct FinancialRecord*)malloc(n2 * sizeof(struct FinancialRecord));
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) 
    {
        (*comparisons)++;
        if (L[i].expenses >= R[j].expenses) 
        {
            arr[k++] = L[i++];
        } 
        else 
        {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) 
    {
        arr[k++] = L[i++];
    }
    while (j < n2) 
    {
        arr[k++] = R[j++];
    }
    free(L);
    free(R);
}
void mergeSort(struct FinancialRecord arr[], int left, int right, int* comparisons) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);
        merge(arr, left, mid, right, comparisons);
    }
}
int partition(struct FinancialRecord arr[], int low, int high, int* comparisons) 
{
    double pivot = arr[high].expenses;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) 
    {
        (*comparisons)++;
        if (arr[j].expenses >= pivot) {
            i++;
            struct FinancialRecord temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    struct FinancialRecord temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
void quickSort(struct FinancialRecord arr[], int low, int high, int* comparisons) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}
int main() 
{
    srand((unsigned int)time(NULL));
    const int numMonths = 12;
    struct FinancialRecord dataMergeSort[numMonths];
    struct FinancialRecord dataQuickSort[numMonths];
    int choice, comparisonsMergeSort = 0, comparisonsQuickSort = 0;
    do 
    {
        printf("\nMenu:\n");
        printf("1. Generate and Perform Merge Sort\n");
        printf("2. Generate and Perform Quick Sort\n");
        printf("3. Compare Sorting Techniques\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                for (int i = 0; i < numMonths; i++) 
                {
                    dataMergeSort[i] = generateRandomMonth(i + 1);
                }
                writeToFile("merge_sort_data.dat", dataMergeSort, numMonths);
                readFromFile("merge_sort_data.dat", dataMergeSort, numMonths);
                comparisonsMergeSort = 0;  
                mergeSort(dataMergeSort, 0, numMonths - 1, &comparisonsMergeSort);
                printf("\nMerge Sort Result:\n");
                for (int i = 0; i < numMonths; i++) 
                {
                    printf("Month: %d, Expenses: %.2f\n", dataMergeSort[i].month, dataMergeSort[i].expenses);
                }
                printf("Number of comparisons in Merge Sort: %d\n", comparisonsMergeSort);
                break;
            case 2:
                for (int i = 0; i < numMonths; i++) 
                {
                    dataQuickSort[i] = generateRandomMonth(i + 1);
                }
                writeToFile("quick_sort_data.dat", dataQuickSort, numMonths);
                readFromFile("quick_sort_data.dat", dataQuickSort, numMonths);
                comparisonsQuickSort = 0;  
                quickSort(dataQuickSort, 0, numMonths - 1, &comparisonsQuickSort);
                printf("\nQuick Sort Result:\n");
                for (int i = 0; i < numMonths; i++) 
                {
                    printf("Month: %d, Expenses: %.2f\n", dataQuickSort[i].month, dataQuickSort[i].expenses);
                }
                printf("Number of comparisons in Quick Sort: %d\n", comparisonsQuickSort);
                break;
            case 3:
                if (comparisonsMergeSort == 0) 
                {
                    printf("Please perform Merge Sort first.\n");
                } 
                else if (comparisonsQuickSort == 0) 
                {
                    printf("Please perform Quick Sort first.\n");
                } 
                else 
                {
                    printf("\nComparing Sorting Techniques:\n");
                    printf("Number of comparisons in Merge Sort: %d\n", comparisonsMergeSort);
                    printf("Number of comparisons in Quick Sort: %d\n");
                    if (comparisonsMergeSort < comparisonsQuickSort) 
                    {
                        printf("Merge Sort is better.\n");
                    } 
                    else if (comparisonsQuickSort < comparisonsMergeSort) 
                    {
                        printf("Quick Sort is better.\n");
                    } 
                    else 
                    {
                        printf("Both sorting techniques have the same number of comparisons.\n");
                    }
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}