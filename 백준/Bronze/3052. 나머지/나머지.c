#include <stdio.h>

int main(void)
{
    int arr[10];
    
    for(int i = 0; i < 10; i++)
    {
        int n;
        scanf("%d", &n);
        arr[i] = n % 42;
    }

    int answer[10];
    answer[0] = arr[0];
    for (int i = 1; i < 10; i++)
    {
        int check = 1;
        answer[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (answer[i] == answer[j])
            {
                check = 0;
                break;
            }
        }
        if (check != 1) answer[i] = -1;
    }
    
    int cnt = 0;

    for (int i = 0; i < 10; i++) if(answer[i] != -1) cnt++;
    
    printf("%d", cnt);

    return 0;
}