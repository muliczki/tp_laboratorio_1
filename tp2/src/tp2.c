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
#define T 1000


int main(void) {
	setbuf(stdout, NULL);

	Employee listaEmployee[T];

	int respuesta;
	int idParaValidar;
	int situacionBorrar;
	int situacionModificar;
	int flagPrimeraCarga=0;
	int preguntaPrimeraCarga;
	int i;


	initEmployees(listaEmployee, T);

	i = hardcodear(listaEmployee, T);


	do{

		respuesta = mostrarMenu();

		switch(respuesta)
		{
				case 1: //no me anda cargar
					listaEmployee[i]= cargarUnEmployee(listaEmployee,T);
					i++;
					flagPrimeraCarga=1;
					break;


				case 2:
				{
					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
						idParaValidar = pedirUnId("modificar", listaEmployee, T);
						situacionModificar = modifyEmployee(listaEmployee, T, idParaValidar);
						analizarSituacion(situacionModificar,"Modificacion");
					}
					break;
					}

				case 3:
				{
					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
						idParaValidar =pedirUnId("eliminar", listaEmployee, T);
						situacionBorrar =removeEmployee(listaEmployee, T, idParaValidar);
						analizarSituacion(situacionBorrar,"Eliminacion");

					}
					break;
				}

				case 4:
				{
					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
					sortEmployees(listaEmployee, T, DOWN);
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
