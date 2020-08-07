/*
    @author: Malbolge;
    @date: 11/07/2020;
    @name: A Fila de Desempregados;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct __vctm
{
    int id;
    struct __vctm *prev;
    struct __vctm *next;
} vctm_t;

vctm_t *fill(int);
vctm_t *delete (vctm_t *, vctm_t *);
int count(vctm_t *);
vctm_t *traverse(vctm_t *, int, int);

int main(int argc, char **argv)
{

    int n, k, m, i;
    vctm_t *list, *K, *M, *auxK, *auxM;

    while (scanf("%d %d %d", &n, &k, &m), n)
    {

        list = fill(n);
        K = list;
        M = list->prev;

        while (count(list) > 2)
        {

            K = traverse(K, k, 0x0);
            M = traverse(M, m, 0x1);

            if (K->next == M)
                auxK = M->next;
            else
                auxK = K->next;

            if (M->prev == K)
                auxM = K->prev;
            else
                auxM = M->prev;

            if (K == M)
            {
                printf("%3d,", M->id);
                list = delete (list, K);
            }
            else
            {
                printf("%3d%3d,", K->id, M->id);
                list = delete (list, M);
                list = delete (list, K);
            }

            K = auxK;
            M = auxM;
        }

        if (count(list) == 2)
        {
            K = traverse(K, k, 0x0);
            M = traverse(M, m, 0x1);

            if (K == M)
                printf("%3d,%3d\n", K->id, K->next->id);
            else
                printf("%3d%3d\n", K->id, K->next->id);
        }
        else
            printf("%3d\n", list->id);
    }

    return 0;
}

vctm_t *fill(int size)
{

    vctm_t *node;
    vctm_t *node_prev;
    vctm_t *start = NULL;

    for (int i = 1; i <= size; ++i)
    {

        node = (vctm_t *)malloc(sizeof(vctm_t));
        node->id = i;

        if (start == NULL)
            start = node;
        else
        {
            node_prev->next = node;
            node->prev = node_prev;
        }

        node_prev = node;
    }

    start->prev = node;
    node->next = start;

    return start;
}

vctm_t *delete (vctm_t *list, vctm_t *reg)
{
    vctm_t *node_prev = reg->prev;
    vctm_t *node_next = reg->next;

    if (reg == list)
    {
        list = list->next;
        node_prev->next = list;
        list->prev = reg->prev;
    }
    else
    {
        node_prev->next = node_next;
        node_next->prev = node_prev;
    }

    free(reg);
    return list;
}

int count(vctm_t *list)
{

    int i;
    vctm_t *node = list;
    for (i = 1; list != node->next; ++i)
        node = node->next;

    return i;
}

vctm_t *traverse(vctm_t *list, int n, int direction)
{

    vctm_t *node = list;
    if (direction == 0)
        while (--n)
            node = node->next;
    else
        while (--n)
            node = node->prev;

    return node;
}