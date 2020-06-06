#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* miArchivo;

	miArchivo = fopen(path,"r");

	if(miArchivo!=NULL)
	{
		parser_EmployeeFromText(miArchivo, pArrayListEmployee);
	}

	fclose(miArchivo);

	return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	FILE* miArchivo;

		miArchivo = fopen(path,"rb");

		if(miArchivo!=NULL)
		{
			parser_EmployeeFromBinary(miArchivo, pArrayListEmployee);
		}

		fclose(miArchivo);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pAuxEmployee;

	pAuxEmployee = employee_new();

	if(pAuxEmployee!=NULL)
	{

	}



    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int largo;
	int i;
	Employee* aux;

	largo = ll_len(pArrayListEmployee);

	for(i=0; i<largo ;i++)
	{
		aux = ll_get(pArrayListEmployee,i);

		printf("%5d - %20s - %5d - %10d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
	}


    return 1;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int campo;
	int orden;

	do{
		printf("Elija un campo de ordenamiento:\n");
		printf("1. Id.\n");
		printf("2. Nombre.\n");
		printf("3. Horas trabajadas.\n");
		printf("4. Sueldo.\n");
		printf("Su opcion: ");
		scanf("%d", &campo);

	}while(campo!=1 && campo!=2 && campo!=3 && campo!=4);

	do{
		printf("\nElija un criterio de ordenamiento:\n");
		printf("1. Ascendente.\n");
		printf("0. Descendiente.\n");
		printf("Su opcion: ");
		scanf("%d", &orden);

	}while(orden!=1 && orden!=0);


	switch(campo)
	{
		case 1: //orden por ID
			ll_sort(pArrayListEmployee, employee_CompareById, orden); //1 ascendente 0 descendente
			break;

		case 2: //orden por NOMBRE
			ll_sort(pArrayListEmployee, employee_CompareByName, orden); //1 ascendente 0 descendente
			break;


	}


    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int largo;
	int i;
	Employee* aux;
	FILE* pFile;
	pFile = fopen(path,"wb");

	largo = ll_len(pArrayListEmployee);

	printf("%d\n", largo);

	if(pFile!=NULL)
	{
		//fprintf(pFile,"Id,Nombre,Hs Trabajadas,Sueldo\n");

		for(i=0; i<largo; i++)
		{
			aux= ll_get(pArrayListEmployee, i);

			fwrite(aux, sizeof(Employee),1,pFile);
			//fprintf(pFile,"%d,%s,%d,%d\n", aux[i].id, aux[i].nombre, aux[i].horasTrabajadas, aux[i].sueldo);
		}

	}

	fclose(pFile);


    return 1;
}

