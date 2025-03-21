#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) scanf(" %d", &arr[i]);
    
    int v;
    scanf(" %d", &v);
    
    int cnt = 0;
    for(int i = 0; i < n; i++) if (arr[i] == v) cnt++;
    
    printf("%d", cnt);
    
    return 0;
}