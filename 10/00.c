#include <stdio.h>
#include <string.h>

// 投票
// 结构体
struct person
{
    char name[20];
    int count;
} leader[3] = {
    "Li", 0,
    "Zhang", 0,
    "Sun", 0};

int main()
{
    int i, j;
    char leader_name[20];
    // 投票
    for (i = 0; i <= 10; i++)
    {
        printf("请输入投票人姓名: ");
        scanf("%s", leader_name);
        // 计票
        for (j = 0; j < 3; j++)
        {
            if (strcmp(leader_name, leader[j].name) == 0)
            {
                leader[j].count++;
                break;
            }
        }
        if (j == 3)
        {
            printf("无效投票\n");
        }
    }
    // 输出结果
    printf("投票结果:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%s: %d 票\n", leader[i].name, leader[i].count);
    }
    return 0;
}