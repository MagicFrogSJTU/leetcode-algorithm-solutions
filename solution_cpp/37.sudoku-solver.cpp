/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (45.38%)
 * Likes:    2387
 * Dislikes: 99
 * Total Accepted:    217.1K
 * Total Submissions: 472.9K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * The '.' character indicates empty cells.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 * 
 * 
 */
#include <iostream>
#include <climits>
#include <map>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    bool row[9][9];
    bool column[9][9];
    bool square[9][9];
    void solveSudoku(vector<vector<char>>& board) {
        memset(row,false,81);
        memset(column,false,81);
        memset(square,false,81);
        for (int x=0; x<9; ++x){
            for (int y=0; y<9; ++y){
                if (board[x][y] == '.') continue;
                int choice = board[x][y] - '1';
                row[x][choice] = column[y][choice] = square[x/3*3+y/3][choice] = true;
            }
        }
        func(board, 0, 0);
    }

    bool func(vector<vector<char>> &board, int x, int y){
        //printf("%d %d \n", x, y);
        int x_next(x), y_next=y+1;
        if (y==9) {
            y_next = 0;
            ++x_next;
            if (x_next==9) return true;
        }

        if (board[x][y] != '.') {
            return func(board, x_next, y_next);
        }else {
            for (int i=0; i<9; ++i){
                if (row[x][i] || column[y][i] || square[x/3*3+y/3][i]) continue;

                board[x][y] = '1' + i;
                row[x][i] = column[y][i] = square[x/3*3+y/3][i] = true;
                if (func(board, x_next, y_next)) return true;
                board[x][y] = '.';
                row[x][i] = column[y][i] = square[x/3*3+y/3][i] = false;
            }
            return false;
        }
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    Solution().solveSudoku(board);
    for (int i=0; i<9; ++i){
        for (int j=0; j<9; ++j){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
