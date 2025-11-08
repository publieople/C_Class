#include <stdio.h>

int main()
{
    int n;
    for(n=100;n<=200;n++)
    {
        (n%3==0)? printf("%d\n",n) : 0;
    }
    return 0;
}