/* Program to compare Linear Search, Binary Search, Bubble Sort,
   Selection Sort, and Quick Sort using execution time and comparisons */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

// Function to perform Linear Search
int linearSearch(int a[], int n, int target, int *comp) {
    *comp = 0;
    for (int i = 0; i < n; i++) {
        (*comp)++;
        if (a[i] == target)
            return i;
    }
    return -1;
}

// Function to perform Binary Search
int binarySearch(int a[], int n, int target, int *comp) {
    int low = 0, high = n - 1;
    *comp = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        (*comp)++;

        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Function to perform Bubble Sort
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        int t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
}

// Function used in Quick Sort (partitioning)
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    int t = a[i + 1];
    a[i + 1] = a[high];
    a[high] = t;

    return i + 1;
}

// Function to perform Quick Sort
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int arr[N], sorted[N];
    int target, comp;

    srand(time(NULL));

    // Generate random array
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10000 + 1;
    }

    // Pick random target
    target = arr[rand() % N];

    printf("Target = %d\n", target);

    // Linear Search
    int index1 = linearSearch(arr, N, target, &comp);
    printf("Linear Search index = %d\n", index1);
    printf("Linear Search comparisons = %d\n", comp);

    // Copy array for sorting
    for (int i = 0; i < N; i++) {
        sorted[i] = arr[i];
    }

    // Sort using Quick Sort for Binary Search
    quickSort(sorted, 0, N - 1);

    // Binary Search
    int index2 = binarySearch(sorted, N, target, &comp);
    printf("Binary Search index = %d\n", index2);
    printf("Binary Search comparisons = %d\n", comp);

    return 0;
}