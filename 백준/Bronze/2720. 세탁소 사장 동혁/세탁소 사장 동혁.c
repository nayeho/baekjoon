#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++)
    {
        int C;
        scanf("%d", &C);
        
        int Q = C / 25;
        C %= 25;

        int D = C / 10;
        C %= 10;

        int N = C / 5;
        int P = C % 5;

        printf("%d %d %d %d\n", Q, D, N, P);
    }
    
    return 0;
}