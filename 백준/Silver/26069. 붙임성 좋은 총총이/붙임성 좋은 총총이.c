#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_NAME 21
#define HASH_SIZE 2003

typedef struct Node
{
    char name[MAX_NAME];
    int id;
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

int id_count = 0;
int danced[MAX * 2] = { 0 };

// djb2 해시
unsigned long hash(const char *str)
{
    unsigned long h = 5381;
    while (*str) h = ((h << 5) + h) + *str++;
    return h % HASH_SIZE;
}

// 문자열 -> id 매핑 (체이닝 방식)
// 이미 등록 -> id 리턴
// 처음 등록 -> 새 노드
int get_id(const char *name)
{
    unsigned long h = hash(name);
    Node *curr = hash_table[h];
    while (curr)
    {
        if (strcmp(curr->name, name) == 0) return curr->id;
        curr = curr->next;
    }
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->id = id_count++;
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
    return new_node->id;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    char a[MAX_NAME], b[MAX_NAME];
    
    // 최초 감염 ChongChong
    int id_chong = get_id("ChongChong");
    danced[id_chong] = 1;
    
    for (int i = 0; i < N; i++)
    {
        scanf("%s %s", a, b);
        int id_a = get_id(a);
        int id_b = get_id(b);

        // 둘 중 하나라도 감염자라면 1
        if (strcmp(a, "ChongChong") == 0 || danced[id_a]) danced[id_b] = 1;
        if (strcmp(b, "ChongChong") == 0 || danced[id_b]) danced[id_a] = 1;
    }

    int result = 0;
    for (int i = 0; i < id_count; i++) if (danced[i]) result++;

    printf("%d\n", result);
    return 0;
}