#include <stdio.h>

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void heapify(int arr[], int n, int i) {
	// Max heap

	int largest = i;
	int lChild = 2 * i + 1;
	int rChild = 2 * i + 2; 

	if (lChild < n && arr[lChild] > arr[largest]) 
		largest = lChild;

	if (rChild < n && arr[rChild] > arr[largest])
		largest = rChild;

	if (largest != i) {
		swap(&arr[i], &arr[largest]);

		// Heapify affected sub-tree
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	int i;

	for (i = (n / 2) - 1; i >= 0; i--) {
		// (n / 2) - 1 is the index of the last 'non-leaf' node
		// since leaf nodes are already a heap, there's no need to heapify them

		heapify(arr, n, i);
	}

	for (i = n - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);

		heapify(arr, i, 0);
	}

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n");
}


int main() {
	int arr[] = {4, 1, 5, 2, 9, 0, 3};
	int size = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, size);

	return 0;
}