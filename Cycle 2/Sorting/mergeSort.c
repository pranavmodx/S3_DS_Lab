#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
    // Merge Sort requires auxilliary array for sorting
    int arr2[high+1];
    int i = low,
        j = mid+1,
        k = low;
    
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }

    // Copies rest of the elements in either of the arrays
    for (; i<=mid; i++)
        arr2[k++] = arr[i];
    for (; j<=high; j++)
        arr2[k++] = arr[j];

    // Transfers sorted elements back to main array
    for (i=low; i<=high; i++)
        arr[i] = arr2[i];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void display(int arr[], int n) {
    int i;
    for (i=0; i<n; i++)
        printf("%d ", arr[i]);
} 
 
int main() {
    int arr[] = {2, 5, 8, 12, 3, 6, 7, 10, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    // merge(arr, 0, n/2, n-1);
    mergeSort(arr, 0, n-1);
    display(arr, n);
 
    return 0;
}