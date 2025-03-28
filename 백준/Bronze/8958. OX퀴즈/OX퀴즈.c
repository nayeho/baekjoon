#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++)
    {
        char test[81];
        scanf("%s", test);

        int score = 0;
        int sequence = 1;
        for(int j = 0; test[j] != '\0'; j++)
        {
            if(test[j] == 'O') score += sequence++;
            else sequence = 1;
        }
        
        printf("%d\n", score);
    }
    
    
    return 0;
}