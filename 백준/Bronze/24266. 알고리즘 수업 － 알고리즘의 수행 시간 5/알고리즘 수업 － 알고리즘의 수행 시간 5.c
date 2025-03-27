#include <stdio.h>

//MenOfPassion(A[], n) {
//    sum <- 0;
//    for i <- 1 to n
//        for j <- 1 to n
//            for k <- 1 to n
//                sum <- sum + A[i] × A[j] × A[k]; # 코드1
//    return sum;
//}

int main(void)
{
    int n;
    scanf("%d", &n);
    
    // 수행 횟수 : n * n * n
    long long result = (long long)n * n * n;
    
    // 시간 복잡도 : O(n) = n^3
    
    printf("%lld\n%d", result, 3);
    
    return 0;
}