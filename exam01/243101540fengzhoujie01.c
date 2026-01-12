#include <stdio.h>

int main()
{
    int limit;
    printf("limit: ");
    scanf("%d", &limit);

    int s = 0;
    int n = 0;
    while (s <= limit)
    {
        s += ++n;
    }

    printf("s = %d, n = %d, limit = %d\n", s, n, limit);

    return 0;
}