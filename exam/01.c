#include <stdio.h>

// 输入3个整数, 通过调用max函数获得3个整数中的最大值, 最后输出

int max(int a, int b, int c)
{
    int max_val = a;
    if (b > max_val)
    {
        max_val = b;
    }
    if (c > max_val)
    {
        max_val = c;
    }
    return max_val;
}
int main()
{
    int x, y, z;
    printf("请输入3个整数: ");
    scanf("%d %d %d", &x, &y, &z);

    int maximum = max(x, y, z);
    printf("最大值是: %d\n", maximum);

    return 0;
}