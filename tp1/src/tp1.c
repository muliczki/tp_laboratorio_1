/*
 ============================================================================
 Name        : tp1.c
 Author      : Uliczki Micaela
 SO          : Windows 10
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
	setbuf(stdout, NULL);

	float a, b, suma, resta, division, compareA, compareB;
	double multiplicacion, factorialA, factorialB;
	int respuesta, intA, intB;
	int flaga = 0, flagb = 0, flag3 = 0, flagceroB = 0, errorFacA = 0, errorFacB = 0;

	do{


	printf("Bienvenido a nuestra calculadora!");  //saludo al usuario
		if(flaga==0)  // si NO ingrese el 1er numero, muestro esto
		{
			printf("\n1. Ingresar 1er operando (A=x)");
		} else     // si YA ingrese el 1er numero, muestro esto
		{
			printf("\n1. Ingresar 1er operando (A=%.2f)",a);
		}
		if(flagb==0)  // si NO ingrese el 2do numero, muestro esto
		{
			printf("\n2. Ingresar 2do operando (B=y)");
		} else     // si YA ingrese el 2do numero, muestro esto
		{
			printf("\n2. Ingresar 2do operando (B=%.2f)",b);
		}

	printf("\n3. Calcular todas las operaciones");
	printf("\n4. Informar resultados");
	printf("\n5. Salir");
	printf("\n \nElija una de las opciones: ");
	scanf("%d", &respuesta);

	switch(respuesta)
	{
		case 1:
			printf("\n1. Ingresar 1er operando (A=x): \n");
			scanf("%f",&a);
			flaga=1; // me informa que ya ingrese un numero como A
			break;

		case 2:
			printf("\n2. Ingresar 2do operando (B=y): \n");
			scanf("%f",&b);
			flagb=1; // me informa que ya ingrese un numero como B
			break;

		case 3:
			if(flaga==0 || flagb==0)   // si no ingrese los dos numeros no puedo calcular
			{
			printf("\nNo has elegido dos operandos.\n"
					"Por favor, realizalo para poder calcular las operaciones.\n\n");
			}
			else
			{
			printf("\nEstamos calculando tus operaciones!!\n\n");
			flag3 = 1; // me dice que ya ingrese la opcion 3
			suma = Sumar(a, b);
			resta = Restar(a, b);
			flagceroB=0;  //por si en la misma ejecucion quiero cambiar el numero de b, que vuelva a cero el flag
			if(b==0){
				flagceroB=1;  //si b es cero, no puedo dividir por cero
			}else
			{
			division = Dividir(a, b);
			}
			multiplicacion = Multiplicar (a, b);
			}

			// tengo que corroborar si ingreso numeros enteros o con decimales
			// si ingreso numero negativo o con decimal > no puedo calcular el fractorial
			// si el numero es cero > fractorial es 1
			intA = a;
			intB = b;

			compareA = a - intA;
			compareB = b - intB;
			errorFacA=0; //por si en la misma ejecucion quiero cambiar el numero de a, que vuelva a cero el flag
			errorFacB=0; //por si en la misma ejecucion quiero cambiar el numero de b, que vuelva a cero el flag

			if (a<0 || compareA!=0)
			{
				errorFacA=1;
			}
			else if (a==0)
			{
				factorialA=1;
			}else
			{
				factorialA = Factorial(intA);
			}

			if (b<0 || compareB!=0)
						{
							errorFacB=1;
						}
						else if (b==0)
						{
							factorialB=1;
						}else
						{
							factorialB = Factorial(intB);
						}
			break;

		case 4:
			if(flag3==0) // si no pedi calcular, no puedo informar resultados
			{
			printf("\nNo has seleccionado la opcion para calcular.\n"
					"Por favor, realizalo para poder mostrarte los resultados.\n\n");
			}
			else
			{
			printf("\nA. La suma entre %.2f y %.2f es: %.2f", a, b, suma);
			printf("\nB. La resta entre %.2f y %.2f es: %.2f", a, b, resta);
			if(flagceroB==1)
			{
			printf("\nC. No es posible dividir por cero");
			}else
			{
			printf("\nC. La division entre %.2f y %.2f es: %.2f", a, b, division);
			}
			printf("\nD. El producto entre %.2f y %.2f es: %.2f", a, b, multiplicacion);
			if(errorFacA==1)
			{
			printf("\nE. No se puede calcular el factorial de %.2f ",a);
			} else
			printf("\nE. El factorial de %.0f es: %.0f ", a, factorialA);
			if(errorFacB==1)
			{
			printf(" y no se puede calcular el factorial de %.2f.\n\n",b);
			} else
			printf("y el factorial de %.0f es: %.0f.\n\n", b, factorialB);
			}
	}


	system("\n pause");
	system("cls");



	}while (respuesta!=5);

	printf("Gracias por utilizar nuestra calculadora!\n\n");

	system("pause");


	return EXIT_SUCCESS;
}

