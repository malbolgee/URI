
#include "stdio.h"

int main () {
 	unsigned int segundo;
 	unsigned char hora, minuto;

  	scanf("%d", &segundo);
  	hora = segundo / 3600;
  	segundo -= hora * 3600;
  	minuto = segundo / 60;
  	segundo -= minuto * 60;

  	printf("%d:%d:%d\n",hora, minuto, segundo);
}
