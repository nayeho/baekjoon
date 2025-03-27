#include <stdio.h>

int main(void)
{
    int a1, a0;
    scanf("%d %d", &a1, &a0);
    
    int c;
    scanf("%d", &c);
    
    int n0;
    scanf("%d", &n0);
    
    // f(n) = a1 * n0 + a0
    // c * g(n) = c * n0
    
    if(a1 * n0 + a0 <= c * n0 && a1 <= c) printf("%d", 1);
    else printf("%d", 0);
    
    return 0;
}