#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>

#define ARRAY_SIZE 50
#define MAX_VALUE 999
#define MIN_VALUE 1

// 日志级别定义
typedef enum {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

// 日志函数声明
void logMessage(LogLevel level, const char* format, ...);
void initLogFile(void);
void closeLogFile(void);

// 全局日志文件指针
static FILE* logFile = NULL;

// 函数声明
void fillArray(int arr[], int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
int sequentialSearch(int arr[], int size, int target, int *foundIndex);
int binarySearch(int arr[], int size, int target, int *foundIndex);
void queryArray(int arr[], int size, int isSorted);
void findNearestValues(int arr[], int size, int target, int *lessThan, int *greaterThan);

// 日志函数实现
void initLogFile(void) {
    logFile = fopen("array_program.log", "a");
    if(logFile == NULL) {
        printf("Warning: Could not open log file for writing.\n");
    } else {
        time_t now;
        time(&now);
        fprintf(logFile, "\n========== Program Started at %s ==========\n", ctime(&now));
        fflush(logFile);
    }
}

void closeLogFile(void) {
    if(logFile != NULL) {
        time_t now;
        time(&now);
        fprintf(logFile, "========== Program Ended at %s ==========\n\n", ctime(&now));
        fclose(logFile);
        logFile = NULL;
    }
}

void logMessage(LogLevel level, const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    // 获取当前时间
    time_t now;
    time(&now);
    struct tm* timeInfo = localtime(&now);
    char timeStr[20];
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", timeInfo);
    
    // 确定日志级别字符串
    const char* levelStr;
    switch(level) {
        case LOG_INFO:    levelStr = "INFO"; break;
        case LOG_WARNING: levelStr = "WARN"; break;
        case LOG_ERROR:   levelStr = "ERROR"; break;
        default:          levelStr = "UNKNOWN"; break;
    }
    
    // 输出到控制台
    printf("[%s] %s: ", timeStr, levelStr);
    vprintf(format, args);
    printf("\n");
    
    // 输出到日志文件
    if(logFile != NULL) {
        fprintf(logFile, "[%s] %s: ", timeStr, levelStr);
        vfprintf(logFile, format, args);
        fprintf(logFile, "\n");
        fflush(logFile);
    }
    
    va_end(args);
}

int main() {
    int arr[ARRAY_SIZE];
    int isSorted = 0;  // 标记数组是否已排序
    char choice;
    
    srand(time(NULL));  // 初始化随机数生成器
    
    // 初始化日志系统
    initLogFile();
    logMessage(LOG_INFO, "Program started");
    
    printf("Menu-driven Array Program\n");
    printf("=========================\n\n");
    logMessage(LOG_INFO, "Menu-driven Array Program initialized");
    
    do {
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
        
        logMessage(LOG_INFO, "User selected option: %c", choice);
        
        switch(choice) {
            case 'F':
                fillArray(arr, ARRAY_SIZE);
                isSorted = 0;  // 填充后数组变为未排序状态
                printf("Array filled with random numbers.\n");
                logMessage(LOG_INFO, "Array filled with %d random numbers", ARRAY_SIZE);
                break;
                
            case 'P':
                logMessage(LOG_INFO, "Printing array contents");
                printArray(arr, ARRAY_SIZE);
                break;
                
            case 'S':
                logMessage(LOG_INFO, "Sorting array using bubble sort");
                bubbleSort(arr, ARRAY_SIZE);
                isSorted = 1;  // 标记为已排序
                printf("Array sorted successfully.\n");
                logMessage(LOG_INFO, "Array sorted successfully");
                break;
                
            case 'Q':
                logMessage(LOG_INFO, "Querying array");
                queryArray(arr, ARRAY_SIZE, isSorted);
                break;
                
            case 'Z':
                printf("Program terminated.\n");
                logMessage(LOG_INFO, "Program terminated by user");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                logMessage(LOG_WARNING, "Invalid menu choice: %c", choice);
        }
        
    } while(choice != 'Z');
    
    // 关闭日志系统
    closeLogFile();
    return 0;
}

// 用随机数填充数组
void fillArray(int arr[], int size) {
    logMessage(LOG_INFO, "Starting to fill array with %d random numbers", size);
    for(int i = 0; i < size; i++) {
        arr[i] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
        logMessage(LOG_INFO, "Array[%d] = %d", i, arr[i]);
    }
    logMessage(LOG_INFO, "Array filling completed");
}

// 打印数组
void printArray(int arr[], int size) {
    if(size == 0) {
        printf("Array is empty.\n");
        logMessage(LOG_WARNING, "Attempted to print empty array");
        return;
    }
    
    logMessage(LOG_INFO, "Printing array of size %d", size);
    printf("Array contents:\n");
    for(int i = 0; i < size; i++) {
        printf("%4d ", arr[i]);
        if((i + 1) % 10 == 0) {  // 每10个元素换行
            printf("\n");
        }
    }
    printf("\n");
    logMessage(LOG_INFO, "Array printing completed");
}

// 冒泡排序
void bubbleSort(int arr[], int size) {
    logMessage(LOG_INFO, "Starting bubble sort on array of size %d", size);
    int comparisons = 0;
    int swaps = 0;
    
    for(int i = 0; i < size - 1; i++) {
        int swapped = 0;
        for(int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if(arr[j] > arr[j + 1]) {
                // 交换元素
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = 1;
            }
        }
        if(!swapped) {
            logMessage(LOG_INFO, "Array already sorted, breaking at pass %d", i);
            break;
        }
    }
    
    logMessage(LOG_INFO, "Bubble sort completed: %d comparisons, %d swaps", comparisons, swaps);
}

// 顺序查找
int sequentialSearch(int arr[], int size, int target, int *foundIndex) {
    logMessage(LOG_INFO, "Starting sequential search for target %d in array of size %d", target, size);
    
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            *foundIndex = i;
            logMessage(LOG_INFO, "Target %d found at index %d using sequential search", target, i);
            return 1;  // 找到
        }
    }
    
    logMessage(LOG_INFO, "Target %d not found using sequential search", target);
    return 0;  // 未找到
}

// 二分查找
int binarySearch(int arr[], int size, int target, int *foundIndex) {
    logMessage(LOG_INFO, "Starting binary search for target %d in array of size %d", target, size);
    
    int left = 0;
    int right = size - 1;
    int steps = 0;
    
    while(left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        logMessage(LOG_INFO, "Binary search step %d: left=%d, right=%d, mid=%d, arr[mid]=%d",
                   steps, left, right, mid, arr[mid]);
        
        if(arr[mid] == target) {
            *foundIndex = mid;
            logMessage(LOG_INFO, "Target %d found at index %d using binary search (completed in %d steps)",
                       target, mid, steps);
            return 1;  // 找到
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    logMessage(LOG_INFO, "Target %d not found using binary search (completed in %d steps)", target, steps);
    return 0;  // 未找到
}

// 查找最接近的值
void findNearestValues(int arr[], int size, int target, int *lessThan, int *greaterThan) {
    logMessage(LOG_INFO, "Finding nearest values to target %d", target);
    
    *lessThan = -1;
    *greaterThan = -1;
    
    for(int i = 0; i < size; i++) {
        if(arr[i] < target) {
            if(*lessThan == -1 || arr[i] > *lessThan) {
                *lessThan = arr[i];
            }
        }
        else if(arr[i] > target) {
            if(*greaterThan == -1 || arr[i] < *greaterThan) {
                *greaterThan = arr[i];
            }
        }
    }
    
    logMessage(LOG_INFO, "Nearest values to %d: lessThan=%d, greaterThan=%d", target, *lessThan, *greaterThan);
}

// 查询数组
void queryArray(int arr[], int size, int isSorted) {
    logMessage(LOG_INFO, "Starting array query (isSorted=%d)", isSorted);
    
    if(size == 0) {
        printf("Array is empty. Please fill the array first.\n");
        logMessage(LOG_WARNING, "Query attempted on empty array");
        return;
    }
    
    int target;
    printf("Enter the number to search for: ");
    scanf("%d", &target);
    logMessage(LOG_INFO, "User entered search target: %d", target);
    
    int foundIndex;
    int found;
    
    if(isSorted) {
        logMessage(LOG_INFO, "Using binary search for target %d", target);
        found = binarySearch(arr, size, target, &foundIndex);
        printf("Using binary search (array is sorted).\n");
    }
    else {
        logMessage(LOG_INFO, "Using sequential search for target %d", target);
        found = sequentialSearch(arr, size, target, &foundIndex);
        printf("Using sequential search (array is not sorted).\n");
    }
    
    if(found) {
        printf("Number %d was located at index %d.\n", target, foundIndex);
        logMessage(LOG_INFO, "Search successful: %d found at index %d", target, foundIndex);
    }
    else {
        printf("Number %d was not found in the list.\n", target);
        logMessage(LOG_INFO, "Search failed: %d not found in array", target);
        
        // 查找最接近的值
        int lessThan, greaterThan;
        findNearestValues(arr, size, target, &lessThan, &greaterThan);
        
        if(lessThan != -1) {
            // 查找小于目标值的最大值的索引
            for(int i = 0; i < size; i++) {
                if(arr[i] == lessThan) {
                    printf("Largest number less than %d: %d at index %d\n", target, lessThan, i);
                    logMessage(LOG_INFO, "Largest number less than %d: %d at index %d", target, lessThan, i);
                    break;
                }
            }
        }
        else {
            printf("No number less than %d found.\n", target);
            logMessage(LOG_INFO, "No number less than %d found", target);
        }
        
        if(greaterThan != -1) {
            // 查找大于目标值的最小值的索引
            for(int i = 0; i < size; i++) {
                if(arr[i] == greaterThan) {
                    printf("Smallest number greater than %d: %d at index %d\n", target, greaterThan, i);
                    logMessage(LOG_INFO, "Smallest number greater than %d: %d at index %d", target, greaterThan, i);
                    break;
                }
            }
        }
        else {
            printf("No number greater than %d found.\n", target);
            logMessage(LOG_INFO, "No number greater than %d found", target);
        }
    }
}