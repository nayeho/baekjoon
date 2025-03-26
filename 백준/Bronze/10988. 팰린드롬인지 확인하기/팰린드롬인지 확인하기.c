#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[101];
    scanf("%s", s);
    int len = strlen(s);
    
    int isPalindrome = 1;
    for(int i = 0; i < (int)(len / 2); i++)
    {
        if(s[i] != s[len - 1 - i])
        {
            isPalindrome = 0;
            break;
        }
    }
    
    printf("%d", isPalindrome);
    
    return 0;
}