#include <stdio.h>

int main()
{
    // break 和 continue
    int n;
    scanf("%d", &n);
    while (n--)
    {
        if (n == 5)
            break;
        if (n % 2 == 0)
            continue;
        printf("%d ", n);
    }
}