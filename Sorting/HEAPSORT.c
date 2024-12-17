// WAP TO PERFORM HEAP SORT 

#include <stdio.h>

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, largest, temp, start, end;

    for (i = n / 2 - 1; i >= 0; i--) {
        j = i;
        while (j * 2 + 1 < n) {
            largest = j;
            if (j * 2 + 1 < n && arr[j * 2 + 1] > arr[largest]) {
                largest = j * 2 + 1;
            }
            if (j * 2 + 2 < n && arr[j * 2 + 2] > arr[largest]) {
                largest = j * 2 + 2;
            }
            if (largest == j) break;
            temp = arr[j];
            arr[j] = arr[largest];
            arr[largest] = temp;
            j = largest;
        }
    }

    for (end = n - 1; end > 0; end--) {
        temp = arr[0];
        arr[0] = arr[end];
        arr[end] = temp;
        j = 0;
        while (j * 2 + 1 < end) {
            largest = j;
            if (j * 2 + 1 < end && arr[j * 2 + 1] > arr[largest]) {
                largest = j * 2 + 1;
            }
            if (j * 2 + 2 < end && arr[j * 2 + 2] > arr[largest]) {
                largest = j * 2 + 2;
            }
            if (largest == j) break;
            temp = arr[j];
            arr[j] = arr[largest];
            arr[largest] = temp;
            j = largest;
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
