#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


int fatorial(short);
void mod_vetor(short vet[], unsigned short);
void press(short vet[], unsigned short);
void vet_invet(short vet[], unsigned short);
void vetOrdVerfi(short vet[], unsigned short);
unsigned short calcQuadrado(unsigned short);
unsigned short contaLetra(char string[], char);
void verificaPalin(char nome[]);
void vetSub(short vet[], unsigned short vetTam, short delta);
void vetSubPosi(short vet[], unsigned short vetTam);
void revertSubPosi(short vet[], unsigned short vetTam);
int fib(unsigned short numero);
void invertString(char string[]);
int buscaBin(short vetor[], short chave);

int main ()
{

	unsigned short elemento, n;
	short vetor[] = { 15, 2, 9, -5 , -7, 0, 3, 1, 2, 16, 4 }; //Tamanho 11;
	short vetor2[] = { 15, 2, 9, -5 , -7, 0, 3, 1, 2, 16, 4 }; // tamanho 11;
	short vetorOrdem[] = { 1, 3, 5, 7, 11, 13, 15, 17, 19 };
	short vetorOrdem2[] = { 1, 3, 5, 7, 11, 13, 15, 17, 19 }; // Tamanho 9;
	short vetorDesord[] = { 19, 17, 15, 13, 13, 11, 7, 5, 3 };
	short vetorBuscaBin[] = { 1, 3, 5, 7, 11, 13, 15, 17, 19 };
	char string[] = "TORRINOLARINGOLOGISTA";
	char nome[] = "arara";

	scanf("%hd", &elemento);
	printf("Questão 1: %d é %d\n", elemento, fatorial(elemento));
	vet_invet(vetor, 11);
	puts("Questão 3: ");
	press(vetor, 11);
	mod_vetor(vetor, 11);
	puts("Vetor Modificado:");
	press(vetor, 11);
	press(vetorOrdem, 9);
	vetOrdVerfi(vetorOrdem, 9);
	press(vetorDesord, 9);
	vetOrdVerfi(vetorDesord, 9);
	puts("Soma de todos os quadrados");
	printf("%d\n", calcQuadrado(elemento));
	puts("Questão 8: ");
	printf("%d\n", contaLetra(string, 'a'));
	puts("Questão 9: ");
	verificaPalin(nome);
	puts("Questão 11:");
	vetSub(vetor2, 11, 5);
	press(vetor2, 11);
	puts("Questão 12:");
	vetSubPosi(vetorOrdem2, 9);
	press(vetorOrdem2, 9);
	puts("Questão 13: ");
	revertSubPosi(vetorOrdem2, 9);
	press(vetorOrdem2, 9);
	puts("Questão 20: ");
	printf("%d\n", fib(elemento));
	puts("Questão 10:");
	printf("%d\n", buscaBin(vetorBuscaBin, 6));




}

//Questão 1;
int fatorial (short numero)
{

	unsigned short i;
	int fatorial = 1;

	if (numero < 0)
		return 1;

	for (i = numero; i > 0; i--)
		fatorial *= i;

	return fatorial;

}

//Questão 2;
void mod_vetor(short vet[], unsigned short vetTam)
{

	unsigned short i;

	for (i = 0; i < vetTam; i++)
	{	
		if (vet[i] <= 0)
			vet[i] = -2;
		else if (vet[i] >= 1 && vet[i] <= 5)
			vet[i] = -1;
		else
			vet[i] = 0;
	}

}


void press(short vet[], unsigned short vetTam)
{

	unsigned short i;
	for (i = 0; i < vetTam; i++)
		printf("%d ", vet[i]);
	printf("\n");

}


//questão 3;
void vet_invet(short vet[], unsigned short vetTam)
{

	unsigned short i, j, aux, tam;

	tam = vetTam / 2;

	for (i = 0, j = vetTam - 1; i < tam; i++, j--)
	{

		aux = vet[j];
		vet[j] = vet[i];
		vet[i] = aux;

	}
}


//Questão 5;
void vetOrdVerfi (short vet[], unsigned short vetTam)
{

	unsigned short i, menor;
	char condicao = true;
	
	menor = vet[0];
	
	for (i = 1; i < vetTam && condicao == true; i++)
		if (vet[i] < menor)
			condicao = false;

	if (condicao == true)
		puts("True");
	else
		puts("False");

}


//Questão 7;
unsigned short calcQuadrado(unsigned short numero)
{

	unsigned short quadrado = 0, i;

	for (i = numero; i > 0; i--)
		quadrado += (int)pow(i, 2);

	return quadrado;

}

//Questão 8;
unsigned short contaLetra(char string[], char letra)
{

	unsigned short i, contador = 0, tam;

	tam = strlen(string);

	for (i = 0; i < tam; i++)
		if (string[i] == letra || string[i] == letra - 32)
			contador++;

	return contador;

}

//Questão 9;
void verificaPalin(char nome[])
{

	unsigned char aux, aux2, copianome[strlen(nome)];
	short i, j;

	strcpy(copianome, nome);

	invertString(copianome);

	if (strcmp(nome, copianome) == 0)
		printf("True\n");
	else
		printf("False\n");

}


//Questão 11;
void vetSub(short vet[], unsigned short vetTam, short delta)
{

	unsigned short i;

	for (i = 0; i < vetTam; i++)
		vet[i] = (vet[i] - delta);

}

//Questão 12;
void vetSubPosi(short vet[], unsigned short vetTam)
{

	unsigned short i;

	for (i = 1; i < vetTam; i++)
		vet[i] = vet[i] - vet[i-1];

}


//Questão 13;
void revertSubPosi(short vet[], unsigned short vetTam)
{

	unsigned short i;

	for (i = vetTam - 1; i > 0; i--)
		vet[i] = vet[i] + vet[i - 1];
	
}


//Questão 20;
int fib(unsigned short numero)
{

	int resultado = 0;
	unsigned short i;

	if (numero == 1)
		return 0;
	else if (numero == 2)
		return 1;
	else if (numero == 3)
		return 1;
	else
	{
		for (i = 0; i < numero; i++)
			resultado = (1/sqrt(5))*pow(((1+sqrt(5))/2), i)-(1/sqrt(5))*pow(((1-sqrt(5))/2), i);
		return resultado;
	}
}

void invertString(char string[])
{

	unsigned short i, j, tam, tam2;
	char aux;

	tam = strlen(string) / 2;
	tam2 = strlen(string);

	for (i = 0, j = tam2 - 1; i < tam; i++, j--)
	{

		aux = string[j];
		string[j] = string[i];
		string[i] = aux;

	}
}

int buscaBin(short vetor[10], short chave)
{

	short menor = 0, maior = 9, meio;

	while (menor <= maior)
	{
		meio = (menor + maior) / 2;
		if (vetor[meio] < chave)
			maior = meio + 1;
		if (vetor[meio] > chave)
			menor = meio - 1;
		if (vetor[meio] == chave)
			return chave;

	}
	return -1;
}