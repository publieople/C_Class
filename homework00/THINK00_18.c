#include <stdio.h>

int main(void)
{
    char c1;
    c1 = 97;
    printf("%c\n", c1);
    printf("%d\n", c1);

    char c2;
    c1 = 'a';
    c2 = 'b';
    c1 = c1 - 32;
    c2 = c2 - 32;
    printf("%c %c\n", c1, c2);
}
