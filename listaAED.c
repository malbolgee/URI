#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define n 5

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
void matrixBool(short matriz[5][5], short numero);
void matrix (unsigned short ordem);


int main ()
{

	unsigned short elemento;
	short vetor[] = { 15, 2, 9, -5 , -7, 0, 3, 1, 2, 16, 4 }; //Tamanho 11;
	short vetor2[] = { 15, 2, 9, -5 , -7, 0, 3, 1, 2, 16, 4 }; // tamanho 11;
	short vetorOrdem[] = { 1, 3, 5, 7, 11, 13, 15, 17, 19 };
	short vetorOrdem2[] = { 1, 3, 5, 7, 11, 13, 15, 17, 19 }; // Tamanho 9;
	short vetorDesord[] = { 19, 17, 15, 13, 13, 11, 7, 5, 3 };
	char string[] = "arara";
	char nome[] = "arara";

	scanf("%hd", &elemento);
	printf("Fatorial do numero: %d é %d\n", elemento, fatorial(elemento));
	puts("Vetor Original: ");
	press(vetor, 11);
	vet_invet(vetor, 11);
	puts("Vetor Invertido:");
	press(vetor, 11);
	mod_vetor(vetor, 11);
	puts("Vetor Modificado:");
	press(vetor, 11);
	press(vetorOrdem, 9);
	vetOrdVerfi(vetorOrdem, 9);
	press(vetorDesord, 9);
	vetOrdVerfi(vetorDesord, 9);
	puts("Soma de todos os quadrados");
	printf("%d\n", calcQuadrado(10));
	printf("Quantidade de letras 'a' da String: %s\n", string);
	printf("%d\n", contaLetra(string, 'a'));
	puts("String Reversa:");
	verificaPalin(nome);
	printf("%s\n", nome);
	puts("Questão 11:");
	vetSub(vetor2, 11, 5);
	press(vetor2, 11);
	puts("Questão 12:");
	vetSubPosi(vetorOrdem2, 9);
	press(vetorOrdem2, 9);
	puts("Questão 13: ");
	revertSubPosi(vetorOrdem2, 9);
	press(vetorOrdem2, 9);
	printf("\n");
	matrix(n);


}

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

void vet_invet(short vet[], unsigned short vetTam)
{

	unsigned short i, j, aux1, aux2;

	for (i = 0, j = vetTam -1; i <= vetTam/2 && j >= vetTam/2; i++, j--)
	{

		aux1 = vet[i];
	    aux2 = vet[j];
	    vet[i] = aux2;
	    vet[j] = aux1;

	}
}

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

unsigned short calcQuadrado(unsigned short numero)
{

	unsigned short quadrado = 0, i;
	for (i = numero; i > 0; i--)
		quadrado += (int)pow(i, 2);

	return quadrado;

}

unsigned short contaLetra(char string[], char letra)
{

	unsigned short i, contador = 0;

	for (i = 0; i < strlen(string); i++)
		string[i] = toupper(string[i]);

	letra = toupper(letra);

	for (i = 0; i < strlen(string); i++)
		if (string[i] == letra)
			contador++;

	return contador;

}

void verificaPalin(char nome[])
{

	unsigned short i,j;
	unsigned char aux, aux2, copianome[strlen(nome)];


	for (i = 0; i < strlen(nome); i++)
		copianome[i] = nome[i];


	for (i = 0, j = strlen(copianome) - 1; i <= strlen(copianome)/2 && j >= strlen(copianome)/2; i++, j--)
	{
		aux = copianome[i];
		aux2 = copianome[j];
		copianome[j] = aux;
		copianome[i] = aux2;
	}

	if (strcmp(nome, copianome) == 0)
		printf("True\n");
	else
		printf("False\n");

}

void vetSub(short vet[], unsigned short vetTam, short delta)
{

	unsigned short i;

	for (i = 0; i < vetTam; i++)
		vet[i] = (vet[i] - delta);

}

void vetSubPosi(short vet[], unsigned short vetTam)
{

	unsigned short i;

	for (i = 1; i < vetTam; i++)
		vet[i] = vet[i] - vet[i-1];

}

void revertSubPosi(short vet[], unsigned short vetTam)
{

	unsigned short i;

	for (i = vetTam - 1; i > 0; i--)
		vet[i] = vet[i] + vet[i - 1];
	
}

void matrix(unsigned short ordem)
{

	short matriz[ordem][ordem];
	unsigned short int linha, coluna;


	for (linha = 0; linha < ordem; linha++)
		for(coluna = 0; coluna < ordem; coluna++)
			matriz[linha][coluna] = (rand() % 10);

	for (linha = 0; linha < ordem; linha++)
	{
		for(coluna = 0; coluna < ordem; coluna++)
			printf("%d ", matriz[linha][coluna]);
		printf("\n");
	}
	printf("\n");


}

void matrixBool(short matriz[n][n], short numero)
{

	
	



}