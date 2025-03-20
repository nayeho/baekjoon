#include <stdio.h>

int main(void)
{
    int a, b, c, time;
    scanf("%d %d %d", &a, &b, &c);
    
    time = a * 60 + b + c;
    time %= 24 * 60;
   
    printf("%d %d\n", (int)(time / 60), time % 60);
    
    return 0;
}