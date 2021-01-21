/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (34.03%)
 * Likes:    3412
 * Dislikes: 167
 * Total Accepted:    447.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board and word consists only of lowercase and uppercase English letters.
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
// 28ms
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                if (backtrace(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }

    bool backtrace(const int x, const int y, int pos, 
                   vector<vector<char>> &board, const string &word) {
        if (board[x][y] == word[pos]) {
            ++pos;
            if (pos == word.size()) return true;
            char buffer(' ');
            swap(board[x][y], buffer);

            if (x>0 && board[x-1][y]!=' ' && backtrace(x-1, y, pos, board, word)) return true;
            if (y>0 && board[x][y-1]!=' ' && backtrace(x, y-1, pos, board, word)) return true;
            if (x+1<board.size() && board[x+1][y]!=' ' && backtrace(x+1, y, pos, board, word)) return true;
            if (y+1<board[0].size() && board[x][y+1]!=' ' && backtrace(x, y+1, pos, board, word)) return true;
            swap(board[x][y], buffer);
        }
        return false;
    }
};
// @lc code=end
