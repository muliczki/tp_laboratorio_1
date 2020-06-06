#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

//VER PORQUE FALLA
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* aux;
	char id[500], nombre[500], horas[500], sueldo[500];

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre, horas,sueldo);

	 while(!feof(pFile))
	 {
			 if(feof(pFile))
			 {
				 break;
			 }

			 fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre, horas,sueldo);

			 aux = employee_newParametros(id, nombre,horas, sueldo);

			 ll_add(pArrayListEmployee, aux);

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

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	Employee* aux;

	while(!feof(pFile))
	{

		 aux=employee_new();
		 if(aux!=NULL)
		 {
			 fread(aux, sizeof(Employee), 1, pFile);
			 ll_add(pArrayListEmployee, aux);
		 }

	}




    return 1;
}
