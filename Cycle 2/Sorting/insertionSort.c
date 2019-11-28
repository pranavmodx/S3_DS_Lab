#include <stdio.h>

void insertionSort(int arr[], int n) {
    // Like Bubble Sort, Insertion Sort is also adaptive and stable
    // It is adaptive by nature. There's no need for flag
    int i, j;
    int key;
    for (i=1; i<n; i++) {
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    insertionSort(arr,n);
    display(arr, n);
 
    return 0;
}