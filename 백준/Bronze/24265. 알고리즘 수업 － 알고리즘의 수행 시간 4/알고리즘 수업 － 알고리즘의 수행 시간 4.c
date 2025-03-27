#include <stdio.h>

//MenOfPassion(A[], n) {
//    sum <- 0;
//    for i <- 1 to n - 1
//        for j <- i + 1 to n
//            sum <- sum + A[i] × A[j]; # 코드1
//    return sum;
//}

int main(void)
{
    int n;
    scanf("%d", &n);
    
    // 수행 횟수 : n * (n - 1) / 2
    long long result = (long long)n * (n - 1) / 2;
    // O(n) = n^2
    
    printf("%lld\n%d", result, 2);
    
    return 0;
}