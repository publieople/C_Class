#include <stdio.h>

int main()
{
    int a[] = {23, 45, 67, 89, 90, 12, 34, 56, 78, 91};

    // 输出所有元素
    // 下标
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("\n");

    // 指针
    for (int *p = a; p < a + 10; p++)
    {
        printf("*p = %d\n", *p);
    }
    printf("\n");
}