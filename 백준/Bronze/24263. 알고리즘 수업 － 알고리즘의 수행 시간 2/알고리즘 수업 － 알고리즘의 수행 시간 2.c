#include <stdio.h>
//MenOfPassion(A[], n) {
//    sum <- 0;
//    for i <- 1 to n
//        sum <- sum + A[i]; # 코드1
//    return sum;
//}

int main(void)
{
    int n;
    scanf("%d", &n);
    
    // 1 부터 n까지 수행하므로 수행 횟수 : n
    // O(n) -> n 이므로 최고차항 차수 : 1
    
    printf("%d\n%d", n, 1);
    
    return 0;
}