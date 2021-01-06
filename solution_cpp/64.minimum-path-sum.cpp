/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (51.55%)
 * Likes:    2558
 * Dislikes: 54
 * Total Accepted:    379.2K
 * Total Submissions: 715.7K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dps(grid[0].size());
        dps[0] = grid[0][0];
        for (int j=1; j<grid[0].size(); ++j){
            dps[j] = dps[j-1] + grid[0][j];
        }
        for (int i=1; i<grid.size(); ++i){
            dps[0] += grid[i][0];
            for (int j=1; j<grid[0].size(); ++j){
                dps[j] = min(dps[j-1], dps[j]) + grid[i][j];
            }
        }
        return dps[grid[0].size()-1];
    }
};
// @lc code=end
