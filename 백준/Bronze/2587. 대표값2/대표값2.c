#include <stdio.h>

int main(void)
{
    // 입력부
    int arr[5];
    for(int i = 0; i < 5; i++) scanf("%d", &arr[i]);
    
    // 논리부 O(n^2) 버블정렬
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4 - i; j++)
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
    int sum = 0;
    for(int i = 0; i < 5; i++) sum += arr[i];
    
    int average = sum / 5; // 모두 10의 배수이니 실수부 안 나옴
    int midean = arr[2];
    
    printf("%d\n%d", average, midean);
    
    return 0;
}