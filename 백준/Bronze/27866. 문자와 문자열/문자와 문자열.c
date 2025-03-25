#include <stdio.h>

int main(void)
{
    char s[1001];
    scanf("%s", s);
    
    int i;
    scanf("%d", &i);
    
    printf("%c", s[i - 1]);
    
    return 0;
}