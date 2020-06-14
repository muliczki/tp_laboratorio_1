#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "datos.h"
#include "Controller.h"



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
			ret = parser_EmployeeFromText(miArchivo, pArrayListEmployee); // si devuelve 0 ok, si -1 error
			fclose(miArchivo);
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
			ret= parser_EmployeeFromBinary(miArchivo, pArrayListEmployee); // si devuelve 0 ok, si -1 error
			fclose(miArchivo);
		}
	}
    return ret;
}



/** \brief Alta de empleados
 *
 * \param int id
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id)
{
	Employee* pAuxEmployee;
	int pruebaId;
	int pruebaNombre;
	int pruebaSueldo;
	int pruebaHoras;
	char nombreAux[128];
	int horasAux;
	int sueldoAux;
	int ret=-1; //error

	if(pArrayListEmployee!=NULL)
	{
		pAuxEmployee = employee_new();

		if(pAuxEmployee!=NULL)
		{
			getString(nombreAux,"Ingrese un nombre: ","Error, ingrese un nombre: ");
			pruebaNombre=employee_setNombre(pAuxEmployee, nombreAux);

			getInt(&horasAux, "Ingrese las horas trabajadas: ", 0, 500, "Error, ingrese las horas trabajadas: ");
			pruebaHoras=employee_setHorasTrabajadas(pAuxEmployee, horasAux);

			getInt(&sueldoAux, "Ingrese el sueldo: ", 10000, 100000, "Error, ingrese el sueldo: ");
			pruebaSueldo=employee_setSueldo(pAuxEmployee, sueldoAux);

			pruebaId=employee_setId(pAuxEmployee, id);

			if(pruebaId==0 && pruebaNombre==0 && pruebaSueldo==0 && pruebaHoras==0)
			{
				ret= ll_add(pArrayListEmployee, pAuxEmployee);
			}

		}
	}


    return ret;
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
	int busquedaIndice;
	int campo;
	int idAux;
	char nombreAux[128];
	char nombreNuevo[128];
	int horasAux;
	int horasNuevo;
	int sueldoAux;
	int sueldoNuevo;
	char rta;
	int ret = -1;
	Employee* aux;

	if(pArrayListEmployee!=NULL)
	{
	busquedaIndice = buscarIndice(pArrayListEmployee);


	aux = ll_get(pArrayListEmployee, busquedaIndice);

	if(aux!=NULL)
	{
		printf("\n%5s - %20s - %15s - %10s\n","ID", "NOMBRE", "HS TRABAJADAS", "SUELDO");
		ret= mostrarUnEmpleado(aux, &idAux, nombreAux, &sueldoAux, &horasAux);

		printf("\nElija que campo desea modificar:\n1. Nombre.\n2. Horas trabajadas.\n3. Sueldo.\n4. Volver a la pantalla principal.\n");
		getInt(&campo, "Ingrese su opcion: ", 1, 4, "Ingrese una opcion valida: ");

		switch(campo)
		{
			case 1:
				getString(nombreNuevo,"Ingrese el nuevo nombre: ", "Error, ingrese el nuevo nombre: ");
				printf("Esta por reemplazar el nombre -%s- por -%s-.", nombreAux, nombreNuevo);
				rta = getChar("\nDesea continuar? s/n: ", 's', 'n', "Error. Desea continuar? s/n: ");
				if(rta=='s'){
					ret= employee_setNombre(aux, nombreNuevo);
				}else{
					ret =2; //anular modificacion
				}
				break;

			case 2:
				getInt(&horasNuevo, "Ingrese las horas trabajadas: ", 0, 500, "Error, ingrese las horas trabajadas: ");
				printf("Esta por reemplazar las horas trabajadas de -%d- a -%d-.", horasAux, horasNuevo);
				rta = getChar("\nDesea continuar? s/n: ", 's', 'n', "Error. Desea continuar? s/n: ");
				if(rta=='s'){
					ret=employee_setHorasTrabajadas(aux, horasNuevo);
				}else{
					ret =2; //anular modificacion
				}
				break;

			case 3:
				getInt(&sueldoNuevo, "Ingrese el sueldo: ", 10000, 100000, "Error, ingrese el sueldo: ");
				printf("Esta por reemplazar el sueldo de -%d- a -%d-.", sueldoAux, sueldoNuevo);
				rta = getChar("\nDesea continuar? s/n: ", 's', 'n', "Error. Desea continuar? s/n: ");
				if(rta=='s'){
					ret=employee_setSueldo(aux, sueldoNuevo);
				}else{
					ret =2; //anular modificacion
				}
				break;

			case 4:
				ret =2;//anular modificacion
				break;


		}

		if(ret==0)
		{

			ret= ll_set(pArrayListEmployee, busquedaIndice, aux);
		}



	}
	}


    return ret;
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

			if(aux!=NULL)
			{
				ret= mostrarUnEmpleado(aux, &idAux, nombreAux, &sueldoAux, &horasAux);
			}


		}
	}

    return ret;
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
	int idAux;
	char nombreAux[128];
	int sueldoAux;
	int horasAux;
	char rta;
	int ret = -1;
	Employee* aux;

	if(pArrayListEmployee!=NULL)
	{
		busquedaIndice = buscarIndice(pArrayListEmployee);

		//aux= ll_pop(pArrayListEmployee, busquedaIndice);  //no lo uso para poder mostrar antes de eliminar y realizar comprobacion

		aux = ll_get(pArrayListEmployee, busquedaIndice);

		if(aux!=NULL)
		{
			printf("%5s - %20s - %15s - %10s\n","ID", "NOMBRE", "HS TRABAJADAS", "SUELDO");
			ret= mostrarUnEmpleado(aux, &idAux, nombreAux, &sueldoAux, &horasAux);

			rta = getChar("Desea eliminar el ID? s/n: ", 's', 'n', "Error, desea eliminar el ID? s/n: ");

			if(rta=='s')
			{
				ret = ll_remove(pArrayListEmployee, busquedaIndice);
			}else
			{
				ret=2; //opcion anular en "analizar situacion" del main
			}

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

	printf("\nElija un campo de ordenamiento:\n1. Id.\n2. Nombre.\n3. Horas trabajadas.\n4. Sueldo.\n5. Volver a la pantalla principal.\n");
	getInt(&campo, "Ingrese su opcion: ", 1, 5, "Ingrese una opcion valida: ");

	if(campo!=5)
	{
		printf("\nElija un criterio de ordenamiento:\n1. Ascendente.\n0. Descendente.\n");
		getInt(&orden, "Ingrese su opcion: ", 0, 1, "Ingrese una opcion valida: ");

		printf("\nORDENANDO...\n\n");
	}

	switch(campo)
	{
		case 1: //orden por ID
			ret=ll_sort(pArrayListEmployee, employee_CompareById, orden); //1 ascendente 0 descendente
			break;

		case 2: //orden por NOMBRE
			ret= ll_sort(pArrayListEmployee, employee_CompareByName, orden); //1 ascendente 0 descendente
			break;

		case 3: //orden por HORAS TRABAJADAS
			ret= ll_sort(pArrayListEmployee, employee_CompareByHours, orden); //1 ascendente 0 descendente
			break;

		case 4: //orden por SUELDO
			ret= ll_sort(pArrayListEmployee, employee_CompareBySalary, orden); //1 ascendente 0 descendente
			break;

		case 5: //anular ordenamiento
			ret=2; //opcion ANULAR "analizar situacion" en el main
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
	int ret; //ERROR
	int largo;
	int i;
	char nombreAux[128];
	int sueldoAux;
	int idAux;
	int horasAux;
	int pruebaId;
	int pruebaNombre;
	int pruebaSueldo;
	int pruebaHoras;
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
			pruebaId= employee_getId(aux, &idAux);
			pruebaNombre= employee_getNombre(aux, nombreAux);
			pruebaSueldo= employee_getSueldo(aux, &sueldoAux);
			pruebaHoras=employee_getHorasTrabajadas(aux, &horasAux);

			if(pruebaId==0 && pruebaNombre==0 && pruebaSueldo==0 && pruebaHoras==0)
			{
				fprintf(pFile,"%d,%s,%d,%d\n", idAux, nombreAux, horasAux, sueldoAux);
			}
			}
		}
	ret=0;
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


/** \brief buscarIdSinUso>>> SE LA UTILIZA UNA UNICA VEZ CUANDO SE LEE UN ARCHIVO PARA SABER CUAL ES EL ULTIMO ID UTILIZADO.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int >>> PRIMER ID PARA USAR. DESPUES SE VA AUTOINCREMENTANDO (EN EL MAIN) EL ID CADA VEZ QUE SE AGREGA UN EMPLEADO
 *
 */
int buscarIdSinUso (LinkedList* pArrayListEmployee)
{
	int idNuevo=-1; //ERROR
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
			if(aux!=NULL)
			{
				employee_getId(aux, &idAux);

				if(i==0 || idAux > maximo)
				{
					maximo=idAux;
				}
			}
		}

		idNuevo=maximo+1;

	}

	return idNuevo;
}


/** \brief buscarId>>> SE LA UTILIZA PARA CORROBORAR QUE EL ID INGRESADO POR EL USUARIO EXISTE EN LA LL
 *
 * \param pArrayListEmployee LinkedList*
 * \param idingresado int
 * \return int >>> indice donde se ubica el id ingresado en la LL / -1 ID inexistente
 *
 */
int buscarId(LinkedList* pArrayListEmployee, int idIngresadoPorUsuario)
{
	int indice=-1; //ERROR
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



/** \brief buscarIndice>>> SE LE PIDE ID AL USUARIO, SE VERIFICA QUE ESTE Y DEVUELVE EL INDICE
 *
 * \param pArrayListEmployee LinkedList*
 * \return int >>> indice donde se ubica el id ingresado en la LL
 *
 */
int buscarIndice (LinkedList* pArrayListEmployee)
{

	int idIngresado;
	int busquedaIndice;

	controller_ListEmployee(pArrayListEmployee);

	do
	 {
		printf("\nSeleccione un ID de la lista: ");
		scanf("%d", &idIngresado);

		busquedaIndice =buscarId(pArrayListEmployee,idIngresado);

		 switch(busquedaIndice)
			{
			        case -1: //id inexistente
			        printf("\nError. ID inexistente. Ingrese uno valido.\n");
			        break;

			        default: //se encontro el ID
			        break;

			 }

	 }while(busquedaIndice==-1);


	return busquedaIndice;
}

