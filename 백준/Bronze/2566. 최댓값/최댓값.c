#include <stdio.h>

int main(void)
{
    int arr[9][9];
    for(int i = 0; i < 9; i++) for(int j = 0; j < 9; j++) scanf("%d", &arr[i][j]);
    
    int max = arr[0][0];
    int max_row_index = 1;
    int max_column_index = 1;
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arr[i][j] > max)
            {
                max = arr[i][j];
                max_row_index = i + 1;
                max_column_index = j + 1;
            }
        }
    }
    printf("%d\n%d %d", max, max_row_index, max_column_index);
    return 0;
}