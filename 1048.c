#include <stdio.h>


float main () {

  float salario, reajuste;
  scanf("%f", &salario);

  if (salario >= 0 && salario <= 400){

    reajuste = salario*0.15;
    salario = salario + reajuste;
    printf("Novo salario: %.2f\n", salario);
    printf("Reajuste ganho: %.2f\n", reajuste);
    printf("Em percentual: 15 %%\n");

  }
  else{

      if (salario > 400 && salario <= 800){

        reajuste = salario*0.12;
        salario = salario + reajuste;
        printf("Novo salario: %.2f\n", salario);
        printf("Reajuste ganho: %.2f\n", reajuste);
        printf("Em percentual: 12 %%\n");


        }
        else{

          if (salario > 800 && salario <= 1200){

            reajuste = salario*0.1;
            salario = salario + reajuste;
            printf("Novo salario: %.2f\n", salario);
            printf("Reajuste ganho: %.2f\n", reajuste);
            printf("Em percentual: 10 %%\n");

          }
          else{

              if (salario > 1200 && salario <= 2000){
              reajuste = salario*0.07;
              salario = salario + reajuste;
              printf("Novo salario: %.2f\n", salario);
              printf("Reajuste ganho: %.2f\n", reajuste);
              printf("Em percentual: 7 %%\n");
            }
            else{

              reajuste = salario*0.04;
              salario = salario + reajuste;
              printf("Novo salario: %.2f\n", salario);
              printf("Reajuste ganho: %.2f\n", reajuste);
              printf("Em percentual: 4 %%\n");

            }
          }
        }
      }
}
