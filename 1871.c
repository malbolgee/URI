/*
	@autor: Malbolge;
	@data: 29/08/2018;
	@nome: Zero vale Zero;
*/

#include <stdio.h>

int main(){
	int m,n,v[15],i;

	while(scanf("%d %d",&m,&n) && (m!=0 || n!=0))
	{
		int soma = m + n;

		//Separa cada dígito do número e coloca em posições do vetor;
		for(i = 0 ; i < 11 ; i++)
		{
			v[i] = soma %10;
			soma /= 10;
		}

		//Imprime o vetor caso o valor da posição i não seja 0;
		//i começa com 10 porque os algarismos foram colocados no vetor de trás
		//para frente;
		for(i = 10 ; i >= 0 ; i--){
			if(v[i] != 0){
				printf("%d",v[i]);
			}
		}
		printf("\n");
	}
}
