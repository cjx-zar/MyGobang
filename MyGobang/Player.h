#ifndef __MYGOBANG_PLAYER_H__
#define __MYGOBANG_PLAYER_H__

#include "Game.h"
#include <vector>

namespace MyGobang {
	class Player {
	public:
		virtual bool ChessDown(std::vector<std::string>& board) = 0;
		virtual void init() = 0;
	};


	class AI : public Player {
	public:
		virtual bool ChessDown(std::vector<std::string>& board);
		virtual void init();
	
	private:
		void thinking(const std::vector<std::string>& board);
		std::vector<std::vector<int>> score;
	};

	class Human : public Player {
	public:
		virtual bool ChessDown(std::vector<std::string>& board);
		virtual void init() {}
	};

}

#endif

