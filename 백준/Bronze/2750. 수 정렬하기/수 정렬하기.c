#include <stdio.h>

int main(void)
{
    // 문제 설명에서 삽입정렬과 버블정렬도 해결할 수 있다고 한다.
    // O(n^2)으로 접근해보자
    
    int N;
    scanf("%d", &N);
    
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
    for(int i = 0; i < N; i++) printf("%d\n", arr[i]);
    
    return 0;
}