#include <stdio.h>

int binSearch(int arr[], int lower, int upper, int item)
{
    if (upper >= 1)
    {
        int mid = (lower + upper) / 2;
        if (item > arr[mid])
        {
            return binSearch(arr, mid + 1, upper, item);
        }
        else if (item < arr[mid])
        {
            return binSearch(arr, lower, mid - 1, item);
        }
        else
            return mid;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 4, 10, 15, 18, 19, 20, 25, 30, 31, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int meow = binSearch(arr, 0, n, 19);
    printf("Element found at index %d \n", meow);
    return 0;
}