#include <stdio.h>

int a[2][3] = {
    {1, 2, 3},
    {4, 5, 6}};
int b[3][2];

// 定义矩阵维度常量
#define ROWS_A 2
#define COLS_A 3
#define ROWS_B 3
#define COLS_B 2

int main()
{
    printf("a = \n");
    for (int i = 0; i < ROWS_A; i++)
    {
        for (int j = 0; j < COLS_A; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // 交换行和列
    for (int i = 0; i < ROWS_B; i++)
    {
        for (int j = 0; j < COLS_B; j++)
        {
            b[i][j] = a[j][i];
        }
    }
    printf("b = \n");
    for (int i = 0; i < ROWS_B; i++)
    {
        for (int j = 0; j < COLS_B; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}