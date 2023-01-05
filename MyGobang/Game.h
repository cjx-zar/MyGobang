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

		void show(); // չʾ������״
		
	private:
		bool Checkover(); // ֻ���lastpos��ʼ����Ƿ��������
		Player *early, *late;
		std::vector<std::string> board;
		ChessPos *lastpos; // ����Player��ChessDown�������Լ�¼���һ�ε�����λ��
	};
}

#endif


