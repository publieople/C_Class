#include <stdio.h>

int main()
{
    // for 循环

    // 1+3+5+...+99
    int sum = 0;
    for (int i = 1; i <= 99; i += 2)
    {
        sum += i;
    }
    printf("%d\n", sum);

    // 2+4+6+...+100
    sum = 0;
    for (int i = 2; i <= 100; i += 2)
    {
        sum += i;
    }
    printf("%d\n", sum);

    // 1+2+3+...+n
    sum = 0;
    int n;
    printf("输入n：");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);

    // 1+2+3+...+i (直到和大于100)
    sum = 0;
    int i;
    for (i = 1; sum <= 100; i++)
    {
        sum += i;
    }
    printf("sum = %d, i = %d\n", sum, i);
}