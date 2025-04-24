#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 21
#define HASH_SIZE 200003  // 큰 테이블에 해당하는 소수

typedef struct
{
    char name[MAX_NAME_LEN];
    int number;
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

// 1-based index
char *poke_index[100001];

// djb 2
int hash(const char *str)
{
    unsigned long hash = 5381;
    while (*str) hash = ((hash << 5) + hash) + *str++;
    return hash % HASH_SIZE;
}

void insert(const char *name, int number)
{
    int h = hash(name);
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) exit(1);
    strcpy(new_node->name, name);
    new_node->number = number;
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
}

int search(const char *name)
{
    int h = hash(name);
    Node *node = hash_table[h];
    while (node)
    {
        if (strcmp(node->name, name) == 0) return node->number;
        node = node->next;
    }
    return -1;
}

int main(void)
{
    int N, M;
    char input[MAX_NAME_LEN];
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        scanf("%s", input);
        poke_index[i] = malloc(strlen(input) + 1);
        strcpy(poke_index[i], input);
        insert(input, i);
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%s", input);
        if (isdigit(input[0]))
        {
            int index = atoi(input);
            printf("%s\n", poke_index[index]);
        }
        else printf("%d\n", search(input));
    }

    return 0;
}
