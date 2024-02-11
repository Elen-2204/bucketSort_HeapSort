#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(float arr[], int n, int i) {
    int largest = i;      
    int left = 2 * i + 1; 
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        float temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}


void heapSort(float arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        float temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    srand(time(NULL));

    float* arr = (float*)malloc(length * sizeof(float));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < length; i++) {
        arr[i] = (float)rand() / RAND_MAX;
    }

    heapSort(arr, length);

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%.4f ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
