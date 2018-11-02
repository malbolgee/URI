/*
	@autor: Malbolge;
	@data: 02/11/2018;
	@nome: Fila;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

	unsigned short numero;
	unsigned short posicao;

} pessoa;


void main ()
{

	/*
		qtsPessoas receberá a quantidade de pessoas na fila;
		qtsPessoasSairam receberá a quantidade de pessoas que saíram da fila;
		i será o índice em várias ocasiões;
		idPessoa será o identificador da pessoa na fila;
		fila[51000] será o vetor de struct que conterá as informações de posição e id de cada pesoa;
	*/

	unsigned short qtsPessoas, qtsPessoasSairam;
	unsigned short i, idPessoa;
	pessoa fila[51000];

	scanf("%hu", &qtsPessoas);

	memset(fila, 0, sizeof(fila));

	// Esse laço enche a struct com os id's das pessoas na fila;
	// O campo posição salva a posição da pessoa no momento da inserção,
	// Entretanto não o faz na posição 'i' e sim na posição de seu id;
	// Isso proporcionará um acesso instantâneo mais tarde sem precisar fazer
	// Uma pesquisa linear todas as vezes que eu quiser "retirar" alguém da fila;
	for (i = 0; i < qtsPessoas; i++)
	{
		scanf("%hu", &idPessoa);
		fila[i].numero = idPessoa;
		fila[idPessoa].posicao = i;

	}


	scanf("%hu", &qtsPessoasSairam);

	// Como não há identificador '0' para ninguém
	// As pessoas que saíram da fila recebem 0 na posição em que foi salva originalmente
	// Mas a pesquisa é "instantânea", pois eu procuro pelo índice em que ela foi salva dentro
	// da própria struct;
	for (i = 0; i < qtsPessoasSairam; i++)
	{

		scanf("%hd", &idPessoa);
		fila[fila[idPessoa].posicao].numero = 0;

	}

	// Aqui um truque para passar na impressão da questão
	// Não pode haver espaços no começo nem no final da impressão;
	// Por isso, uma variável 'flag' verifica se já foi impresso alguma coisa
	// Note que pode haver o número 0 na primeira ou demais posições e ele não será impresso
	// Por isso, é necessário verificar se alguma coisa já foi impressa até o momento;
	bool primEspaco = false;
	for (i = 0; i < qtsPessoas; i++)
		if (fila[i].numero)
		{
			if (primEspaco == true && i != qtsPessoas)
				printf(" ");

			primEspaco = true;
			printf("%hu", fila[i].numero);
		}

	printf("\n");
}
