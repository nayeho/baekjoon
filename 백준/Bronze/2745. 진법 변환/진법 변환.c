#include <stdio.h>
#include <string.h>

int main(void)
{
    char N[31];
    int B;
    scanf("%s %d", N, &B);
    
    int len = strlen(N);
    int result = 0;
    
    int exp = 0;
    for(int i = 0; i < len; i++)
    {
        char ch = N[len - 1 - i];
        int convert = 0;
        if(ch >= 'A') convert = (int)(ch - 'A' + 10);
        else convert = (int)(ch - '0');
        
        int weight = 1;
        for(int j = 0; j < exp; j++) weight *= B;
        
        result += convert * weight;
        
        exp++;
    }
    
    printf("%d", result);
    
    return 0;
}