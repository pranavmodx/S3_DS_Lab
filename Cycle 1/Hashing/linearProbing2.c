#include <stdio.h>
#include <stdlib.h>

int hash(int x, int size)
{
    return x % size;
}

int *linearProbe(int arr[], int size)
{
    int i = 0;
    static int newArr[10] = {};
    // arr[size] = {} or { 0 } initialises all elements to zero at once.
    // 'static' needed because local variables don't exist in memory after function call.
    // arrays can't be returned by functions directly in C/C++.

    while (i < size)
    {
        int key = hash(arr[i], size);

        if (newArr[key] == 0)
            newArr[key] = arr[i];
        else
        {
            int j = i;
            int offset = 1;
            int key2 = hash(key + offset, size);

            while (key2 != key)
            {
                key2 = hash(key + offset, size);

                if (newArr[key2] == 0)
                {
                    newArr[key2] = arr[i];
                    break;
                }
                else
                {
                    j++;
                    offset++;
                }
            }
        }
        i++;
    }
    return newArr;
}

int main()
{
    int n, size = 10, *newArr;

    printf("Enter size of array : ");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));

    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    newArr = linearProbe(arr, size);

    printf("\n New array is : ");
    for (i = 0; i < size; i++)
        printf("%d \t", newArr[i]);
    printf("\n");

    return 0;
}