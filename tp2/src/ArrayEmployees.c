#include "ArrayEmployees.h"


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee list[], int len)
{
	int i;
	if(len!=0)
	{
	for(i=0; i<len; i++)
		{
		list[i].isEmpty=TRUE;
		}
		return 0;
	}else
	{
		return -1;
	}
}


/** \Funcion hardcodear, carga unos datos modelos en el array de empleados para poder testear el resto de las funciones.
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (!-1) if Ok // me devuelve el primer id libre para usar
*
*/
int hardcodear(Employee list[], int len)
 {
	int i;
	int id[5]= {1,2,3,4,5};
	char nombres[5][51] = {"Ana","Lucas","Maria Soledad","Juan Martin", "Julio"};
	char apellidos[5][51] = {"Garcia","Lopez","Perez","Ramirez", "Tunez"};
	float salarios[5] = { 25000, 40000 ,35650.555, 27500, 33500.75 };
	int sectores[5] = {4, 2 ,3, 3, 5};
	int vacios[5] = {FALSE, FALSE, FALSE, FALSE, FALSE};

	if(5<len)
	{
		for(i=0; i < 5; i++)
		{
	     list[i].id=id[i];
	     strcpy(list[i].name,nombres[i]);
	     strcpy(list[i].lastName,apellidos[i]);
	     list[i].salary=salarios[i];
	     list[i].sector=sectores[i];
	     list[i].isEmpty=vacios[i];
		}
		return id[4]+1; //me devuelve el primer id sin usar
	}
	else
	{
		return -1; //no hay lugar
	}

}




/* brief: creacion de variables y llama a la funcion addEmployee, le pasa las variables como parametros
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param: id que viene hardcodeado del main (para que no se repita)
    return: int -1 no hay espacio.
             	 0 se cargo correctamente
*/
int cargarEmpleado(Employee* list, int len, int id)
{
	char name[51];
	char lastName[51];
	float salary=0;
	int sector=0;
	int estado=0;

	estado = addEmployee(list, len, id, name, lastName, salary, sector);

	return estado; // si es -1 no hay espacio   /   0 se cargo correctamente
}



/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok **/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int indiceEncontrado;

    indiceEncontrado = buscarLibre(list, len);

    if(indiceEncontrado!= -1) //encontro lugar
    {
        printf("\n---------------------------------------------------");
        printf("\n              ALTA EMPLEADO                   ");
        printf("\n---------------------------------------------------\n");

        //si encuentro lugar, pido los datos
        //cambiar el estado

        printf("Cargue los siguientes datos del nuevo empleado:\n");

        getString(name,"Nombre");
        getString(lastName,"Apellido");
        printf("Sueldo: ");
        scanf("%f", &salary);
        printf("Sector: ");
        scanf("%d", &sector);


        strcpy(list[indiceEncontrado].name,name);
        strcpy(list[indiceEncontrado].lastName,lastName);
	    list[indiceEncontrado].id=id;
	    list[indiceEncontrado].salary=salary;
	    list[indiceEncontrado].sector=sector;
	    list[indiceEncontrado].isEmpty=FALSE;
        printf("ID Proveedor: %d\n", id);

	    return 0; //se cargo producto

    }

    return indiceEncontrado; //indice -1, no hay lugar
}


/** \brief search in a existing list of employees the first empty position
* \param list employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (!-1) if Ok, return the first empty position**/
int buscarLibre (Employee* list, int len)
{
    int i;
    int indice=-1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==TRUE)
        {
            indice=i;
            break; // rompo para que me devuelva la primera posicion vacia
        }
    }
    return indice;
}

/** \brief pedirle al usuario un string y formatearlo (elimino salto de linea del fgets y paso a minuscula el string y primeras letras mayusculas)
* \param char string, que lo completa el usuario
* \param char texto, texto que se informa en el printf para reutilizar la funcion
* \return void **/
void getString(char palabra[], char texto[] )
{
   int largoString;
   int i;

	printf("%s: ",texto);
	fflush(stdin);
	//__fpurge(stdin);
	fgets(palabra,51,stdin);

	largoString= strlen(palabra);       // busco el largo del string
	palabra[largoString-1]='\0';
	largoString= strlen(palabra);


	strlwr(palabra);
	palabra[0]=toupper(palabra[0]);

	for(i=0; i<largoString; i++)
	{
		if(palabra[i]==' ')
		{
			palabra[i+1]=toupper(palabra[i+1]);

		}
	}

}




void mostrarUnEmployee(Employee list[], int index)
{
		printf("%5d %15s %15s %12.2f %5d\n",list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int mostrarEmployees(Employee list[], int len)
{
	int i;
	if(len<0)
	{
		return -1;
	}else
	{
	printf("%5s - %15s - %15s - %12s - %5s\n", "ID", "NOMBRE", "APELLIDO", "SUELDO", "SECTOR");
	for(i=0; i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				mostrarUnEmployee(list,i);
			}
		}
		return 0;
	}
}



int removeEmployee (Employee list[], int len, int id)
{
	int situacion;
	int posicionId;
	char respuesta;
	situacion = findEmployeeById(list, len, id);

	if(situacion==-1)
	{
		return -1;   // no se encontro el ID

	}else
	{
		posicionId = posicionDelId(list, len, id);

		printf("Esta por borrar el ID %d - %s %s - desea confirmar? s/n: ",id, list[posicionId].name, list[posicionId].lastName);
		fflush(stdin);
		scanf("%c",&respuesta);
		if(respuesta=='s')
		{
			list[posicionId].isEmpty=TRUE;
			printf("\nSe ha eliminado el ID %d - %s %s - de la base.\n", id, list[posicionId].name, list[posicionId].lastName);
		return 0;  		// eliminacion confirmada
		}else
		{
		return 1;			// eliminacion cancelada
		}

	}


}

int posicionDelId (Employee list[], int len, int id)
{
	int i;
	int posicionId;

	for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==FALSE && id==list[i].id) //no valido si esta vacio porque ya lo hice en el buscar, aca quiero chequear la posicion del id
			{
				posicionId=i;
				break;
			}
		}
	return posicionId;
}


int modifyEmployee (Employee list[], int len, int id)
{
	int posicionId;
	int situacion;
	char respuesta;

	situacion = findEmployeeById(list, len, id);


	if(situacion!=-1)
	{
		posicionId = posicionDelId(list, len, id);

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
		strlwr(nuevoString);  // poner string a minuscula
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


int pedirleIdAlUsuario (Employee list[], int len)
{
    int busquedaId;
    int idIngresadoPorUsuario;
    int estadoMostrar;

    ordenarEmployeesPorId(list, len); //ordeno array por id de menor a mayor

 do
 {
	estadoMostrar= mostrarEmployees(list, len);
	if(estadoMostrar==0)
	{
    printf("\nSeleccione un ID de la lista: ");
	scanf("%d", &idIngresadoPorUsuario);

	printf("\n\n");

    busquedaId =findEmployeeById(list, len, idIngresadoPorUsuario);

    switch(busquedaId)
	{
	        case 1: //se encontro el ID
	        break;

	        case -1: //id inexistente
	        printf("Error. ID empleado inexistente. Ingrese uno valido.\n\n");

	 }
	}


}   while(busquedaId==-1);

	 return idIngresadoPorUsuario;

}



/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee list[], int len, int idIngresadoPorUsuario)
{
    int i;
    for(i=0; i<len; i++)
	    {
	        if(list[i].isEmpty==FALSE && idIngresadoPorUsuario==list[i].id)
	        {
	                 return 1; //se encontro el id
	                 break;
	        }
	    }
	return -1; //no se encontro el id
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
				if(strcmp(list[i].lastName, list[j].lastName)>order || (strcmp(list[i].lastName, list[j].lastName)==0 && list[i].sector>list[j].sector))   // >0 de A a Z			<0 o <1 de la Z a la a
				{
					auxiliarEmployee = list[i];
					list[i]=list[j];
					list[j]=auxiliarEmployee;
				}

			}
		}
	}

}



void ordenarEmployeesPorId (Employee* list, int len)  //Listado de los empleados ordenados id menor a mayor
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
				if(list[i].id > list[j].id)
				{
					auxiliarEmployee = list[i];
					list[i]=list[j];
					list[j]=auxiliarEmployee;
				}

			}
		}
	}

}
