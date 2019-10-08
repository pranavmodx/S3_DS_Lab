#include <stdio.h>

int binSearch(int arr[], int n, int item)
{
    int lower = 0;
    int upper = n;
    int mid;

    int i;
    for (i = 0; i < n; i++)
    {
        mid = (lower + upper) / 2;
        if (item > arr[mid])
        {
            lower = mid + 1;
        }
        else if (item < arr[mid])
        {
            upper = mid - 1;
        }
        else
            return mid;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 4, 10, 15, 18, 19, 20, 25, 30, 31, 40, 100, 150};
    int n = sizeof(arr) / sizeof(arr[0]);
    int idx = binSearch(arr, n, 31);
    printf("Element found at index %d \n", idx);
    return 0;
}
