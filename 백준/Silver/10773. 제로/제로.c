#include <stdio.h>

#define MAX 1000000

int stack[MAX]; // 동적할당 하고 싶지만 정적할당 하자
int size = 0; // 배열의 크기 전역에서 바라보기

int main(void)
{
    int K;
    scanf("%d", &K);
    
    unsigned int sum = 0; // 합이 2^31 - 1보다 작으므로
    for(int i = 0; i < K; i++)
    {
        int input;
        scanf("%d", &input);
        if(input == 0) stack[size-- - 1] = 0;
        else stack[size++] = input;
    }
    
    for(int i = 0; i < size; i++) sum += stack[i];
    
    printf("%u\n", sum);
    
    return 0;
}