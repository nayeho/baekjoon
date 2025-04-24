#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 20000 // 단어의 개수 최대 20000개
#define MAX_WORD_LEN 51 // 단어의 최대 길이 50 + 널문자 '\0'

// 그냥 해도 되지만
// 구조체를 활용해서 전개해보자 (이전 좌표평면 문제처럼)

typedef struct
{
    char word[MAX_WORD_LEN];
} Word;

// 비교 함수 로직
// 길이가 짧은 단어 -> 긴 단어 순
// 길이가 같다면 사전순 (strcmp 함수 활용하자)

int compare(const Word *first, const Word *second)
{
    int len_first = strlen(first->word);
    int len_second = strlen(second->word);
    
    // 단어의 길이가 다를 때,
    // first가 짧으면 음수
    // second가 짧으면 양수를 반환하기 위해 단순 뺄셈 계산 후 반환
    if(len_first != len_second) return len_first - len_second;
    return strcmp(first->word, second->word);
}

void merge(Word *array, Word *temp, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;

    while(i <= mid && j <= right)
    {
        if(compare(&array[i], &array[j]) <= 0) temp[k++] = array[i++];
        else temp[k++] = array[j++];
    }
    
    while (i <= mid) temp[k++] = array[i++];
    while (j <= right) temp[k++] = array[j++];

    for (int i = left; i <= right; i++) array[i] = temp[i];
}

void merge_sort(Word *array, Word *temp, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(array, temp, left, mid);
        merge_sort(array, temp, mid + 1, right);
        merge(array, temp, left, mid, right);
    }
}

int main(void) {
    
    int N;
    scanf("%d", &N);

    Word *words = malloc(sizeof(Word) * N);
    Word *temp = malloc(sizeof(Word) * N);
    
    if(words == NULL) return 1;
    if(temp == NULL) return 1;

    for (int i = 0; i < N; i++) scanf("%s", words[i].word);

    merge_sort(words, temp, 0, N - 1);

    // 단, 중복된 단어는 하나만 남기고 제거해야 한다.
    printf("%s\n", words[0].word);
    
    for (int i = 1; i < N; i++)
    {
        if (strcmp(words[i - 1].word, words[i].word) != 0)
        {
            printf("%s\n", words[i].word);
        }
    }

    free(words);
    free(temp);
    return 0;
}