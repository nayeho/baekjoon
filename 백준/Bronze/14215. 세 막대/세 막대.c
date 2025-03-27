#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(a + b <= c) printf("%d", 2 * (a + b) - 1);
    else if(b + c <= a) printf("%d", 2 * (b + c) - 1);
    else if(c + a <= b) printf("%d", 2 * (c + a) - 1);
    else printf("%d", a + b + c);
    
    return 0;
}