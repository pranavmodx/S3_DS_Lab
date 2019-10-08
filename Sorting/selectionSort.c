#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n) {
    int i, j;
    int min_idx;
    for (i=0; i<n-1; i++) {
        min_idx = i;
        for (j=i+1; j<n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(&arr[i], &arr[min_idx]);
    }
}

void display(int arr[], int n) {
    int i;
    for (i=0; i<n; i++)
        printf("%d ", arr[i]);
} 

int main() {
    int arr[] = {4, 1, 7, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    display(arr, n);
 
    return 0;
}