/*

    @author: Malbolge;
    @date: 21/02/2020;
    @name: Distribuição de Artigos;

*/

#include <stdio.h>
#include <stdbool.h>

typedef struct _peer{

    int max;
    int paper;
    bool over;

} peer_t;

void insertion(peer_t *, int);
bool check(peer_t *, int);


int main(int argc, char **argv)
{

    int i, n, papers;

    while (scanf("%d", &n), n)
    {

        peer_t rev[110] = { 0 };

        for (i = 0; i < n; ++i)
            scanf("%d", &rev[i].max);

        scanf("%d", &papers);
    
        insertion(rev, n);
        
        i = 0;
        while (papers && !check(rev, n))
        {

            if (rev[i % n].paper < rev[i % n].max)
                rev[i % n].paper += 1, --papers;
            else
                rev[i % n].over = true;
            
            ++i;

        }

        if (papers)
        {

            puts("Impossible");
            continue;

        }

        for (i = 0; i < n; ++i)
            printf("%d\n", rev[i].paper);

    }

    return 0;

}

bool check(peer_t *v, int size)
{

    for (int i = 0; i < size; ++i)
        if (v[i].over == false)
            return false;

    return true;

}


void insertion(peer_t *v, int size)
{

    int i = 1, j; 
    peer_t pivot;

    while (i < size)
    {

        j = i - 1;
        pivot = v[i];

        while (j >= 0 && v[j].max < pivot.max)
            v[j + 1] = v[j], --j;

        ++i;
        v[j + 1] = pivot;
    
    }

}