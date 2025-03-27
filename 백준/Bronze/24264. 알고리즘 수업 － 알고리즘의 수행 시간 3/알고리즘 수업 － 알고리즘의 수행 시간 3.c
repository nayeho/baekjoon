#include <stdio.h>
//MenOfPassion(A[], n) {
//    sum <- 0;
//    for i <- 1 to n
//        for j <- 1 to n
//            sum <- sum + A[i] × A[j]; # 코드1
//    return sum;
//}
int main(void)
{
    int n;
    scanf("%d", &n);
    
    // 수행 횟수 : n * n
    // O(n) = n^2
    
    long long result = (long long)n * n;
    
    printf("%lld\n%d", result, 2);
    
    return 0;
}