
#include <stdio.h>

int main() {
	//quantidade de batalhas e o bonus
	unsigned int batalhas, bonus;
	//ataque, defesa e level
	unsigned int atk1, atk2, def1, def2, lv1, lv2;
	double gp1, gp2;

	scanf("%d", &batalhas);

	do {

		scanf("%d",&bonus);

		scanf("%d %d %d", &atk1, &def1, &lv1);
		scanf("%d %d %d", &atk2, &def2, &lv2);

		//faz o calculo dos golpes
		gp1 = (atk1+def1)/2.0;
		gp2 = (atk2+def2)/2.0;

		//aplica os bonus
		if (lv1 % 2 == 0)
			gp1 += bonus;

		if (lv2 % 2 == 0)
			gp2 += bonus;

		if (gp1 == gp2) {
			printf("Empate\n");
		} else if (gp1 > gp2) {
			printf("Dabriel\n");
		} else {
			printf("Guarte\n");
		}

		batalhas--;
	} while (batalhas > 0);

	return 0;
}
