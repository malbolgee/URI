/*
    @autor: Malbolge;
    @data: 04/03/2019;
    @nome: Número Para Nome;
*/

#include <stdio.h>
#include <unistd.h>

#define true 1
#define false 0

typedef struct string{

    char numeros[40];

} string;

string unidade[10] = {"zero", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
string especial[10] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
string dezena[9] = {"vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa", "cem"};
string centena[9] = {"cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

void main ()
{


    int n;
    _Bool flag;

    while (scanf("%d", &n) != EOF)
    {

        flag= false;
        if (n == 0)
            puts("zero");
        else
        {

            if (n >= 10000)
                flag = true;

            if (n >= 100000)
            {

                if (n <= 100999)
                    printf("cem"), n -= 100000;
                else
                    printf("%s", centena[n / 100000 - 1].numeros);

                n %= 100000;

                if (n == 0)
                {

                    puts(" mil");
                    continue;

                }
                else if (n < 1000)
                    if (n % 100 && n > 100)
                        printf(" mil ");
                    else
                        printf(" mil e ");
                else
                    printf(" e ");

            }
            if (n >= 20000)
            {

                printf("%s", dezena[n / 10000 - 2].numeros);
                n %= 10000;
 
                if (n == 0)
                {

                    puts(" mil");
                    continue;

                }
                else if (n < 1000)
                    if (n % 100 && n > 100)
                        printf(" mil ");
                    else
                        printf(" mil e ");
                else
                    printf(" e ");

            }
            if (n >= 10000)
            {
                
                printf("%s", especial[(n / 1000) % 10].numeros);
                n %= 1000;
                if (n == 0)
                {

                    puts(" mil");
                    continue;

                }
                else if (n < 1000 && n)
                    if (n % 100 && n > 100)
                        printf(" mil ");
                    else
                        printf(" mil e ");
                else
                    printf(" e ");

            }
            if (n >= 1000)
            {

                if (n >= 2000 || flag)
                    printf("%s ", unidade[n / 1000].numeros);
                
                if (n % 1000 == 0)
                    printf("mil");
                
                n %= 1000;
                if (n == 0)
                {
                    printf("\n");
                    continue;

                }
                else if (n < 100 || (n < 1000 && n % 100 == 0))
                    printf("mil e ");
                else
                    printf("mil ");

            }
            if (n >= 100)
            {

                if (n == 100)
                    printf("cem");
                else
                    printf("%s", centena[n / 100 - 1].numeros);
                
                n %= 100;
                if (n == 0)
                {

                    printf("\n");
                    continue;

                }
                else
                    printf(" e ");

            }
            if (n >= 20)
            {

                printf("%s", dezena[n / 10 - 2].numeros);
                n %= 10;

                if (n == 0)
                {

                    printf("\n");
                    continue;

                }
                else
                    printf(" e ");

            }
            if (n >= 10)
                printf("%s", especial[n % 10].numeros), n = 0;

            if (n < 10 && n)
                printf("%s", unidade[n].numeros);

            printf("\n");

        }

    }

}