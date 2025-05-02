#include <stdio.h>

int main(void)
{
    // 0! = 1
    // 1! = 1
    // 2! = 2
    // 3! = 6
    // 4! = 12
    // 5! = 60
    // 6! = 360
    
    // 1의 배수 -> 0
    // 10의 배수 -> 1
    // 100의 배수 -> 2
    // 1000의 배수 -> 3
    // ...
    
    // 팩토리얼 전개에서 5보다 2의 배수 빈도가 명확하게 많으므로,
    // 5의 개수를 카운트하면 10의 지수를 구할 수 있다.
    
    int N;
    scanf("%d", &N);
    
    int count_5 = 0;
    
    for(int i = 1; i <= N; i++)
    {
        int temp = i;
        while(temp % 5 == 0)
        {
            count_5++;
            temp /= 5;
        }
    }
    printf("%d\n", count_5);
    return 0;
}