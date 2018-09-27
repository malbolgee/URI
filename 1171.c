/*
	@autor: Malbolge;
	@data: 26/09/2018;
	@nome: Frequência de Números;
*/

#include <stdio.h>

typedef struct{

	short valor;
	short qtsAparicao;

} tipoQuantidade;


void ordena(tipoQuantidade vet[], unsigned short);
void qSortInterno(tipoQuantidade v[], int inicio, int fim);

void main ()
{

	unsigned short casos, contador;
	short i, j;
	
	scanf("%hu", &casos);

	// Vetor do struct do tipoQuantidade;
	tipoQuantidade numeros[casos];

		// Enche o vetor;
		for (i = 0; i < casos; i++)
			scanf("%hu", &numeros[i].valor);

		// Itera sobre o vetor verificando as repetições;
		// A quantidade de repetição de um número é salvo na sua posição
		// No campo qtsAparição;
		for (i = 0; i < casos; i++)
		{
			contador = 0;
			for (j = 0; j < casos; j++)
			{	
				
				if (numeros[i].valor == numeros[j].valor)
					contador++;

				numeros[i].qtsAparicao = contador;	

			}	

		}

		qSortInterno(numeros, 0, casos-1);
		
		// Se o elemento da posição anterior for igual ao da posição atual
		// Quer dizer que há repetição, então não o imprima;
		for(i = 0; i < casos; i++)
			if (numeros[i - 1].valor != numeros[i].valor)
				printf("%hu aparece %hu vez(es)\n", numeros[i].valor, numeros[i].qtsAparicao);

		
}

// Quicksort
void qSortInterno(tipoQuantidade v[], int inicio, int fim) 
{
  tipoQuantidade pivot;
  tipoQuantidade temp;
  int i,j;

  if(fim - inicio > 0)
  {
	    i = inicio;
	    j = fim;
	    pivot = v[(i + j) / 2];
	    
	    do {

	      while(v[i].valor < pivot.valor) 
	        i++;
	      while(v[j].valor > pivot.valor) 
	        j--; 
	      if(i <= j)
	      { 
	        temp = v[i];
	        v[i] = v[j];
	        v[j] = temp;
	        i++; j--;
	      }

	    } while (i <= j);

	    qSortInterno(v,inicio, j);
	    qSortInterno(v, i,fim);

  }
}