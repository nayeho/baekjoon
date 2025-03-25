#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++)
    {
        char s[1001];
        scanf("%s", s);
        int length = 0;
        while(s[length] != '\0') length++;
        
        printf("%c%c\n", s[0], s[length - 1]);
    }
    
    return 0;
}