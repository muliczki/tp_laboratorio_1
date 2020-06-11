#include "datos.h"


int mostrarMenu(void)
{
    int respuesta;

	printf(" BASE EMPLEADOS");
	printf("\n****************");
	printf("\nMENU:");
	printf("\n1.  Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
	printf("\n2.  Cargar los datos de los empleados desde el archivo databin.csv (modo binario).");
	printf("\n3.  Alta de empleado.");
	printf("\n4.  Modificar datos de empleado.");
	printf("\n5.  Baja de empleado.");
	printf("\n6.  Listar empleados.");
	printf("\n7.  Ordenar empleados.");
	printf("\n8.  Guardar los datos de los empleados en el archivo data.csv (modo texto).");
	printf("\n9.  Guardar los datos de los empleados en el archivo databin.csv (modo binario).");
	printf("\n10. Salir.\n");
	getInt(&respuesta, "Ingrese su opcion: ", 1, 10, "Ingrese una opcion valida: ");

	return respuesta;
}

// - 1 ES ERROR
void analizarSituacion (int situacion, char texto[])
{

	if(situacion==-1)
	{
		printf("\nERROR!! REINTENTAR.\n\n");    //error
	}
	else if(situacion==2)
	{
		printf("\nOPCION ANULADA.\n\n");    //anulado
	}
	else
	{
		printf("\n%s.\n\n", texto);     //CORRECTO
	}

}


char getChar (char* texto, char opcion1, char opcion2, char* error)
{
	char caracter;
	int flag=0;

	do
	{
		if(flag==0)
		{
			printf("%s", texto);
			flag=1;
		}else
		{
			printf("%s", error);
		}

		fflush(stdin);
		scanf("%c",&caracter);


	}while(caracter!=opcion1 && caracter!=opcion2);

	return caracter;
}


void getString (char* string ,char* texto, char* error)
{
	int largoString;
	int i;
	int ret=0;
	int flag=0;


	do
	{
		if(flag==0)
		{
			printf("%s", texto);
			flag=1;
		}else
		{
			printf("%s", error);
		}

		fflush(stdin);
		gets(string);
		 //POR SI LO TENGO QUE EJECUTAR EN GDB
		/*
		fgets(string,51,stdin);

		largoString= strlen(string);
		string[largoString-1]='\0';
		largoString= strlen(string);
		*/
		largoString= strlen(string);       // busco el largo del string

		for(i=0; i<largoString && string[i]!= '\0'; i++ )
		{
			if((string[i]>64 && string[i]<91) || (string[i]>96 && string[i]<123) || string[i]==' ')
			{
				ret = 0;
				continue;
			}else
			{
				ret = -1;
				break;
			}
		}
	}
	while(ret==-1);

	strlwr(string);

	string[0]= toupper(string[0]);

	for(i=0; i<largoString; i++)
	{
		if(string[i]==' ')
		{
			string[i+1]= toupper(string[i+1]);
		}
	}


}

void getInt (int* entero ,char* texto, int minimo, int maximo, char* error)
{
	int flag=0;

	do
	{
		if(flag==0)
		{
			printf("%s", texto);
			flag=1;
		}else
		{
			printf("%s", error);
		}

		scanf("%d",entero);


	}while(*entero<minimo || *entero>maximo);

}

