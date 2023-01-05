#ifndef __MYGOBANG_GAME_H__
#define __MYGOBANG_GAME_H__
#include "Player.h"
#include <vector>
#include <string>

namespace MyGobang {
	class ChessPos {
	public:
		ChessPos(int x, int y) : row(x), col(y) {}
		ChessPos() : row(-1), col(-1) {}
	private:
		int row, col;
	};


	class Game{
	public:
		Game(Player *e, Player *l) : early(e), late(e) { init(); }
		void play();

		void replay() {
			init();
			play();
		}

		void init();

		void show(); // 展示棋盘现状
		
	private:
		bool Checkover(); // 只需从lastpos开始检查是否结束即可
		Player *early, *late;
		std::vector<std::string> board;
		ChessPos *lastpos; // 传入Player的ChessDown函数，以记录最后一次的落子位置
	};
}

#endif


