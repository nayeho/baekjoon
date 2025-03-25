#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    int a_reverse = (a % 10) * 100 + ((int)(a / 10) % 10) * 10 + (int)(a / 100);
    int b_reverse = (b % 10) * 100 + ((int)(b / 10) % 10) * 10 + (int)(b / 100);
    
    if(a_reverse > b_reverse) printf("%d", a_reverse);
    else printf("%d", b_reverse);
    return 0;
}