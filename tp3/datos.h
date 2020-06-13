#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DATOS_H_
#define DATOS_H_


int mostrarMenu(void);

void analizarSituacion (int situacion, char texto[]);

char getChar (char* texto, char opcion1, char opcion2, char* error);
void getString (char* string ,char* texto, char* error);
void getInt (int* entero ,char* texto, int minimo, int maximo, char* error);
void formatearString(char* string);


#endif /* DATOS_H_ */
