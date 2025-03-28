#include <stdio.h>

int main(void)
{
    // 계속 버블정렬 써도 괜찮은가?
    
    int N, k;
    scanf("%d %d", &N, &k);
    
    // 입력부
    int arr[N];
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    
    // 논리부
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0; j < N - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // 출력부
    // 1명이라면 arr[N - 1]
    // 2명이라면 arr[N - 2]
    printf("%d", arr[N - k]);
    
    return 0;
}