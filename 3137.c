/*
    @author: Tiago;
    @date: 03/11/2020;
    @name: Páginas de um Livro;
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{

    int p;
    //! Quantos dígitos eu já contei;
    int v[] = {0, 9, 189, 2889, 38889, 488889};

    scanf("%d", &p);
    size_t index = (size_t)floor(log10(p));

    //! Já somei os dígitos de 1 até k;
    int k = ((int)pow(10, index) - 1);
    
    //! Quantos números faltam, apartir de k, para achegar em p;
    int q = p - k;

    //! Eu sei que os q números têm index + 1 dígitos;
    printf("%ld\n", v[index] + (q * (index + 1)));

    return 0;
}