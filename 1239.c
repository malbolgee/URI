/*
	@autor: Malbolge;
	@data: 09/11/2018;
	@nome: Atalhos Bloggo;
*/

#include <stdio.h>
#include <string.h>

void atalhosItalico(char *, char *);
void atalhosNegrito(char *, char *);

void main ()
{


	char texto[500] = { 0 };
	char textoItalico[500] = { 0 };
	char textoNegrito[500] = { 0 };

	while (scanf(" %[^\n]", texto) != EOF)
	{


		atalhosItalico(texto, textoItalico);
		atalhosNegrito(textoItalico, textoNegrito);

		printf("%s\n", textoNegrito);


	}

}

void atalhosItalico(char *texto, char *textoSaida)
{

	unsigned short i, j, k;
	unsigned short qtsAparicaoSublinhado;
	char *abreItalico = "<i>";
	char *fechaItalico = "</i>";

	i = j = 0;
	qtsAparicaoSublinhado = 0;
	while (texto[i])
	{

		while (texto[i] != '_')
		{
			textoSaida[j++] = texto[i++];

			if (texto[i] == '\0')
				break;
		}

		if (texto[i] == '\0')
			break;

		k = 0;
		if (texto[i] == '_' && (qtsAparicaoSublinhado % 2 == 0))
		{	
			i++;	
			qtsAparicaoSublinhado++;
			while (abreItalico[k])
				textoSaida[j++] = abreItalico[k++];
		}
		
		k = 0;
		if (texto[i] == '_' && qtsAparicaoSublinhado % 2 != 0)
		{		
				i++;
				qtsAparicaoSublinhado++;	
				while (fechaItalico[k])
					textoSaida[j++] = fechaItalico[k++];

				textoSaida[j++] = ' ';

				if (qtsAparicaoSublinhado >= 2)
					qtsAparicaoSublinhado = 0;
		}

		
		i++;

		if (texto[i] == '\0')
			break;

	}

	textoSaida[j] = '\0';

}

void atalhosNegrito(char *texto, char *textoSaida)
{

	unsigned short i, j, k;
	unsigned short qtsAparicaoAsterisco;
	char *abreNegrito = "<b>";
	char *fechaNegrito = "</b>";

	i = j = 0;
	qtsAparicaoAsterisco = 0;
	while (texto[i])
	{

		while (texto[i] != '*')
		{
			textoSaida[j++] = texto[i++];

			if (texto[i] == '\0')
				break;
		}

		if (texto[i] == '\0')
			break;

		k= 0;
		if (texto[i] == '*' && (qtsAparicaoAsterisco % 2 == 0))
		{	
			i++;	
			qtsAparicaoAsterisco++;
			while (abreNegrito[k])
				textoSaida[j++] = abreNegrito[k++];
		}

		k = 0;
		if (texto[i] == '*' && qtsAparicaoAsterisco % 2 != 0)
		{		
				i++;
				qtsAparicaoAsterisco++;	
				while (fechaNegrito[k])
					textoSaida[j++] = fechaNegrito[k++];

				textoSaida[j++] = ' ';
		}
	

		if (qtsAparicaoAsterisco >= 2)
			qtsAparicaoAsterisco = 0;

		i++;

	}

	textoSaida[j] = '\0';

}