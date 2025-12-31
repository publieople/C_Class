#include <stdio.h>

// 文件操作
// 从键盘上输入一些字符，逐个写入到指定文件 file1.txt 中
// 然后再从该文件中读取这些字符，并显示在屏幕上
int main()
{
    FILE *fp;
    char ch;

    fp = fopen("file1.txt", "w");
    printf("请输入一些字符，以换行结束：\n");
    while ((ch = getchar()) != '\n')
        fputc(ch, fp);
    fclose(fp);

    fp = fopen("file1.txt", "r");
    printf("从file1.txt文件中读取的字符是：\n");
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
}