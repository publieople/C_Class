#include <stdio.h>
#include <limits.h>

int main()
{
    // 斐波那契数列计算
    long long x, y, t;
    x = 1;
    y = 1;

    printf("斐波那契数列前100项：\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%lld", x);

        // 检测是否会发生溢出
        if (y > 0 && x > LLONG_MAX - y)
        {
            printf(" (在第%d项之后发生溢出！)", i + 1);
            break;
        }

        if (i < 99)
            printf(" , ");

        t = y;
        y = x + y;
        x = t;
    }
    printf("\n");
    return 0;
}
