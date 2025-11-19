#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// 选择排序

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // 交换元素
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    // 初始化随机数种子
    srand(time(NULL));

    // 随机填充数组 10 个元素
    int arr[10];
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }

    // 输出原始数组
    printf("原始数组：");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, size);
    printf("排序后的数组：");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
