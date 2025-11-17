#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int *scores;
    int i;
    int max, min;
    float sum = 0.0;
    float average;

    // 读取学生人数
    scanf("%d", &n);

    // 根据学生人数动态分配内存
    scores = (int *)malloc(n * sizeof(int));
    if (scores == NULL)
    {
        printf("内存分配失败！\n");
        return 1;
    }

    // 读取学生成绩
    for (i = 0; i < n; i++)
    {
        scanf("%d", &scores[i]);
    }

    // 初始化最大值和最小值
    max = scores[0];
    min = scores[0];

    // 计算最高分、最低分和总分
    for (i = 0; i < n; i++)
    {
        if (scores[i] > max)
        {
            max = scores[i];
        }
        if (scores[i] < min)
        {
            min = scores[i];
        }
        sum += scores[i];
    }

    // 计算平均分
    average = sum / n;

    // 输出结果
    printf("最高分: %d\n", max);
    printf("最低分: %d\n", min);
    printf("平均分: %.2f\n", average);

    // 释放动态分配的内存
    free(scores);

    return 0;
}
