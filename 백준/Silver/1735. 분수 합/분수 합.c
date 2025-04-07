#include <stdio.h>

int GCD(int num1, num2)
{
    int G;
    int result;
    while(1)
    {
        if(num2 == 0)
        {
            G = num1;
            break;
        }
        else
        {
            result = num1 % num2;
            num1 = num2;
            num2 = result;
        }
    }
    return G;
}

int main(void)
{
    int A, B; // 첫 번째 분자와 분모
    scanf("%d %d", &A, &B);
    
    int C, D; // 두 번째 분자와 분모
    scanf("%d %d", &C, &D);
    
    //   A         C      Ad+bC
    // ------ + ------ = ------
    //  B(bG)    D(dG)`    bdG
    
    // G(B와 D의 최대 공약수)를 먼저 구하자
    int G_BD = GCD(B, D);
    
    int b = B / G_BD;
    int d = D / G_BD;
    int molecule = A * d + b * C; // 분자
    int denominator = b * d * G_BD; // 분모
    
    // 분자와 분모의 최대 공약수 GG
    int G_molecule_denominator = GCD(molecule, denominator);
    
    int divisor_molecule = molecule / G_molecule_denominator;
    int divisor_denominator = denominator / G_molecule_denominator;
    
    printf("%d %d", divisor_molecule, divisor_denominator);
    return 0;
}