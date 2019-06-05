/*
	@autor: Malbolge;
	@data: 01/06/2019;
	@nome: Carrega ou não Carrega?
*/

#include <stdio.h>

#define true 1
#define false 0

char scanff(int *a);
void print_dln(unsigned n);

int main (int arc, char **argv)
{

	unsigned x, y;

	while (scanff(&x) != EOF)
		scanff(&y), print_dln(x ^ y);

	return 0;

}

inline char scanff(int *a)
{

    register char c = 0;
    *a = 0;
	c = getchar_unlocked();
    while (c >= 48)
        *a = *a * 10 + (c - '0'), c = getchar_unlocked();

	return c;

}

inline void print_dln(unsigned n) 
{

	char i = 10;
	char output_buffer[11];
	output_buffer[10] = '\n';
	do{

		output_buffer[--i] = (n % 10) + '0', n /= 10;

	}while(n);

	do{

		putchar_unlocked(output_buffer[i]);

	}while(++i < 11);

}