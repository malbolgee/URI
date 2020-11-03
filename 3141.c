/*
    @author: Malbolge e Tiago;
    @date: 03/11/2020;
    @name: Dúvida Etária;
*/

#include <stdio.h>

int main(int argc, char **argv)
{

    char name[55];
    int dda, mma, aaa;
    int ddn, mmn, aan;

    scanf("%[^\n]%*c", name);
    scanf("%d/%d/%d", &dda, &mma, &aaa);
    scanf("%d/%d/%d", &ddn, &mmn, &aan);

    int idade = aaa - aan;

    int d[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

    int xa = d[mma - 1] + dda;
    int xn = d[mmn - 1] + ddn;

    if ((idade == 0) || (xa < xn))
        printf("Voce tem %d anos %s.\n", (idade - 1) < 0 ? 0 : idade - 1, name);
    else if (xa == xn)
        printf("Feliz aniversario!\nVoce tem %d anos %s.\n", idade, name);
    else
        printf("Voce tem %d anos %s.\n", idade, name);

    // Outra solução possível.
    
    // if (mma == mmn && dda == ddn)
    //     printf("Feliz aniversario!\nVoce tem %d anos %s.\n", idade, name);
    // else if (mma > mmn)
    //     printf("Voce tem %d anos %s.\n", idade, name);
    // else
    // {
    //     if (mma == mmn)
    //     {
    //         if (dda > ddn)
    //             printf("Voce tem %d anos %s.\n", idade, name);
    //         else
    //             printf("Voce tem %d anos %s.\n", (idade - 1) < 0 ? 0 : idade - 1, name);
    //     }
    //     else
    //         printf("Voce tem %d anos %s.\n", (idade - 1) < 0 ? 0 : idade - 1, name);
    // }
    return 0;
}