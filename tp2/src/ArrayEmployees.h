#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
int buscarLibre (Employee* list, int len);

int cargarEmpleado(Employee* list, int len, int id);

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

void getString(char palabra[], char texto[] );




int mostrarMenu(void);

int preguntarPrimeraCarga(int flag);




void mostrarUnEmployee(Employee list[], int index);

int mostrarEmployees(Employee list[], int len);





int cargarId (Employee list[], int len);



int findEmployeeById(Employee list[], int len, int idIngresadoPorUsuario);




int removeEmployee (Employee list[], int len, int id);

int modifyEmployee (Employee list[], int len, int id);


char* formatearNombres (Employee unEmpleado);


int modificarString(char texto[], Employee list[], int len, int id);

int modificarFlotante(char texto[], Employee list[], int len, int id);

int modificarEntero(char texto[], Employee list[], int len, int id);

void analizarSituacion (int situacion, char texto[]);

void sortEmployees(Employee* list, int len, int order);

void ordenarEmployeesPorId (Employee* list, int len);








int pedirleIdAlUsuario (Employee list[], int len);

int buscarId(Employee list[], int len, int idIngresadoPorUsuario);

int posicionDelId (Employee list[], int len, int id);




