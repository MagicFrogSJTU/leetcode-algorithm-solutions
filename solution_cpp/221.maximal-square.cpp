/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (37.35%)
 * Likes:    3124
 * Dislikes: 79
 * Total Accepted:    267.4K
 * Total Submissions: 711.2K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */
#include <iostream>
#include <climits>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        vector<int> dps(matrix[0].size());
        for (int i=0; i<dps.size(); ++i)
            dps[i] = matrix[0][i] - '0';
        int max_len = *max_element(dps.begin(), dps.end());

        for (int i=1; i<matrix.size(); ++i){
            int last_dps_j_minus_1 = dps[0];
            dps[0] = matrix[i][0] - '0';
            max_len = max(max_len, dps[0]);
            for (int j=1; j<matrix[i].size(); ++j){
                if (matrix[i][j] == '0'){
                    last_dps_j_minus_1 = dps[j];
                    dps[j] = 0;
                }else{
                    last_dps_j_minus_1 = min(min(dps[j-1], dps[j]), last_dps_j_minus_1) + 1;
                    swap(last_dps_j_minus_1, dps[j]);
                    max_len = max(max_len, dps[j]);
                }
            }
        }
        return pow(max_len, 2);
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << Solution().maximalSquare(matrix) << endl;
    matrix = {{'0'}, {'1'}};
    cout << Solution().maximalSquare(matrix) << endl;
    return 0;
}
