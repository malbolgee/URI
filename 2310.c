/*
	@autor: Malbolge;
	@data: 31/10/2018;
	@nome: Voleibol;
*/

#include <stdio.h>

typedef struct{

	char nome[100];
	unsigned short qtsTentativaSaque;
	unsigned short qtsTentativaBloqueio;
	unsigned short qtsTentativaAtaque;
	unsigned short sucessoSaque;
	unsigned short sucessoBloqueio;
	unsigned short sucessoAtaque;

} jogador;

void main ()
{
	unsigned qtsTotalTentativaSaque, qtsTotalTentativaBloqueio, qtsTotalTentativaAtaque;
	unsigned totalSucessoSaque, totalSucessoBloqeio, totalSucessoAtaque;
	unsigned short qtsJogadores;
	unsigned short i, aux;

	scanf("%hu", &qtsJogadores);

	i = 0;
	aux = qtsJogadores;
	jogador equipe[qtsJogadores];
	while (qtsJogadores--)
	{

		scanf(" %s", equipe[i].nome);
		scanf("%hu %hu %hu", &equipe[i].qtsTentativaSaque, &equipe[i].qtsTentativaBloqueio, &equipe[i].qtsTentativaAtaque);
		scanf("%hu %hu %hu", &equipe[i].sucessoSaque, &equipe[i].sucessoBloqueio, &equipe[i].sucessoAtaque);
		i++;

	}

	totalSucessoSaque = totalSucessoAtaque = totalSucessoBloqeio = 0;
	qtsTotalTentativaSaque = qtsTotalTentativaBloqueio = qtsTotalTentativaAtaque = 0;

	for (i = 0; i < aux; i++)
	{

		qtsTotalTentativaSaque += equipe[i].qtsTentativaSaque;
		qtsTotalTentativaBloqueio += equipe[i].qtsTentativaBloqueio;
		qtsTotalTentativaAtaque += equipe[i].qtsTentativaAtaque;
		totalSucessoSaque += equipe[i].sucessoSaque;
		totalSucessoBloqeio += equipe[i].sucessoBloqueio;
		totalSucessoAtaque += equipe[i].sucessoAtaque;

	}

	printf("Pontos de Saque: %.2f %%.\n", (totalSucessoSaque * 100.0f) / qtsTotalTentativaSaque);
	printf("Pontos de Bloqueio: %.2f %%.\n", (totalSucessoBloqeio * 100.0f) / qtsTotalTentativaBloqueio);
	printf("Pontos de Ataque: %.2f %%.\n", (totalSucessoAtaque * 100.0f) / qtsTotalTentativaAtaque);

}
