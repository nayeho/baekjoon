#include <stdio.h>

int main(void)
{
    int chess[6] = {1, 1, 2, 2, 2, 8};
    int find[6];
    
    for(int i = 0; i < 6; i++) scanf("%d", &find[i]);
    for(int i = 0; i < 6; i++) printf("%d ", chess[i] - find[i]);
    
    return 0;
}