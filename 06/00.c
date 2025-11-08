#include <stdio.h>

// 利用字符数组处理多个字符或字符串
int main(void)
{
    // 定义一个字符数组并初始化
    char a[5] = {'H', 'e', 'l', 'l', 'o'};
    char b[6] = "World"; // 自动添加字符串结束符 '\0'
    int i;
    printf("Character array a: ");
    for (i = 0; i < 5; i++)
    {
        printf("%c", a[i]);
    }
    printf("\nCharacter array b: ");
    for (i = 0; i < 6; i++)
    {
        printf("%c", b[i]);
    }
    printf("\n");
    return 0;
}