/*
    @autor: Malbolge;
    @data: 20/03/2019;
    @nome: Eu Posso Adivinhar a Estrutura de Dados!;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXSIZE 1000

typedef unsigned short us;

//----------------------- Structs de Fila ------------------

typedef struct tipoNoQueue{

    int dado;
    struct tipoNoQueue *proximo;

} tipoNoQueue;

typedef struct tipoFila{

    tipoNoQueue *primeiro;
    tipoNoQueue *ultimo;

} tipoFila;

//----------------------- Structs de Pilha ------------------

typedef struct tipoNoPilha{

    int dado;
    struct tipoNoPilha *proximo;

} tipoNoPilha;

typedef struct tipoPilha{

    tipoNoPilha *topo;

} tipoPilha;

//----------------- Structs de Fila de Prioridade----------

typedef struct pqueue{

    int dado;
    int prioridade;

} pqueue;

typedef struct _pqueue{

    int qtd;
    struct pqueue dados[MAXSIZE];

} _pqueue;

//----------------------- Funções de Fila------------------

void queue(tipoFila *);
void push(tipoFila *, int);
int front(tipoFila *);
void pop(tipoFila *);

//----------------------- Funções de Pilha-----------------

void stack(tipoPilha *);
void pushPilha(tipoPilha *, int);
void popPilha(tipoPilha *);
int top(tipoPilha *);

//----------------- Funções de Fila de Prioridade----------

_pqueue* priotiry();
void pushPqueue(_pqueue *, int, int );
void popPqueue(_pqueue *);
int topPqueue(_pqueue *);
void balanceiaRemocao(_pqueue *, int);
void balanceiaInsercao(_pqueue *, int);


void main ()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {

        int x, comando, i;
        _Bool queueN, stackN, pqueue;
        _pqueue *priotiry_queue = priotiry();
        tipoFila fila;
        tipoPilha stackk;

        queue(&fila);
        stack(&stackk);

        queueN = stackN = pqueue = true;
        for (i = 0; i < n; ++i)
        {

            scanf("%d %d", &comando, &x);

            if (comando == 1)
            {

                pushPqueue(priotiry_queue, x, x);
                pushPilha(&stackk, x);
                push(&fila, x);

            }
            else
            {

                if (top(&stackk) != x)
                    stackN = false;
                else
                    popPilha(&stackk);
                
                if (front(&fila) != x)
                    queueN = false;
                else
                    pop(&fila);

                if (topPqueue(priotiry_queue) != x)
                    pqueue = false;
                else
                    popPqueue(priotiry_queue);

            }

        }

        if (!stackN && !queueN && !pqueue)
            printf("impossible\n");
        else if (stackN && pqueue)
            printf("not sure\n");
        else if (stackN && queueN)
            printf("not sure\n");
        else if (pqueue && queueN)
            printf("not sure\n");
        else if (pqueue)
            printf("priority queue\n");
        else if (queueN)
            printf("queue\n");
        else if (stackN)
            printf("stack\n");

    }

}

void queue(tipoFila *fila)
{

    fila->primeiro = fila->ultimo = NULL;

}

void push(tipoFila *fila, int x)
{

    tipoNoQueue *auxiliar;

    auxiliar = (tipoNoQueue *) malloc(sizeof(tipoNoQueue));

    if (!auxiliar)
        exit(1);

    if (fila->primeiro)
    {

        fila->ultimo->proximo = auxiliar;
        auxiliar->proximo = NULL;

    }
    else
        fila->primeiro = auxiliar;

    fila->ultimo = auxiliar;
    auxiliar->dado = x;

}

void pop(tipoFila *fila)
{

    tipoNoQueue *auxiliar;

    if (fila->primeiro)
    {

        if (fila->primeiro->proximo)
        {

            auxiliar = fila->primeiro;
            fila->primeiro = fila->primeiro->proximo;
            free(auxiliar);
            return;

        }
        else
        {

            auxiliar = fila->primeiro;
            fila->primeiro = fila->ultimo = NULL;
            free(auxiliar);
            return;

        }

    }
    else
        return;

}

int front(tipoFila *fila)
{

    return fila->primeiro->dado;

}

void stack(tipoPilha *pilha)
{

    pilha->topo = NULL;

}

int top(tipoPilha *pilha)
{

    return pilha->topo->dado;

}

void popPilha(tipoPilha *pilha)
{

    tipoNoPilha *auxiliar;

    auxiliar = pilha->topo;

    if (auxiliar)
    {

        pilha->topo = auxiliar->proximo;
        free(auxiliar);

    }

}

void pushPilha(tipoPilha *pilha, int x)
{

    tipoNoPilha *auxiliar;

    auxiliar = (tipoNoPilha *) malloc(sizeof(tipoNoPilha));

    if (!auxiliar)
        exit(1);

    auxiliar->proximo = pilha->topo;
    pilha->topo = auxiliar;
    auxiliar->dado = x;

}

void pushPqueue(_pqueue *filaP, int prioridade, int id)
{

    if (filaP == NULL)
        exit(1);

    if (filaP->qtd == MAXSIZE)
        exit(1);

    filaP->dados[filaP->qtd].dado = id;
    filaP->dados[filaP->qtd].prioridade = prioridade;
    balanceiaInsercao(filaP, filaP->qtd);
    ++filaP->qtd;

}

void balanceiaInsercao(_pqueue *filaP, int filho)
{

    int pai;
    pqueue tmp;

    pai = (filho - 1) / 2;

    while ((filho > 0) && (filaP->dados[pai].prioridade <= filaP->dados[filho].prioridade))
    {

        tmp = filaP->dados[filho];
        filaP->dados[filho] = filaP->dados[pai];
        filaP->dados[pai] = tmp;

        filho = pai;
        pai = (pai - 1) / 2;

    }

}

int topPqueue(_pqueue *filaP)
{

    if (filaP == NULL ||filaP->qtd == 0)
        return 0;

    return filaP->dados[0].dado;

}

_pqueue* priotiry()
{

    _pqueue *filaP;

    filaP = (_pqueue *) malloc(sizeof(_pqueue));

    if (filaP)
        filaP->qtd = 0;

    return filaP;

}

void popPqueue(_pqueue *filaP)
{

    if (filaP == NULL)
        exit(1);

    if (filaP->qtd == 0)
        exit(1);

    --filaP->qtd;
    filaP->dados[0] = filaP->dados[filaP->qtd];
    balanceiaRemocao(filaP, 0);

}

void balanceiaRemocao(_pqueue *filaP, int pai)
{

    int filho;
    pqueue tmp;

    filho = 2 * pai + 1;

    while (filho < filaP->qtd)
    {

        if (filho < filaP->qtd - 1)
            if (filaP->dados[filho].prioridade < filaP->dados[filho + 1].prioridade)
                ++filho;

        if (filaP->dados[pai].prioridade >= filaP->dados[filho].prioridade)
            break;

        tmp = filaP->dados[pai];
        filaP->dados[pai] = filaP->dados[filho];
        filaP->dados[filho] = tmp;
        
        pai = filho;
        filho = 2 * pai + 1;

    }

}