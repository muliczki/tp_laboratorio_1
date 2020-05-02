#include "ArrayEmployees.h"

/*
 void hardcodear(Employee list[])
{
	Employee list[0] = {1, "Ana", "Garcia", 25000, 4, 0};
}
*/



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
	int i;
	for(i=0; i<len; i++)
		{
		list[i].isEmpty=TRUE;
		}
	return 0;
}

int cargarId (Employee list[], int len)
{
	//id=1; //el ID empieza en 1. no considere a empleado con ID cero
	int i;

	for(i=0; i<len; i++)
	{
		if((list[i].isEmpty==TRUE) && ( (i+1)!=list[i].id) )  //// veeeeeeeeeeer funciona pero no me usa los id borrados
		{
			return i+1;
		}
	}
return -1;
}

//int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
Employee cargarUnEmployee(Employee list[], int len)
{
	Employee unEmpleado;
	unEmpleado.id=cargarId(list, len);

	unEmpleado.isEmpty=FALSE;
	printf("ALTA DE EMPLEADO.\nCargue los siguientes datos del nuevo empleado:");
	printf("\nNumero ID: %d\n",unEmpleado.id);
	printf("Nombre: ");
	fflush(stdin);
	gets(unEmpleado.name);
	printf("Apellido: ");
	fflush(stdin);
	gets(unEmpleado.lastName);
	printf("Sueldo: ");
	scanf("%f", &unEmpleado.salary);
	printf("Sector: ");
	scanf("%d", &unEmpleado.sector);

	//formatearNombres(unEmpleado);

	return unEmpleado;
}

	/*
	char* formatearNombres (Employee unEmpleado)
	{
	char auxiliar[51];
	strcpy(auxiliar, unEmpleado.name);
	strlwr(auxiliar);
	auxiliar[0]=toupper(auxiliar[0]); //incluir biblioteca #include <ctype.h>

	printf("%s", auxiliar);
	return auxiliar;
	}
	*/



void mostrarUnEmployee(Employee list[], int i)
{
		printf("%5d %15s %15s %12.2f %5d\n",list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
}

void mostrarEmployees(Employee list[], int len)
{
	int i;
	printf("   ID       Nombre        Apellido         Sueldo    Sector\n");
	for(i=0; i<len;i++)
	{
		if(list[i].isEmpty==FALSE)
		{
			mostrarUnEmployee(list,i);
		}
	}
}



int removeEmployee (Employee list[], int len, int id)
{
	int posicionId;
	char respuesta;
	posicionId = buscarID(list, len, id);

	if(posicionId==-1)
	{
		return -1;   // no se encontro el ID

	}else
	{
		printf("Esta por borrar el ID %d - %s %s - desea confirmar? s/n: ",id, list[posicionId].name, list[posicionId].lastName);
		fflush(stdin);
		scanf("%c",&respuesta);
		if(respuesta=='s')
		{
			list[id-1].isEmpty=TRUE;
			printf("\nSe ha eliminado el ID %d - %s %s - de la base.\n", id, list[posicionId].name, list[posicionId].lastName);
		return 0;  		// eliminacion confirmada
		}else
		{
		return 1;			// eliminacion cancelada
		}

	}


}

int modifyEmployee (Employee list[], int len, int id)
{
	int posicionId;
	int situacion;
	char respuesta;
		posicionId = buscarID(list, len, id);

	if(posicionId!=-1)
	{
		printf("\nEsta por modificar el ID %d - %s %s -",id, list[posicionId].name, list[posicionId].lastName);
		printf("\n\nSeleccione lo que desea modificar: ");
		printf("\na) Nombre.");
		printf("\nb) Apellido.");
		printf("\nc) Sueldo.");
		printf("\nd) Sector.");
		printf("\n\nIngrese su opcion: ");
		fflush(stdin);
		scanf("%c",&respuesta);

		switch(respuesta)
		{
		case 'a':
			 	 situacion = modificarString("nombre", list, len, posicionId);
			 	 break;

		case 'b':
			 	 situacion= modificarString("apellido", list, len, posicionId);
			 	 break;

		case 'c':
				 situacion= modificarFlotante("sueldo", list, len, posicionId);
				 break;

		case 'd':
				 situacion= modificarEntero("sector", list, len, posicionId);
				 break;

		default:
				 situacion=1; // cancelado

		}

	}else
	{
		situacion=posicionId;  //posicion -1 > id no encontrado
	}

return situacion;

}



int modificarString(char texto[], Employee list[], int len, int posicionId)
{
	char nuevoString[51];
	char respuesta;
	int i;

	printf("\nIngrese el nuevo %s: ",texto); // le pido al usuario el nuevo string
	fflush(stdin);
	gets(nuevoString);
	if(strcmp(texto,"nombre")==0) // pregunto si es el nombre
	{
		printf("\nEsta seguro que desea modificar el %s '%s' por '%s'? s/n: ",texto, list[posicionId].name, nuevoString);
	}
	else 						// si es el apellido pasa esto
	{
		printf("\nEsta seguro que desea modificar el %s '%s' por '%s'? s/n: ",texto, list[posicionId].lastName, nuevoString);
	}
	fflush(stdin);
	scanf("%c",&respuesta);
	if(respuesta=='s')
	{
		strlwr(nuevoString);  // poner todo a minuscula
		nuevoString[0]=toupper(nuevoString[0]);  //poner primera letra mayuscula
		for(i=0; i<51; i++)
		{
			if(nuevoString[i]==' ')
			{
				nuevoString[i+1]=toupper(nuevoString[i+1]); // preguntar si hay nombre/apellido compuesto
			}
		}

		if(strcmp(texto,"nombre")==0)
			{
			strcpy(list[posicionId].name,nuevoString);
			}else
			{
				strcpy(list[posicionId].lastName,nuevoString);
			}
		printf("\nEl nuevo %s es '%s'.\n",texto, nuevoString);
		return 0;    //Modificacion confirmada
	}else
	{
		return 1;   //Modificacion cancelada
	}
}

int modificarFlotante(char texto[], Employee list[], int len, int posicionId)
{
	float nuevoFloat;
	char respuesta;

	// if(strcmp(texto,"sueldo")==0)      // base por si tuviese mas int a modificar
	printf("\nEl %s actual es $%.2f.",texto, list[posicionId].salary);
	printf("\nIngrese el nuevo %s: ",texto);
	scanf("%f", &nuevoFloat);

	printf("Esta seguro que desea modificar el %s '$%.2f' por '$%.2f'? s/n: ",texto, list[posicionId].salary, nuevoFloat);

	fflush(stdin);
	scanf("%c",&respuesta);
	if(respuesta=='s')
	{
		list[posicionId].salary=nuevoFloat;

		printf("\nEl nuevo %s es '$%.2f'.\n",texto, nuevoFloat);
		return 0;   //Modificacion confirmada
	}else
	{
		return 1;   //Modificacion cancelada
	}
}

int modificarEntero(char texto[], Employee list[], int len, int posicionId)
{
	int nuevoInt;
	char respuesta;

	// if(strcmp(texto,"sector")==0)      // base por si tuviese mas int a modificar
	printf("\nEl %s actual es %d.",texto, list[posicionId].sector);
	printf("\nIngrese el nuevo %s: ",texto);
	scanf("%d", &nuevoInt);

	printf("Esta seguro que desea modificar el %s '%d' por '%d'? s/n: ",texto, list[posicionId].sector, nuevoInt);

	fflush(stdin);
	scanf("%c",&respuesta);
	if(respuesta=='s')
	{
		list[posicionId].sector=nuevoInt;

		printf("\nEl nuevo %s es '%d'.\n",texto, nuevoInt);
		return 0;   //Modificacion confirmada
	}else
	{
		return 1;   //Modificacion cancelada
	}
}


int mostrarMenu(void)
{
	int respuesta;

	printf("BASE DE EMPLEADOS");
	printf("\nElija una de las siguientes opciones:");
	printf("\n1. ALTAS.");
	printf("\n2. MODIFICAR.");
	printf("\n3. BAJAS.");
	printf("\n4. INFORMAR.");
	printf("\n5. SALIR DEL SISTEMA.");
	printf("\n\nIngrese su opcion: ");
	scanf("%d",&respuesta);

	return respuesta;
}





int preguntarPrimeraCarga(int flag)
{
	int estado;
	if(flag == 0)
	{
		printf("No ha cargado ningun empleado. Por favor, realicelo.\n");
		estado=-1;
	}else
	{
		estado=1;
	}
	return estado;
}


int pedirUnId (char texto[], Employee list[], int len)
{
	int id;
	printf("Ingrese el ID que desea %s: ",texto);
	scanf("%d", &id);
	return id;

}

int buscarID(Employee list[], int len, int id)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==FALSE && list[i].id==id)
		{
			return i;  // devuelvo la posicion del ID
		}
	}
	return -1;  //no se encontro el ID
}

void analizarSituacion (int situacion, char texto[])
{
	if(situacion==-1)
	{
		printf("\nID no encontrado, intente nuevamente.\n\n");     //ID no encontrado
	}
	else if(situacion==0)
	{
		printf("\n%s correcta y finalizada.\n\n",texto);    //confirmada
	}
	else if(situacion==1)
	{
		printf("\n%s cancelada.\n\n", texto);          // cancelado
	}
}


void sortEmployees(Employee* list, int len, int order)  //Listado de los empleados ordenados alfabéticamente por Apellido y Sector
{
	int i;
	int j;
	Employee auxiliarEmployee;

	for(i=0;i<len-1;i++)
	{
		if(list[i].isEmpty==FALSE)
		{
			for(j=i+1;j<len;j++)
			{
				if(strcmp(list[i].lastName, list[j].lastName)>order)   // >0 de A a Z			<0 o <1 de la Z a la a
				{
					auxiliarEmployee = list[i];
					list[i]=list[j];
					list[j]=auxiliarEmployee;
				}else
				{
					if(strcmp(list[i].lastName, list[j].lastName)==0)
					{
						if(list[i].sector>list[j].sector)  // >sector de menor a mayor
						{
							auxiliarEmployee = list[i];
							list[i]=list[j];
							list[j]=auxiliarEmployee;
						}
					}

				}
			}
		}
	}

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==FALSE)
		{
		printf("%5d %15s %15s %12.2f %5d\n",list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
		}
	}
	}

