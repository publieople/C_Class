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

    printf("Menu-driven Array Program\n");
    printf("=========================\n\n");

    do
    {
        // 显示菜单
        printf("\nMENU\n");
        printf("Select one of the following options:\n");
        printf("F. Fill array with a random number series\n");
        printf("P. Print the array\n");
        printf("S. Sort the array\n");
        printf("Q. Query the array\n");
        printf("Z. Terminate the program\n");
        printf("\nEnter your choice: ");

        scanf(" %c", &choice);
        choice = toupper(choice);

        switch (choice)
        {
        case 'F':
            fillArray(arr, ARRAY_SIZE);
            isSorted = 0; // 填充后数组变为未排序状态
            printf("Array filled with random numbers.\n");
            break;

        case 'P':
            printArray(arr, ARRAY_SIZE);
            break;

        case 'S':
            bubbleSort(arr, ARRAY_SIZE);
            isSorted = 1; // 标记为已排序
            printf("Array sorted successfully.\n");
            break;

        case 'Q':
            queryArray(arr, ARRAY_SIZE, isSorted);
            break;

        case 'Z':
            printf("Program terminated.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
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
        printf("Array is empty.\n");
        return;
    }

    printf("Array contents:\n");
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
        printf("Array is empty. Please fill the array first.\n");
        return;
    }

    int target;
    printf("Enter the number to search for: ");
    scanf("%d", &target);

    int foundIndex;
    int found;

    if (isSorted)
    {
        found = binarySearch(arr, size, target, &foundIndex);
        printf("Using binary search (array is sorted).\n");
    }
    else
    {
        found = sequentialSearch(arr, size, target, &foundIndex);
        printf("Using sequential search (array is not sorted).\n");
    }

    if (found)
    {
        printf("Number %d was located at index %d.\n", target, foundIndex);
    }
    else
    {
        printf("Number %d was not found in the list.\n", target);

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
                    printf("Largest number less than %d: %d at index %d\n", target, lessThan, i);
                    break;
                }
            }
        }
        else
        {
            printf("No number less than %d found.\n", target);
        }

        if (greaterThan != -1)
        {
            // 查找大于目标值的最小值的索引
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == greaterThan)
                {
                    printf("Smallest number greater than %d: %d at index %d\n", target, greaterThan, i);
                    break;
                }
            }
        }
        else
        {
            printf("No number greater than %d found.\n", target);
        }
    }
}