/*
	@autor: Malbolge;
	@data: 07/05/2019;
	@nome: A Mudança Continua!!;
*/

#include <stdio.h>

void main()
{

	float y, x;

	while (scanf("%f", &y) != EOF)
	{

		x = (int)y;
		int horas = ((int)(y * 240) / 3600) % 60;
		int minutos = ((int)(y * 240) / 60) % 60;
		int segundos = (int)(y * 240) % 60;

		if (x >= 0 && x < 90 || x == 360)
			printf("Bom Dia!!\n%02d:%02d:%02d\n", (horas + 6) % 24, minutos, segundos);
		else if (x >= 90 && x < 180)
			printf("Boa Tarde!!\n%02d:%02d:%02d\n", (horas + 6) % 24, minutos, segundos);
		else if (x >= 180 && x < 270)
			printf("Boa Noite!!\n%02d:%02d:%02d\n", (horas + 6) % 24, minutos, segundos);
		else if (x >= 270 && x < 360)
			printf("De Madrugada!!\n%02d:%02d:%02d\n", (horas + 6) % 24, minutos, segundos);
			
	}

}