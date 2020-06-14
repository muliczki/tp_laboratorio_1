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
				//cambie los paths porque bajo un mismo nombre, si una ejecucion lo guarda en binario por ej, y la proxima lo quiero leer en texto, lee vacio
				//asi como esta, me deja leer en binario/texto y puedo guardar en cualquiera de los dos formatos ( ejemplo leo texto y lo guardo en binario)

				case 1: //puedo leer archivo SOLO cuando la lista este vacia, para no duplicar datos
					if(ll_isEmpty(listaEmpleados)==1){
					situacion= controller_loadFromText("data2.csv",listaEmpleados); //PARA EJECUTAR POR CONSOLA ECLIPSE
					//situacion= controller_loadFromText("../data2.csv",listaEmpleados); //PARA EJECUTAR DESDE .EXE EN CARPETA DEBUG
					analizarSituacion(situacion, "ARCHIVO DE TEXTO CARGADO");
					id = buscarIdSinUso(listaEmpleados); //busca el id maximo en el archivo y me devuelve el primer id sin uso
					}else {
						analizarSituacion(0, "YA CARGO UN ARCHIVO O TIENE EMPLEADOS CARGADOS, NO PUEDE CARGAR NUEVAMENTE"); // 0 opcion para que printee el paramentro
					}
					break;

				case 2: //puedo leer archivo SOLO cuando la lista este vacia, para no duplicar datos
					if(ll_isEmpty(listaEmpleados)==1){
					situacion= controller_loadFromBinary("databin.csv",listaEmpleados); //PARA EJECUTAR POR CONSOLA ECLIPSE
					//situacion= controller_loadFromBinary("../databin.csv",listaEmpleados); //PARA EJECUTAR DESDE .EXE EN CARPETA DEBUG
					analizarSituacion(situacion, "ARCHIVO BINARIO CARGADO");
					id = buscarIdSinUso(listaEmpleados); //busca el id maximo en el archivo y me devuelve el primer id sin uso
					} else {
						analizarSituacion(0, "YA CARGO UN ARCHIVO O TIENE EMPLEADOS CARGADOS, NO PUEDE CARGAR NUEVAMENTE"); // 0 opcion para que printee el paramentro
					}
					 break;

				case 3: //si el usuario decide agregar un empleado sin cargar archivo, no podra cargar el archivo desp. Tiene que confirmar para poder avanzar
					if(ll_isEmpty(listaEmpleados)==1){
						analizarSituacion(0, "NO HA CARGADO UN ARCHIVO, SI CONTINUA NO PODRA CARGARLO MAS ADELANTE"); // 0 opcion para que printee el paramentro
						rta = getChar("Desea continuar? s/n: ", 's', 'n', "Error. Desea continuar? s/n: ");
						if(rta=='s'){
							controller_addEmployee(listaEmpleados, id);
							id++;
						}else{
							break;
						}
					}else{
					controller_addEmployee(listaEmpleados, id);
					id++; //id autoincremental
					}
					break;

				case 4:
					if(ll_isEmpty(listaEmpleados)==1){
					analizarSituacion(0, "NO HAY EMPLEADOS EN SISTEMA, POR FAVOR CARGUE UN ARCHIVO O UN EMPLEADO"); // 0 opcion para que printee el paramentro
					}else {
					situacion = controller_editEmployee(listaEmpleados);
					analizarSituacion(situacion, "EMPLEADO MODIFICADO");
					}
					break;


				case 5:
					if(ll_isEmpty(listaEmpleados)==1){
					analizarSituacion(0, "NO HAY EMPLEADOS EN SISTEMA, POR FAVOR CARGUE UN ARCHIVO O UN EMPLEADO"); // 0 opcion para que printee el paramentro
					}else {
					situacion = controller_removeEmployee(listaEmpleados);
					analizarSituacion(situacion, "EMPLEADO ELIMINADO");
					}
					break;


				case 6:
					if(ll_isEmpty(listaEmpleados)==1){
					analizarSituacion(0, "NO HAY EMPLEADOS EN SISTEMA, POR FAVOR CARGUE UN ARCHIVO O UN EMPLEADO"); // 0 opcion para que printee el paramentro
					}else {
					situacion= controller_ListEmployee(listaEmpleados);
					analizarSituacion(situacion, "LISTADO INFORMADO");
					}
					break;

				case 7:
					if(ll_isEmpty(listaEmpleados)==1){
					analizarSituacion(0, "NO HAY EMPLEADOS EN SISTEMA, POR FAVOR CARGUE UN ARCHIVO O UN EMPLEADO"); // 0 opcion para que printee el paramentro
					}else {
					situacion = controller_sortEmployee(listaEmpleados);
					analizarSituacion(situacion, "LISTADO ORDENADO");
					}
					break;

				case 8:
					if(ll_isEmpty(listaEmpleados)==1){
					analizarSituacion(0, "NO HAY EMPLEADOS EN SISTEMA, POR FAVOR CARGUE UN ARCHIVO O UN EMPLEADO"); // 0 opcion para que printee el paramentro
					}else {
					situacion= controller_saveAsText("data2.csv",listaEmpleados); //cambie el path para no romper el data.csv
					analizarSituacion(situacion, "ARCHIVO DE TEXTO GUARDADO");
					}
					break;

				case 9:
					if(ll_isEmpty(listaEmpleados)==1){
					analizarSituacion(0, "NO HAY EMPLEADOS EN SISTEMA, POR FAVOR CARGUE UN ARCHIVO O UN EMPLEADO"); // 0 opcion para que printee el paramentro
					}else {
					situacion= controller_saveAsBinary("databin.csv",listaEmpleados); //cambie el path para no romper el data.csv
					analizarSituacion(situacion, "ARCHIVO BINARIO GUARDADO");
					}
				   break;

				case 10:
					analizarSituacion(0, "GRACIAS POR UTILIZAR NUESTRO SISTEMA"); // 0 opcion para que printee el paramentro
				   break;

			}

		printf("\n");
		system("pause");
		printf("\n\n");

		}while(opcion != 10);

    }

    return 0;
}
