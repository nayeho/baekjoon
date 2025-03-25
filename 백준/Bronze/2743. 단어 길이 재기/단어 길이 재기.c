#include <stdio.h>

int main(void)
{
    char s[101];
    scanf("%s", s);
    
    int length = 0;
    char* p = s;
    while(*p++) length++;
    
    printf("%d", length);
    
    return 0;
}