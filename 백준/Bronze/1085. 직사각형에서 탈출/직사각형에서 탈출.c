#include <stdio.h>

int abs(int num)
{
    return num > 0 ? num : num * -1;
}

int main(void)
{
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    int min_distance = 1000;
    
    if(abs(x) < min_distance) min_distance = abs(x);
    if(abs(y) < min_distance) min_distance = abs(y);
    if(abs(x - w) < min_distance) min_distance = abs(x - w);
    if(abs(y - h) < min_distance) min_distance = abs(y - h);
    
    printf("%d", min_distance);
    
    return 0;
}