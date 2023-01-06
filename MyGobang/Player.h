#ifndef __MYGOBANG_PLAYER_H__
#define __MYGOBANG_PLAYER_H__

#include <numeric>
#include <vector>

namespace MyGobang {
	class ChessPos;

	class Player {
	public:
		virtual ChessPos* ChessDown(std::vector<std::string>& board) = 0;
	protected:
		bool eorl;				// 先后手标记
	};

	class AI : public Player {
	public:
		AI(bool flag) { eorl = flag; score.resize(10); std::iota(score.begin(), score.end(), 0); }
		virtual ChessPos* ChessDown(std::vector<std::string>& board);
	
	private:
		ChessPos* thinking(const std::vector<std::string>& board); //决定下一步落子在哪
		std::vector<int> score;
	};

	class Human : public Player {
	public:
		Human(bool flag) { eorl = flag; }
		virtual ChessPos* ChessDown(std::vector<std::string>& board);
	};

}

#endif

