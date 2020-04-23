#include "Game.h"
#include <time.h>


Game::Game() {
	//names
	srand(time(NULL));
	std::vector<std::string> names = { "Jose", "Maria", "Aina", "Paco", "Alex", "Martin" };
	p1.id = names[rand() % names.size()];
	p2.id = names[rand() % names.size()];
	p3.id = names[rand() % names.size()];
	p4.id = names[rand() % names.size()];

	//create cards 
	Card tmp;
	std::vector<Card> vTmp;
	int aux;
	for (int i = 0; i < 4; i++) {//palos
		tmp.palo = (Suit)i;
		for (int j = 1; j <= 12; j++) {//valor
			tmp.valor = j;
			vTmp.push_back(tmp);
		}
	}
	for (int i = 0; i < vTmp.size(); i++) {
		aux = rand() % vTmp.size();//creamos un  indice aleatorio
		deck.push(vTmp[aux]);//metemos ese en la stack del mazo
		vTmp.erase(vTmp.begin() + aux);//deleteamos esa posicion del vector auxiliar
	}

	//distribute
	for (int i = 0; i < 7; i++) {
		p1.hand.push(deck.top());
		deck.pop();

		p2.hand.push(deck.top());
		deck.pop();

		p3.hand.push(deck.top());
		deck.pop();

		p4.hand.push(deck.top());
		deck.pop();
	}

}

Card Game::GetNewCard() {
	Card tmp = deck.top();
	deck.pop();
	return tmp;
}

void Game::DiscardeCard(Card c) {
	discarted.push(c);
}

void Game::PrintDiscarded() {
	std::cout << discarted.top().palo << "/" << discarted.top().valor << std::endl;
}