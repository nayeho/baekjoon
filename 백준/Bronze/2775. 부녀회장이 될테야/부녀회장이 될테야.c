#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    
    int arr[15][15] = {0, };
    
    for(int i = 0; i < 15; i++)
    {
        arr[0][i] = i;
    }
    
    for(int i = 1; i < 15; i++)
    {
        for(int j = 1; j < 15; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    
    for(int i = 0; i < T; i++)
    {
        int k, n;
        scanf("%d %d", &k, &n);
        printf("%d\n", arr[k][n]);
    }
    return 0;
}