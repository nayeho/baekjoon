#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 200003

typedef struct
{
    int value;
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

int hash(int x){ return x % HASH_SIZE; }

void insert(int x)
{
    int h = hash(x);
    Node *node = hash_table[h];
    while (node)
    {
        if (node->value == x) return;
        node = node->next;
    }

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) exit(1);
    new_node->value = x;
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
}

int erase(int x)
{
    int h = hash(x);
    Node *curr = hash_table[h];
    Node *prev = NULL;

    while (curr)
    {
        if (curr->value == x)
        {
            if (prev) prev->next = curr->next;
            else hash_table[h] = curr->next;
            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;
}

void free_table()
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        Node *curr = hash_table[i];
        while (curr)
        {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int main(void)
{
    int N, M, num, count = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        insert(num);
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &num);
        if (erase(num) == 0) insert(num);
    }

    for (int i = 0; i < HASH_SIZE; i++)
    {
        Node *curr = hash_table[i];
        while (curr)
        {
            count++;
            curr = curr->next;
        }
    }

    printf("%d\n", count);
    free_table();
    return 0;
}
