#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    // 1 : 1C0 + 1C1 = 1 + 1 = 2
    // 2 : 2C0 + 2C1 + 2C2 = 1 + 2 + 1 = 4
    // 3 : 3C0 + 3C1 + 3C2 + 3C3 = 1 + 3 + 3 + 1 = 8
    // 4 : 4C0 + 4C1 + 4C2 + 4C3 + 4C4 = 1 + 4 + 6 + 4 + 1 = 16
    // 5 : 5C0 + 5C1 + 5C2 + 5C3 + 5C4 + 5C5 = 1 + 5 + 10 + 10 + 5 + 1 = 32
    int result = 1;
    for(int i = 0; i < N; i++) result *= 2;
    printf("%d\n", result);
    return 0;
}