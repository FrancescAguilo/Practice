#include "Panel.h"

void Panel::insert(int position, Ball ball) {
	std::vector<Ball>::iterator it = panel.begin() + position;
	panel.emplace(it, ball);
}

int Panel::verifier(int position, Ball ball) {
	int cont, aux = 0;
	//se podria hacer con iterators
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

void Panel::deleteThree(int position) {
	std::vector<Ball>::iterator it = panel.begin() + position;
	panel.erase(it, it + 3);
	
}

void Panel::insertThree() {
	//inserto 3 bolas desplazando todo lo demas en 3 posiciones aleatorias del panel
	int pos;

	std::vector<Ball>::iterator it = panel.begin();
	Ball ball;
	for (int i = 0; i < 2; i++) {
		pos = rand() % panel.size();
		it = panel.begin() + pos;
		ball.color = static_cast<color> (rand() % 6);
		panel.emplace(it, ball);
	}
	
}