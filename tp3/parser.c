#include "parser.h"
#include <stdlib.h>


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret=-1; //error
	Employee* aux;
	char id[500], nombre[500], horas[500], sueldo[500];
	int datos;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{

		 datos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre, horas,sueldo); // leo la primera linea para no guardar los titulos

		 while(!feof(pFile)) //ejecuto mientras no sea el final del archivo
		 {
				 if(feof(pFile)){
					 break;
				 }

				 datos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre, horas,sueldo); // leo cada linea de datos, asigno variables TEXTO

				 if(datos==4) // para chequear que haya leido X cantidad de datos
				 {
					 aux = employee_newParametros(id, nombre,horas, sueldo); //guardo nuevo empleado en puntero auxiliar

					 if(aux!=NULL)
					 {
						 ret= ll_add(pArrayListEmployee, aux); //si encuentro espacio, lo agrego a la LL. si lo agrego DEVUELVE 0>>> ok
					 }
				 }

		}
	}


    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int ret=-1; //error
	Employee* aux;
	int dato;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			if(feof(pFile)){
				 break;
			}

			 aux=employee_new(); //pido espacio para LEER un nuevo empleado aux
			 if(aux!=NULL)
			 {
				 dato= fread(aux, sizeof(Employee), 1, pFile); //leo una estructura del archivo y la escribo en el auxiliar

				 if(dato==1) // para chequear que haya leido UNA ESTRUCTURA de datos
				 {
				 ret = ll_add(pArrayListEmployee, aux);  //si lei un dato, lo agrego a la LL. si lo agrego DEVUELVE 0>>> ok
				 }
			 }

		}
	}

    return ret;
}
