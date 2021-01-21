/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (42.30%)
 * Likes:    1892
 * Dislikes: 289
 * Total Accepted:    303.9K
 * Total Submissions: 712.6K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */

// @lc code=start
// 12ms
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row1zero(false), column1zero(false);

        for (int i=0; i<matrix.size(); ++i){
            if (!matrix[i][0]) {
                column1zero = true;
                break;
            }
        }
        for (auto i : matrix[0]){
            if (!i) {
                row1zero = true;
                break;
            }
        }
        for (int i=0; i<matrix.size(); ++i){
            for (int j=0; j<matrix[0].size(); ++j) {
                if (!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i=1; i<matrix.size(); ++i){
            if (!matrix[i][0]) {
                for (int j=1; j<matrix[0].size(); ++j){
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i=1; i<matrix[0].size(); ++i){
            if (!matrix[0][i]) {
                for (int j=1; j<matrix.size(); ++j) matrix[j][i] = 0;
            }
        }
        if (row1zero) {
            for (int i=0; i<matrix[0].size(); ++i) matrix[0][i] = 0;
        }
        if (column1zero) {
            for (int i=0; i<matrix.size(); ++i) matrix[i][0] = 0;
        }
        
    }
};
// @lc code=end
