#include "Game.h"
#include <iostream>

namespace MyGobang {
	void Game::init() {
		board = std::vector<std::string>(10, std::string(".........."));
		lastpos = nullptr;
		early->init();
		late->init();
	}

	void Game::play() {

	}

	bool Game::Checkover() {

	}

	void Game::show() {
		std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
		for (int i = 0; i < board.size(); i++) {
			std::cout << i << " ";
			for (const auto & ch : board[i]) {
				std::cout << ch << " ";
			}
			std::cout << std::endl;
		}
	}

}
