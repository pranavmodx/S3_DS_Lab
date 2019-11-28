#include <stdio.h>
#include <stdlib.h>

int hash(int x, int size)
{
    return x % size;
}

void linearProbe(int arr[], int newArr[], int size)
{
    int i = 0;

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

    printf("New array is : ");
    for (i = 0; i < 10; i++)
        printf("%d \t", newArr[i]);
    printf("\n");
}

int main()
{
    int n, size = 10, newArr[10] = {};

    printf("Enter size of array : ");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));

    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    linearProbe(arr, newArr, size);

    return 0;
}