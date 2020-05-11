#include <stdio.h>
#include <string> 
#include <iostream>
#include <vector>
#include "Card.h"
#include "Player.h"
#include "Game.h"
#include<Windows.h>
#include <time.h>




void main() {
	srand(time(NULL));
	bool exit = false;
	Game game = Game();
	


	while (true) {
		std::cout << "Juego de cartas de Francesc Aguilo" << std::endl;
	
		if (GetKeyState(VK_ESCAPE)) {
			exit = true;
		}
	
		Sleep(20);
		system("CLS");
	};
	
}