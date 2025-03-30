#include <stdio.h>

int main(void)
{
    while(1)
    {
        int n;
        scanf("%d", &n);
        
        if(n == 0) break;
        
        int origin = n;
        int reverse = 0;
        
        while(n)
        {
            reverse *= 10;
            reverse += n % 10;
            n /= 10;
        }
        
        if(reverse == origin) printf("yes\n");
        else printf("no\n");
        
    }
    return 0;
}