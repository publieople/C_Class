#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    (x == 0)? printf("0\n") : (x > 0)? printf("1\n") : printf("-1\n");
    return 0;
}