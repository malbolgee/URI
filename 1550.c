/*
    @autor: Malbolge;
    @data: 31/07/2019;
    @nome: Inversão;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef struct __queue__node{

    int data;
    struct __queue__node *next;

} queue_node;

typedef struct __queue__type{

    queue_node *first;
    queue_node *last;

} queue_t;

int a, b;
int d[100010];

void bfs(int);
void pop(queue_t *);
int front(queue_t *);
_Bool is_empty(queue_t *);
void push(queue_t *, int);
void make_queue(queue_t *);

int main(int argc, char **argv)
{

    int t;
    scanf("%d", &t);

    while (t--)
    {

        memset(d, -1, sizeof(d));
        scanf("%d %d", &a, &b);

        bfs(a);

        printf("%d\n", d[b]);

    }

    return 0;

}

void bfs(int u)
{

    queue_t queue;
    make_queue(&queue);
    push(&queue, u);

    d[u] = 0;

    while (!is_empty(&queue))
    {

        int v = front(&queue);

        if (d[b] != -1)
            break;

        pop(&queue);

        int rev = 0, uu = v;

        while (uu)
        {

            rev *= 10;
            rev += uu % 10;
            uu /= 10;

        }

        if (d[rev] == -1)
            d[rev] = d[v] + 1, push(&queue, rev);
        
        if (d[v + 1] == -1)
            d[v + 1] = d[v] + 1, push(&queue, v + 1);

    }

}

void make_queue(queue_t *__queue)
{

    __queue->first = NULL;
    __queue->last = NULL;

}

void push(queue_t *__queue, int __data)
{

    queue_node *aux;
    aux = (queue_node *) malloc(sizeof(queue_node));

    if (__queue->first)
        __queue->last->next = aux;
    else
        __queue->first = aux;

    aux->next = NULL;
    __queue->last = aux;
    aux->data = __data;

}

void pop(queue_t *__queue)
{

    queue_node *aux;

    if (__queue->first)
    {

        if (__queue->first->next)
        {

            aux = __queue->first;
            __queue->first = __queue->first->next;
            free(aux);           
            
        }
        else
        {

            aux = __queue->first;
            __queue->first = __queue->last = NULL;
            free(aux);
            
        }

    }
    else
        return;

}

_Bool is_empty(queue_t *__queue)
{

    return __queue->first == NULL;

}

int front(queue_t *__queue)
{

    return __queue->first->data;

}