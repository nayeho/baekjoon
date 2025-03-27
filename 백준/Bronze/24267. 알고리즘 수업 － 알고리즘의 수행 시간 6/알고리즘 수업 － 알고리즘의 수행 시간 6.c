#include <stdio.h>
//MenOfPassion(A[], n) {
//    sum <- 0;
//    for i <- 1 to n - 2
//        for j <- i + 1 to n - 1
//            for k <- j + 1 to n
//                sum <- sum + A[i] × A[j] × A[k]; # 코드1
//    return sum;
//}
int main(void)
{
    int n;
    scanf("%d", &n);
    
    // 수행 횟수 : (n - 2) * (n - 1) * n / 6
    // 시간 복잡도 O(n) = n^3
    
    long long result = (long long)(n - 2) * (n - 1) * n / 6;
    
    printf("%lld\n%d", result, 3);
    return 0;
}