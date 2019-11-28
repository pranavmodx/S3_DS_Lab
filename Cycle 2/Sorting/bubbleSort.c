#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n) {
    // Bubble sort is stable and adaptive sorting algorithm
    // It is not adaptive by nature. We must introduce flag
    int i, j;
    int flag = 0; // For Adaptivity
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) 
            break;
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
    bubbleSort(arr, n);
    display(arr, n);

    return 0;
}