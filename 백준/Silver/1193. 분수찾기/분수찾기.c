#include <stdio.h>

int normal(int n)
{
    return 1 + (n * (n - 1) / 2);
}

int main(void)
{
    int X;
    scanf("%d", &X);
    
    // Category 1 : 1
    // Category 2 : 2 ~ 3
    // Category 3 : 4 ~ 6
    // Category 4 : 7 ~ 10
    // Category 5 : 11 ~ 15
    
    int category = 2;
    while(1)
    {
        if(X < normal(category))
        {
            category--;
            break;
        }
        else
        {
            category++;
        }
    }
    int step = X - normal(category);
    int numerator = category - step;
    int denominator = 1 + step;
    
    if (category % 2 == 0)
    { // 짝수 대각선: 위에서 아래
        numerator = step + 1;
        denominator = category - step;
    }
    else
    { // 홀수 대각선: 아래에서 위
        numerator = category - step;
        denominator = step + 1;
    }
    printf("%d/%d\n", numerator, denominator);
    
    return 0;
}