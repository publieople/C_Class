#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>

#define ARRAY_SIZE 50
#define MAX_VALUE 999
#define MIN_VALUE 1

// 日志级别定义
typedef enum
{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

// 日志函数声明
void logMessage(LogLevel level, const char *format, ...);
void initLogFile(void);
void closeLogFile(void);

// 全局日志文件指针
static FILE *logFile = NULL;

// 函数声明
void fillArray(int arr[], int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
int sequentialSearch(int arr[], int size, int target, int *foundIndex);
int binarySearch(int arr[], int size, int target, int *foundIndex);
void queryArray(int arr[], int size, int isSorted);
void findNearestValues(int arr[], int size, int target, int *lessThan, int *greaterThan);

// 日志函数实现
void initLogFile(void)
{
    logFile = fopen("array_program.log", "a");
    if (logFile == NULL)
    {
        printf("Warning: Could not open log file for writing.\n");
    }
    else
    {
        time_t now;
        time(&now);
        fprintf(logFile, "\n========== Program Started at %s ==========\n", ctime(&now));
        fflush(logFile);
    }
}

void closeLogFile(void)
{
    if (logFile != NULL)
    {
        time_t now;
        time(&now);
        fprintf(logFile, "========== Program Ended at %s ==========\n\n", ctime(&now));
        fclose(logFile);
        logFile = NULL;
    }
}

void logMessage(LogLevel level, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    // 获取当前时间
    time_t now;
    time(&now);
    struct tm *timeInfo = localtime(&now);
    char timeStr[20];
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", timeInfo);

    // 确定日志级别字符串
    const char *levelStr;
    switch (level)
    {
    case LOG_INFO:
        levelStr = "INFO";
        break;
    case LOG_WARNING:
        levelStr = "WARN";
        break;
    case LOG_ERROR:
        levelStr = "ERROR";
        break;
    default:
        levelStr = "UNKNOWN";
        break;
    }

    // 输出到控制台
    printf("[%s] %s: ", timeStr, levelStr);
    vprintf(format, args);
    printf("\n");

    // 输出到日志文件
    if (logFile != NULL)
    {
        fprintf(logFile, "[%s] %s: ", timeStr, levelStr);
        vfprintf(logFile, format, args);
        fprintf(logFile, "\n");
        fflush(logFile);
    }

    va_end(args);
}

int main()
{
    int arr[ARRAY_SIZE];
    int isSorted = 0; // 标记数组是否已排序
    char choice;

    srand(time(NULL)); // 初始化随机数生成器

    // 初始化日志系统
    initLogFile();
    logMessage(LOG_INFO, "程序已启动");

    printf("菜单驱动的数组程序\n");
    printf("=========================\n\n");
    logMessage(LOG_INFO, "菜单驱动的数组程序已初始化");

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

        logMessage(LOG_INFO, "用户选择了选项: %c", choice);

        switch (choice)
        {
        case 'F':
            fillArray(arr, ARRAY_SIZE);
            isSorted = 0; // 填充后数组变为未排序状态
            printf("数组已用随机数填充。\n");
            logMessage(LOG_INFO, "使用 %d 个随机数填充数组", ARRAY_SIZE);
            break;

        case 'P':
            logMessage(LOG_INFO, "打印数组内容");
            printArray(arr, ARRAY_SIZE);
            break;

        case 'S':
            logMessage(LOG_INFO, "使用冒泡排序对数组进行排序");
            bubbleSort(arr, ARRAY_SIZE);
            isSorted = 1; // 标记为已排序
            printf("数组已排序。\n");
            logMessage(LOG_INFO, "数组已排序成功");
            break;

        case 'Q':
            logMessage(LOG_INFO, "查询数组");
            queryArray(arr, ARRAY_SIZE, isSorted);
            break;

        case 'Z':
            printf("程序已退出。\n");
            logMessage(LOG_INFO, "用户终止了程序");
            break;

        default:
            printf("无效选择，请重试。\n");
            logMessage(LOG_WARNING, "无效的菜单选择: %c", choice);
        }

    } while (choice != 'Z');

    // 关闭日志系统
    closeLogFile();
    return 0;
}

// 用随机数填充数组
void fillArray(int arr[], int size)
{
    logMessage(LOG_INFO, "开始用 %d 个随机数填充数组", size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
        logMessage(LOG_INFO, "数组[%d] = %d", i, arr[i]);
    }
    logMessage(LOG_INFO, "数组填充完成");
}

// 打印数组
void printArray(int arr[], int size)
{
    if (size == 0)
    {
        printf("数组为空。\n");
        logMessage(LOG_WARNING, "尝试打印空数组");
        return;
    }

    logMessage(LOG_INFO, "打印数组，大小：%d", size);
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
    logMessage(LOG_INFO, "数组打印完成");
}

// 冒泡排序
void bubbleSort(int arr[], int size)
{
    logMessage(LOG_INFO, "开始对大小为 %d 的数组进行冒泡排序", size);
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                // 交换元素
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = 1;
            }
        }
        if (!swapped)
        {
            logMessage(LOG_INFO, "数组已排序，在第 %d 趟提前结束", i);
            break;
        }
    }

    logMessage(LOG_INFO, "冒泡排序完成：%d 次比较，%d 次交换", comparisons, swaps);
}

// 顺序查找
int sequentialSearch(int arr[], int size, int target, int *foundIndex)
{
    logMessage(LOG_INFO, "开始在大小为 %d 的数组中进行顺序查找，目标：%d", size, target);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            *foundIndex = i;
            logMessage(LOG_INFO, "使用顺序查找找到目标 %d，索引 %d", target, i);
            return 1; // 找到
        }
    }

    logMessage(LOG_INFO, "顺序查找未找到目标 %d", target);
    return 0; // 未找到
}

// 二分查找
int binarySearch(int arr[], int size, int target, int *foundIndex)
{
    logMessage(LOG_INFO, "开始在大小为 %d 的数组中进行二分查找，目标：%d", size, target);

    int left = 0;
    int right = size - 1;
    int steps = 0;

    while (left <= right)
    {
        steps++;
        int mid = left + (right - left) / 2;
        logMessage(LOG_INFO, "二分查找 步骤 %d: left=%d, right=%d, mid=%d, arr[mid]=%d",
                   steps, left, right, mid, arr[mid]);

        if (arr[mid] == target)
        {
            *foundIndex = mid;
            logMessage(LOG_INFO, "使用二分查找找到目标 %d，索引 %d（共 %d 步）",
                       target, mid, steps);
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

    logMessage(LOG_INFO, "二分查找未找到目标 %d（共 %d 步）", target, steps);
    return 0; // 未找到
}

// 查找最接近的值
void findNearestValues(int arr[], int size, int target, int *lessThan, int *greaterThan)
{
    logMessage(LOG_INFO, "查找与目标 %d 最近的值", target);

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

    logMessage(LOG_INFO, "目标 %d 的最接近值：lessThan=%d, greaterThan=%d", target, *lessThan, *greaterThan);
}

// 查询数组
void queryArray(int arr[], int size, int isSorted)
{
    logMessage(LOG_INFO, "开始查询数组 (isSorted=%d)", isSorted);

    if (size == 0)
    {
        printf("数组为空。请先填充数组。\n");
        logMessage(LOG_WARNING, "在空数组上尝试查询");
        return;
    }

    int target;
    printf("请输入要查找的数字：");
    scanf("%d", &target);
    logMessage(LOG_INFO, "用户输入查找目标: %d", target);

    int foundIndex;
    int found;

    if (isSorted)
    {
        logMessage(LOG_INFO, "使用二分查找目标 %d", target);
        found = binarySearch(arr, size, target, &foundIndex);
        printf("使用二分查找（数组已排序）。\n");
    }
    else
    {
        logMessage(LOG_INFO, "使用顺序查找目标 %d", target);
        found = sequentialSearch(arr, size, target, &foundIndex);
        printf("使用顺序查找（数组未排序）。\n");
    }

    if (found)
    {
        printf("数字 %d 位于索引 %d。\n", target, foundIndex);
        logMessage(LOG_INFO, "查找成功：%d 位于索引 %d", target, foundIndex);
    }
    else
    {
        printf("未在数组中找到数字 %d。\n", target);
        logMessage(LOG_INFO, "查找失败：数组中未找到 %d", target);

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
                    logMessage(LOG_INFO, "小于 %d 的最大数：%d，索引 %d", target, lessThan, i);
                    break;
                }
            }
        }
        else
        {
            printf("未找到小于 %d 的数。\n", target);
            logMessage(LOG_INFO, "未找到小于 %d 的数", target);
        }

        if (greaterThan != -1)
        {
            // 查找大于目标值的最小值的索引
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == greaterThan)
                {
                    printf("大于 %d 的最小数：%d，索引 %d\n", target, greaterThan, i);
                    logMessage(LOG_INFO, "大于 %d 的最小数：%d，索引 %d", target, greaterThan, i);
                    break;
                }
            }
        }
        else
        {
            printf("未找到大于 %d 的数。\n", target);
            logMessage(LOG_INFO, "未找到大于 %d 的数", target);
        }
    }
}