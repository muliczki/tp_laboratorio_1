#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "datos.h"


int main()
{
	setbuf(stdout, NULL);

    int opcion;
   // int largo;
    int situacion=0;
    int id=1; // si no cargo archivo, el primer id es el 1
    char rta;

    LinkedList* listaEmpleados = ll_newLinkedList();

    if(listaEmpleados!=NULL)
    {
    	do{
		opcion = mostrarMenu();

		switch(opcion)
			{
				case 1: //puedo leer archivo SOLO cuando la lista este vacia, para no duplicar datos
					if(ll_isEmpty(listaEmpleados)==1){
					situacion= controller_loadFromText("data2.csv",listaEmpleados); //PARA EJECUTAR POR CONSOLA ECLIPSE
					//situacion= controller_loadFromText("../data2.csv",listaEmpleados); //PARA EJECUTAR DESDE .EXE EN CARPETA DEBUG
					analizarSituacion(situacion, "ARCHIVO DE TEXTO CARGADO");
					id = buscarIdSinUso(listaEmpleados);
					}else {
						analizarSituacion(situacion, "YA CARGO UN ARCHIVO O TIENE EMPLEADOS CARGADOS, NO PUEDE CARGAR NUEVAMENTE");
					}
					break;

				case 2: //puedo leer archivo SOLO cuando la lista este vacia, para no duplicar datos
					if(ll_isEmpty(listaEmpleados)==1){
					situacion= controller_loadFromBinary("databin.csv",listaEmpleados); //cambie el path por las dudas, para no romper el data.csv
					analizarSituacion(situacion, "ARCHIVO BINARIO CARGADO");
					id = buscarIdSinUso(listaEmpleados);
					} else {
						analizarSituacion(situacion, "YA CARGO UN ARCHIVO O TIENE EMPLEADOS CARGADOS, NO PUEDE CARGAR NUEVAMENTE");
					}
					 break;

				case 3: //si el usuario decide agregar un empleado sin cargar archivo, no podra cargar el archivo desp. Tiene que confirmar para poder avanzar
					if(ll_isEmpty(listaEmpleados)==1){
						analizarSituacion(situacion, "NO HA CARGADO UN ARCHIVO, SI CONTINUA NO PODRA CARGARLO MAS ADELANTE");
						rta = getChar("Desea continuar? s/n: ", 's', 'n', "Error. Desea continuar? s/n: ");
						if(rta=='s'){
							controller_addEmployee(listaEmpleados, id);
							id++;
						}else{
							break;
						}
					}else{
					controller_addEmployee(listaEmpleados, id);
					id++;
					}
					break;

				case 4:
					if(ll_isEmpty(listaEmpleados)==1){
					analizarSituacion(situacion, "NO HAY EMPLEADOS EN SISTEMA, POR FAVOR CARGUE UN ARCHIVO O UN EMPLEADO");
					}else {
					situacion = controller_editEmployee(listaEmpleados);
					analizarSituacion(situacion, "EMPLEADO MODIFICADO");
					}
					//controller_addEmployee(listaEmpleados, id);
					break;


				case 5:
					if(ll_isEmpty(listaEmpleados)==1){
					analizarSituacion(situacion, "NO HAY EMPLEADOS EN SISTEMA, POR FAVOR CARGUE UN ARCHIVO O UN EMPLEADO");
					}else {
					situacion = controller_removeEmployee(listaEmpleados);
					analizarSituacion(situacion, "EMPLEADO ELIMINADO");
					}
					break;


				case 6:
					if(ll_isEmpty(listaEmpleados)==1){
					analizarSituacion(situacion, "NO HAY EMPLEADOS EN SISTEMA, POR FAVOR CARGUE UN ARCHIVO O UN EMPLEADO");
					}else {
					situacion= controller_ListEmployee(listaEmpleados);
					analizarSituacion(situacion, "LISTADO INFORMADO");
					}
					break;

				case 7:
					if(ll_isEmpty(listaEmpleados)==1){
					analizarSituacion(situacion, "NO HAY EMPLEADOS EN SISTEMA, POR FAVOR CARGUE UN ARCHIVO O UN EMPLEADO");
					}else {
					situacion = controller_sortEmployee(listaEmpleados);
					analizarSituacion(situacion, "LISTADO ORDENADO");
					}
					break;

				case 8:
					situacion= controller_saveAsText("data2.csv",listaEmpleados); //cambie el path para no romper el data.csv
					analizarSituacion(situacion, "ARCHIVO DE TEXTO GUARDADO");
					break;

				case 9:
					situacion= controller_saveAsBinary("databin.csv",listaEmpleados); //cambie el path para no romper el data.csv
					analizarSituacion(situacion, "ARCHIVO BINARIO GUARDADO");
				   break;

				case 10:
					situacion=0;
					analizarSituacion(situacion, "GRACIAS POR UTILIZAR NUESTRO SISTEMA");
				   break;

			}

		printf("\n");
		system("pause");
		printf("\n\n");

		}while(opcion != 10);

    }

    return 0;
}
