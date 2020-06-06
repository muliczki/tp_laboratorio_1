
#include "Employee.h"

Employee* employee_new()
{
	Employee* pAuxEmpleado;
	pAuxEmpleado = (Employee*) malloc(sizeof(Employee));
	return pAuxEmpleado;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pAuxEmpleado;
	pAuxEmpleado=employee_new();

	if(pAuxEmpleado!=NULL)
	{
		//ESTA MAL USAR SET Y VALIDAR PERO PARA PROBAR
		pAuxEmpleado->id=atoi(idStr);
		strcpy(pAuxEmpleado->nombre, nombreStr);
		pAuxEmpleado->horasTrabajadas=atoi(horasTrabajadasStr);
		pAuxEmpleado->sueldo=atoi(sueldoStr);

	}

	//employee_setNombre(pAuxEmpleado, nombreStr);

	// mal pero para probar:

	return pAuxEmpleado;
}

/*void pedirNombreAlUsuario (char* nombreStr)
{
	char nombreAux[128];
	int largoString;
	int i;

	printf("Ingrese el nombre: ");
	fflush(stdin);
	//gets(nombreAux);
	//__fpurge(stdin);
	fgets(nombreAux,128,stdin);

	largoString= strlen(nombreAux);       // busco el largo del string
	nombreAux[largoString-1]='\0';
	largoString= strlen(nombreAux);       // busco el largo del string

	strlwr(nombreAux);

	nombreAux[0] = toupper(nombreAux[0]);

	for(i=0; i<largoString; i++)
	{
		if(nombreAux[i]==' ')
		{
			nombreAux[i+1]=toupper(nombreAux[i+1]);
		}
	}



	strcpy(nombreStr, nombreAux);

}

*/
/*
int employee_setNombre(Employee* this,char* nombre)
{

}

int employee_getNombre(Employee* this,char* nombre)
{

}



int employee_setSueldo(Employee* this,int sueldo)
{

}
int employee_getSueldo(Employee* this,int* sueldo)
{


}

int employee_setId(Employee* this,int id)
{

}
int employee_getId(Employee* this,int* id)
{

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{


}


*/

int employee_CompareById(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		if(dato1->id > dato2->id)
		{
			valor=1; //el 1 es MAYOR que el 2
		}
		else if (dato1->id < dato2->id)
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


int employee_CompareByName(void* e1, void* e2)
{
	int valor=-1;

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		valor = strcmp(dato1->nombre, dato2->nombre);

	}

    return valor;
}


