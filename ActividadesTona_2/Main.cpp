#include <stdio.h>
#include <string> 
#include <random>
#include <iostream>
#include <time.h>

#define MAX_ENEMIES 5
enum Enemytype { ZOMBIE, VAMPIRE, GHOST, WITCH };

struct Enemy {
	Enemytype type;
	std::string name;
	int health;
};

bool equalEnemies(Enemy e1, Enemy e2) {
	if (e1.name == e2.name && e1.type == e2.type) {
		return true;
	}
	else {
		return false;
	}
}

Enemy createRandomEnemy() {
	Enemytype enumType[] = { ZOMBIE, VAMPIRE, GHOST, WITCH }; 
	std::string names[] = { "jose", "miguel", "antonio","paco" };

	Enemy e1;
	e1.name = names[rand() % 4];
	e1.type = enumType[rand() % 4];
	e1.health = rand() % 100 + 1;

	return e1;
}

std::string getEnemyTypeString(Enemytype eT) {
	Enemytype enumType[] = { ZOMBIE, VAMPIRE, GHOST, WITCH };
	std::string names[] = { "ZOMBIE", "VAMPIRE", "GHOST","WITCH" };

	switch (eT)
	{
	case ZOMBIE:
		return "ZOMBIE";
		break;
	case VAMPIRE:
		return "VAMPIRE";
		break;
	case GHOST:
		return "GHOST";
		break;
	case WITCH:
		return "WITCH";
		break;
	default:
		return "NULL";
		break;
	}
}

void main() {
	srand(time(NULL));
	Enemy enemies[MAX_ENEMIES];
	int i = 0;

	while(i < MAX_ENEMIES) {
		enemies[i] = createRandomEnemy();
		for (int j = 0; j < i; j++) {
			if (equalEnemies(enemies[i], enemies[j])) {
				i--;
			}
		}
		i++;
	}

	for (int i = 0; i < MAX_ENEMIES; i++) {
		std::cout << enemies[i].name << " / " << getEnemyTypeString(enemies[i].type) << " / " << enemies[i].health << std::endl;
	}
	system("pause");
}