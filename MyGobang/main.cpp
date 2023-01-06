#include <iostream>
#include "Game.h"

using namespace MyGobang;

int main() {
	std::cout << "Welcome to Czar's Gobang Game !!!" << std::endl;
	Game *game = new Game();
	game->Play();
	return 0;
}

