#include <stdio.h>
#include <string> 
#include <random>
#include <iostream>
#include <time.h>

enum Movement { UP, DOWN, LEFT, RIGHT };
enum Types { NONE, ROCK, COIN, PLAYER };

const int NUM_ROWS = 10;
const int NUM_COLUMNS = 10;
const int rocksPerCent = 20;
const int coinsPerCent = 30;

struct vector2 {
	int x;
	int y;
};

struct Player {
	vector2 position;
	int score;
	void addScore() {
		score++;
	}
	void setPos(vector2 newPos) {
		position = newPos;
	}

};

struct Board {
	Types type;
	//preguntar si meter las funciones que conciernen la board aqui para no llevarlo a remolque o si hacemos clase y no struct

};

void initializeBoard(Board board[NUM_ROWS][NUM_COLUMNS]) {
	int maxRocks = ((NUM_COLUMNS * NUM_ROWS) / 100) * rocksPerCent;
	int maxCoins = ((NUM_COLUMNS * NUM_ROWS) / 100) * coinsPerCent;

	//Puede que haya menos del % indicado en caso de que se repita
	//ya que no miramos si antes habia algo alli 
	for (int i = 0; i < maxRocks; i++) {
		board[rand() % NUM_ROWS][rand() % NUM_COLUMNS].type = ROCK;
	}

	for (int i = 0; i < maxCoins; i++) {
		board[rand() % NUM_ROWS][rand() % NUM_COLUMNS].type = COIN;
	}
	
	board[rand() % NUM_ROWS][rand() % NUM_COLUMNS].type = PLAYER;
	
}

bool checkMovement(Board board[NUM_ROWS][NUM_COLUMNS], vector2 v, Movement mov) {

	switch (mov)
	{
	case UP:
		return(board[v.x][v.y - 1].type != ROCK && v.y > 0);
	case DOWN:
		return(board[v.x][v.y + 1].type != ROCK && v.y < NUM_COLUMNS);
	case LEFT:
		return(board[v.x - 1][v.y].type != ROCK && v.x > 0);
	case RIGHT:
		return(board[v.x + 1][v.y].type != ROCK && v.x < NUM_ROWS);
	default:
		break;
	}
	
}

bool existCoin(Board board[NUM_ROWS][NUM_COLUMNS], Player p, Movement mov) {

	switch (mov)
	{
	case UP:
		return(board[p.position.x][p.position.y - 1].type == COIN);
	case DOWN:
		return(board[p.position.x][p.position.y + 1].type == COIN);
	case LEFT:
		return(board[p.position.x - 1][p.position.y].type == COIN);
	case RIGHT:
		return(board[p.position.x + 1][p.position.y].type == COIN);
	default:
		return false;
	}
}

void movePlayer(Board board[NUM_ROWS][NUM_COLUMNS], Player p, Movement mov) {
	
	switch (mov)//es mas correcto break o return void?
	{
	case UP:
		p.setPos(vector2{ p.position.x, p.position.y - 1 });
		return;
	case DOWN:
		p.setPos(vector2{ p.position.x, p.position.y + 1 });
		return;
	case LEFT:
		p.setPos(vector2{ p.position.x - 1, p.position.y });
		return;
	case RIGHT:
		p.setPos(vector2{ p.position.x + 1, p.position.y });
		return;
	default:
		return;
	}

}

bool gameOver(Board board[NUM_ROWS][NUM_COLUMNS]) {

	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			if (board[i][j].type == COIN) {
				return false; //No termina porque quedan monedas
			}
		}
	}
	return true;
}

void printBoard(Board board[NUM_ROWS][NUM_COLUMNS]) {
	for (int i = 0; i < NUM_ROWS; i++) {
		std::cout << "|";
		for (int j = 0; j < NUM_COLUMNS; j++) {

			if (board[i][j].type == ROCK) {
				std::cout << "*";
			}
			else if (board[i][j].type == COIN) {
				std::cout << "$";
			}
			else if (board[i][j].type == PLAYER) {
				std::cout << "P";
			}
			else{
				std::cout << "0";
			}
			std::cout << "|";
		}
		std::cout << std::endl;
	}
}

void play(Board board[NUM_ROWS][NUM_COLUMNS], Player p, Movement mov) {
	if (checkMovement(board, p.position, mov)) {
		if (existCoin(board, p, mov)) {
			p.addScore();
			movePlayer(board, p, mov);
		}
	}
}


void main() {
	srand(time(NULL));
	Player p;
	Board board[NUM_ROWS][NUM_COLUMNS];
	std::string aux;

	initializeBoard(board);
	printBoard(board);

	/*do {
		std::cout << "Move: ";
		std::cin >> aux;
		play(board, p, aux);


		printBoard(board);
		system("CLS");
	} while (aux != "q");*/

	system("PAUSE");
}