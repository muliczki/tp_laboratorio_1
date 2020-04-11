/*
 ============================================================================
 Name        : tp1.c
 Author      : Uliczki Micaela
 ============================================================================
 */

//usar double
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
	setbuf(stdout, NULL);;
	float a, b;
	float suma, resta, multiplicacion, division;
	int respuesta;
	int flaga =0;
	int flagb =0;
	int flag3 =0;
	int flagcero =0;



	do{

	if(flaga==0)
	{
	printf("1. Ingresar 1er operando (A=x)");
	} else
	{
	printf("1. Ingresar 1er operando (A=%.2f)",a);
	}
	if(flagb==0)
	{
	printf("\n2. Ingresar 2do operando (B=y)");
	} else
	{
	printf("\n2. Ingresar 2do operando (B=%.2f)",b);
	}

	printf("\n3. Calcular todas las operaciones");
	printf("\n	a) Calcular la suma (A+B)");
	printf("\n	b) Calcular la resta (A-B)");
	printf("\n	c) Calcular la division (A/B)");
	printf("\n	d) Calcular la multiplicacion (A*B)");
	printf("\n	e) Calcular el factorial (A!)");
	printf("\n4. Informar resultados");
	printf("\n5. Salir.");

	printf("\nElija una de las opciones: ");
	scanf("%d", &respuesta);

	switch(respuesta)
	{
		case 1:
			printf("\n1. Ingresar 1er operando (A=x): ");
			scanf("%f",&a);
			flaga=1;
			break;

		case 2:
			printf("\n2. Ingresar 2do operando (B=y): ");
			scanf("%f",&b);
			flagb=1;
			break;

		case 3:
			if(flaga==0 || flagb==0)
			{
			printf("\nNo has elegido dos operandos. Por favor, realizalo para poder calcular las operaciones.\n");
			}
			else
			{
			printf("\nEstamos calculando tus operaciones!!\n");
			flag3 = 1;
			suma = Sumar(a, b);
			resta = Restar(a, b);
			if(b==0){
				flagcero=1;
			}else
			{
			division = Dividir(a, b);
			}
			multiplicacion = Multiplicar (a, b);
			}
			break;

		case 4:
			if(flag3==0)
			{
			printf("\nNo has seleccionado la opción para calcular. Por favor, realizalo para poder mostrarte los resultados.\n");
			}
			else
			{
			printf("\nLa suma es: %.2f", suma);
			printf("\nLa resta es: %.2f", resta);
			if(flagcero==1)
			{
			printf("\nNo es posible dividir por cero");
			}else
			{
			printf("\nLa división es: %.2f", division);
			}
			printf("\nEl producto es: %.2f\n", multiplicacion);

			}
	}


	system("pause");

	}while (respuesta!=5);

	printf("\nGracias por utilizar nuestra calculadora!");



	return EXIT_SUCCESS;
}

