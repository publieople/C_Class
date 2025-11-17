#include <stdio.h>

int main()
{
    // 分段函数
    int x;
    printf("请输入一个整数：");
    scanf("%d", &x);
    if (x >= 0 && x < 2)
    {
        printf("y = %d\n", x);
    }
    else if (x >= 2 && x < 4)
    {
        printf("y = %d\n", 2 * x - 2);
    }
    else if (x >= 4)
    {
        printf("y = %d\n", 3 * x - 6);
    }
    else
    {
        printf("非法输入\n");
    }

    // 及格检测
    int theory_score, practice_score;
    printf("请输入一门课的理论成绩和实践成绩：");
    scanf("%d %d", &theory_score, &practice_score);
    if (theory_score >= 60 && practice_score >= 60)
    {
        printf("恭喜，通过！\n");
    }
    else if (theory_score < 60 && practice_score >= 60)
    {
        printf("请加强理论学习\n");
    }
    else if (theory_score >= 60 && practice_score < 60)
    {
        printf("请加强实践训练\n");
    }
    else
    {
        printf("非法输入\n");
    }

    // 判断成绩等级
    int score;
    printf("请输入成绩（0-100）：");
    scanf("%d", &score);
    if (score >= 90 && score <= 100)
    {
        printf("优秀\n");
    }
    else if (score >= 80 && score < 90)
    {
        printf("良好\n");
    }
    else if (score >= 70 && score < 80)
    {
        printf("中等\n");
    }
    else if (score >= 60 && score < 70)
    {
        printf("及格\n");
    }
    else if (score >= 0 && score < 60)
    {
        printf("不及格\n");
    }
    else
    {
        printf("非法输入\n");
    }
}