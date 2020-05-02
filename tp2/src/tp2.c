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

	Employee listaEmployee[T]= {{1, "Ana", "Garcia", 25000, 4, 0},
								{2, "Lucas", "Lopez", 40000, 2, 0},
								{3, "Juan Martin", "Acosta", 45750.255, 1, 0},
								{4, "Maria Soledad", "Tunez", 37800.5, 2, 0},
								{5, "Julio", "Garcia", 32300, 2, 0}};
	int respuesta;
	int idParaValidar;
	int situacionBorrar;
	int situacionModificar;
	int flagPrimeraCarga=0;
	int preguntaPrimeraCarga;
	int i=5;  //HARDCODEO

	initEmployees(listaEmployee, T);
	listaEmployee[0].isEmpty=0;  //HARDCODEO
	listaEmployee[1].isEmpty=0;  //HARDCODEO
	listaEmployee[2].isEmpty=0;  //HARDCODEO
	listaEmployee[3].isEmpty=0;  //HARDCODEO
	listaEmployee[4].isEmpty=0;  //HARDCODEO



	do{

		respuesta = mostrarMenu();

		switch(respuesta)
		{
				case 1:
				{
					listaEmployee[i]= cargarUnEmployee(listaEmployee,T);
					i++;
					flagPrimeraCarga=1;
					break;
				}

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
