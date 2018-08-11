/*
	@autor: Malbolge;
	@data: 06/08/2018;
	@nome: Imposto de Renda;
*/


#include <stdio.h>

int main ()
{

	float x, nivel1, nivel2, nivel3;

	scanf("%f", &x);

	if (x >= 0.0 && x <= 2000.0)
		printf("Isento\n");
	else
	{

		x -= 2000.0;
		if (x <= 1000.0)
		{

			nivel1 = x*0.08;
			printf("R$ %.2f\n", nivel1);
		}
		else
		{

			nivel1 = 80.0;
			x -= 1000.0;
			if (x <= 1500.0)
			{

				nivel2 = x*0.18;
				printf("R$ %.2f\n", nivel1+nivel2);

			}
			else
			{

				nivel2 = 270.0;
				x -= 1500.0;
				nivel3 = x*0.28;
				printf("R$ %.2f\n", nivel1+nivel2+nivel3);

			}
		}
	}
}
