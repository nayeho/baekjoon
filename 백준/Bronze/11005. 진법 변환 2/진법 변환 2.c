#include <stdio.h>
#include <string.h>

int main(void)
{
    int N, B;
    scanf("%d %d", &N, &B);
    
    char temp[31];
    int count = 0;
    while(N > 0)
    {
        temp[count++] = N % B > 9 ? (char)(N % B - 10 + 'A') : (char)(N % B + '0');
        N = (int)(N / B);
    }
    temp[count] = '\0';
    
    // temp를 역순으로 출력
    
    int len = strlen(temp);
    char result[len];
    
    for(int i = 0; i < len; i++) result[i] = temp[len - 1 - i];
    result[len] = '\0';
    printf("%s", result);
    
    return 0;
}