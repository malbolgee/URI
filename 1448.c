/*
	@autor: Malbolge;
	@data: 27/10/2018;
	@nome: Telefone Sem Fio;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main ()
{

	char stringOriginal[110], time1[110], time2[110];
	unsigned short posiErradoTime1, posiErradoTime2;
	unsigned short casos, i, qtsInstancias = 0;
	unsigned contadorTime1, contadorTime2;
	bool errouTime1, errouTime2;
	char lixo;

	scanf("%hu", &casos);
	scanf("%c", &lixo);

	while (casos--)
	{

		scanf("%[^\n]%c%[^\n]%c%[^\n]", stringOriginal, &lixo, time1, &lixo, time2);
		scanf("%c", &lixo);

		contadorTime1 = 0;
		contadorTime2 = 0;
		errouTime1 = false;
		errouTime2 = false;
		posiErradoTime1 = 0;
		posiErradoTime2 = 0;

		for (i = 0; stringOriginal[i]; i++)
		{
			if (time1[i] == stringOriginal[i])
				contadorTime1++;
			else
				if (!errouTime1)
				{
					posiErradoTime1 = i;
					errouTime1 = true;
				}
			if (time2[i] == stringOriginal[i])
				contadorTime2++;
			else
				if (!errouTime2)
				{
					posiErradoTime2 = i;
					errouTime2 = true;
				}

			if (posiErradoTime1 == posiErradoTime2)
			{
				errouTime1 = false;
				errouTime2 = false;

			}

		}

		if (contadorTime1 == contadorTime2 && errouTime1 == true && errouTime2 == true && posiErradoTime1 > posiErradoTime2)
			printf("Instancia %hu\ntime 1\n", ++qtsInstancias);
		else if (contadorTime1 == contadorTime2 && errouTime1 == true && errouTime2 == true && posiErradoTime1 < posiErradoTime2)
			printf("Instancia %hu\ntime 2\n", ++qtsInstancias);
		else if (contadorTime1 == contadorTime2)
			printf("Instancia %hu\nempate\n", ++qtsInstancias);
		else if (contadorTime1 > contadorTime2)
			printf("Instancia %hu\ntime 1\n", ++qtsInstancias);
		else
			printf("Instancia %hu\ntime 2\n", ++qtsInstancias);

		printf("\n");

		memset(stringOriginal, 0, sizeof(stringOriginal));
		memset(time1, 0, sizeof(time1));
		memset(time2, 0, sizeof(time2));

	}

}
