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
        result %= 1234567891;
        pow *= 31;
        pow %= 1234567891;
    }
    
    printf("%lld", result);
    return 0;
}