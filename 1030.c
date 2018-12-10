/*
    @autor: Malbolge;
    @data: 10/12/2018;
    @nome: A Lenda de Flavious Josephus;
*/

#include <stdio.h>

unsigned short recorrencia(unsigned short qtsSoldados, unsigned short qtsPulos);

void main ()
{

    unsigned short casos;
    unsigned short qtsInstancias;
    unsigned short qtsSoldados, qtsPulos;

    scanf("%hu", &casos);

    qtsInstancias = 0;
    while (casos--)
    {

        scanf("%hu %hu", &qtsSoldados, &qtsPulos);
        printf("Case %hu: %hu\n", ++qtsInstancias, recorrencia(qtsSoldados, qtsPulos) + 1);

    }


}

unsigned short recorrencia(unsigned short qtsSoldados, unsigned short qtsPulos)
{

    unsigned short i, retorno;
    retorno = 0;

    for (i = 2; i <= qtsSoldados; i++)
        retorno = (retorno + qtsPulos) % i;

    return retorno;

}