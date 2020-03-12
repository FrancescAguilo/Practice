#include <stdio.h>
#include <string> 
#include <random>
#include <iostream>
#include <time.h>

enum color { RED, BLUE, YELLOW, GREEN , WHITE, BLACK};

struct Ball {
	color color;
};

//Si haces resize para hacer la array mas pequeña a pelo, la funcion dejara
//de copiar valores cuando el size nuevo llegue al maximo perdiendo todo lo siguiente
Ball* resize(int size, Ball* gunCharger) {
	Ball* tmp = gunCharger; //guardamos
	gunCharger = nullptr; //vaciamos
	gunCharger = new Ball[size]; //creamos
	for (int i = 0; i < size; i++) { //copiamos del principio para adelante
		gunCharger[i] = tmp[i];
	}
	return gunCharger;
}
//Igual que el resize pero en lugar de cargarse lo ultimo se carga lo primero hasta caber
Ball* inverseResize(int size, Ball* gunCharger) {
	Ball* tmp = gunCharger; //guardamos
	gunCharger = nullptr; //vaciamos
	gunCharger = new Ball[size]; //creamos
	for (int i = size; i > 0; i--) { //copiamos del final para atras
		gunCharger[i] = tmp[i];
	}
	return gunCharger;
}

struct Panel {
	Ball *panel; 
	int size;

	void init() {
		//hacer cin para leerlo
		panel = new Ball[size];
	}

	void insert(int position, Ball ball) {
		Ball *tmp;
		//Hacenos resize para que quepa
		size += 1;
		panel = resize(size, panel);

		//Movemos todo para dejar el hueco:

		//Ponemos el contador al final, situamos el tmp a uno menos 
		//y vamos moviendo los datos una casillla a la derecha
		//hasta llegar a position (incluida) para despues meter 
		//lo que queremos sin importar lo que habia
		for (int i = size; i > position; i--) {
			tmp = &panel[i - 1];
			panel[i] = *tmp;
		}
		//Metemos el data
		panel[position] = ball;
	}

	int verifier(int position, Ball ball) {
		int cont, aux = 0;
		//compara la que nos dan, si con la que comprara es igual suma 1 al contador
		//en el momento en que el contador sume 3 lo retorna
		//si no es del mismo color vuelve a setear el cont a 0
		for (int i = position - 2; i < position + 2; i++) {
			if (panel[i].color == ball.color) {
				if (cont == 3) {
					return cont;
				}
				if (cont == 0) {
					aux = i;
				}
				cont++;
			}
			else {
				cont = 0;
			}
		}

		return -1; //retorna -1 si no hay 3 seguidas
	}

	void deleteThree(int position) {
		//(resize especial) 
		Ball *tmp = panel;
		panel = nullptr;
		size -= 3;
		panel = new Ball[size];
		int i, j = 0;

		//el contador j va en la array anterior mientras que el i en la actual
		//al encontrar las tres bolas que no queremos, saltamos los tres espacios
		//en la anterior array mientras que el contador de la nueva sigue igual
		//y van parejos en relacion 3 posiciones a uno despues de encontrarlas
		do {
			if (i == position) {
				j += 3;
			}

			panel[i] = tmp[j];
			i++;
			j++;
		} while (i < size);
	}

	void insertThree() {//suponemos que las inserta al final
		size += 3;
		panel = resize(size, panel);
		//hacemos resize para que nos de una array dinamica igual 
		//pero con 3 espacios mas al final
		//simplemente a los 3 espacios del final les damos color rand
		for (int i = size - 3; i < size; i++) {
			panel[i].color = static_cast<color> (rand() % 6);
		}
	}
};

struct Player {
	std::string name;
	int score;

	struct Gun {
		Ball *position; //donde apunta 
		int pos;//mirate esto bro

		Ball *gunCharger; //cargador
		int chargerSize; 

		Ball shoot() {
			//Nos guardamos lo que vamos a eliminar para poder retornarlo despues
			//Hacemos el resize inverso para que el for se salte la primera
			//posicion y no la ultima como haria en condiciones normales
			//retornamos el valor removed
			Ball aux = gunCharger[0];
			gunCharger = inverseResize(chargerSize - 1, gunCharger);
			return aux;
		}

	};

	Gun gun;
};


void init(std::string name, int position) {
	Player player;
	player.name = name;
	player.gun.pos = position;//deberia ser asi?
	player.score = 0;
	player.gun.chargerSize = 20;
	player.gun.gunCharger = new Ball[player.gun.chargerSize];
	for (int i = 0; i < 20; i++) {
		player.gun.gunCharger[i].color = static_cast<color> (rand() % 6);
	}
}

void main() {
	do {
		init("fran", 4);

		system("CLS");
	} while (true);

}