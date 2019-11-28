#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
int partition(int arr[], int lb, int ub) {
    int low = lb;
    int high = ub;
    int pivot = arr[lb]; // Assigns first element as pivot

    while (low < high) {
        while (arr[low] <= pivot && low < ub) // low < ub ensures bound check
            low++;
        while (arr[high] > pivot) 
            high--;
        if (low < high) 
            swap(&arr[low], &arr[high]);
    }
    swap(&arr[lb], &arr[high]); // The 'pivot' is placed at the correct index, ie, it is sorted
    return high; // 'high' is the partitioned index using which recursive calls can be made
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) { // Checks that atleast 2 elements are present
        int pt_idx = partition(arr, lb, ub);
        quickSort(arr, lb, pt_idx - 1); // First half
        quickSort(arr, pt_idx + 1, ub); // Second half
    }
}

void display(int arr[], int n) {
    int i;
    for (i=0; i<n; i++)
        printf("%d ", arr[i]);
} 

int main() {
    int arr[] = {4, 100, 7, 10, 9, 11, 2, 3, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n);
    display(arr, n);

    return 0;
}
