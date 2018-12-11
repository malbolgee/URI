/*
	@autor: Malbolge;
	@data: 11/12/2018;
	@nome: Lendo Livros;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	int qtsPaginasAtual;
	int qtsDiasAdiantados;
	int qtsPaginasFuturo;
	int resultado;

	scanf("%d", &qtsPaginasAtual);

	while (true)
	{

		scanf("%d %d", &qtsDiasAdiantados, &qtsPaginasFuturo);

		resultado = (qtsDiasAdiantados * qtsPaginasAtual * qtsPaginasFuturo) / (qtsPaginasFuturo - qtsPaginasAtual);

		if (resultado == 1)
			printf("%d pagina\n", resultado);
		else
			printf("%d paginas\n", resultado);

		scanf("%d", &qtsPaginasAtual);

		if (qtsPaginasAtual == 0)
			break;

	}

}
