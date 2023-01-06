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
		int getrow() { return row; }
		int getcol() { return col; }
	private:
		int row, col;
	};

	class Game{
	public:
		void Play();
		
	private:
		void EorL();						// 选择先手后手
		void Init();						// Play中调用
		void Show();						// 展示棋盘现状
		bool Checkover();					// 只需从lastpos开始检查是否结束即可
		Player *early, *late;
		std::vector<std::string> board;
		ChessPos *lastpos;					// 传入Player的ChessDown函数，以记录最后一次的落子位置
	};
}

#endif


