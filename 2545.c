/*
    @author: Malbolge;
    @date: 11/04/2023;
    @problem: Manyfile;
    @subject: Graph;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILES 1121

bool visited[MAX_FILES];

int status[MAX_FILES];
int adj[MAX_FILES][MAX_FILES];
int topologically_sorted[MAX_FILES];

int num_files;
int num_vertices;
int number_of_vertices;

enum COLOR
{
    WHITE,
    GRAY,
    BLACK
};

int dfs(int);
int maxx(int, int);
bool topological_sorting(int);

int main(int argc, char **argv)
{

    while (~scanf("%d", &num_files))
    {

        num_vertices = num_files;
        memset(status, false, sizeof(int) * MAX_FILES);
        memset(topologically_sorted, 0, sizeof(int) * MAX_FILES);
        memset(adj, 0, sizeof(int) * (MAX_FILES * MAX_FILES));
        memset(visited, false, sizeof(bool) * MAX_FILES);

        for (int i = 1; i <= num_files; ++i)
        {
            int num_dependecies;
            scanf("%d", &num_dependecies);
            while (num_dependecies--)
            {
                int dependecy;
                scanf("%d", &dependecy);
                adj[dependecy][i] = 1;
            }
        }

        bool has_cycle = false;
        for (int i = 1; i <= num_files && !has_cycle; ++i)
            if (status[i] != BLACK)
                has_cycle = topological_sorting(i);

        if (has_cycle)
        {
            printf("-1\n");
            continue;
        }

        int maximum_depth = 0;
        for (int i = 1; i <= num_files; ++i)
            if (!visited[topologically_sorted[i]])
                maximum_depth = maxx(maximum_depth, dfs(topologically_sorted[i]));

        printf("%d\n", maximum_depth);
    }

    return 0;
}

inline int maxx(int a, int b)
{

    return a > b ? a : b;
}

int dfs(int u)
{

    visited[u] = true;
    int internal_maximum_depth = 0;
    for (int i = 1; i <= num_files; ++i)
        if (adj[u][i] && !visited[i])
            internal_maximum_depth = maxx(internal_maximum_depth, dfs(i));

    return internal_maximum_depth + 1;
}

bool topological_sorting(int u)
{

    status[u] = GRAY;
    for (int i = 1; i <= num_files; ++i)
    {
        if (adj[u][i])
        {
            if (status[i] == GRAY)
                return true;
            else if (status[i] == WHITE && topological_sorting(i))
                return true;
        }
    }

    topologically_sorted[num_vertices--] = u;
    status[u] = BLACK;
    return false;
}