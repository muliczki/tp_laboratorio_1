

typedef struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
} Employee;


int initEmployees(Employee list[], int len);

Employee cargarUnEmployee(Employee list[], int len);

int cargarId (Employee list[], int len);

void mostrarUnEmployee(Employee list[], int i);

void mostrarEmployees(Employee list[], int len);
