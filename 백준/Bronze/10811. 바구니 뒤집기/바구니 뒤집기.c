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
        
        int size = j - i + 1;
        int temp[size];

        for(int l = 0; l < size; l++) temp[l] = arr[j - 1 - l];
        
        for(int l = i - 1; l < j; l++) arr[l] = temp[l - (i - 1)]; 
    }
    
    for(int k = 0; k < n; k++) printf("%d ", arr[k]);
    
    return 0;
}