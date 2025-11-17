#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ARRAY_SIZE 50
#define MAX_VALUE 999
#define MIN_VALUE 1

// 函数声明
void fillArray(int arr[], int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
int sequentialSearch(int arr[], int size, int target, int *foundIndex);
int binarySearch(int arr[], int size, int target, int *foundIndex);
void queryArray(int arr[], int size, int isSorted);
void findNearestValues(int arr[], int size, int target, int *lessThan, int *greaterThan);

int main()
{
    int arr[ARRAY_SIZE];
    int isSorted = 0; // 标记数组是否已排序
    char choice;

    srand(time(NULL)); // 初始化随机数生成器

    printf("菜单驱动的数组程序\n");
    printf("=========================\n\n");

    do
    {
        // 显示菜单
        printf("\n菜单\n");
        printf("请选择以下选项：\n");
        printf("F. 用随机数填充数组\n");
        printf("P. 打印数组\n");
        printf("S. 排序数组\n");
        printf("Q. 查询数组\n");
        printf("Z. 退出程序\n");
        printf("\n请输入选择（字母）：");

        scanf(" %c", &choice);
        choice = toupper(choice);

        switch (choice)
        {
        case 'F':
            fillArray(arr, ARRAY_SIZE);
            isSorted = 0; // 填充后数组变为未排序状态
            printf("数组已用随机数填充。\n");
            break;

        case 'P':
            printArray(arr, ARRAY_SIZE);
            break;

        case 'S':
            bubbleSort(arr, ARRAY_SIZE);
            isSorted = 1; // 标记为已排序
            printf("数组已排序。\n");
            break;

        case 'Q':
            queryArray(arr, ARRAY_SIZE, isSorted);
            break;

        case 'Z':
            printf("程序已退出。\n");
            break;

        default:
            printf("无效选择，请重试。\n");
        }

    } while (choice != 'Z');

    return 0;
}

// 用随机数填充数组
void fillArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
    }
}

// 打印数组
void printArray(int arr[], int size)
{
    if (size == 0)
    {
        printf("数组为空。\n");
        return;
    }

    printf("数组内容：\n");
    for (int i = 0; i < size; i++)
    {
        printf("%4d ", arr[i]);
        if ((i + 1) % 10 == 0)
        { // 每10个元素换行
            printf("\n");
        }
    }
    printf("\n");
}

// 冒泡排序
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // 交换元素
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 顺序查找
int sequentialSearch(int arr[], int size, int target, int *foundIndex)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            *foundIndex = i;
            return 1; // 找到
        }
    }
    return 0; // 未找到
}

// 二分查找
int binarySearch(int arr[], int size, int target, int *foundIndex)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            *foundIndex = mid;
            return 1; // 找到
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return 0; // 未找到
}

// 查找最接近的值
void findNearestValues(int arr[], int size, int target, int *lessThan, int *greaterThan)
{
    *lessThan = -1;
    *greaterThan = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < target)
        {
            if (*lessThan == -1 || arr[i] > *lessThan)
            {
                *lessThan = arr[i];
            }
        }
        else if (arr[i] > target)
        {
            if (*greaterThan == -1 || arr[i] < *greaterThan)
            {
                *greaterThan = arr[i];
            }
        }
    }
}

// 查询数组
void queryArray(int arr[], int size, int isSorted)
{
    if (size == 0)
    {
        printf("数组为空。请先填充数组。\n");
        return;
    }

    int target;
    printf("请输入要查找的数字：");
    scanf("%d", &target);

    int foundIndex;
    int found;

    if (isSorted)
    {
        found = binarySearch(arr, size, target, &foundIndex);
        printf("使用二分查找（数组已排序）。\n");
    }
    else
    {
        found = sequentialSearch(arr, size, target, &foundIndex);
        printf("使用顺序查找（数组未排序）。\n");
    }

    if (found)
    {
        printf("数字 %d 位于索引 %d。\n", target, foundIndex);
    }
    else
    {
        printf("未在数组中找到数字 %d。\n", target);

        // 查找最接近的值
        int lessThan, greaterThan;
        findNearestValues(arr, size, target, &lessThan, &greaterThan);

        if (lessThan != -1)
        {
            // 查找小于目标值的最大值的索引
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == lessThan)
                {
                    printf("小于 %d 的最大数：%d，索引 %d\n", target, lessThan, i);
                    break;
                }
            }
        }
        else
        {
            printf("未找到小于 %d 的数。\n", target);
        }

        if (greaterThan != -1)
        {
            // 查找大于目标值的最小值的索引
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == greaterThan)
                {
                    printf("大于 %d 的最小数：%d，索引 %d\n", target, greaterThan, i);
                    break;
                }
            }
        }
        else
        {
            printf("未找到大于 %d 的数。\n", target);
        }
    }
}