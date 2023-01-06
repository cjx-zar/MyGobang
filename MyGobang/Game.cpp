#include "Game.h"
#include "tools.h"
#include <iostream>
#include <string>
#include <vector>


namespace MyGobang {
	void Game::Play() {
		while (1) {						// 整个程序
			EorL();
			Init();
			while (1) {					// 一局游戏
				lastpos = early->ChessDown(board);
				Show();
				if (Checkover()) {
					std::cout << "Early hand win !" << std::endl;
					break;
				}

				lastpos = late->ChessDown(board);
				Show();
				if (Checkover()) {
					std::cout << "Late hand win !" << std::endl;
					break;
				}
			}
			std::cout << "Play again ? (input y for yes and other for no)" << std::endl;
			char ch;
			std::cin >> ch;
			if (ch != 'y') break;
		}
	}

	void Game::EorL() {
		std::cout << "Please enter 0/1 to select early hand(0) or late hand(1)." << std::endl;
		int eorl;
		while (1) {
			std::cin >> eorl;
			if (eorl == 0) {
				early = new Human(0);
				late = new AI(1);
				break;
			}
			else if (eorl == 1) {
				early = new AI(0);
				late = new Human(1);
				break;
			}
			else std::cout << "Input invalid ! Please input 0/1!" << std::endl;
		}

	}

	void Game::Init() {
		board = std::vector<std::string>(10, std::string(".........."));
		lastpos = nullptr;
	}

	void Game::Show() {
		std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
		for (int i = 0; i < board.size(); i++) {
			std::cout << i << " ";
			for (const auto & ch : board[i]) {
				std::cout << ch << " ";
			}
			std::cout << std::endl;
		}
	}

	bool Game::Checkover() {
		return MaxCountOneLine(board, lastpos->getrow(), lastpos->getcol(), board[lastpos->getrow()][lastpos->getcol()]) >= 5;
	}

}
