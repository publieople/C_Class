#include <stdio.h>

int main()
{
    int a[10];
    int i, j, temp;
    float sum = 0;

    printf("10个学生的成绩：\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("平均分：%.2f\n", sum / 10);
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("排序后的成绩：\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}