#include "tools.h"
#include <vector>
#include <string>
#include <algorithm>

namespace MyGobang {
	int MaxCountOneLine(const std::vector<std::string> &board, int x, int y, char color) {
		int rowcnt = 1, colcnt = 1, deg45cnt = 1, deg135cnt = 1;
		// ÐÐ
		for (int i = x + 1; i < board.size() && board[i][y] == color; i++) rowcnt++;
		for (int i = x - 1; i >= 0 && board[i][y] == color; i--) rowcnt++;

		// ÁÐ
		for (int i = y + 1; i < board.size() && board[x][i] == color; i++) colcnt++;
		for (int i = y - 1; i >= 0 && board[x][i] == color; i--) colcnt++;

		// 45¡ã
		for (int i = 1; x - i >= 0 && y + i < board.size() && board[x - i][y + i] == color; i++) deg45cnt++;
		for (int i = 1; x + i < board.size() && y - i >= 0 && board[x + i][y - i] == color; i++) deg45cnt++;

		// 135¡ã
		for (int i = 1; x - i >= 0 && y - i >= 0 && board[x - i][y - i] == color; i++) deg135cnt++;
		for (int i = 1; x + i < board.size() && y + i < board.size() && board[x + i][y + i] == color; i++) deg135cnt++;

		return std::max(std::max(rowcnt, colcnt), std::max(deg45cnt, deg135cnt));
	}
}
