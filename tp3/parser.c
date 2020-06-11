#include "parser.h"
#include <stdlib.h>

//int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
//int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* aux;
	char id[500], nombre[500], horas[500], sueldo[500];
	int datos;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre, horas,sueldo);

	 while(!feof(pFile))
	 {
			 if(feof(pFile))
			 {
				 break;
			 }

			 datos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre, horas,sueldo);

			 if(datos==4) // para chequear que haya leido X cantidad de datos
			 {
				 aux = employee_newParametros(id, nombre,horas, sueldo);

				 if(aux!=NULL)
				 {
					 ll_add(pArrayListEmployee, aux);
				 }
			 }
	}



    return 1;
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

	Employee* aux;
	int dato;

	while(!feof(pFile))
	{

		if(feof(pFile))
		{
			 break;
		}
		 aux=employee_new();
		 if(aux!=NULL)
		 {
			 dato= fread(aux, sizeof(Employee), 1, pFile);

			 if(dato!=0) // para chequear que haya leido UNA ESTRUCTURA de datos
			 {
			 ll_add(pArrayListEmployee, aux);
			 }
		 }

	}




    return 1;
}
