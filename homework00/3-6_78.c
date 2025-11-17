#include <stdio.h>

int main(void)
{
    // 二位数组
    int matrix[4][3] = {
        {78, 69, 90},
        {72, 55, 83},
        {65, 81, 53},
        {92, 85, 78}};
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrix[i][j]);
            sum += matrix[i][j];
        }
        printf("sum = %d\n", sum);
    }
}