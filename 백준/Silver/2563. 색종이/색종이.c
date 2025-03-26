#include <stdio.h>

int main(void)
{
    char paper[100][100] = {0};
    
    int color;
    scanf("%d", &color);
    
    
    
    
    for(int a = 0; a < color; a++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        
        for(int i = n; i < n + 10; i++)
        {
            for(int j = m; j < m + 10; j++)
            {
                paper[i][j] = 1;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < 100; i++) for(int j = 0; j < 100; j++) if(paper[i][j] == 1) count++;
    
    printf("%d", count);
    return 0;
}