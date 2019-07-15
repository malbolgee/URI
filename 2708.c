/*

	@autor: Malbolge;
	@data: 14/07/2019;
	@nome: Turistas no Parque Huacachina;

*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

int main(int argc, char **argv)
{

	int t, c, tmp;
	char com[10];

	t = c = 0 ;
	while (true)
	{

		scanf("%s", com);
		if (strcmp(com, "ABEND") == 0)
			break;

		scanf("%d", &tmp);
		if (strcmp(com, "SALIDA") == 0)
			t += tmp, c++;
		else
			t -= tmp, c--;

	}

	printf("%d\n%d\n", t, c);

	return 0;

}