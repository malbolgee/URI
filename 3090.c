/*
    @author: Malbolge;
    @data: 25/06/2020;
    @name: Campo de Batalha;
*/

#include <stdio.h>

void print_d(int n);

int main(int argc, char **argv)
{

    float n, m, ratio;
    int s, t, x, y, above, below;

    scanf("%f %f %d%*c", &n, &m, &s);

    ratio = n / m;
    above = below = 0;

    while (s--)
    {

        scanf("%d %d %u", &x, &y, &t);
        if ((float)x <= (y * ratio))
            above += t;
        else
            below += t;
    }

    print_d(above);
    putchar_unlocked(' ');
    print_d(below);
    putchar_unlocked('\n');

    return 0;
}

inline void print_d(int n)
{

	int i = 10;
	char output_buffer[10];
	do{

		output_buffer[--i] = (n % 10) + '0';
		n /= 10;

	}while(n);

	do
	{
		putchar_unlocked(output_buffer[i]);

	}while(++i < 10);

}