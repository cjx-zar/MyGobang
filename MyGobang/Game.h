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
		void EorL();						// ѡ�����ֺ���
		void Init();						// Play�е���
		void Show();						// չʾ������״
		bool Checkover();					// ֻ���lastpos��ʼ����Ƿ��������
		Player *early, *late;
		std::vector<std::string> board;
		ChessPos *lastpos;					// ����Player��ChessDown�������Լ�¼���һ�ε�����λ��
	};
}

#endif


