/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (51.97%)
 * Likes:    838
 * Dislikes: 102
 * Total Accepted:    180.4K
 * Total Submissions: 346.6K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int c(0);
        for (int i=0; i<n/2; ++i){
            for (int j=0; j<n-1-2*i; ++j){
                ans[i][i+j] = ++c;
            }
            for (int j=0; j<n-1-2*i; ++j){
                ans[i+j][n-1-i] = ++c;
            }
            for (int j=0; j<n-1-2*i; ++j){
                ans[n-1-i][n-1-i-j] = ++c;
            }
            for (int j=0; j<n-1-2*i; ++j){
                ans[n-1-i-j][i] = ++c;
            }
        }
        if (n%2==1) ans[n/2][n/2] = ++c;
        return ans;
        
    }
};
// @lc code=end
