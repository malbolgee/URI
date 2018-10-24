/*
	@autor: Malbolge;
	@data: 23/10/2018;
	@nome: Paridade;
*/

#include <stdio.h>

void main ()
{

	unsigned qtsUns, i;
	char bitString[105];

	scanf("%s", bitString);

	qtsUns = 0;
	for (i = 0; bitString[i]; i++)
		if (bitString[i] == '1')
			qtsUns++;

	if (qtsUns % 2 == 0)
		bitString[i] = '0';
	else
		bitString[i] = '1';

	bitString[++i] = '\0';

	printf("%s\n", bitString);


}
