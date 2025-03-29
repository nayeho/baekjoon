#include <stdio.h>

int main(void)
{
    while(1)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        
        if(a == 0 && b == 0 && c == 0)
        {
            break;
        }
        
        int check = 0;
        if(a * a == b * b + c * c || b * b == c * c + a * a || c * c == a * a + b * b) 
        {
            check = 1;
        }
        if(check) printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}