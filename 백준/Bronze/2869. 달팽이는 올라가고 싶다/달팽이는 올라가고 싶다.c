#include <stdio.h>

int main(void)
{
    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);
    
    int day = (V - B - 1) / (A - B) + 1;
    
    printf("%d", day);
    return 0;
}