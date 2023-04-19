/*
    @autor: Malbolge;
    @data: 04/12/2023;
    @nome: Estradas Escuras;
    @subject: Graphs, BFS, MST, Kruskal, Prim
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EDGES_COUNT 200100
#define MAX_HEAP_SIZE (MAX_EDGES_COUNT << 1)

typedef struct _heap_element
{
    int vertex, weight;
} heap_element_t;

typedef struct _vertex
{
    int vertex, weight;
    struct _vertex *next;
} vertex_t;

typedef struct _graph
{
    vertex_t *adj;
} graph_t;

int size = 0;
bool inMST[MAX_EDGES_COUNT];
heap_element_t heap[MAX_HEAP_SIZE];

void insert(heap_element_t);
heap_element_t pop();
static int parent(int);
static int left_child(int);
static int right_child(int);
static void shift_up(int);
static void shift_down(int);
bool is_queue_empty();
static void swap(heap_element_t *, heap_element_t *);

graph_t *new_graph(int);
vertex_t *new_vertex(int, int);
void push(graph_t *, int, int, int);
void add_edge(graph_t *, int, int, int);

int prim(graph_t *, int);

int main(int argc, char **argv)
{

    int vertices, edges;
    scanf("%d %d", &vertices, &edges);

    while (vertices | edges)
    {

        size = 0;
        int total_cost = 0;
        graph_t *graph = new_graph(edges);

        int x, y, z;
        for (int i = 0; i < edges; ++i)
            scanf("%d %d %d", &x, &y, &z), add_edge(graph, x, y, z), total_cost += z;

        printf("%d\n", total_cost - prim(graph, x));

        scanf("%d %d", &vertices, &edges);
    }

    return 0;
}

void insert(heap_element_t element)
{
    heap[size] = element;
    shift_up(size++);
}

heap_element_t pop()
{
    heap_element_t result = heap[0];
    heap[0] = heap[--size];
    shift_down(0);
    return result;
}

static inline int parent(int i)
{
    return (i - 1) >> 1;
}

static inline int left_child(int i)
{
    return (i << 1) | 1;
}

static inline int right_child(int i)
{
    return (i << 1) + 2;
}

bool is_queue_empty()
{
    return size <= 0;
}

static void shift_up(int i)
{
    int parent_index = parent(i);
    if (i > 0 && heap[i].weight < heap[parent_index].weight)
        swap(&heap[i], &heap[parent_index]), shift_up(parent_index);
}

static void shift_down(int i)
{

    int min_index = i;
    int left_child_index = left_child(i);
    int right_child_index = right_child(i);

    if (left_child_index < size && heap[left_child_index].weight < heap[min_index].weight)
        min_index = left_child_index;

    if (right_child_index < size && heap[right_child_index].weight < heap[min_index].weight)
        min_index = right_child_index;

    if (i != min_index)
        swap(&heap[i], &heap[min_index]), shift_down(min_index);
}

static inline void swap(heap_element_t *a, heap_element_t *b)
{
    heap_element_t t = *a;
    *a = *b;
    *b = t;
}

graph_t *new_graph(int number_of_edges)
{

    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
    graph->adj = (vertex_t *)malloc(sizeof(vertex_t) * (number_of_edges + 1));

    for (int i = 0; i <= number_of_edges; ++i)
        graph->adj[i].next = NULL;

    return graph;
}
vertex_t *new_vertex(int u, int w)
{
    vertex_t *v = (vertex_t *)malloc(sizeof(vertex_t));
    v->vertex = u;
    v->weight = w;

    return v;
}

void push(graph_t *graph, int u, int v, int w)
{

    vertex_t *vertex = new_vertex(u, w);
    vertex->next = graph->adj[v].next;
    graph->adj[v].next = vertex;
}

void add_edge(graph_t *graph, int u, int v, int w)
{
    push(graph, u, v, w);
    push(graph, v, u, w);
}

int prim(graph_t *graph, int start_vertex)
{

    int mst_cost = 0;
    memset(inMST, false, sizeof(bool) * MAX_EDGES_COUNT);
    insert((heap_element_t){start_vertex, 0});

    while (!is_queue_empty())
    {

        heap_element_t u = pop();

        if (inMST[u.vertex])
            continue;

        mst_cost += u.weight;
        inMST[u.vertex] = true;

        for (vertex_t *i = graph->adj[u.vertex].next; i != NULL; i = i->next)
        {
            int vertex = i->vertex;
            int weight = i->weight;

            if (inMST[vertex] == false)
                insert((heap_element_t){vertex, weight});
        }
    }

    return mst_cost;
}