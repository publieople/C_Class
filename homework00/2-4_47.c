#include <stdio.h>

int main(void)
{
    // 输入两个数,输出最大值
    int a, b;
    printf("请输入两个数：");
    scanf("%d %d", &a, &b);
    printf("最大值是：%d\n", a > b ? a : b);

    // 判断能否被 5 整除
    printf("请输入一个数：");
    scanf("%d", &a);
    if (a % 5 == 0)
    {
        printf("输入的整数能被 5 整除\n");
    }
    else
    {
        printf("输入的整数不能被 5 整除\n");
    };

    // 判断闰年
    printf("请输入一个年份：");
    scanf("%d", &a);
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
    {
        printf("输入的整数是闰年\n");
    }
    else
    {
        printf("输入的整数不是闰年\n");
    };
}