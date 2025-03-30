#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    
    int S, M, L, XL, XXL, XXXL;
    scanf("%d %d %d %d %d %d", &S, &M, &L, &XL, &XXL, &XXXL);
    
    int T, P;
    scanf("%d %d", &T, &P);
    
    int T_result = 0;

    T_result += (S % T != 0) ? S / T + 1 : S / T;
    T_result += (M % T != 0) ? M / T + 1 : M / T;
    T_result += (L % T != 0) ? L / T + 1 : L / T;
    T_result += (XL % T != 0) ? XL / T + 1 : XL / T;
    T_result += (XXL % T != 0) ? XXL / T + 1 : XXL / T;
    T_result += (XXXL % T != 0) ? XXXL / T + 1 : XXXL / T;
    
    int P_result = N / P;
    int P_mod = N % P;
    
    printf("%d\n%d %d\n", T_result, P_result, P_mod);
    
    
    return 0;
}