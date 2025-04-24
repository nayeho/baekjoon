#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000      // 문자열의 개수
#define MAX_LEN 501      // 문자열 길이 최댓값

// 소수: 해시 충돌 감소용
// 2, 10, 100 등 배수 계열이면 수열이 쉽게 겹치게 된다
// 같은 인덱스에 여러 값이 연결리스트로 저장되게 되면
// 예) hash_table[10] : "a" -> "b" -> "c" -> NULL
// 이라면 "c"를 탐색하는 시간 복잡도가 O(n)으로 수렴하게 된다.
// 소수를 사용해 겹치는 인덱스를 줄이면 시간 복잡도가 O(1)로 향하게 된다.
// 그러므로, 소수를 활용하자
// 작은 테이블 : 1031, 2053
// 중간 테이블 : 10007, 20011
// 큰 테이블 : 131071, 262147
// 아주 큰 테이블 : 10000019, 10000079
#define HASH_SIZE 20011  

// 연결 리스트
typedef struct
{
    char word[MAX_LEN];
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

// djb2 해시를 사용하자
// 대니얼 J.번스타인 ver2
int hash(const char *str)
{
    // 해시 시작값을 5381로 설정
    // 실험적으로 좋은 분산 결괏값을 보인 값
    // 관습적으로 사용됨
    unsigned long hash = 5381;
    // hash << 5 는 hash * 2 * 2 * 2 * 2 * 2
    // 즉, hash * 32(2^5)
    // (hash << 5) + hash -> hash * 33의 의미
    // 여기에 ASCII 값을 더해 하나의 정수값으로 압축!
    while (*str) hash = ((hash << 5) + hash) + *str++;
    // 굉장히 큰 hash를 해시 테이블 크기수로 나눠서 최종 인덱스를 결정
    return hash % HASH_SIZE;
}

// 체이닝 기법(Chaining)
// 소수로부터 같은 인덱스를 할당받은 문자열들을
// 연결 리스트로 엮어서
// 같은 인덱스에 여러 문자열을 저장할 수 있다
void insert(const char *str)
{
    int h = hash(str);
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) exit(1);
    strcpy(new_node->word, str);
    // 기존 해시 테이블에 저장된 연결 리스트가 있다면
    // new_node -> 기존 노드 -> ...
    // 형식으로 연결
    // 즉, 연결 리스트의 가장 앞에 삽입
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
}

int search(const char *str)
{
    int h = hash(str);
    Node *curr = hash_table[h];
    while (curr != NULL)
    {
        // 각 노드의 word와 입력 문자열 str 비교
        // 해시값으로 변환된 인덱스 h의 모든 연결 리스트를 탐색해서
        // 같은 문자열을 찾으면 1, 없으면 0을 반환
        if (strcmp(curr->word, str) == 0) return 1;
        curr = curr->next;
    }
    return 0;
}

// 열었으면 닫자
// 할당했으면 닫자
// 연결했으면 닫자
void free_table()
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        Node *curr = hash_table[i];
        while (curr != NULL)
        {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int main(void)
{
    int N, M, count = 0;
    char str[MAX_LEN];

    scanf("%d %d", &N, &M);

    // 입력부
    for (int i = 0; i < N; i++)
    {
        scanf("%s", str);
        insert(str);
    }

    // 들어온 문자열이 
    // 해시 테이블에 존재하는지 확인
    for (int i = 0; i < M; i++)
    {
        scanf("%s", str);
        if (search(str)) count++;
    }

    printf("%d\n", count);
    free_table();
    return 0;
}
