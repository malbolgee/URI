/*
	@autor: Malbolge;
	@data: 30/09/2018;
	@nome: VaiNaSort;
*/

#include <stdio.h>
#include <stdbool.h>

bool verificaOrd(short vet[], short cmp[], unsigned short tam);

void main ()
{

	unsigned short numero, i;
	unsigned short qtsOrd;
	bool resultado;

	while (true)
	{	
		scanf("%hu", &numero);

		if (numero == 0)
			break;

		short caixa[numero];
		short cmp[numero];

		// Enche um vetor comparação com números que vão de 1 até n;
		for (i = 0; i < numero; i++)
			cmp[i] = i+1;

		// Quantidade de tentativas já começa com 1
		// Pois mesmo que na primeira tentativa já fique ordenado
		// Gastou uma tentativa;
		qtsOrd = 1;
		do
		{
			// Enche o vetor principal com a entrada do usuário;
			for (i = 0; i < numero; i++)
				scanf("%hu", &caixa[i]);

			// Variável resultado recebe a resposta da função que verifica a ordenação;
			resultado = verificaOrd(caixa, cmp, numero);

			// Se não estiver ordenado; 
			// Quantidade de tentativas aumenta 1;
			if (!resultado)
				qtsOrd++;

		} while (!resultado);
		
		printf("%hu\n", qtsOrd);			

	}


}

bool verificaOrd(short vet[], short cmp[], unsigned short tam)
{

	unsigned short i;

	// Se encontrar um número diferenta em posições iguais, o vetor não
	// Está ordenado e a função retorna falso;
	for (i = 0; i < tam; i++)
		if (vet[i] != cmp[i])
			return false;

	return true;

}