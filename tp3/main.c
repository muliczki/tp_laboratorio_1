#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);

    int option;
    int largo;


    LinkedList* listaEmpleados = ll_newLinkedList();


    do{

	printf("opcion: ");
    scanf("%d", &option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                largo = ll_len(listaEmpleados);

                printf("%d\n", largo);
                break;

            case 2:
                 controller_loadFromBinary("databin.csv",listaEmpleados);
                 largo = ll_len(listaEmpleados);

                 printf("%d\n", largo);
                 break;
            /*
            case 3:
            	controller_addEmployee(listaEmpleados);
			*/

            case 6:
            	controller_ListEmployee(listaEmpleados);

                break;

            case 7:
            	controller_sortEmployee(listaEmpleados);
                break;

            case 8:

                           break;

            case 9:
            	controller_saveAsBinary("databin.csv",listaEmpleados);

			   printf("Guardado\n");
			   largo = ll_len(listaEmpleados);

			                  printf("%d\n", largo);
			   break;

        }
    }while(option != 10);
    return 0;
}
