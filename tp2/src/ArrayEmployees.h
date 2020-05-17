#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define UP 1
#define DOWN 0
#define TRUE 1
#define FALSE 0



struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
} typedef Employee;



// inicializo en cero

int initEmployees(Employee list[], int len);

// hardcodeo datos en el array para testear

int hardcodear(Employee list[], int len);

// agregar empleados

int cargarEmpleado(Employee* list, int len, int id);

	int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

		int buscarLibre (Employee* list, int len);

		void getString(char palabra[], char texto[] );


// funciones varias del main

int mostrarMenu(void);

int preguntarPrimeraCarga(int flag);

void analizarSituacion (int situacion, char texto[]);



// mostrar empleados

int mostrarEmployees(Employee list[], int len);

	void mostrarUnEmployee(Employee list[], int index);


// funciones vinculadas al id

int pedirleIdAlUsuario (Employee list[], int len, char texto[]);

int findEmployeeById(Employee list[], int len, int idIngresadoPorUsuario);



// funciones de remover y modificar

int removeEmployee (Employee list[], int len, int id);

int modifyEmployee (Employee list[], int len, int id);

	int modificarString(char texto[], Employee list[], int len, int id);

	int modificarFlotante(char texto[], Employee list[], int len, int id);

	int modificarEntero(char texto[], Employee list[], int len, int id);



// ordenar array

int sortEmployees(Employee* list, int len, int order);

void ordenarEmployeesPorId (Employee* list, int len);


// calcular estadisticas y mostrar

int obtenerCantidadEmpleados (Employee* list, int len);

float obtenerTotalSueldos (Employee* list, int len);

float promediarSueldos (float totalSueldos, int cantidadEmpleados);

int contarEmpleadosMayorAlPromedio (Employee* list, int len, float promedioSueldos);

void mostrarEstadisticas (Employee* list, int len);




