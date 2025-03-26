#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
 
    int group_num = 0; //그룹 단어의 개수
    for(int i = 0; i < n; i++)
    {
        char word[101];
        scanf("%s", word);
 
        //그룹 단어인지 확인
        int alphabet[26]; //index 0 부터 a, b, ..
        for(int j = 0; j < 26; j++) alphabet[j] = 0;
 
        int word_len = strlen(word);
        for(int k = 0; k < word_len; k++)
        {
            char letter = word[k];
            if(alphabet[letter-'a'] == 0) alphabet[letter-'a'] = 1;
            else
            {   //이미 1이라면, 바로 앞 문자 확인 앞 문자와 다르다면, 그룹 단어가 아님
                if(word[k-1] != word[k]) break; 
            }
            //여기까지 오면 그룹단어
            if(k == word_len - 1) group_num++;
        }
    }
    printf("%d\n", group_num);
}