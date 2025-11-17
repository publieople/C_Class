#include <stdio.h>

int main(void)
{
    int c;

    printf("请输入字符（按回车键结束输入）：\n");

    // 使用getchar读取输入，直到遇到换行符
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // 使用putchar输出每个字符
        putchar(c);
    }

    // 输出换行
    putchar('\n');

    return 0;
}
