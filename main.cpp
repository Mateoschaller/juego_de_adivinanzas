#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
	
	//Le pedimos al usuario el rango de numeros limites, en el cual se encontrara el random number
	int min, max, max_intentos;
	cout << "Ingrese el rango de numeros y separados por un espacio (por ejemplo: 1 50)";
	cin >> min >> max;
	cout << "Ingrese la cantidad maxima de intentos: ";
	cin >> max_intentos;
	
	// Se validan los datos ingresados por el usuario
	if (min >= max || max_intentos <= 0) {
		cout << "Rango / cantidad de intentos incorrectos << endl";
		return 1;
	} 
	
	// Vamos a generar el random number dentro del rango que establecio el usuario al inicio del codigo
	srand(time(NULL));
	int numero_aleatorio = rand() % (max - min + 1) + min;
	
	// Variable para llevar la cuenta de los intentos llevados y los numeros ingresados
	int intentos = 0;
	vector<int> numeros_ingresados;
	
	// Comenzamos la logica del juego
	while (intentos < max_intentos) {
		// Se solicita un numero al usuario y luego lo validamos
		int numero_ingresado;
		cout << "Ingrese un numero: ";
		cin >> numero_ingresado;
		if (numero_ingresado < min || numero_ingresado > max) {
			cout << "Numero fuera de rango. " << endl;
			continue;
		}
		if (find(numeros_ingresados.begin(), numeros_ingresados.end(), numero_ingresado) != numeros_ingresados.end()) {
			cout << "Ya se ingreso este numero." << endl;
			continue;
		}
		numeros_ingresados.push_back(numero_ingresado);
		intentos++;
		
		// Se verifica si el numero ingresado por el usuario es el numero secreto
		if (numero_ingresado == numero_aleatorio) {
			cout << "Felicidades, usted adivino el numero!!" << endl;
			break;
		} else if (numero_ingresado < numero_aleatorio) {
			cout << "El numero ingresado es menor que el numero aleatorio." << endl;
		} else {
			cout << "El numero ingresado es mayor que el numero aleatorio." << endl;
		}
		
		// Aca mostraremos los numeros ignresados hasta el momento
		sort(numeros_ingresados.begin(), numeros_ingresados.end());
		cout << "Numeros ingresados hasta el momento: ";
		for (int i = 0; i < numeros_ingresados.size(); i++) {
			cout << numeros_ingresados[i] << " ";
		}
		cout << endl;
		
		// Vamos a mostrar los intentos llevados y restantes
		cout << "Intentos realizados hasta el momento: " << intentos << endl;
		cout << "Intentos restantes: " << max_intentos - intentos << endl;
		
	}
	
	// Si el usuario se queda sin intentos, a continuacion mostraremos el random number
	if (intentos == max_intentos) {
		cout << "Lo siento, se quedo sin intentos. El numero secreto era: " << numero_aleatorio << endl;
	}
	
	return 0;
	// Fin
	
}



