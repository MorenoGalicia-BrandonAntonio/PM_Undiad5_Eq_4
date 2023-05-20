// pch.cpp: el archivo de código fuente correspondiente al encabezado precompilado
#include "pch.h"
// Cuando se utilizan encabezados precompilados, se requiere este archivo de código fuente para que la compilación se realice correctamente.

int __stdcall suma(int a, int b) {
	//data
	int resultado;

	_asm { //ensamblador inline

		mov eax, a
		add eax, b

		mov resultado, eax

	}

	return resultado;
}

int __stdcall largo_cadena(const char* str) {
	int len = strlen(str);
	return len;

}

int __stdcall escribir_cadena(char* str, int len_buffer) {
	const char* aux = "GARUCO"; //debe ser menor que len_buffer
	int len = strlen(aux);
	for (int i = 0; i < len; i++)
	{
		str[i] = aux[i];
	}
	return len;
}

int __stdcall PromedioDelUsuario(char*cadRes, char* nombre, int cal1, int cal2, int cal3) {
	//a nombre no se le hara nada en este programa

	int prom;
	int pDecimal;

	_asm {
		mov eax, 0
		add eax, cal1
		add eax, cal2
		add eax, cal3

		mov edx, 0
		mov ecx, 3
		div ecx

		mov pDecimal, edx
		mov prom, eax
	}
	prom += pDecimal / 3;
	
	int c = 0;
	const char* aux = " Tiens un Promedio de: ";

	//cadres = cadres + nombre
	//agrega a carRes el nombre dek akumno
	int len = strlen(nombre);
	for (int i = 0; i < len; i++) {
		cadRes[c] = nombre[i];
		c++;
	}

	//cadres = cadres + aux
	//agregar el contenido de axu a cadres
	len = strlen(aux);
	for (int i = 0; i < len; i++) {
		cadRes[c] = aux[i];
		c++;
	}
	
	//para combertir el aski en numeros
	//cadres = cadres + promedio
	if (prom == 10) {
		cadRes[c] = 49;
		c++;
	}
	else {
		cadRes[c] = prom + 49;
	}
	//en aski 48 es 0, 49 es 1, asi susesivamente

	c++; // retorna la cantidad de caracteres de la palabra
	return c;
	// como actividad intentar una variacion del codigo para el martes
}

/*
int __stdcall Velocidad(char* cadRes, char* nombre, int distancia, int tiempo) {

	int velocidad;
	int pDecimal;

	_asm {
		mov eax, distancia
		mov ebx, tiempo 

		mov edx, 0

		div ebx // eax / ebx => distancia timepo

		mov pDecimal, edx
		mov velocidad, eax 
	}

	// velociadad += pDecimal / tiempo;

	int c = 0;

	int len = strlen(nombre);
	for (int i = 0; i < len; i++)
	{
		cadRes[c] = nombre[i];
		c++;
	}

	const char* aux = " Tiene una Velocidad de: "; //debe ser menor que len_buffer
	//cadREs = cadRes + aux
	//ingresar el contenido de aux a cadRes...
	len = strlen(aux);
	for (int i = 0; i < len; i++)
	{
		cadRes[c] = nombre[i];
		c++;
	}

	//buscar cuantos digitos tiene la variable
	int auxVelocidad = velocidad;
	int cont;
	while (auxVelocidad >= 10) {
		auxVelocidad /= 10;
		cont++;
	}

	if (cont >= 1) {
		int div = 10;
		for (int i = 0; i < cont; i++)
		{
			div = div * 10;
		}
		while (velocidad > 10)
		{
			int t = velocidad / div;
			cadRes[c] = t + 48;
			c++;
			velocidad = velocidad % div;
		}
		cadRes[c] = velocidad + 48;
		c++;
	}
	else {
		cadRes[c] = velocidad + 48;
		c++;
	}

	
	return c;
}
*/

int __stdcall velocidad(char* cadRes, char* nombre, int distancia, int tiempo) {
	//velocidad = ditancia / tiempo

	int velocidad;
	int pDecimal;

	_asm {
		mov eax, distancia
		mov ebx, tiempo

		mov edx, 0

		div ebx // eax / edx => distancia / tiempo

		mov pDecimal, edx
		mov velocidad, eax
	}

	//velocidad += pDecimal / tiempo;

	int c = 0; //inicio de la cadena resultado     

	c += addCadena2Cadena(cadRes, c, nombre);

	const char* aux = " tiene una velociad de: "; //debe ser menor que len_buffer
	c += addCadena2Cadena(cadRes, c, aux);

	//Params: cadena en la que se concatenara, posicion de inicio del numero, numero a concatenar 
	c += addNum2Cadena(cadRes, c, velocidad);
	//retorna la cantidad de caracteres en la palabra ...

	return c;
}

int __stdcall addCadena2Cadena(char* cadRes, int indice, const char* cadena) {

	int len = strlen(cadena);

	for (int i = 0; i < len; i++) //recorre cada caracter del nombre del carrito
	{
		cadRes[indice] = cadena[i];
		indice++;
	} return len;
}

int __stdcall addNum2Cadena(char* cadRes, int indice, int numero) {
	//buscar cuantos digitos tiene la variables

	int tempNumero = numero;
	int cont = 0; //almacena el total de digitos-1

	while (tempNumero >= 10) {
		tempNumero /= 10;
		cont++;
	}

	//X  = 1
	//XX =  10
	//XXX = 100
	//XXXX = 1000

	if (cont >= 1) { //se entra solo cuando son dos o mas digitos los que componen al numero
		int div = 10;

		for (int i = 0; i < cont - 1; i++) { //busca encontrar al divisor
			div = div * 10;
		}
		
		while (numero > 10) { //obtener el digito mas a la izquierda ... 
			int t = numero / div;
			cadRes[indice] = t + 48;
			indice++;
			numero = numero % div;
			div = div / 10;
		}
		cadRes[indice] = numero + 48;
		indice++;

	}
	else { //con  = 0
		cadRes[indice] = numero + 48;
		indice++;
	}

	return cont + 1;
}

/*
int __stdcall compararNumeros(char* cadRes, char* nombre, int numero1, int numero2, int totdigitos) {
	
	//comparar digito a digito 

	totdigitos = -1;
	int divisor = 0;

	_asm {
		//numero1 se queda en memoria
		mov ebx, numero2

		//mov ecx, totdigitos

		cmp totdigitos, 1
		jnle continuar

		mov ecx, totdigitos
		mov ebx, 10
		mov eax, 10
		ciclo:
			mul ebx 	
		inc ecx
		cmp ecx, totdigitos
		jl ciclo

		continuar:
		mov divisor, eax 
		
	}

	return divisor;

	//velocidad += pDecimal / tiempo;

	int c = 0; //inicio de la cadena resultado     

	c += addCadena2Cadena(cadRes, c, nombre);

	const char* aux = " tiene una velociad de: "; //debe ser menor que len_buffer
	c += addCadena2Cadena(cadRes, c, aux);

	//Params: cadena en la que se concatenara, posicion de inicio del numero, numero a concatenar 
	//c += addNum2Cadena(cadRes, c, velocidad);
	//retorna la cantidad de caracteres en la palabra ...

	//return c;
}
*/

int __stdcall SumaNumerosVector(char* cadRes, char* nombre, int vector) {
	
	int c = 0;

	_asm {
		mov ebx, vector //almacena la ubicacion de la memoria del cector (donde se inicia)
		mov edx, esi //respaldo de la posicion de inicio del vector

		//como es neustro vector la primera posicion en cuantos elemenos tenemos . entonces
		//se mueve a ecx, la primera posicion  para obtener la
		mov ecx, dword ptr[esi] //cantidad de elemento que tiene el arreglo

		//la primera posicion activa util para el vector es la tercesa posicion
		//como empiesa en 0, la tercera posicion es como sumarle a 8 la primera posicion
		// 0 = primera, 4 = segunda posicion, 8 = tercera posicio
		add esi, 4 //apartir de aqui operar con el arreglo

		//se va a usar a eax, como contador, entonces por eso se inicializa en 0
		mov eax, 0

		//inicia el ciclo
		ciclo:
			add eax, dword ptr[esi + 8] //obtiene el valor de la posicion actual de apuntador
			add esi, 4 //se le suma 4 a esi, porque cada elemento en el vector se separa por 4 bytes
			loop ciclo //repite el acceso al vector para realizar la suma de la cantidad de elemtnos "activos"

		//a la posicion de origen respaldada (edi) se le esta sumando 4, para acceder a la segunda posicion del vector
		//asociada si acumalador una vez en esta posicion se almacena en ella la suma de los digitos del vector
		mov dword ptr[edi+4], eax 
	}

	return vector;
}