#include <stdio.h>

// 冒泡排序
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("Round %d: \n", i + 1);
        for (int j = 0; j < n - 1 - i; j++) {
            printf("Compare arr[%d]=%d and arr[%d]=%d. \n", j, arr[j], j + 1, arr[j + 1]);
            if (arr[j] > arr[j + 1]) {
                // 交换
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printf("Swap arr[%d] and arr[%d]\n", j, j + 1);
                printf("After swap: ");
                for (int k = 0; k < n; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
    }
}

// 快速排序
void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        printf("\n=== Quick Sort Partition ===\n");
        printf("Partition range: [%d, %d]\n", left, right);
        printf("Current array: ");
        for (int k = left; k <= right; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

        int pivot = arr[left];
        printf("Pivot element: arr[%d] = %d\n", left, pivot);
        int i = left;
        int j = right;

        while (i < j) {
            printf("\n--- Step ---\n");
            printf("i = %d, j = %d\n", i, j);
            printf("Current array: ");
            for (int k = left; k <= right; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");

            // 从右向左找小于pivot的元素
            while (arr[j] >= pivot && i < j) {
                printf("Compare arr[%d]=%d with pivot=%d: >= pivot, j--\n", j, arr[j], pivot);
                j--;
            }
            if (i < j) {
                printf("Found arr[%d]=%d < pivot, move to arr[%d]\n", j, arr[j], i);
                arr[i] = arr[j];
                printf("After move: ");
                for (int k = left; k <= right; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }

            // 从左向右找大于pivot的元素
            while (arr[i] <= pivot && i < j) {
                printf("Compare arr[%d]=%d with pivot=%d: <= pivot, i++\n", i, arr[i], pivot);
                i++;
            }
            if (i < j) {
                printf("Found arr[%d]=%d > pivot, move to arr[%d]\n", i, arr[i], j);
                arr[j] = arr[i];
                printf("After move: ");
                for (int k = left; k <= right; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }

        // 放置基准值
        arr[i] = pivot;
        printf("\n=== Partition Complete ===\n");
        printf("Pivot position: arr[%d] = %d\n", i, pivot);
        printf("Partitioned array: ");
        for (int k = left; k <= right; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
        printf("Left subarray: [%d, %d], Right subarray: [%d, %d]\n", left, i-1, i+1, right);

        // 递归排序左右子数组
        quick_sort(arr, left, i - 1);
        quick_sort(arr, i + 1, right);
    }
}

int main() {
    int arr[] = {45, 32, 84, 16, 13, 37, 7, 9, 8, 0};
    // int arr[10];
    // for (int i = 0; i < 10; i++) {
    //     scanf("%d", &arr[i]);
    // }
    int n = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // quick_sort(arr, 0, n - 1);
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    return 0;
}
