#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    int arr[n];
    
    for(int k = 0; k < n; k++) arr[k] = k + 1;
    
    for(int k = 0; k < m; k++)
    {
        int i, j;
        scanf("%d %d", &i, &j);
        
        int temp;
        temp = arr[i - 1];
        arr[i - 1] = arr[j - 1];
        arr[j - 1] = temp;
    }
    
    for(int k = 0; k < n; k++) printf("%d ", arr[k]);
    return 0;
}