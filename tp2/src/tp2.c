/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define T 10


int main(void) {
	setbuf(stdout, NULL);

	Employee listaEmployee[T];
	int respuesta;
	int flagAlumno=0;
	int i=0;

	initEmployees(listaEmployee, T);



	do{
		printf("BASE DE EMPLEADOS");
		printf("\nElija una de las siguientes opciones:");
		printf("\n1. ALTAS.");
		printf("\n2. MODIFICAR.");
		printf("\n3. BAJAS.");
		printf("\n4. INFORMAR.");
		printf("\n5. SALIR DEL SISTEMA.");
		printf("\n\nIngrese su opcion: ");
		scanf("%d",&respuesta);

		switch(respuesta)
		{
				case 1:
				{
					listaEmployee[i]= cargarUnEmployee(listaEmployee,T);
					i++;
					flagAlumno=1;
					break;
				}
				case 4:
				{
					if(flagAlumno==0)
					{
						printf("No ha cargado ningun empleado. Por favor, realicelo.\n");
					}else
					{
					mostrarEmployees(listaEmployee, T);
					}
					break;
				}

		}
	system("pause");
	system("cls");


	}while(respuesta!=5);



	return EXIT_SUCCESS;
}
