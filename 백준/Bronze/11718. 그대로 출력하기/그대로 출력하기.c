#include <stdio.h>

int main(void)
{
    char s[101];
    while(scanf(" %[^\n]", s) != EOF)
    {
        printf("%s\n", s);
    }
    
    return 0;
}