
/**a) Calcular la suma (A+B)
 * Sumar: realiza la suma de dos numeros float
 *
 * par1: 1er numero float
 * par2: 2do numero float
 *
 * return: la suma en numero float
 *
 */
float Sumar (float numero_uno, float numero_dos)
{
	float suma;
	suma = numero_uno + numero_dos;
	return suma;
}

//------------------------------------------------------------------------

/**b) Calcular la resta (A-B)
 * Restar: realiza la resta de dos numeros float
 *
 * par1: 1er numero float
 * par2: 2do numero float
 *
 * return: la resta en numero float
 *
 */
float Restar (float numero_uno, float numero_dos)
{
	float resta;
	resta = numero_uno - numero_dos;
	return resta;
}

//------------------------------------------------------------------------

//
/**c) Calcular la division (A/B)
 * Dividir: realiza la division de dos numeros float
 *
 * par1: 1er numero float (dividendo)
 * par2: 2do numero float (divisor)
 *
 * return: la division en numero float
 *
 */
float Dividir (float numero_uno, float numero_dos)
{
	float division;
	division = numero_uno / numero_dos;
	return division;
}

//------------------------------------------------------------------------


/**d) Calcular la multiplicacion (A*B)
 * Multiplicar: realiza la multiplicacion de dos numeros float
 *
 * par1: 1er numero float
 * par2: 2do numero float
 *
 * return: el producto en numero DOUBLE
 *
 */
double Multiplicar (float numero_uno, float numero_dos)
{
	double multiplicacion;
	multiplicacion = numero_uno * numero_dos;
	return multiplicacion;
}


//------------------------------------------------------------------------


/**e) Calcular el factorial (A!)
 * Factorial: realiza el factorial de UN NUMERO INT
 *
 * par1: UN numero INT
 *
 * return: el FACTORIAL en numero DOUBLE
 *
 */
double Factorial (int numero)
{
	double i;
	double fractorial=1;

	for (i=numero; i>0; i--)
	{
		fractorial *= i;
	}
	return fractorial;
}
