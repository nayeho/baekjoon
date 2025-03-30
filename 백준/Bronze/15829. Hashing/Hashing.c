#include <stdio.h>

int main(void)
{
    int L;
    scanf("%d", &L);
    
    char word[51];
    scanf("%s", word);
    
    long long result = 0;
    long long pow = 1;
    for(int i = 0; i < L; i++)
    {
        result += (long long)(word[i] - 'a' + 1) * pow;
        pow *= 31;
    }
    
    printf("%lld", result % 1234567891);
    return 0;
}