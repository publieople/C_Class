#include <stdio.h>

int main(void)
{
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, sum = 0, i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
                sum += a[i][j];
        }
    }
    printf("%d\n", sum);
}