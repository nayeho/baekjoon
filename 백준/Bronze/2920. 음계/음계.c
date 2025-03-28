#include <stdio.h>

int main(void)
{
    int scale[8];
    for(int i = 0; i < 8; i++) scanf("%d", &scale[i]);
    if(scale[0] == 1)
    {
        int check = 1;
        for(int i = 0; i < 8; i++)
        {
            if(scale[i] != i + 1)
            {
                check = 0;
                break;
            }
        }
        if(check) printf("ascending");
        else printf("mixed");
    }
    else if(scale[0] == 8)
    {
        int check = 1;
        for(int i = 0; i < 8; i++)
        {
            if(scale[i] != 8 - i)
            {
                check = 0;
                break;
            }
        }
        if(check) printf("descending");
        else printf("mixed");
    }
    else printf("mixed");
    return 0;
}