/*
    @autor: Nilson Andrade;
    @data: 30/08/2019;
    @nome: Coloque Tijolos na Parede;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int main(int argc, char **argv)
{

	int n, k, i, j;
	int fe, topo, fd;
	int matriz[10][10];

	scanf("%d", &n);

	while (n--)
	{

		memset(matriz, -1, sizeof(matriz));
		for(i = 0; i <= 8; i += 2)
			for(j = 0, k = 0; j <= (i / 2); j++, k += 2)
				scanf("%d", &matriz[i][k]);

		for(i = 0; i < 8; i += 2){
			for(j = 0, k = 0; j <= (i / 2); j++, k += 2){

				topo = matriz[i][k];
				fe = matriz[i + 2][k];
				fd = matriz[i + 2][k + 2];
				matriz[i + 2][k + 1] = ((topo - fe - fd) / 2);
				matriz[i + 1][k] = fe + matriz[i + 2][k + 1];
				matriz[i + 1][k + 1] = matriz[i + 2][k + 1] + fd;

			}
		}

		for(i = 0; i < 9; i++){
			for(j = 0; j < i; j++)
				printf("%d ", matriz[i][j]);

			printf("%d\n", matriz[i][j]);

		}

	}

	return 0;

}