#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0
#define HARD 5


typedef struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
} Employee;



int hardcodear(Employee list[], int len);

int mostrarMenu(void);

int preguntarPrimeraCarga(int flag);

int initEmployees(Employee list[], int len);

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

Employee cargarUnEmployee(Employee list[], int len);

int cargarId (Employee list[], int len);

void mostrarUnEmployee(Employee list[], int i);

void mostrarEmployees(Employee list[], int len);

int buscarID(Employee list[], int len, int id);

int removeEmployee (Employee list[], int len, int id);

int modifyEmployee (Employee list[], int len, int id);


char* formatearNombres (Employee unEmpleado);

int pedirUnId (char texto[], Employee list[], int len);

int modificarString(char texto[], Employee list[], int len, int id);

int modificarFlotante(char texto[], Employee list[], int len, int id);

int modificarEntero(char texto[], Employee list[], int len, int id);

void analizarSituacion (int situacion, char texto[]);

void sortEmployees(Employee* list, int len, int order);
