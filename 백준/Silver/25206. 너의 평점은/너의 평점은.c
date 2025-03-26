#include <stdio.h>
#include <string.h>

int main(void)
{
    int total_score = 0;
    double sum = 0;
    for(int i = 0; i < 20; i++)
    {
        char subject[51];
        double score;
        char grade[3];
        
        scanf("%s %lf %s", subject, &score, grade);
        

        
        if(grade[0] != 'P')
        {
            total_score += score;
            if(grade[0] == 'A' && grade[1] == '+') sum += 4.5 * score;
            else if(grade[0] == 'A' && grade[1] == '0') sum += 4.0 * score;
            else if(grade[0] == 'B' && grade[1] == '+') sum += 3.5 * score;
            else if(grade[0] == 'B' && grade[1] == '0') sum += 3.0 * score;
            else if(grade[0] == 'C' && grade[1] == '+') sum += 2.5 * score;
            else if(grade[0] == 'C' && grade[1] == '0') sum += 2.0 * score;
            else if(grade[0] == 'D' && grade[1] == '+') sum += 1.5 * score;
            else if(grade[0] == 'D' && grade[1] == '0') sum += 1.0 * score;
        }
    }
    printf("%f", sum / total_score);
    
    return 0;
}