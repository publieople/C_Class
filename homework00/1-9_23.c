#include <stdio.h>

int main(void)
{
    // 十进制整数各位数字分离
    long long n, temp;
    int digit, count = 0;

    printf("Enter a number: ");
    scanf("%lld", &n);

    // 处理负数情况
    if (n < 0)
    {
        printf("-");
        n = -n;
    }

    // 特殊情况：输入为0
    if (n == 0)
    {
        printf("0\n");
        return 0;
    }

    // 先计算数字的位数
    temp = n;
    while (temp > 0)
    {
        count++;
        temp = temp / 10;
    }

    // 根据位数创建数组
    int digits[count];

    // 使用循环分离各位数字
    temp = n;
    for (int i = 0; i < count; i++)
    {
        digit = temp % 10; // 获取最后一位数字
        digits[i] = digit;
        temp = temp / 10; // 去掉最后一位数字
    }

    // 输出各位数字（从最高位到最低位）
    printf("The number is: ");
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d", digits[i]);
    }
    printf("\n");

    return 0;
}
