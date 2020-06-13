
#include "Employee.h"


/** \brief employee_new. Crea espacio en memoria dinamica para guardar UN dato tipo Employee, PERO SIN PARAMETROS
 *
 * \param void
 * \return Employee*
 *
 */
Employee* employee_new()
{
	Employee* pAuxEmpleado;
	pAuxEmpleado = (Employee*) malloc(sizeof(Employee));
	return pAuxEmpleado; //no valido aca que sea NULL porque seria igualmente pasar NULL, cada vez que se llama a esta funcion se verifica el NULL
}



/** \brief employee_newParametros Crea espacio en memoria dinamica para guardar UN dato tipo Employee y recibe los datos como parametros EN TEXTO.
 * 								  Lo uso para leer los archivos de TEXTO
 * \param char* idStr,
 * \param char* nombreStr,
 * \param char* horasTrabajadasStr,
 * \param char* sueldoStr
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pAuxEmpleado=NULL;
	int pruebaId;
	int pruebaNombre;
	int pruebaSueldo;
	int pruebaHoras;

	if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		pAuxEmpleado=employee_new();

		if(pAuxEmpleado!=NULL)
		{
			//no valido aca, lo hago cuando pido datos.
			//Considero que los datos ya fueron validados antes de ser guardados
			pruebaId = employee_setId(pAuxEmpleado, atoi(idStr));
			pruebaNombre= employee_setNombre(pAuxEmpleado, nombreStr);
			pruebaSueldo= employee_setSueldo(pAuxEmpleado, atoi(sueldoStr));
			pruebaHoras= employee_setHorasTrabajadas(pAuxEmpleado, atoi(horasTrabajadasStr));

			if(pruebaId==-1 || pruebaNombre==-1 || pruebaSueldo==-1 || pruebaHoras==-1)
			{
				pAuxEmpleado=NULL;
			}

		}
	}
	return pAuxEmpleado;
}



/** \brief employee_setNombre escribe en el campo de un empleado de la LL, el dato pasado como parametro
 * \param Employee* this,
 * \param char* nombre,
 * \return int =  0>>OK  -1>>NULO
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{

    int ret = -1;
    if(this!=NULL && nombre!=NULL)
    {

        strcpy(this->nombre , nombre);
        ret = 0;
    }


    return ret;

}

/** \brief employee_getNombre escribe en la variable local pasada como parametro el dato de un campo de un empleado de la LL
 * \param Employee* this,
 * \param char* nombre,
 * \return int =  0>>OK  -1>>NULO
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{

    int ret = -1;
    if(this!=NULL && nombre!=NULL)
    {

        strcpy(nombre,this->nombre);
        ret = 0;
    }


    return ret;
}


/** \brief employee_setSueldo escribe en el campo de un empleado de la LL, el dato pasado como parametro
 * \param Employee* this,
 * \param int sueldo,
 * \return int =  0>>OK  -1>>NULO
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->sueldo = sueldo;
        ret = 0;
    }


    return ret;
}


/** \brief employee_getSueldo escribe en la variable local pasada como parametro el dato de un campo de un empleado de la LL
 * \param Employee* this,
 * \param int* sueldo,
 * \return int =  0>>OK  -1>>NULO
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret = -1;
    if(this!=NULL && sueldo!=NULL)
    {

    	(*sueldo)= this->sueldo;
        ret = 0;
    }


    return ret;

}


/** \brief employee_setId escribe en el campo de un empleado de la LL, el dato pasado como parametro
 * \param Employee* this,
 * \param int id,
 * \return int =  0>>OK  -1>>NULO
 *
 */
int employee_setId(Employee* this,int id)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->id = id;
        ret = 0;
    }


    return ret;

}


/** \brief employee_getId escribe en la variable local pasada como parametro el dato de un campo de un empleado de la LL
 * \param Employee* this,
 * \param int* id,
 * \return int =  0>>OK  -1>>NULO
 *
 */
int employee_getId(Employee* this,int* id)
{
    int ret = -1;
    if(this!=NULL && id!=NULL)
    {

    	(*id)= this->id;
        ret = 0;
    }


    return ret;
}


/** \brief employee_setHoras escribe en el campo de un empleado de la LL, el dato pasado como parametro
 * \param Employee* this,
 * \param int horas,
 * \return int =  0>>OK  -1>>NULO
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret = -1;
    if(this!=NULL)
    {

    	this->horasTrabajadas = horasTrabajadas;
        ret = 0;
    }


    return ret;
}


/** \brief employee_gethoras escribe en la variable local pasada como parametro el dato de un campo de un empleado de la LL
 * \param Employee* this,
 * \param int* horas,
 * \return int =  0>>OK  -1>>NULO
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    int ret = -1;
    if(this!=NULL && horasTrabajdas!=NULL)
    {

    	(*horasTrabajdas)= this->horasTrabajadas;
        ret = 0;
    }


    return ret;

}



/** \brief employee_CompareById >> castea dos variables de tipo void a tipo Employee y las compara segun el campo ID
 * \param void* e1,
 * \param void* e2,
 * \return int =  0:"1=2"  -1:"1<2"    1:"1>2"
 *
 */
int employee_CompareById(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int numero1;
	int numero2;

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		valor= employee_getId(dato1, &numero1);
		valor = employee_getId(dato2, &numero2);

		if(numero1 > numero2)
		{
			valor=1; //el 1 es MAYOR que el 2
		}
		else if (numero1 < numero2)
		{
			valor =-1; //el 1 es MENOR que el 2
        }
        else
        {
            valor=0; //el 1 y 2 son IGUALES
        }
    }

    return valor;
}

/** \brief employee_CompareByName >> castea dos variables de tipo void a tipo Employee y las compara segun el campo NOMBRE
 * \param void* e1,
 * \param void* e2,
 * \return int =  0:"1=2"  -1:"1<2"    1:"1>2"
 *
 */
int employee_CompareByName(void* e1, void* e2)
{
	int valor=-10;
	char nombre1[128];
	char nombre2[128];

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		valor = employee_getNombre(dato1,nombre1);
		valor = employee_getNombre(dato2,nombre2);

		valor = strcmp(nombre1, nombre2);

	}

    return valor;
}

/** \brief employee_CompareByHours >> castea dos variables de tipo void a tipo Employee y las compara segun el campo HORAS
 * \param void* e1,
 * \param void* e2,
 * \return int =  0:"1=2"  -1:"1<2"    1:"1>2"
 *
 */
int employee_CompareByHours(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int horas1;
	int horas2;

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		valor= employee_getHorasTrabajadas(dato1, &horas1);
		valor =employee_getHorasTrabajadas(dato2, &horas2);

		if(horas1 > horas2)
		{
			valor=1; //el 1 es MAYOR que el 2
		}
		else if (horas1 < horas2)
		{
			valor =-1; //el 1 es MENOR que el 2
        }
        else
        {
            valor=0; //el 1 y 2 son IGUALES
        }
    }

    return valor;
}


/** \brief employee_CompareBySalary >> castea dos variables de tipo void a tipo Employee y las compara segun el campo SUELDO
 * \param void* e1,
 * \param void* e2,
 * \return int =  0:"1=2"  -1:"1<2"    1:"1>2"
 *
 */
int employee_CompareBySalary(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int sueldo1;
	int sueldo2;

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		valor= employee_getSueldo(dato1, &sueldo1);
		valor= employee_getSueldo(dato2, &sueldo2);

		if(sueldo1 > sueldo2)
		{
			valor=1; //el 1 es MAYOR que el 2
		}
		else if (sueldo1 < sueldo2)
		{
			valor =-1; //el 1 es MENOR que el 2
        }
        else
        {
            valor=0; //el 1 y 2 son IGUALES
        }
    }

    return valor;
}



int mostrarUnEmpleado (Employee* aux, int* idAux, char* nombreAux, int* sueldoAux, int* horasAux)
{
	int ret=-1;
	int pruebaId;
	int pruebaNombre;
	int pruebaSueldo;
	int pruebaHoras;

	if(aux!=NULL && idAux!=NULL && nombreAux!=NULL && sueldoAux!=NULL && horasAux!=NULL)
	{
	pruebaId= employee_getId(aux, idAux);
	pruebaNombre= employee_getNombre(aux, nombreAux);
	pruebaSueldo= employee_getSueldo(aux, sueldoAux);
	pruebaHoras=employee_getHorasTrabajadas(aux, horasAux);

	if(pruebaId==0 && pruebaNombre==0 && pruebaSueldo==0 && pruebaHoras==0)
		{
		printf("%5d - %20s - %15d - %10d\n", *idAux, nombreAux,  *horasAux, *sueldoAux);
		ret=0;
		}
	}

	return ret;
}
