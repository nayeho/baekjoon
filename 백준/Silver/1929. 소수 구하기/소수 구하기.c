#include <stdio.h>

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    
    int arr[1000001];
    
    for(int i = 2; i < 1000001; i++)
    {
        arr[i] = 1;
    }
    
    for(int i = 2; i <= N; i++)
    {
        for(int j = i * 2; j <= N; j += i)
        {
            arr[j] = 0;
        }
    }
    
    for(int i = M; i <= N; i++)
    {
        if(arr[i] == 1)
        {
            printf("%d\n", i);
        }
    }
    
    return 0;
}