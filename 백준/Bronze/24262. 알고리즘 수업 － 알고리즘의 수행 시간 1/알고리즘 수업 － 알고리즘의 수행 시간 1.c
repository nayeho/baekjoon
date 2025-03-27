#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    
    //    MenOfPassion(A[], n) {
    //        i = ⌊n / 2⌋;
    //        return A[i]; # 코드1
    //    }
    
    // 함수 호출 시 return 1번만 일어나고 끝
    // 수행 횟수 -> 항상 1
    // 다항식 -> O(n) = 1 이므로 최고차항 차수는 0
    
    printf("%d\n%d", 1, 0);
    return 0;
}