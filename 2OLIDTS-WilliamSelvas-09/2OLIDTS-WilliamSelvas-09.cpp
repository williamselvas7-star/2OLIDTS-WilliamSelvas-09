// 2OLIDTS-WilliamSelvas-09.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#define MaxTamC 10

typedef int TipoDato;

using namespace std;

int main(){

	int frente = 0, final = 0;
	TipoDato A[MaxTamC];
	int contador = 0;

	// Inicializar la cola 
	frente = 0;
	final = 0;

	cout << " Desea agregar elementos a la cola? (s/n): ";
	char respuesta;
	cin >> respuesta;

	while ((respuesta == 's' || respuesta == 'S') && contador < 10) {
		if ((final + 1) % MaxTamC == frente) {
			cout << "Desbordamiento de la cola" << endl;
			return 1;
		}

		cout << "Ingrese un elemento para la cola: ";
		TipoDato elemento;
		cin >> elemento;
		
		final = (final + 1) % MaxTamC;
		A[final] = elemento;

		contador++;
		cout << "Elemento " << contador << " agregado a la cola: " << elemento << endl;

		if (contador < 10) {
			cout << "Desea agregar mas elementos a la cola? (s/n): ";
			cin >> respuesta;
		}
	}

	// Validar si la cola está vacía
	if (frente == final) {
		cout << "La cola esta vacía. " << endl;
		return 1;
	}

	// Obtener el primer elemento de la cola 
	TipoDato primerElemento = A[(frente + 1) & MaxTamC];
	cout << "El primer elemento de la cola es: " << primerElemento << endl;

	//Elimina un elemento de la cola 
	frente = (frente + 1) % MaxTamC;

	//Imprimir elemento de la cola en el orden en que fueron ingresados
	cout << "Elementos  de la cola en el orden de ingreso: " << endl;
	for (int i = frente + 1; i <= final; i = (i + 1) % MaxTamC) {
		cout << A[i] << ""; 
	}

	cout << endl;
	
	return 0;
}
