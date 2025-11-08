#include <stdio.h>

int main()
{
    int i, j, n = 0;
    int m;
    scanf("%d", &m);

    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 5; j++, n++)
        {
            if (i == j)
                printf("%d\t", i * j);
            else
                printf("#\t");
        }
        printf("\n");
    }

    printf("\n");
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 5; j++, n++)
        {
            if (j != m)
                printf("%d\t", i * j);
            else
                printf("#\t");
        }
        printf("\n");
    }

    return 0;
}