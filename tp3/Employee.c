
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
		//FALTA AGREGAR EL RETORNO!!!!!!

		//no valido aca, lo hago cuando pido datos.
		//Considero que si los datos ya fueron validados antes de ser guardados
		employee_setId(pAuxEmpleado, atoi(idStr));
		employee_setNombre(pAuxEmpleado, nombreStr);
		employee_setSueldo(pAuxEmpleado, atoi(sueldoStr));
		employee_setHorasTrabajadas(pAuxEmpleado, atoi(horasTrabajadasStr));

		//pAuxEmpleado->horasTrabajadas=atoi(horasTrabajadasStr);
		//pAuxEmpleado->id=atoi(idStr);
		//strcpy(pAuxEmpleado->nombre, nombreStr);
		//pAuxEmpleado->sueldo=atoi(sueldoStr);

	}



	return pAuxEmpleado;
}




int employee_setNombre(Employee* this,char* nombre)
{

    int ret = 0;
    if(this!=NULL && nombre!=NULL)
    {

        strcpy(this->nombre , nombre);
        ret = 1;
    }


    return ret;

}

int employee_getNombre(Employee* this,char* nombre)
{

    int ret = 0;
    if(this!=NULL && nombre!=NULL)
    {

        strcpy(nombre,this->nombre);
        ret = 1;
    }


    return ret;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int ret = 0;
    if(this!=NULL)
    {

    	this->sueldo = sueldo;
        ret = 1;
    }


    return ret;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret = 0;
    if(this!=NULL && sueldo!=NULL)
    {

    	(*sueldo)= this->sueldo;
        ret = 1;
    }


    return ret;

}

int employee_setId(Employee* this,int id)
{
    int ret = 0;
    if(this!=NULL)
    {

    	this->id = id;
        ret = 1;
    }


    return ret;

}

int employee_getId(Employee* this,int* id)
{
    int ret = 0;
    if(this!=NULL && id!=NULL)
    {

    	(*id)= this->id;
        ret = 1;
    }


    return ret;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret = 0;
    if(this!=NULL)
    {

    	this->horasTrabajadas = horasTrabajadas;
        ret = 1;
    }


    return ret;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    int ret = 0;
    if(this!=NULL && horasTrabajdas!=NULL)
    {

    	(*horasTrabajdas)= this->horasTrabajadas;
        ret = 1;
    }


    return ret;

}




int employee_CompareById(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int numero1;
	int numero2;

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		employee_getId(dato1, &numero1);
		employee_getId(dato2, &numero2);

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


int employee_CompareByName(void* e1, void* e2)
{
	int valor=-1;
	char nombre1[128];
	char nombre2[128];

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		employee_getNombre(dato1,nombre1);
		employee_getNombre(dato2,nombre2);


		//valor = strcmp(dato1->nombre, dato2->nombre);
		valor = strcmp(nombre1, nombre2);

	}

    return valor;
}

int employee_CompareByHours(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int horas1;
	int horas2;

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		employee_getHorasTrabajadas(dato1, &horas1);
		employee_getHorasTrabajadas(dato2, &horas2);

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

int employee_CompareBySalary(void* e1, void* e2)
{
	int valor=-10; //numero no razonable para indicar que es nulo
	int sueldo1;
	int sueldo2;

	if(e1!=NULL && e2!=NULL)
	{
		Employee* dato1 = (Employee*)e1;
		Employee* dato2 = (Employee*)e2;

		employee_getSueldo(dato1, &sueldo1);
		employee_getSueldo(dato2, &sueldo2);

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
