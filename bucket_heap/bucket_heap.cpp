#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    float value;
    struct Node *next;
};

void insert(struct Node **bucket, float value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;

    if (*bucket == NULL) {
        *bucket = newNode;
        return;
    }

    if (value < (*bucket)->value) {
        newNode->next = *bucket;
        *bucket = newNode;
        return;
    }

    struct Node *current = *bucket;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printBucket(struct Node *bucket) {
    while (bucket != NULL) {
        printf("%.2f ", bucket->value);
        bucket = bucket->next;
    }
}

void bucketSort(float arr[], int n) {
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        insert(&buckets[index], arr[i]);
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printBucket(buckets[i]);
    }
    printf("\n");
}

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    srand(time(NULL));

    float *arr = (float *)malloc(length * sizeof(float));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < length; i++) {
        arr[i] = (float)rand() / RAND_MAX; // Generate random float between 0 and 1
    }

    bucketSort(arr, length);

    free(arr);

    return 0;
}
