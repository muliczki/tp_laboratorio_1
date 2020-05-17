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



int main(void) {
	setbuf(stdout, NULL);

	Employee listaEmployee[T];

	int respuesta;
	int idParaValidar;
	int estado;
	int id;
	int flagPrimeraCarga=0;
	int preguntaPrimeraCarga;


	estado = initEmployees(listaEmployee, T);
	if(estado==-1)
	{
		analizarSituacion(estado,"Inicio");
	}

	id = hardcodear(listaEmployee, T);


	do{

		respuesta = mostrarMenu();

		switch(respuesta)
		{
				case 1:
					estado = cargarEmpleado(listaEmployee,T, id);
					analizarSituacion(estado,"Carga");
					id++;
					flagPrimeraCarga=1;
					break;


				case 2:
					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
						idParaValidar = pedirleIdAlUsuario(listaEmployee, T, "MODIFICAR");
						estado = modifyEmployee(listaEmployee, T, idParaValidar);
						analizarSituacion(estado,"Modificacion");
					}
					break;


				case 3:
					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
						idParaValidar = pedirleIdAlUsuario(listaEmployee, T, "ELIMINAR");
						estado =removeEmployee(listaEmployee, T, idParaValidar);
						analizarSituacion(estado,"Eliminacion");

					}
					break;

				case 4:
					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
						estado = sortEmployees(listaEmployee, T, DOWN);
						if(estado==0)
						{
							estado = mostrarEmployees(listaEmployee, T);
						}

						mostrarEstadisticas(listaEmployee, T);

					}
					break;

		}
	system("pause");
	system("cls"); //en eclipse no funciona


	}while(respuesta!=5);


	printf("Gracias por utilizar nuestro programa!\n\n");
	system("pause");


	return EXIT_SUCCESS;
}




