#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str1[9], str2[9], str3[9];
    scanf("%s %s %s", str1, str2, str3);
    
    int next;
    if(atoi(str1) != 0) next = atoi(str1) + 3;
    else if(atoi(str2) != 0) next = atoi(str2) + 2;
    else next = atoi(str3) + 1;
    
    if(next % 3 == 0 && next % 5 == 0) printf("FizzBuzz\n");
    else if(next % 3 == 0) printf("Fizz\n");
    else if(next % 5 == 0) printf("Buzz\n");
    else printf("%d\n", next);
    
    return 0;
}