#include "Card.h"


Card::Card() {

}

Card::Card(Suit p, int v) {
	palo = p;
	valor = v;
}

bool Card::operator==(const Card& c2){
	if (palo == c2.palo && valor == c2.valor) {
		return true;
	}
	return false;
}

bool Card::Greater::operator()(const Card&c1, const Card& c2) {
	return c1.valor < c2.valor;
}