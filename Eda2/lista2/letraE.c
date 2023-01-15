#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

void quickselect(int *arr, int low, int high, int k) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        if (pivot == k) {
            return;
        } else if (pivot > k) {
            quickselect(arr, low, pivot - 1, k);
        } else {
            quickselect(arr, pivot + 1, high, k);
        }
    }
}

int main() {
    int n, p, x;
    scanf("%d %d %d", &n, &p, &x);
    int *v = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int start = x * p;
    quickselect(v, 0, n - 1, start);
    quickselect(v, start + 1, n - 1, start + x - 1);
    quicksort(v, start, start + x - 1);

    for (int i = start; i <= start + x - 1; i++) {
        printf("%d\n", v[i]);
    }

    free(v);
    return 0;
}
