/*
	@autor: Malbolge;
	@data: 13/10/2018;
	@nome: Tempo de um Evento;
*/

#include <stdio.h>

void main ()
{

	unsigned diaComeco, horaComeco, minutoComeco, segundoComeco;
  	unsigned diaFim, horaFim, minutoFim, segundoFim;
	unsigned qtsSegundosComeco, qtsSegundosFim;
	unsigned tempoFinal;
	char string[10];

	scanf("%s %u", string, &diaComeco);
	scanf("%u : %u : %u", &horaComeco, &minutoComeco, &segundoComeco);

	scanf("%s %u", string, &diaFim);
	scanf("%u : %u : %u", &horaFim, &minutoFim, &segundoFim);

	// Transforma tudo para segundos com o intuito de trabalhar em uma mesma base;
	qtsSegundosComeco = segundoComeco + minutoComeco*60 + horaComeco*60*60 + diaComeco*60*60*24;
	qtsSegundosFim = segundoFim + minutoFim*60 + horaFim*60*60 + diaFim*60*60*24;

	// O tempo do evento será a diferença de segundos do fim com o começo;
	tempoFinal = qtsSegundosFim - qtsSegundosComeco;

	// Os prins convertem de volta os tempos para suas bases lidas
	// Descontanto a quantidade a cada novo print;
	printf("%u dia(s)\n", tempoFinal/(60*60*24));
	tempoFinal = tempoFinal % (60*60*24);
	printf("%u hora(s)\n", tempoFinal/(60*60));
	tempoFinal = tempoFinal % (60*60);
	printf("%u minuto(s)\n", tempoFinal/(60));
	tempoFinal = tempoFinal % (60);
	printf("%u segundo(s)\n", tempoFinal);


}
