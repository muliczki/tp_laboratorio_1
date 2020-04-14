//a) Calcular la suma (A+B)

float Sumar (float numero_uno, float numero_dos)
{
	float suma;
	suma = numero_uno + numero_dos;
	return suma;
}


//b) Calcular la resta (A-B)
float Restar (float numero_uno, float numero_dos)
{
	float resta;
	resta = numero_uno - numero_dos;
	return resta;
}

//c) Calcular la division (A/B)
float Dividir (float numero_uno, float numero_dos)
{
	float division;
	division = numero_uno / numero_dos;
	return division;
}

// d) Calcular la multiplicacion (A*B)
double Multiplicar (float numero_uno, float numero_dos)
{
	double multiplicacion;
	multiplicacion = numero_uno * numero_dos;
	return multiplicacion;
}


double Factorial (int numero)
{
	int i;
	int fractorial=1;

	for (i=numero; i>0; i--)
	{
		fractorial *= i;
	}
	return fractorial;
}
