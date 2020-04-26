#include "ArrayEmployees.h"
#include <stdio.h>

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee list[], int len)
{
	list->isEmpty=0;
	return 0;
}

int cargarId (Employee list[], int len)
{
	int id=1;
	int i;

	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty==1)
		{
			id++;
		}
	}
	return id;
}


Employee cargarUnEmployee(Employee list[], int len)
{
	Employee unEmpleado;
	unEmpleado.id=cargarId(list, len);
	//printf("El ID es: %d",unEmpleado.id);
	printf("Ingrese el nombre del empleado: ");
	fflush(stdin);
	gets(unEmpleado.name);
	printf("Ingrese el apellido del empleado: ");
	fflush(stdin);
	gets(unEmpleado.lastName);
	printf("Ingrese el sueldo del empleado: ");
	scanf("%f", &unEmpleado.salary);
	printf("Ingrese el sector del empleado: ");
	scanf("%d", &unEmpleado.sector);

	unEmpleado.isEmpty=1;
	return unEmpleado;
}


void mostrarUnEmployee(Employee list[], int i)
{
		printf("El ID es: %d",list[i].id);
		printf("\nEl nombre del empleado es: %s",list[i].name);
		printf("\nEl apellido del empleado es: %s", list[i].lastName);
		printf("\nEl sueldo del empleado es: %.2f", list[i].salary);
		printf("\nEl sector del empleado es: %d\n", list[i].sector);
}

void mostrarEmployees(Employee list[], int len)
{
	int i;
	for(i=0; i<len;i++)
	{
		if(list[i].isEmpty==1)
		{
			mostrarUnEmployee(list,i);
		}
	}
}
