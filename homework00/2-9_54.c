#include <stdio.h>

int main()
{
    // while 循环

    // 1+3+5+...+99
    int sum = 0;
    int i = 1;
    while (i < 100)
    {
        sum += i;
        i += 2;
    }
    printf("1+3+5+...+99 = %d\n", sum);

    // 2+4+6+...+100
    sum = 0;
    i = 2;
    while (i <= 100)
    {
        sum += i;
        i += 2;
    }
    printf("2+4+6+...+100 = %d\n", sum);

    // 1+2+3+...+n
    sum = 0;
    i = 1;
    int n;
    printf("输入n：");
    scanf("%d", &n);
    while (i <= n)
    {
        sum += i;
        i++;
    }
    printf("1+2+3+...+%d = %d\n", n, sum);

    // 1+2+3+...+i (直到和大于100)
    sum = 0;
    i = 1;
    while (sum <= 100)
    {
        sum += i;
        i++;
    }
    printf("sum = %d, i = %d\n", sum, i);
}