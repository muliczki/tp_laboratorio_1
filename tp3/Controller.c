#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "datos.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1; //opcion "ERROR" para la funcion "analizar situacion" en el main
	FILE* miArchivo;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
	miArchivo = fopen(path,"r");

		if(miArchivo!=NULL)
		{
			parser_EmployeeFromText(miArchivo, pArrayListEmployee);
			fclose(miArchivo);
			ret=0; //opcion CORRECTO "analizar situacion" en el main
		}

	}
	return ret;
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
	int ret=-1; //opcion "ERROR" para la funcion "analizar situacion" en el main
	FILE* miArchivo;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		miArchivo = fopen(path,"rb");

		if(miArchivo!=NULL)
		{
			parser_EmployeeFromBinary(miArchivo, pArrayListEmployee);
			fclose(miArchivo);
			ret=0; //opcion CORRECTO "analizar situacion" en el main
		}
	}


    return ret;
}


int buscarIdSinUso (LinkedList* pArrayListEmployee)
{
	int idNuevo;
	int largo;
	int i;
	Employee* aux;
	int idAux;
	int maximo;

	if(pArrayListEmployee!=NULL)
	{
		largo = ll_len(pArrayListEmployee);

		for(i=0; i<largo ;i++)
		{
			aux = ll_get(pArrayListEmployee,i);
			employee_getId(aux, &idAux);

			if(i==0 || idAux > maximo)
			{
				maximo=idAux;
			}
		}

		idNuevo=maximo+1;

	}

	return idNuevo;
}




/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id)
{
	Employee* pAuxEmployee;
	char nombreAux[128];
	int horasAux;
	int sueldoAux;

	if(pArrayListEmployee!=NULL)
	{
		pAuxEmployee = employee_new();

		if(pAuxEmployee!=NULL)
		{
			getString(nombreAux,"Ingrese un nombre: ","Error, ingrese un nombre: ");
			employee_setNombre(pAuxEmployee, nombreAux);

			getInt(&horasAux, "Ingrese las horas trabajadas: ", 0, 500, "Error, ingrese las horas trabajadas: ");
			employee_setHorasTrabajadas(pAuxEmployee, horasAux);

			getInt(&sueldoAux, "Ingrese el sueldo: ", 10000, 100000, "Error, ingrese el sueldo: ");
			employee_setSueldo(pAuxEmployee, sueldoAux);

			employee_setId(pAuxEmployee, id);

			ll_add(pArrayListEmployee, pAuxEmployee);


		}
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
	int ret=-1; //opcion "ERROR" para la funcion "analizar situacion" en el main
	char nombreAux[128];
	int sueldoAux;
	int idAux;
	int horasAux;
	Employee* aux;

	if(pArrayListEmployee!=NULL)
	{
		largo = ll_len(pArrayListEmployee);

		printf("%5s - %20s - %15s - %10s\n","ID", "NOMBRE", "HS TRABAJADAS", "SUELDO");

		for(i=0; i<largo ;i++)
		{
			aux = ll_get(pArrayListEmployee,i);
			employee_getId(aux, &idAux);
			employee_getNombre(aux, nombreAux);
			employee_getSueldo(aux, &sueldoAux);
			employee_getHorasTrabajadas(aux, &horasAux);

			printf("%5d - %20s - %15d - %10d\n", idAux, nombreAux, horasAux, sueldoAux);
			/*
			if(idAux!=0)
			{
			printf("%5d - %20s - %15d - %10d\n", idAux, nombreAux, horasAux, sueldoAux);
			}
			*/
		}
		ret=0; //opcion CORRECTO "analizar situacion" en el main
	}

    return ret;
}

int buscarId(LinkedList* pArrayListEmployee, int idIngresadoPorUsuario)
{
	int indice=-1;
    int i;
    int largo;
    int idAux;
    Employee* aux;

    if(pArrayListEmployee!=NULL)
    {
    	largo=ll_len(pArrayListEmployee);


    for(i=0; i<largo; i++)
	    {
    		aux= ll_get(pArrayListEmployee, i);
    		if(aux!=NULL)
    		{
    		employee_getId(aux, &idAux);

	            if(idIngresadoPorUsuario==idAux)
	              {
	                 indice= ll_indexOf(pArrayListEmployee, aux); //se encontro el id
	                 break;
	             }
	        }
	    }

    }
	return indice;
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
	int busquedaIndice;
	int idIngresado;
	int idAux;
	char nombreAux[128];
	char rta;
	int ret = -1;
	Employee* aux;

	controller_ListEmployee(pArrayListEmployee);

	do
	 {
		printf("\nSeleccione un ID de la lista: ");
		scanf("%d", &idIngresado);



		busquedaIndice =buscarId(pArrayListEmployee,idIngresado);

		 switch(busquedaIndice)
			{
			        case -1: //id inexistente
			        printf("Error. ID inexistente. Ingrese uno valido.\n\n");
			        break;

			        default: //se encontro el ID
			        break;

			 }

	 }while(busquedaIndice==-1);



	//aux= ll_pop(pArrayListEmployee, busquedaIndice);  //no lo uso para poder mostrar antes de eliminar y realizar comprobacion

	aux = ll_get(pArrayListEmployee, busquedaIndice);

	if(aux!=NULL)
	{
		employee_getId(aux, &idAux);
		employee_getNombre(aux, nombreAux);

		printf("ID: %5d - %10s\n", idAux, nombreAux);

		rta = getChar("Desea eliminar el ID? s/n: ", 's', 'n', "Error, desea eliminar el ID? s/n: ");

		if(rta=='s')
		{

			ret = ll_remove(pArrayListEmployee, busquedaIndice);
		}else
		{
			ret=2; //opcion anular en "analizar situacion" del main
		}

	}



    return ret;
}







/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret =-1; //ERROR
	int campo;
	int orden;

	printf("\nElija un campo de ordenamiento:\n");
	printf("1. Id.\n");
	printf("2. Nombre.\n");
	printf("3. Horas trabajadas.\n");
	printf("4. Sueldo.\n");
	printf("5. Volver a la pantalla principal.\n");
	getInt(&campo, "Ingrese su opcion: ", 1, 5, "Ingrese una opcion valida: ");

	if(campo!=5)
	{
		printf("\nElija un criterio de ordenamiento:\n");
		printf("1. Ascendente.\n");
		printf("0. Descendente.\n");
		getInt(&orden, "Ingrese su opcion: ", 0, 1, "Ingrese una opcion valida: ");

		printf("\nORDENANDO...\n\n");
	}

	switch(campo)
	{
		case 1: //orden por ID
			ll_sort(pArrayListEmployee, employee_CompareById, orden); //1 ascendente 0 descendente
			ret=0; //opcion CORRECTO "analizar situacion" en el main
			break;

		case 2: //orden por NOMBRE
			ll_sort(pArrayListEmployee, employee_CompareByName, orden); //1 ascendente 0 descendente
			ret=0; //opcion CORRECTO "analizar situacion" en el main
			break;

		case 3: //orden por HORAS TRABAJADAS
			ll_sort(pArrayListEmployee, employee_CompareByHours, orden); //1 ascendente 0 descendente
			ret=0; //opcion CORRECTO "analizar situacion" en el main
			break;

		case 4: //orden por SUELDO
			ll_sort(pArrayListEmployee, employee_CompareBySalary, orden); //1 ascendente 0 descendente
			ret=0; //opcion CORRECTO "analizar situacion" en el main
			break;

		case 5: //anular ordenamiento
			ret=1; //opcion ANULAR "analizar situacion" en el main
			break;

	}


    return ret;
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
	int ret=-1; //ERROR
	int largo;
	int i;
	char nombreAUx[128];
	int sueldoAux;
	int idAux;
	int horasAux;
	Employee* aux;
	FILE* pFile;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
	largo = ll_len(pArrayListEmployee);
	pFile = fopen(path,"w");

	if(pFile!=NULL)
	{
		fprintf(pFile,"ID,NOMBRE,HORAS TRABAJADAS,SUELDO\n");

		for(i=0; i<largo; i++)
		{
			aux= ll_get(pArrayListEmployee, i);
			if(aux!=NULL)
			{
			employee_getId(aux, &idAux);
			employee_getNombre(aux, nombreAUx);
			employee_getHorasTrabajadas(aux, &horasAux);
			employee_getSueldo(aux, &sueldoAux);

            fprintf(pFile,"%d,%s,%d,%d\n", idAux, nombreAUx, horasAux, sueldoAux);
			}
		}
	ret =0; //opcion CORRECTO "analizar situacion" en el main
	fclose(pFile);
	}

	}


    return ret;
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
	int ret=-1; //ERROR
	int largo;
	int i;
	Employee* aux;
	FILE* pFile;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
	pFile = fopen(path,"wb");
	largo = ll_len(pArrayListEmployee);

	//printf("%d\n", largo);

	if(pFile!=NULL)
	{

		for(i=0; i<largo; i++)
		{
			aux= ll_get(pArrayListEmployee, i);
			if(aux!=NULL)
			{
			fwrite(aux, sizeof(Employee),1,pFile);
			}
		}

	ret =0; //opcion CORRECTO "analizar situacion" en el main
	fclose(pFile);
	}

	}

    return ret;
}

