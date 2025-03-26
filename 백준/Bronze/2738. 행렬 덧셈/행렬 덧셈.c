#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    int arr_A[n][m];
    int arr_B[n][m];
    
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &arr_A[i][j]);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &arr_B[i][j]);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) printf("%d ", arr_A[i][j] + arr_B[i][j]);
        printf("\n");
    }
    return 0;    
}