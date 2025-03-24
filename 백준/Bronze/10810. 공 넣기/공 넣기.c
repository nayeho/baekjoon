#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    int arr[n];
    for(int a = 0; a < n; a++) arr[a] = 0;
        
    for(int a = 0; a < m; a++)
    {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        
        for(int b = i - 1; b < j; b++) arr[b] = k;
    }
    
    for(int a = 0; a < n; a++) printf("%d ", arr[a]);
    
    return 0;
}