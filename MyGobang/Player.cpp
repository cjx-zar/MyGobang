#include "Player.h"
#include "Game.h"
#include "tools.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

namespace MyGobang {
	ChessPos* AI::ChessDown(std::vector<std::string>& board) {
		ChessPos *pos = thinking(board);
		board[pos->getrow()][pos->getcol()] = eorl ? 'X' : 'O';
		return pos;
	}

	ChessPos* AI::thinking(const std::vector<std::string>& board) {
		int x, y, curmax = -1;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				int a = MaxCountOneLine(board, i, j, eorl ? 'X' : 'O');		//放置自己的颜色
				int b = MaxCountOneLine(board, i, j, eorl ? 'O' : 'X');		//放置对手的颜色
				int cur = std::max(score[2 * a - 1], score[2 * b - 2]);
				if (cur > curmax) {
					curmax = cur;
					x = i;
					y = j;
				}
			}
		}
		return new ChessPos(x, y);
	}

	ChessPos* Human::ChessDown(std::vector<std::string>& board) {
		std::cout << "Please input your chessdown row and col (seperate by space)" << std::endl;
		int row, col;
		while (1) {					//输入直到合法
			std::cin >> row >> col;
			if (row < 0 || row>9 || col < 0 || col>9) std::cout << "Invalid position ! Chess again !" << std::endl;
			else if (board[row][col] != '.') std::cout << "Position is not empty ! Chess again !" << std::endl;
			else {
				board[row][col] = eorl ? 'X' : 'O';
				break;
			}
		}
		return new ChessPos(row, col);
	}
}