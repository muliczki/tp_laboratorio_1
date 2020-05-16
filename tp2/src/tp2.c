/*
 ============================================================================
 Name        : tp2.c
 Author      : Uliczki Micaela - 1F
 Description : Windows 10 - Eclipse
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define T 1000
#define UP 1
#define DOWN 0


int main(void) {
	setbuf(stdout, NULL);

	Employee listaEmployee[T];

	int respuesta;
	int idParaValidar;
	int estado;
	int id;
	int situacionModificar;
	int flagPrimeraCarga=0;
	int preguntaPrimeraCarga;


	estado = initEmployees(listaEmployee, T);
	if(estado==-1)
	{
		printf("Error. No hay espacio.\n\n");
	}

	id = hardcodear(listaEmployee, T);


	do{

		respuesta = mostrarMenu();

		switch(respuesta)
		{
				case 1:
					estado = cargarEmpleado(listaEmployee,T, id);
					id++;
					flagPrimeraCarga=1;
					break;


				case 2:
					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
						idParaValidar = pedirleIdAlUsuario(listaEmployee, T);
						situacionModificar = modifyEmployee(listaEmployee, T, idParaValidar);
						analizarSituacion(situacionModificar,"Modificacion");
					}
					break;


				case 3:
					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
						idParaValidar = pedirleIdAlUsuario(listaEmployee, T);
						estado =removeEmployee(listaEmployee, T, idParaValidar);
						analizarSituacion(estado,"Eliminacion");

					}
					break;

				case 4:
					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
					sortEmployees(listaEmployee, T, DOWN);
					mostrarEmployees(listaEmployee, T);
					}
					break;

		}
	system("pause");
	system("cls"); //en eclipse no funciona


	}while(respuesta!=5);



	return EXIT_SUCCESS;
}
